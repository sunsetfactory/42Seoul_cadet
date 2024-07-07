#include "../includes/Server.hpp"
#include "../includes/Channel.hpp"
#include "../includes/Client.hpp"
#include "../includes/Command.hpp"

#define seok "@debugSeok" << std::endl

// Server::Server(char *portNum, char *password)
Server::Server(int portNum, std::string password)
{
	_command = new Command(*this);	// Command 객체 생성 -> 왜? 전방선언 하...
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
	kqueueInit();	// kq에 serverSock(리스닝소켓) 등록
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
    if (kevent(_kq, &_changeList[0], _changeList.size(), 0, 0, NULL) == -1) 
        throw std::logic_error("ERROR :: kevent() error");
}

// command <option>

#include <fstream>

void Server::execute()
{
	int _eventCnt;
	static std::ofstream logFile("log.txt");

	_eventCnt = 0;
	std::cout << "#7_execute 시작" << "\n=== === === ===\n\n" << std::endl;
	while (1)
	{
		_eventCnt = kevent(_kq, &_changeList[0], _changeList.size(), _eventList, 256, NULL);
		logFile << "eventCnt : " << _eventCnt << std::endl;
		if (_eventCnt == -1)
		{
			close(_serverSock);
			throw std::runtime_error("kevent error");
		}
		_changeList.clear();
		std::cout << "#eventCnt : " << _eventCnt << std::endl;
		for (int i = 0; i < _eventCnt; i++)
		{
			std::cout << "#i:" << i << std::endl;
			_curr_event = &_eventList[i];
			if (_curr_event->flags & EV_ERROR)
			{
				std::cerr << "EV_ERROR" << std::endl;
				if (_curr_event->ident == static_cast<uintptr_t>(_serverSock))
				{
					closeClient();
					close(_serverSock);
					throw std::runtime_error("server socket error");
				}
				else
				{
					std::cerr << "client socket error" << std::endl;
					disconnectClient(_curr_event->ident);
				}
			}
			else if (_curr_event->filter == EVFILT_READ)
			{
				std::cout << "#READ EVENT 감지" << std::endl;
				if (_curr_event->ident == static_cast<uintptr_t>(_serverSock))
				{
					std::cout << "#The first connect" << std::endl;
					int clientSock;
					if ((clientSock = accept(_serverSock, NULL, NULL)) == -1)
						throw acceptError();
					std::cout << "#accept 완료 : (" << clientSock << ")" << std::endl;
					fcntl(clientSock, F_SETFL, O_NONBLOCK);
					changeEvent(clientSock, READ, NULL);
					_clientList.insert(std::make_pair(clientSock, Client(clientSock)));
					std::cout << "#clientList에 추가 완료 : (" << clientSock << ")" << std::endl;
				}
				else if (_clientList.find(_curr_event->ident) != _clientList.end())
				{
					std::cout << "#Client socket: " << _curr_event->ident << std::endl;
					_command->run(_curr_event->ident);
					std::cout << "#command run 완료" << std::endl;
				}
			}
		}
		std::cout << "#send point" << std::endl;
		std::map<int, Client>::iterator iter;
		iter = _clientList.begin();
		while (iter != _clientList.end())
		{
			if (iter->second.getReciveBuf().empty() == false)
			{
				std::cout << "#->send to " << iter->first << iter->second.getReciveBuf() << "\n\n" << std::endl;
				send(iter->first, iter->second.getReciveBuf().c_str(), iter->second.getReciveBuf().size(), 0);
				iter->second.clearReciveBuf();
			}
			iter++;
		}
		std::cout << "#send 완료\n\n\n" << std::endl;
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


// 태현 추가
Server::~Server()
{
	std::map<int, Client>::iterator iter;
	iter = _clientList.begin();
	while (iter != _clientList.end())
	{
		close(iter->first);
		iter++;
	}

	std::map<std::string, Channel*>::iterator channelIter;
	channelIter = _channelList.begin();
	while (channelIter != _channelList.end())
	{
		delete (channelIter->second);
		channelIter++;
	}

	_clientList.clear();
	_channelList.clear();
	delete _command;	// new Command(*this); 생성자에서 동적할당했었음
	close(_serverSock);
}

std::map<int, Client>::iterator Server::findClient(std::string nickname)
{
	std::map<int, Client>::iterator iter;
	
	iter = _clientList.begin();
	while (iter != _clientList.end())
	{
		if (iter->second.getNickname() == nickname)
			return (iter);
		iter++;
	}
	return (iter);
}

std::map<int, Client> &Server::getClientList()
{
	return (_clientList);
}

std::map<std::string, Channel*> &Server::getChannelList()
{
	return (_channelList);
}

Channel* Server::findChannel(std::string channel_name)
{
	std::map<std::string, Channel*>::iterator iter;
	
	iter = _channelList.find(channel_name);
	if (iter != _channelList.end())
		return ((iter->second));
	return (NULL);
}

void Server::appendNewChannel(int fd, std::string& channelName)
{
	_channelList.insert(std::make_pair(channelName, new Channel(channelName, fd)));
}

std::string Server::getMessage(int clientSock)
{
    std::string message;
    char buf[513];										// line max_len == 510 (512 - "\r\n") + 1 for '\0'
    int n = recv(clientSock, buf, sizeof(buf) - 1, 0);	// 512 characters 까지만
    if (n <= 0)
    {
        if (n < 0)
            std::cerr << "client read error!" << std::endl;
        disconnectClient(clientSock);
    }
    else
    {
        if (n > 512) // 메시지가 510자를 초과하는 경우
        {
			buf[510] = '\r';	//실제 글자 번째인 511번째에 '\r'을 넣어줌
			buf[511] = '\n';	//실제 글자 번째인 512번째에 '\n'을 넣어줌
			buf[512] = '\0';

        	message = std::string(buf, 513);	// 'std::string(buf, 513);' -> buf의 513개의 문자를 message에 저장
        }
        else
        {
            buf[n] = '\0';
            message = buf;
        }
    }
    return message;
}

std::string Server::getPassword()
{
	return (_password);
}

void Server::removeChannel(std::string channelName)
{
	_channelList.erase(channelName);
}

void Server::closeClient()
{
	std::map<int, Client> clients = _clientList;

	for (std::map<int, Client>::iterator c_it = clients.begin(); c_it != clients.end(); c_it++)
		close(c_it->first);
}

void Server::disconnectClient(int client_fd)
{
	std::string ch_name;
	std::string nickname = _clientList[client_fd].getNickname();
	std::vector<std::string>  channels = _clientList[client_fd].getChannelList();

	// 들어가있는 모든 채널에서 삭제
	for (std::vector<std::string>::iterator m_it = channels.begin(); m_it != channels.end(); m_it++)
	{
		ch_name = *m_it;
		_channelList[ch_name]->removeFdListClient(client_fd);
		_channelList[ch_name]->removeOperatorFd(client_fd);
		_channelList[ch_name]->removeInviteFd(client_fd);
	}
	_clientList[client_fd].clearReciveBuf();
	_clientList[client_fd].clearAllChannel();
	_clientList.erase(client_fd);
	std::cout << "close client " << client_fd << std::endl;
	close(client_fd);
}
