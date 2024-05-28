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
	std::cout << server_fd << std::endl;
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

int Server::accept_socket()
{
	// 클라이언트 연결 허용
	// accept 함수는 클라이언트로부터 연결 요청이 올 때까지 블록된다. (블록된다는 것은 다른 작업을 수행할 수 없다는 것을 의미)
	// 연결 요청이 오면 새로운 소켓 파일 디스크립터를 반환한다.
	// 이 소켓 파일 디스크립터를 통해 클라이언트와 통신할 수 있다.
	// 이때 반환된 파일 디스크립터는 클라이언트를 식별하는 데 사용된다.
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int Server::read_and_write_socket()
{
	while (true)
	{
		// read 함수는 클라이언트로부터 데이터를 읽어들인다.
		// 이때 반환된 바이트 수는 buffer에 저장된 데이터의 길이를 의미한다.
		int valread = read(new_socket, buffer, BUFFER_SIZE);
		if (valread <= 0)
		{
			std::cout << "Client disconnected" << std::endl;
			break;
		}
		// send 함수는 클라이언트로 데이터를 전송한다.
		std::cout << "Received: " << buffer << std::endl;
		send(new_socket, buffer, valread, 0);
		std::memset(buffer, 0, BUFFER_SIZE);
	}
	return 0;
}

int Server::close_socket()
{
	close(new_socket);
	close(server_fd);
	return 0;
}

int Server::run()
{
	create_socket();
	bind_socket();
	listen_socket();
	accept_socket();
	read_and_write_socket();

	return 0;
}

int main()
{
	Server server;
	server.run();

	return 0;
}

// orthodox canonical form
Server::Server() : server_fd(0), new_socket(0), addrlen(sizeof(address))
{
	memset(buffer, 0, sizeof(buffer));
}

Server::~Server()
{
	close_socket();
}
