#include "client.hpp"

int Client::create_socket()
{
	// 소켓 파일 디스크립터 생성
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		std::cerr << "Socket creation error" << std::endl;
		return -1;
	}
	return 0;
}

int Client::connect_socket()
{
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// IP 주소 변환
	// inet_pton함수는 문자열로 된 IP 주소를 네트워크 바이트 순서의 정수로 변환
	// 성공하면 두 번째 인자로 전달된 주소 구조체에 변환된 주소를 저장
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		std::cerr << "Invalid address/ Address not supported" << std::endl;
		return -1;
	}
	connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	return 0;
}

int Client::read_send_socket()
{
	while (true)
	{
		std::cout << "Enter message: ";
		std::cin.getline(buffer, BUFFER_SIZE);

		send(sock, buffer, strlen(buffer), 0);
		read(sock, buffer, BUFFER_SIZE);
		std::cout << "Echo from server: " << buffer << std::endl;
		std::memset(buffer, 0, BUFFER_SIZE);
	}
}

int Client::close_socket()
{
	close(sock);
	return 0;
}

int Client::run()
{
	create_socket();
	connect_socket();
	read_send_socket();

	return 0;
}

int main()
{
	Client client;
	client.run();

	return 0;
}

// orthodox canonical form
Client::Client() : sock(0)
{
	std::memset(&serv_addr, '0', sizeof(serv_addr));
	std::memset(buffer, '0', sizeof(buffer));
}

Client::Client(const Client &other)
{
	sock = other.sock;
	serv_addr = other.serv_addr;
	std::memcpy(buffer, other.buffer, BUFFER_SIZE);
}

Client &Client::operator=(const Client &other)
{
	if (this != &other)
	{
		sock = other.sock;
		serv_addr = other.serv_addr;
		std::memcpy(buffer, other.buffer, BUFFER_SIZE);
	}
	return *this;
}

Client::~Client()
{
	close_socket();
}
