#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>		// std::cout
#include <cstring>		// std::memset
#include <unistd.h>		// close
#include <sys/socket.h> // socket, bind, listen, accept, send, recv
#include <netinet/in.h> // sockaddr_in
#include <sys/types.h>	// socket, bind, listen, accept, send, recv
#include <sys/event.h>	// kqueue, kevent
#include <sys/time.h>	// struct timespec
#include <fcntl.h>		// fcntl (for non-blocking)

#define PORT 8080
#define BUFFER_SIZE 65536

class Server
{
private:
	int server_fd;
	struct sockaddr_in address;
	int addrlen;
	int kq;

	int create_socket();
	int bind_socket();
	int listen_socket();
	void add_event();
	void handle_event();
	int accept_socket(int kq);
	void handle_client(struct kevent &event);
	int close_socket();

	Server(const Server &other);
	Server &operator=(const Server &other);

public:
	int run();

	Server();
	~Server();
};

#endif // SERVER_HPP
