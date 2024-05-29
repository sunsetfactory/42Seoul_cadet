#include "server.hpp"

int Server::create_socket()
{
	// AF_INET: IPv4 프로토콜을 사용한다는 것을 의미
	// SOCK_STREAM: TCP 프로토콜을 사용한다는 것을 의미
	// 이때 반환된 파일 디스크립터는 소켓을 식별하는 데 사용된다.
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	std::cout << "Server socket created: " << server_fd << std::endl;

	int flags = fcntl(server_fd, F_GETFL, 0);
	fcntl(server_fd, F_SETFL, flags | O_NONBLOCK);

	return 0;
}

int Server::bind_socket()
{
	// 소켓과 포트를 바인딩
	// INADDR_ANY: 모든 IP 주소로부터의 연결을 허용한다는 것을 의미
	// htons: 호스트 바이트 순서를 네트워크 바이트 순서로 변환한다.
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// bind 함수는 소켓에 주소를 할당한다.
	// 이때 sockaddr_in 구조체를 sockaddr 구조체로 변환해야 한다.
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int Server::listen_socket()
{
	// 연결 대기
	// 3: 동시에 처리할 수 있는 연결의 최대 개수
	// 동시에 처리할 수 있는 최대 연결 개수란 서버가 동시에 처리할 수 있는 최대 클라이언트의 수를 의미한다.
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	return 0;
}

void Server::add_event(int kq, int ident, int filter, int flags)
{
	// kqueue 생성
	kq = kqueue();
	if (kq == -1)
	{
		perror("kqueue");
		exit(EXIT_FAILURE);
	}

	// server_fd를 kqueue에 등록
	struct kevent change;
	EV_SET(&change, ident, filter, flags, 0, 0, NULL);
	if (kevent(kq, &change, 1, NULL, 0, NULL) == -1)
	{
		perror("kevent");
		exit(EXIT_FAILURE);
	}
}

int Server::run()
{
	create_socket();
	bind_socket();
	listen_socket();

	// kqueue 생성
	kq = kqueue();
	if (kq == -1)
	{
		perror("kqueue");
		exit(EXIT_FAILURE);
	}
	// server_fd를 kqueue에 등록
	struct kevent change;
	// EV_SET: 이벤트를 설정 (struct kevent *kev, uintptr_t ident, short filter, u_short flags, u_int fflags, intptr_t data, void *udata)
	// EVFILT_READ: 파일 디스크립터에 대한 읽기 가능 여부를 확인
	// EV_ADD: 이벤트를 추가
	// EV_ENABLE: 이벤트를 활성화
	// __kevp__->ident = (arg[0]);                  \ // 이벤트 식별자, 파일 디스크립터
	// __kevp__->filter = (arg[1]);                 \ // 이벤트 필터, EVFILT_READ = 파일 디스크립터에 대한 읽기 가능 여부를 확인, EVFILT_WRITE = 파일 디스크립터에 대한 쓰기 가능 여부를 확인
	// __kevp__->flags = (arg[2]);                  \ // 이벤트 플래그, EV_ADD = 이벤트를 추가, EV_DELETE = 이벤트를 삭제, EV_ENABLE = 이벤트를 활성화, EV_DISABLE = 이벤트를 비활성화

	EV_SET(&change, server_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);

	// kevent를 통해 이벤트를 등록
	// kevent 함수는 이벤트를 등록하고 이벤트가 발생할 때까지 대기
	if (kevent(kq, &change, 1, NULL, 0, NULL) == -1)
	{
		perror("kevent register");
		exit(EXIT_FAILURE);
	}

	// 이벤트가 발생하면 이벤트를 처리
	struct kevent events[10];
	while (true)
	{
		// 이벤트가 발생할 때까지 대기
		int nevents = kevent(kq, NULL, 0, events, 10, NULL);
		if (nevents == -1)
		{
			perror("kevent wait");
			exit(EXIT_FAILURE);
		}
		// 이벤트 처리
		for (int i = 0; i < nevents; i++)
		{
			if (events[i].ident == static_cast<uintptr_t>(server_fd))
			{
				accept_socket(kq);
			}
			else
			{
				handle_client(events[i]);
			}
		}
	}

	close_socket();
	return 0;
}

int Server::accept_socket(int kq)
{
	int new_client_fd;								   // 클라이언트의 파일 디스크립터
	struct sockaddr_in client_address;				   // 클라이언트의 주소
	socklen_t client_addrlen = sizeof(client_address); // 클라이언트 주소의 길이

	// 클라이언트의 연결을 수락
	while ((new_client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_addrlen)) != -1)
	{
		std::cout << "Accepted new connection: " << new_client_fd << std::endl;

		// 클라이언트의 파일 디스크립터를 non-blocking 모드로 설정
		int flags = fcntl(new_client_fd, F_GETFL, 0);	   // 파일 디스크립터의 플래그를 가져온다.
		fcntl(new_client_fd, F_SETFL, flags | O_NONBLOCK); // 파일 디스크립터의 플래그에 O_NONBLOCK을 추가한다.

		// 클라이언트의 파일 디스크립터를 kqueue에 등록
		struct kevent change;

		// EV_SET: 이벤트를 설정 (struct kevent *kev, uintptr_t ident, short filter, u_short flags, u_int fflags, intptr_t data, void *udata)
		// EVFILT_READ: 파일 디스크립터에 대한 읽기 가능 여부를 확인
		// EV_ADD: 이벤트를 추가
		// EV_ENABLE: 이벤트를 활성화

		// __kevp__->ident = (arg[0]);                  \ // 이벤트 식별자
		// __kevp__->filter = (arg[1]);                 \ // 이벤트 필터
		// __kevp__->flags = (arg[2]);                  \ // 이벤트 플래그
		// __kevp__->fflags = (arg[3]);                 \ // 이벤트 플래그
		// __kevp__->data = (arg[4]);                   \ // 이벤트 데이터
		// __kevp__->udata = (arg[5]);                  \ // 이벤트 사용자 데이터
		EV_SET(&change, new_client_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);

		// kevent를 통해 이벤트를 등록
		if (kevent(kq, &change, 1, NULL, 0, NULL) == -1)
		{
			perror("kevent register client");
			close(new_client_fd);
		}
	}

	if (errno != EAGAIN && errno != EWOULDBLOCK)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

	return 0;
}

void Server::handle_client(struct kevent &event)
{
	int client_fd = event.ident;
	if (event.flags & EV_EOF)
	{
		// Client disconnected
		std::cout << "Client disconnected: " << client_fd << std::endl;
		close(client_fd);
	}
	else if (event.filter == EVFILT_READ)
	{
		char buffer[BUFFER_SIZE];
		int bytes_read = read(client_fd, buffer, sizeof(buffer));
		if (bytes_read > 0)
		{
			std::cout << "Received: " << buffer << std::endl;
			send(client_fd, buffer, bytes_read, 0);
			memset(buffer, 0, BUFFER_SIZE);
		}
		else
		{
			if (bytes_read == 0)
				std::cout << "Client disconnected: " << client_fd << std::endl;
			else
				perror("read");

			close(client_fd);
		}
	}
}

int Server::close_socket()
{
	close(server_fd);
	return 0;
}

int main()
{
	Server server;
	server.run();

	return 0;
}

// Orthodox canonical form
Server::Server() : server_fd(0), addrlen(sizeof(address))
{
}

Server::~Server()
{
	close_socket();
}
