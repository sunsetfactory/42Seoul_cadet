#include "../includes/Server.hpp"
#include "../includes/IRCException.hpp"

/* constructor */
// Server::Server(char *portNum, char *password)
Server::Server(int portNum, std::string password) : _command(*this)
{
	_portNum = portNum;
	_password = password;
	_clientAddrSize = sizeof(_clientAddr);
}

void Server::run()
{
	setServerSock();
	setServerAddr();
	setServerBind();
	setServerListen();
	execute();
}

void Server::setServerSock()
{
	int opiton = 1;
	_serverSock = socket(PF_INET, SOCK_STREAM, 0);
	if (_serverSock == -1)
		throw std::runtime_error("socket error");
	if (setsockopt(_serverSock, SOL_SOCKET, SO_REUSEADDR, &opiton, sizeof(opiton)) == -1)
	{
		close(_serverSock);
		throw std::runtime_error("setsockopt error");
	}
}

void Server::setServerAddr()
{
	memset(&_serverAddr, 0, sizeof(_serverAddr));
	_serverAddr.sin_family = AF_INET;
	_serverAddr.sin_addr.s_addr = INADDR_ANY;
	_serverAddr.sin_port = htons(_portNum);
}

void Server::setServerBind()
{
	if (bind(_serverSock, (struct sockaddr *)&_serverAddr, sizeof(_serverAddr)) == -1)
	{
		close(_serverSock);
		throw std::runtime_error("bind error");
	}
}

void Server::setServerListen()
{
	if (listen(_serverSock, MAX_CONNECTION) == -1)
	{
		close(_serverSock);
		throw std::runtime_error("listen error");
	}
}

void Server::kqueueInit()
{
	_kq = kqueue();
	if (_kq == -1)
	{
		close(_serverSock);
		throw std::runtime_error("kqueue error");
	}

	changeEvent(_serverSock, READ, NULL);
    // struct kevent change_event;
    // EV_SET(&change_event, _serverSock, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL); // kqueue 설정
    // _changeList.push_back(change_event);

    if (kevent(_kq, &_changeList[0], _changeList.size(), 0, 0, NULL) == -1) 
        throw std::logic_error("ERROR :: kevent() error");
}

// command <option>

void Server::execute()
{
	kqueueInit();			// kq에 serverSock(리스닝소켓) 등록
	while (1)
	{
		_eventCnt = kevent(_kq, &_changeList[0], _changeList.size(), _eventList, 256, NULL);
		// Kq를 통해 생성된 이벤트 큐(kevent)를 식별할 것이고, \
		changeList에 있는 이벤트들을 _changeList.size()만큼 감시하고, \
		실제로 이벤트가 발생한 것이 있으면, eventList[256]에 이벤트들을 저장한다 -> \
		저장하고, 그 수만큼을 반환
		if (_eventCnt == -1)
		{
			close(_serverSock);
			throw std::runtime_error("kevent error");
		}
		_changeList.clear();
		for (int i = 0; i < _eventCnt; i++)
		{
			_curr_event = &_eventList[i];
			if (_curr_event->flags & EV_ERROR)
			{
				if (_curr_event->ident == _serverSock)
				{
					// closeClient();
					close(_serverSock);
					throw std::runtime_error("server socket error");
				}
				else
				{
					std::cerr << "client socket error" << std::endl;
					// disconnectClient(_curr_event.ident);
				}
			}
			else if (_curr_event->flags == EVFILT_READ)
			{
				if (_curr_event->ident == _serverSock)
				{
					int clientSock;
					if ((clientSock = accept(_serverSock, NULL, NULL)) == -1)
						throw acceptError();
					std::cout << "accept new client: " << clientSock << std::endl;
					fcntl(clientSock, F_SETFL, O_NONBLOCK);

					changeEvent(clientSock, READ, NULL);
					_clients[clientSock] = Client(clientSock);
				}
				else if (_clients.find(_curr_event->ident) != _clients.end())
				{
					char buf[1024];
					int n = recv(_curr_event->ident, buf, sizeof(buf), 0);

					if (n <= 0)
					{
						if (n < 0)
							std::cerr << "client read error!" << std::endl;
						// disconnectClient(_curr_event.ident);
					}
					else
					{
						buf[n] = '\0';
						_clients[_curr_event->ident].addBuffer(buf);
						std::cout << "received data from " << _curr_event->ident << ": " << _clients[_curr_event->ident].getBuffer() << std::endl;
						_command.run(_curr_event->ident);
					}
				}
			}
		}
	}
}

void Server::changeEvent(int ident, int flag, void *udata)
{
	struct kevent temp_event;
	if (flag == READ)
		EV_SET(&temp_event, ident, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, udata);
	else if (flag == WRITE)
		EV_SET(&temp_event, ident, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, udata);
	_changeList.push_back(temp_event);
}


/* destructor */
Server::~Server()
{
}