#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

class Server
{
private:
	// Member Variables
	int server_fd;
	int new_socket;
	struct sockaddr_in address;
	int addrlen;
	char buffer[BUFFER_SIZE];

	// Member Functions
	int create_socket();
	int bind_socket();
	int listen_socket();
	int accept_socket();
	int read_and_write_socket();
	int close_socket();

	// Orthodox Canonical Form
	Server(const Server &other);
	Server &operator=(const Server &other);

public:
	// Server Run
	int run();

	// Orthodox Canonical Form
	Server();
	~Server();
};

#endif // SERVER_HPP