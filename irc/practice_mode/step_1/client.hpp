#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1500

class Client
{
private:
	// Member Variables
	int sock;
	struct sockaddr_in serv_addr;
	char buffer[BUFFER_SIZE];

	// Member Functions
	int create_socket();
	int connect_socket();
	int read_send_socket();
	int close_socket();

	// Orthodox Canonical Form
	Client(const Client &other);
	Client &operator=(const Client &other);

public:
	// Client Run
	int run();

	// Orthodox Canonical Form
	Client();
	~Client();
};

#endif // CLIENT_HPP