### ./main.cpp
```cpp
#include "includes/Server.hpp"

int	filter(int *port, std::string *password, char *av1, char *av2)
{
	for (int i = 0; av1[i]; i++)
	{
		if (!isdigit(av1[i]))
			return (std::cerr << "Port number is not a number" << std::endl || 1);
	}

	*port = atoi(av1);
	if (*port < 1024 || *port > 65535)
		return (std::cerr << "Wrong port number" << std::endl || 1);

	*password = std::stringstream(av2).str();
	if (password->empty())
		return (std::cerr << "Password empty" << std::endl || 1);

	if (password->length() > 10) // Password is too long
		return (std::cerr << "Password too long" << std::endl || 1);
	
	return (0);
}

int main(int argc, char *argv[])
{
	int			port;
	std::string	password;

	if (argc != 3)
		return (std::cerr << "Usage: ./ircserv [port] [password]" << std::endl || 1);

	if (filter(&port, &password, argv[1], argv[2]))
		return (1);

	try
	{
		Server server(port, password);
		server.run();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

```
### ./includes/Main.hpp
```cpp
#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include <sys/event.h>
# include <arpa/inet.h>
# include <sys/event.h>
# include <fcntl.h>
# include <err.h>
# include <sys/fcntl.h>
# include <sys/socket.h>
# include <unistd.h>
# include <map>
# include <vector>
# include <sstream>
# include <algorithm>
# include <cstddef>

# define BUF_SIZE 1024

// PASS
# define ERR_NEEDMOREPARAMS "Not enough parameters\r\n"
# define ERR_PASSWDMISMATCH "Password incorrect\r\n"
# define ERR_ALREADYREGISTRED "You may not reregister\r\n"

// NICK
# define ERR_NICKNAMEINUSE "Nickname is already in use\r\n"
# define ERR_NICKCOLLISION "Nickname collision KILL from\r\n"
# define ERR_NONICKNAMEGIVEN "No nickname given\r\n"
# define ERR_ERRONEUSNICKNAME "Erroneus nickname\r\n"

// PRIVMSG
# define ERR_NOSUCHCHANNEL "No such channel\r\n"
# define ERR_NOSUCHNICK "No such nick/channel\r\n"

// PART
# define ERR_NOSUCHCHANNEL "No such channel\r\n"
# define ERR_NOTONCHANNEL "You're not on that channel\r\n"

// KICK
# define ERR_CHANOPRIVSNEEDED "You're not channel operator\r\n"
# define ERR_USERNOTINCHANNEL "They aren't on that channel\r\n"

// COMMON
# define ERR_NOTREGISTERED "You have not registered\r\n"

// MODE
# define ERR_UMODEUNKNOWNFLAG "Unknown MODE flag\r\n"
# define ERR_USERSDONTMATCH "Can't change mode for other users\r\n"
# define ERR_UNKNOWNMODE "is unknown mode char to me\r\n"
# define ERR_CHANNELISFULL "Cannot join channel (+l)\r\n"

// JOIN
# define ERR_INVITEONLYCHAN "Cannot join channel (+i)\r\n"
# define ERR_BADCHANNELKEY "Cannot join channel (+k)\r\n"

// TOPIC
# define RPL_NOTOPIC "No topic is set\r\n"

// INVITE
# define ERR_USERONCHANNEL "is already on channel\r\n"
# define RPL_INVITING "Inviting\r\n"

#endif
```
### ./includes/Server.hpp
```cpp
#ifndef SERVER_HPP
#define SERVER_HPP
#define BUF_SIZE 1024
#define MAX_CONNECTION 5

#define READ 0
#define WRITE 1

#include "../includes/Main.hpp"

class	Client;
class	Channel;
class	Command;

class	Server
{
	private:
		Server();
		Server(const Server &);
		Server &operator=(const Server &);

		std::map<int, Client> 				_clientList;
		std::map<std::string, Channel *>	_channelList;
		struct sockaddr_in					_clientAddr;
		socklen_t							_clientAddrSize;
		Command								*_command;
		std::string							_password;
		unsigned short int					_portNum;
		struct sockaddr_in					_serverAddr;
		int									_serverSock;
		int									_kq;
		struct kevent						_eventList[256];
		struct kevent						*_curr_event;
		std::vector<struct kevent>			_changeList;

		void								kqueueInit();
		void								changeEvent(int ident, int flag, void *udata);
		void								setServerSock();
		void								setServerAddr();
		void								setServerBind();
		void								setServerListen();
		void								execute();
		int									recvMessage(int);
		void								addClient(int);
		bool								checkMessageEnds(int);
		void								doCommand(int);

		void								closeClient();
		void								disconnectClient(int client_fd);

	public:
		Server(int, std::string);
		~Server();

		void								run();

		std::map<int, Client>&				getClientList();
		std::string							getPassword();
		std::string							getMessage(int, int);
		std::map<std::string, Channel *>&	getChannelList();
		
		Channel*							findChannel(std::string);
		std::map<int, Client>::iterator		findClient(std::string);
		void								removeChannel(std::string);
		void								appendNewChannel(int, std::string &);

		class bindError : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("bind error");
			}
		};
		class listenError : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("listen error");
			}
		};
		class kqueueError : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("kqueue error");
			}
		};
		class keventError : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("kevent error");
			}
		};
		class acceptError : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("accept error");
			}
		};
		class readError : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("read error");
			}
		};
		class unknownError : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("unknown error");
			}
		};
};

#endif
```
### ./includes/Error.hpp
```cpp
#ifndef ERROR_HPP
# define ERROR_HPP

# include "../includes/Client.hpp"

// PASS
# define ERR_NEEDMOREPARAMS "Not enough parameters\r\n"
# define ERR_PASSWDMISMATCH "Password incorrect\r\n"
# define ERR_ALREADYREGISTRED "You may not reregister\r\n"

// NICK
# define ERR_NICKNAMEINUSE "Nickname is already in use\r\n"
# define ERR_NICKCOLLISION "Nickname collision KILL from\r\n"
# define ERR_NONICKNAMEGIVEN "No nickname given\r\n"
# define ERR_ERRONEUSNICKNAME "Erroneus nickname\r\n"

// PRIVMSG and PART
# define ERR_NOSUCHCHANNEL "No such channel\r\n"
# define ERR_NOSUCHNICK "No such nick/channel\r\n"
# define ERR_CANNOTSENDTOCHAN "Cannot send to channel\r\n"

// PART
# define ERR_NOTONCHANNEL "You're not on that channel\r\n"

// KICK
# define ERR_CHANOPRIVSNEEDED "You're not channel operator\r\n"
# define ERR_USERNOTINCHANNEL "They aren't on that channel\r\n"

// COMMON
# define ERR_NOTREGISTERED "You have not registered\r\n"

// MODE
# define ERR_UMODEUNKNOWNFLAG "Unknown MODE flag\r\n"
# define ERR_USERSDONTMATCH "Can't change mode for other users\r\n"
# define ERR_UNKNOWNMODE "is unknown mode char to me\r\n"
# define ERR_CHANNELISFULL "Cannot join channel (+l)\r\n"

// JOIN
# define ERR_INVITEONLYCHAN "Cannot join channel (+i)\r\n"
# define ERR_BADCHANNELKEY "Cannot join channel (+k)\r\n"

// TOPIC
# define RPL_NOTOPIC "No topic is set\r\n"

// INVITE
# define ERR_USERONCHANNEL "is already on channel\r\n"
# define RPL_INVITING "Inviting\r\n"

// OTHER
# define ERR_UNKNOWNCOMMAND "Unknown command\r\n"

class Client;

void ERROR_nosuchnick_401(Client &, std::string);
void ERROR_nosuchchannel_403(Client &, std::string);
void ERROR_cantsendtochan_404(Client &, std::string);
void ERROR_usernotinchannel_441(Client &, std::string, std::string);
void ERROR_notonchannel_442(Client &, std::string);
void ERROR_useronchannel_443(Client &, std::string, std::string);
void ERROR_nonicknamegiven_431(Client &);
void ERROR_erroneusnickname_432(Client &);
void ERROR_nicknameinuse_433(Client &);
void ERROR_notregistered_451(Client &);
void ERROR_needmoreparams_461(Client &);
void ERROR_alreadyregistred_462(Client &);
void ERROR_passwdmismatch_464(Client &);
void ERROR_channelisfull_471(Client &, std::string);
void ERROR_unknownmode_472(Client &, char);
void ERROR_inviteonlychan_473(Client &, std::string);
void ERROR_badchannelkey_475(Client &, std::string);
void ERROR_chanoprivsneeded_482(Client &, std::string);
void ERROR_unknowncommand_421(Client &, std::string);

#endif

```
### ./includes/Channel.hpp
```cpp
#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "../includes/Main.hpp"
# include "../includes/Server.hpp"

class Channel
{
	private:
		std::string                 _channelName;
		
		std::vector<int>            _operatorFdList;
		std::vector<int>            _clientFdList;
		std::vector<int>            _inviteFdList;
		std::string                 _topic;
		std::string                 _key;

		bool                        _inviteStatus;
		bool                        _topicStatus;
		bool                        _keyStatus;
		bool                        _limitStatus;

		unsigned int                _limit;

	public:
		Channel();
		Channel(const std::string&, int);
		Channel(const Channel &);
		Channel &operator=(const Channel &);
		~Channel();

		// getters
		std::string                 getChannelName();
		std::vector<int>            getFdListClient();
		std::vector<int>            getFdListOperator();
		std::string                 getMode();
		std::string                 getTopic();
		unsigned int                getLimit();
		std::string                 getKey();
		std::vector<int>::iterator  findIterClient(int);

		void                        setChannelName(std::string&);
		void                        setMode(unsigned char, char, int);
		void                        setLimit(unsigned int);
		void                        setTopic(std::string);
		void                        setKey(std::string);
		void                        appendFdListClient(int);
		void                        removeFdListClient(int);
		void                        addOperatorFd(int);
		void                        removeOperatorFd(int);
		void                        appendFdListInvite(int);
		void						setOperator(int, char);
		void						removeInviteFd(int);

		bool						diffMode(unsigned char);
		bool                        diffInvite(int);
		bool                        diffKey(std::string);
		bool                        diffClientInChannel(int);
		bool                        diffOperator(int);	

		std::string					makeMsgForm(int);
		void						messageAllChannel(int, std::string, std::string, std::string);
};

#endif

```
### ./includes/Command.hpp
```cpp
#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "../includes/Main.hpp"
# include "../includes/Client.hpp"
# include "../includes/Server.hpp"
# include "../includes/Util.hpp"
# include "../includes/Error.hpp"
# include "../includes/Channel.hpp"

#define PREFIX_SERVERNAME "localhost.42seoul.kr"

class Client;
class Server;
class Channel;

class Command
{

	private:
		Command();
		Command &operator=(const Command&);
		Command(const Command&);

		Server						&_server;
		std::vector<int> 			_sendNickList;
		std::vector<int>::iterator	_sendNickIter;

	public:
		Command(Server &server);
		~Command();

		void		run(int, int);
		void		irssiSignUp(int, std::string);
		void		signUp(int, std::map<int, Client>::iterator, std::vector<std::string>&, std::map<int, Client>&);
		void		notRegister(int, std::map<int, Client>::iterator, std::map<int, Client>&);
		void		signIn(int, std::vector<std::string>&);
		void		pass(int, std::vector<std::string>);
		void		nick(int, std::vector<std::string>);
		void		user(int, std::vector<std::string>);
		void 		privmsg(int, std::vector<std::string>);
		void		quit(int, std::vector<std::string>);
		void		part(int, std::vector<std::string>);
		void		join(int, std::vector<std::string>);
		void		kick(int, std::vector<std::string>);
		void		mode(int, std::vector<std::string>);
		void		topic(int, std::vector<std::string>);
		void		invite(int, std::vector<std::string>);
		void		list(int, std::vector<std::string>);
		void		ping(int, std::vector<std::string>);
		void		botCommand(int, std::vector<std::string>);
		void		topicMessage(int, std::string);
		bool		nicknameDuplicate(std::string, std::map<int, Client>&);
		bool		nickNameValidate(std::string);
		bool		checkRealname(std::string);
		bool		checkBotCommand(std::string);
		std::string	channelMessage(int, std::vector<std::string>);
		void		channelPRIVMSG(std::string, Client&, Channel*);
		void		channelPART(int, std::string, std::vector<std::string>);
		void		nameListMsg(int, std::string);
		std::string intToString(int);

		std::string					makeMsgForm(int, std::string);
		void						messageAllChannel(int, std::string, std::string, std::string);
		void 						plus_messageAllChannel(int, std::string, std::string, std::string, std::string);

};

#endif


// <message>  ::= [':' <prefix> <SPACE> ] <command> <params> <crlf>
// <prefix>   ::= <servername> | <nick> [ '!' <user> ] [ '@' <host> ]
// <command>  ::= <letter> { <letter> } | <number> <number> <number>
// <SPACE>    ::= ' ' { ' ' }
// <params>   ::= <SPACE> [ ':' <trailing> | <middle> <params> ]

// <middle>   ::= <Any *non-empty* sequence of octets not including SPACE
//                or NUL or CR or LF, the first of which may not be ':'>
// <trailing> ::= <Any, possibly *empty*, sequence of octets not including
//                  NUL or CR or LF>

// <crlf>     ::= CR LF

```
### ./includes/Util.hpp
```cpp
#ifndef UTIL_HPP
# define UTIL_HPP

# include "Main.hpp"
# include "Command.hpp"

bool						isSpecialChar(char c);
std::vector<std::string>	split(std::string str, char delim);

#endif

```
### ./includes/Client.hpp
```cpp
#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "Server.hpp"

class Client
{
	private:
		int							_fd;
		std::vector<std::string>	_channelList;

		std::string					_reciveBuf;
		std::string					_nickName;
		std::string					_userName;
		std::string					_realName;
		std::string					_hostName;
		std::string					_serverName;

		bool						_isRegiPass;
		bool						_isRegiNick;
		bool						_isRegiUser;

		std::stringstream			_eofBuffer;
		bool						_eofFlag;
		Client &operator=(const Client &);

	
	public:
		Client();
		Client(int);
		Client(const Client &);
		~Client();
		std::vector<std::string>::iterator	findChannel(std::string);

		int							getClientFd();
		std::vector<std::string>	&getChannelList();
		std::string					getNickname();
		std::string					getUsername();
		std::string					getHostname();
		std::string					getServername();
		std::string					getRealname();
		std::string					getReciveBuf();
		bool						getIsRegist();
		bool						getRegiPass();
		bool						getRegiNick();
		bool						getRegiUser();
		std::stringstream			&getEofBuffer();
		bool						getEofFlag();

		void						setRegiPass(bool);
		void						setRegiNick(bool);
		void						setRegiUser(bool);
		void						setRegiAll(bool);
		void						setNickname(std::string);
		void						setUserinfo(std::string, std::string, std::string, std::string);
		void						appendReciveBuf(std::string);
		void						appendChannelList(std::string);
		void						setEofBuffer(std::stringstream&);
		void						setEofFlag(bool);

		void						clearReciveBuf();
		void						clearAllChannel();
		void						resetClient();
		void						deleteChannel(std::string);
};

#endif
```
### ./docker_ALL/Dockerfile
```Dockerfile
# FROM ubuntu:20.04
FROM debian:bullseye

# Set environment variable to prevent interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Change to Kakao mirror server for faster download speeds
RUN sed -i 's|http://archive.ubuntu.com/ubuntu/|http://mirror.kakao.com/ubuntu/|g' /etc/apt/sources.list  # 추가된 부분: Kakao 미러 서버 설정

# Update package list and install necessary packages
RUN apt-get update && \
    apt-get install -y sudo tzdata && \
	sudo apt-get install -y tcpflow && \
	sudo apt-get install -y netcat-openbsd

RUN echo "taehkwon: 'sudo', 'tzdata' Done" && \
	echo "taehkwon: Waiting.. install (1)inspircd and (2)irssi"

# Install inspircd and irssi
RUN sudo apt-get install -y inspircd && \
    echo "Asia/Seoul" > /etc/timezone && \
    ln -fs /usr/share/zoneinfo/Asia/Seoul /etc/localtime && \
    dpkg-reconfigure --frontend noninteractive tzdata && \
    sudo apt-get install -y irssi

# Create required directory
RUN sudo mkdir -p /var/run/inspircd

# Copy the entrypoint script to the container
COPY start.sh /usr/local/bin/

# Make the entrypoint script executable
RUN chmod +x /usr/local/bin/start.sh

# Set the entrypoint
ENTRYPOINT ["/usr/local/bin/start.sh"]

```
### ./docker_ALL/docker-compose.yml
```yml
services:
  irc:
    build: .
    container_name: irc
    ports:
      - "6667:6667"
    tty: true

```
### ./docker_ALL/start.sh
```bash
#!/bin/bash

echo "taehkwon: Starting the InspIRCd server...\n"

# Start inspircd in the background
sudo inspircd --runasroot --nofork &

# Wait for 20 seconds to ensure the process ID is generated
echo "taehkwon: Waiting for 20 seconds to ensure the process ID is generated...\n"
sleep 20
echo "\ntaehkwon: Done!\n"

echo "taehkwon: Starting tcpflow to capture IRC traffic on port 6667...\n"
sudo tcpflow -i lo port 6667 -c &

# irssi -c 127.0.0.1 -p 6667 -n taehkwon
# docker exec -it irc /bin/bash

# Keep the container running
tail -f /dev/null

```
### ./command/Kick.cpp
```cpp
#include "../includes/Command.hpp"
#include "../includes/Util.hpp"

void Command::kick(int fd, std::vector<std::string> cmdVector)
{
	// KICK <channel> <nickname>

	std::map<int, Client>& clientList = _server.getClientList();			// 서버에 접속한 클라이언트 리스트
	std::map<int, Client>::iterator operator_iter = clientList.find(fd);	// 클라이언트 리스트에서 '명령어를 사용'하려는 클라이언트의 fd를 찾아 반환
	if (cmdVector.size() < 3)												// "KICK, <channel>, <nickname>" 안 들어올 경우
	{
		ERROR_needmoreparams_461(operator_iter->second);
		return;
	}

	std::stringstream ss(cmdVector[1]);
	std::string buffer;
	std::vector<std::string> channelVector;
	while (getline(ss, buffer, ','))
	{
		channelVector.push_back(buffer);
	}	// ex) #channel1, #channel2, #channel3

	// ==== 채널마다 oper 권한있는지 확인 ====
	std::vector<std::string>::iterator channel_iter;
	for (channel_iter = channelVector.begin(); channel_iter != channelVector.end(); channel_iter++)
	{
		Channel *channel = _server.findChannel(*channel_iter);					// 채널을 찾아 반환
		if (channel && !channel->diffOperator(fd))								// 채널이 존재하고, 채널의 operator가 아닐 경우
		{
			ERROR_chanoprivsneeded_482(operator_iter->second, *channel_iter);
			return;
		}
	}
	// ==== 통과 ====


	std::stringstream nickss(cmdVector[2]);
	std::string nickbuffer;
	std::vector<std::string> nickVector;
	while (getline(nickss, nickbuffer, ','))
	{
		nickVector.push_back(nickbuffer);
	}
	std::vector<std::string>::iterator nickIter;

	nickIter = nickVector.begin();
	// ==== 채널 kick ====
	for (channel_iter = channelVector.begin(); channel_iter != channelVector.end(); channel_iter++)
	{
		Channel *channel = _server.findChannel(*channel_iter);					// 채널을 찾아 반환

		if (channel == NULL)													// 채널이 존재하지 않을 경우
			ERROR_nosuchchannel_403(operator_iter->second, *channel_iter);
		else
		{
			std::map<int, Client>::iterator target = _server.findClient(*nickIter);	// <nickname> 찾아 반환

			// ==== <nickname> 인가 확인 ====
			if (target == _server.getClientList().end())								// <nickname> 서버에 존재하지 않을 경우
			{
				ERROR_nosuchnick_401(operator_iter->second, *nickIter);
				return;
			}
			if (target->second.getClientFd() == -1)										// <nickname> Client::resetclient()일 경우
			{
				ERROR_nosuchnick_401(operator_iter->second, *nickIter);
				return;
			}
			if (target->second.getNickname() == operator_iter->second.getNickname())	// <nickname> 자신일 경우
			{
				return;
			}
			// ==== 통과 ====

			// ==== 본격적으로 kick ====
			else
			{
				if (channel->diffClientInChannel(target->second.getClientFd()) == false)	// 찾고자 하는 채널에 <nickname>이 존재하지 않을 경우
					ERROR_usernotinchannel_441(operator_iter->second, *nickIter, *channel_iter);

				else
				{
					std::string message = *nickIter;
					if (cmdVector.size() > 3)
						message += " " + cmdVector[3];

					messageAllChannel(fd, *channel_iter, "KICK", message);		// 채널에 있는 모든 클라이언트에게 메시지 전송
					channel->removeFdListClient(target->second.getClientFd());	// '채널이 갖고 있는' 클라이언트 리스트에서 해당 nickname 클라이언트 제거
					channel->removeOperatorFd(target->second.getClientFd());	// '채널이 갖고 있는' 클라이언트 리스트에서 해당 nickname 클라이언트 제거
					target->second.deleteChannel(*channel_iter);				// '클라이언트가 갖고 있는' std::vector<std::string> _channelList; 에서 해당 채널 '_channelList.erase(iter);'
				}
			}
		}
		nickIter++;
	}
	// ==== kick 끝 ==== 
}
```
### ./command/Topic.cpp
```cpp
#include "../includes/Command.hpp"
#include "../includes/Util.hpp"

void Command::topic(int fd, std::vector<std::string> cmdVector)
{	// 양식: TOPIC <channel> <topic>
	// ex) TOPIC #test :topic

	// ==== 인자 유효성 검사 ====
	if (cmdVector.size() < 2)												// 곧 cmdVector[1] 사용할거라, cmdVector[0] Topic만 있으면 안됨
	{
		ERROR_needmoreparams_461(_server.getClientList().find(fd)->second);
		return ;
	}
	// ==== 통과 ====
	Channel *channel = _server.findChannel(cmdVector[1]);					// <channel>을 찾는다

	// ==== 채널이 없는 경우 ====
	if (channel == NULL)													// 만약 채널이 없다면
	{
		ERROR_nosuchchannel_403(_server.getClientList().find(fd)->second, cmdVector[1]);
		return ;
	}
	// ==== 통과 ====

	std::vector<int> clientFdList = channel->getFdListClient();				// 채널에 있는 클라이언트 목록(참여자들) 가져옮
	std::vector<int>::iterator clientIter;

	// ==== 클라이언트가 채널에 있는지 확인 ====
	clientIter = std::find(clientFdList.begin(), clientFdList.end(), fd);	// 채널's 클라이언트 목록에 -> fd가 있는지 확인
	if (clientIter == clientFdList.end())									// 클라이언트 목록에 없으면
	{
		ERROR_notonchannel_442(_server.getClientList().find(fd)->second, cmdVector[1]);
		return ;
	}
	// ==== 통과 ====

	// ** 본격적으로 Topic 변경 **
	// Topic 변경 케이스 2가지
	// (1) 모드 +t인 경우: 채널 오퍼레이터만 변경 가능
	// (2) 모드 +t가 아닌 경우: 누구나 변경 가능

	// ==== (2) 모드 +t가 아닌 경우: 누구나 변경 가능 ====
	if (cmdVector.size() == 2)
	{	// TOPIC <channel> 만 입력된 경우 -> Topic 조회

		// ==== 채널 유효성 검사 ====
		if (channel == NULL)												// 만약 채널이 없으면 <-> 인자 부족 461 에러랑은 다름
		{
			ERROR_nosuchchannel_403(_server.getClientList().find(fd)->second, cmdVector[1]);
			return ;
		}
		// ==== 통과 ====

		if (channel->getTopic().empty())
		{	// 기존 Topic 없는 경우
			// topic #gen
			_server.getClientList().find(fd)->second.appendReciveBuf(std::string(PREFIX_SERVERNAME) + " 331 " + _server.getClientList().find(fd)->second.getNickname() + " " + cmdVector[1] + " :" + RPL_NOTOPIC + "\r\n");
			return ;
		}
		else
		{
			_server.getClientList().find(fd)->second.appendReciveBuf(std::string(PREFIX_SERVERNAME) + " 332 " + _server.getClientList().find(fd)->second.getNickname() + " " + cmdVector[1] + " :" + channel->getTopic() + "\r\n");
		}	
	}
	else
	{	// TOPIC <channel> <topic> 입력된 경우 -> Topic 변경
		// ==== (1) 모드 +t인 경우: 채널 오퍼레이터만 변경 가능 ====
		if (channel->diffMode('t'))												// 모드 +t인 경우 -> "님 방장임?" -> 아니라면, 밑에 로직으로 넘어가지말고 걍 나가셈(return)
		{
			if (channel->diffOperator(fd) == false)								// 채널 오퍼레이터가 아니면
			{
				ERROR_chanoprivsneeded_482(_server.getClientList().find(fd)->second, cmdVector[1]);
				return ;
			}
		}
		// ==== 통과 ====

		if (cmdVector[2] == ":")											// 만약 ':'만 들어오면 빈 주제 -> 원래는, ":another topic" 이렇게 ':' 이거 입력하고 topic 들어오는게 정석
			channel->setTopic("");											// 빈 주제니까 빈 문자열로 설정
		else
		{	// ':' 이후의 문자열을 모두 합쳐서 Topic으로 설정
			std::string str = cmdVector[2];									// ":another" (cmdVector[2]) "topic" (cmdVector[3]) ..
			for (size_t i = 3; i < cmdVector.size(); i++)
				str += " " + cmdVector[i];									//  -> ":another topic"
			if (str[0] == ':')												// ':'로 시작하면 ':' 제거 -> messageAllChannel에서 이미 씀 -> " :" + message + "\r\n")
				str = str.substr(1);										// ':' 제거
			channel->setTopic(str);											// 채널 토픽(std::string)으로 저장
		}
		messageAllChannel(fd, cmdVector[1], "TOPIC", channel->getTopic());	// 채널에 있는 모든 클라이언트에게 TOPIC 메시지 전송
	}
}

```
### ./command/Pass.cpp
```cpp
#include "../includes/Command.hpp"

void Command::pass(int fd, std::vector<std::string> command_vec)
{	/* PASS <password> */
	std::map<int, Client>& clientList = _server.getClientList();
	std::map<int, Client>::iterator iter;
	
	std::cout << "#PASS" << std::endl;
	iter = clientList.find(fd);
	if (iter->second.getRegiPass() == true)
	{
		ERROR_alreadyregistred_462(iter->second);
		return;
	}

	if (command_vec.size() < 2)
	{
		ERROR_needmoreparams_461(iter->second);
		iter->second.appendReciveBuf("/PASS <password>\r\n");
		return;
	}

	std::string userPassword = _server.getPassword();	// "/ircserv 6667 1234" 중에서 -> "1234"가 '서버 비밀번호'
	std::cout << "#userPassword: " << userPassword << std::endl;
	if (command_vec[1] != userPassword)
	{
		ERROR_passwdmismatch_464(iter->second);
		send(fd, iter->second.getReciveBuf().c_str(), iter->second.getReciveBuf().length(), 0);
		iter->second.resetClient();
		clientList.erase(fd);
		close(fd);
		return;
	}

	iter->second.setRegiPass(true);	// Client가 서버 Password 인증 완료한 상태
	std::cout << "#PASS 완료" << std::endl;
}
```
### ./command/Part.cpp
```cpp
#include "../includes/Command.hpp"
#include "../includes/Util.hpp"

void Command::part(int fd, std::vector<std::string> cmdVector)
{
	// PART <channel>
	std::map<int, Client>& clientList = _server.getClientList();
	std::map<int, Client>::iterator fd_iter;

	fd_iter = clientList.find(fd);
	if (cmdVector.size() < 2)
	{
		ERROR_needmoreparams_461(fd_iter->second);
		return;
	}

	std::stringstream ss(cmdVector[1]);			// <channel>{,<channel>}
	std::string buffer;
	std::vector<std::string> channelVector;
	while (getline(ss, buffer, ','))			//	<channel> <channel> <channel> ... 담는다
		channelVector.push_back(buffer);
	
	std::vector<std::string>::iterator channelVector_iter;
	channelVector_iter = channelVector.begin();

	while (channelVector_iter != channelVector.end())
	{
		std::vector<std::string>::iterator channelList_iter;
		channelList_iter = fd_iter->second.findChannel(*channelVector_iter);	// 입력받은 채널 #general #random .. '채널'에 해당하는 iter 위치 반환
		if (channelList_iter != fd_iter->second.getChannelList().end())			// 만약, 채널에 있으면
		{
			Channel *channel = _server.findChannel(*channelList_iter);			// 채널 iter로 채널 본연의 Channel *channel 반환
			messageAllChannel(fd, *channelList_iter, "PART", channelMessage(2, cmdVector));
			
			channel->removeFdListClient(fd);									// 채널 인원 목록에서 fd 제거
			channel->removeOperatorFd(fd);										// 채널 오퍼레이터 목록에서 fd 제거
			fd_iter->second.deleteChannel(*channelList_iter);					// 클라이언트가 속한 채널 List에서 해당 채널 제거
			
			if (channel->getFdListClient().size() == 0)							// 만약 해당 채널에 남은 인원이 1명이라면
			{
				_server.removeChannel(channel->getChannelName());				// 서버에서 채널리스트 중 해당 채널 제거
				delete channel;
 				// Server::appendNewChannel(int fd, std::string& channelName) 에서
 				// ( ... , 'new Channel'(channelName, fd)));
				// new로 동적할당했기 때문에 Channel 은 꼭 delete 할것!!
			}
		}
		else	//만약 채널에 fd가 없는데 시도할 경우
		{
			if (_server.findChannel(*channelVector_iter))						// #channel가 존재는 할 경우
				ERROR_notonchannel_442(fd_iter->second, *channelVector_iter);	// ERR_NOTONCHANNEL "You're not on that channel\r\n"
			else																// #channel자체가 존재하지 않을 경우
				ERROR_nosuchchannel_403(fd_iter->second, *channelVector_iter);	// ERR_NOSUCHCHANNEL "No such channel\r\n"
		}
		channelVector_iter++;
	}
}
```
### ./command/Ping.cpp
```cpp
#include "../includes/Command.hpp"

void Command::ping(int fd, std::vector<std::string> cmdVector)
{
	// PING <server1> [<server2>]
	// PING 명령어는 서버간의 연결을 확인하기 위해 사용됨 (server2는 생략 가능)
		// 적절한 PONG 메시지로 응답하여 아직 연결되어 있고 살아있음을 표시해야 함
		// 정기적으로 보내야 하고, 연결이 설정된 시간 내에 PING 명령에 응답하지 않으면 시간 내에 응답하지 않으면 해당 연결이 닫힘
	std::map<int, Client>& clientList = _server.getClientList();
	std::map<int, Client>::iterator clientIt = clientList.find(fd);

	if (clientIt == clientList.end())	// fd 클라이언트가 클라이언트 리스트에 존재하지 않을 경우
		return;

	if (cmdVector.size() < 2)	// server1이 없을 경우
	{
		ERROR_needmoreparams_461(clientIt->second);
		clientIt->second.appendReciveBuf("/PING <token>\r\n");
		return;
	}
	clientIt->second.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " PONG " + std::string(PREFIX_SERVERNAME) + " :" + cmdVector[1] + "\r\n");
}
```
### ./command/Invite.cpp
```cpp
#include "../includes/Command.hpp"
#include "../includes/Util.hpp"

void Command::invite(int fd, std::vector<std::string> cmdVector)
{	// *유의* 까먹지 말자 여기서 fd는 명령어를 '사용'하려고 하는 클라이언트의 fd!!

	// INVITE <nickname> <channel> -> MODE 에서 +i 설정 시 초대 유효 (설정 안 되어 있어도 초대 기능 작동은 함)
	Client &client = _server.getClientList().find(fd)->second;	// map<int, Client>에서 (fd)를 키로 가지는 Client value를 찾아 반환

	if (cmdVector.size() < 3)	// "INVITE, <nickname>, <channel>" 안 들어올 경우
	{
		ERROR_needmoreparams_461(client);
		return;
	}

	std::map<int, Client>::iterator target = _server.findClient(cmdVector[1]);	// map<int, Client>에서 (cmdVector[1] == nickname)를 키로 가지는 Client value를 찾아 반환
	Channel *channel = _server.findChannel(cmdVector[2]);						// cmdVector[2] == #channel
	// 대상이 서버에 접속해있는지, 대상이 <channel>에 있는지
	
	// ===== 인가 확인 작업 =====
	if (target == _server.getClientList().end())								// findClient()에서 end반환 했을 시 -> 클라이언트 리스트에 없다는 뜻 -> 못 찾았으니 에러
	{
		ERROR_nosuchnick_401(client, cmdVector[1]);
		return;
	}
	if (channel == NULL)														// findChannel()에서 NULL 반환 했을 시 -> 채널 리스트에 없다는 뜻 -> 못 찾았으니 에러
	{
		ERROR_nosuchchannel_403(client, cmdVector[2]);
		return;
	}
	// 명령 주체 클라이언트에 대한 채널에 있는가 체크
	if (channel->diffClientInChannel(client.getClientFd()) == false)			// 채널리스트에서, '명령어를 사용'하려고 하는 닉네임이 있는지 '비교'해봤는데, false 일 경우
	{
		ERROR_notonchannel_442(client, cmdVector[2]);
		return;
	}
	if (channel->diffOperator(client.getClientFd()) == false)					// "야 너 방장 맞음??" -> 채널리스트에서, '명령어를 사용'하려고 하는 닉네임이 '오퍼레이터'인지 '비교'해봤는데, false 일 경우
	{
		ERROR_chanoprivsneeded_482(client, cmdVector[2]);
		return;
	}
	// 명령 타겟이 채널에 있는가 체크
	if (channel->diffClientInChannel(target->second.getClientFd()) == true)		// "야 걔 방에 있음??" -> 채널리스트에서, '초대받을 사람'이 있는지 '비교'해봤는데, true 일 경우
	{
		ERROR_useronchannel_443(client, cmdVector[1], cmdVector[2]);
		return;
	}
	// ==== 통과 =====

	target->second.appendReciveBuf(":" + client.getNickname() + " INVITE " + target->second.getNickname() + " " + cmdVector[2] + "\r\n");
	// "명령어 사용하는 클라이언트 닉네임: '명령어 사용자 닉네임' 'INVITE' '초대받을 사람 닉네임' '#채널'"
	// == "누가 너 초대했는디?"

	client.appendReciveBuf(std::string(PREFIX_SERVERNAME) + " 341 " + client.getNickname() + " " + cmdVector[1] + " " + cmdVector[2] + " :" + RPL_INVITING + "\r\n");
	// "명령어 사용하는 클라이언트 닉네임 '341' '명령어 사용자 닉네임' '#채널' 'RPL_INVITING'"
	// == "야 너 누구 초대했더라 명령어 먹힘ㅇㅇ"

	channel->appendFdListInvite(target->second.getClientFd());
	// 채널리스트에서, '초대받을 사람'의 fd를 초대 리스트에 추가
}
```
### ./command/List.cpp
```cpp
#include "../includes/Command.hpp"

void Command::list(int fd, std::vector<std::string> cmdVector)
{
	// LIST 명령어는 채널 목록과 토픽을 보여준다
    std::map<std::string, Channel*>& channelList = _server.getChannelList();
    std::map<int, Client>& clientList = _server.getClientList();
    std::map<int, Client>::iterator clientIt = clientList.find(fd);

    if (clientIt == clientList.end())	// fd 클라이언트가 클라이언트 리스트에 존재하지 않을 경우
        return;

    Client &client = clientIt->second;	// map<int, Client>에서 fd에 해당하는 Client 객체 반환

	for (std::vector<std::string>::iterator it = cmdVector.begin(); it != cmdVector.end(); it++)
	{
		std::cout << *it << ".";
	}
	std::cout << std::endl;

	client.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " 321 " + client.getNickname() + " Channel :Users Name\r\n");

	// 채널 2개 이상일 때
    if (cmdVector.size() >= 2 && cmdVector[1] != "")
    {	// 채널 여러개일 때: #channel1,#channel2
        std::vector<std::string> channelNames = split(cmdVector[1], ',');
		std::vector <std::string>::iterator it = channelNames.begin();
		while (it != channelNames.end())
		{	// #channel1, #channel2, ... 채널 순회
			std::map<std::string, Channel*>::iterator channelIt = channelList.find(*it);	// 채널 리스트에서 #channel 채널 찾기
			if (channelIt != channelList.end())
			{
				Channel* channel = channelIt->second;
				std::string channelName = channel->getChannelName();
				std::string topic = channel->getTopic();
				client.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " 322 " + client.getNickname() + " " + channelName + " " + intToString(channel->getFdListClient().size()) + " :" + "[+" + topic + "]" + "\r\n");
			}
			it++;
		}
    }
    else
    {
		std::map<std::string, Channel*>::iterator channelIt = channelList.begin();
		while (channelIt != channelList.end())
		{
			Channel* channel = channelIt->second;
			std::string channelName = channel->getChannelName();
			std::string topic = channel->getTopic();
			client.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " 322 " + client.getNickname() + " " + channelName + " " + intToString(channel->getFdListClient().size()) + " :" + "[+" + topic + "]" + "\r\n");
			channelIt++;
		}
    }

	client.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " 323 " + client.getNickname() + " :End of /LIST\r\n");
    send(fd, client.getReciveBuf().c_str(), client.getReciveBuf().length(), 0);
    client.clearReciveBuf();
}

```
### ./command/User.cpp
```cpp
#include "../includes/Command.hpp"

void Command::user(int fd, std::vector<std::string> cmdVector)
{	//	"/USER <username> <hostname> <servername> <:realname>"
	std::map<int, Client>& clientList = _server.getClientList();
	std::map<int, Client>::iterator iter;
	std::string realnameArgv;

	iter = clientList.find(fd);
	if ((iter->second.getRegiUser()) == true)	// 이미 등록된 유저인 경우
	{
		ERROR_alreadyregistred_462(iter->second);
		return;
	}

	if ((iter->second.getRegiPass()) == false)	// Client가 pass 인증이 안되어있으면
	{
		ERROR_notregistered_451(iter->second);
		send(fd, iter->second.getReciveBuf().c_str(), iter->second.getReciveBuf().length(), 0);
		iter->second.resetClient();	// 그 클라이언트 상태 초기화
		clientList.erase(fd);		// 클라이언트 리스트에서 삭제
		close(fd);					// 그 클라이언트 소켓 닫기
		return;
	}

	if (cmdVector.size() < 5)		// USER <username> <hostname> <servername> <:realname> 5개 이상이 아닌 경우
	{
		std::cout << "#// USER <username> <hostname> <servername> <:realname> 5개 이상이 아닌 경우" << std::endl;
		std::cout << "#cmdVector.size() : " << cmdVector.size() << std::endl;
		ERROR_needmoreparams_461(iter->second);
		iter->second.appendReciveBuf("/USER <username> <hostname> <servername> <:realname>\r\n");
		return;
	}

	if (cmdVector.size() > 5 && cmdVector[4][0] != ':')	// realname이 :로 시작하지 않는 경우
	{
		std::cout << "#// realname이 :로 시작하지 않는 경우" << std::endl;
		std::cout << "#cmdVector.size() : " << cmdVector.size() << std::endl;
		ERROR_needmoreparams_461(iter->second);
		iter->second.appendReciveBuf("/USER <username> <hostname> <servername> <:realname>\r\n");
		return;
	}

	for (size_t idx = 4; idx < cmdVector.size(); idx++)
	{
		realnameArgv += cmdVector[idx];
		if (idx != cmdVector.size() - 1)	// 마지막에는 공백 추가 안함 ex) last' '. (X)
			realnameArgv += " ";			// "KIM SU HYUN" 완성
	}

	iter->second.setUserinfo(cmdVector[1], cmdVector[2], cmdVector[3], realnameArgv);
	iter->second.setRegiUser(true);
	std::cout << "#USER 완료" << std::endl;
}

```
### ./command/Quit.cpp
```cpp
#include "../includes/Command.hpp"
#include "../includes/Util.hpp"

void Command::quit(int fd, std::vector<std::string> cmdVector)
{	// 양식: QUIT <message>
	std::map<int, Client>& clientList = _server.getClientList();
	std::map<int, Client>::iterator clientIter;

	clientIter = clientList.find(fd);								// 서버 clientList(서버 참여자 목록)에서 fd를 찾는다
	if (clientIter == clientList.end())								// 만약 fd가 clientList에 없다면
		return ;													// 함수 종료
	
	// 메시지 구성 종류는 총 3가지임 - tmi
	// (1) 정상종료: A client session is ended with a quit message -> "QUIT <message>"
	// (2) 서버간 연결 끊김: netsplits (disconnecting of two servers) occur ->  "composed of the names of two servers involved.."
	// (3) 클라이언트 이슈: client  issuing  a  QUIT  command  (e.g.  client  dies and EOF occurs on socket) -> "message  reflecting the nature of the event which caused it to happen"
	// Command - quit() 에서는 (1) 정상종료만 다룰거임
	std::vector<std::string> channelList;
	channelList = clientIter->second.getChannelList();				// 클라이언트(fd)가 참여한 '채널'들' 목록'을 가져옴 -> 왜? 클라이언트 private에 clientList이 있어서 가능
	std::vector<std::string>::iterator channelIter;
	
	channelIter = channelList.begin();
	while (channelIter != channelList.end())
	{	// 클라이언트가 참여한 채널 목록을 순회할거임
		Channel *channel = _server.findChannel(*channelIter);		// 채널 목록'들' 중 채널 하나
		
		// ==== 채널 유효성 검사 ====
		if (channel == NULL)										// 호오옥시라도 만약 채널이 없다면: 엥? 왜 혹시임? -> clientIter->second.getChannelList() 클라이언트에서 가져왔자너~ 업뎃안됐을수도?
			continue ;												// 다음 채널로 넘어가~
		// ==== 통과 ====

		channel->removeFdListClient(fd);							// 해당 채널에서 클라이언트(fd)를 제거
		channel->removeOperatorFd(fd);								// 해당 채널에서 클라이언트(fd)를 오퍼레이터에서 제거 -> 어차피 없으면 "_operatorFdList.end()" 반환됨 ㄱㅊㄱㅊ
		messageAllChannel(fd, channel->getChannelName(), "QUIT", channelMessage(1, cmdVector));	// 채널에 메시지를 보냄 -> cmdVector[1]은 <message>
		
		if (channel->getFdListClient().size() == 0)					// 만약 채널에 남은 클라이언트가 1명이라면
		{
			_server.removeChannel(channel->getChannelName());		// 서버's 채널 목록에서 <#채널이름> 해당 채널 제거
			delete channel;											// 채널 메모리 해제
			// Server::appendNewChannel(int fd, std::string& channelName) 에서
 			// ( ... , 'new Channel'(channelName, fd)));
			// new로 동적할당했기 때문에 Channel 은 꼭 delete 할것!!
		}
		channelIter++;												// 다음 채널로 넘어감
	}
	clientIter->second.resetClient();								// 클라이언트 정보 초기화 -> 다른 클라이언트 또 쓸 수 있게
	clientList.erase(fd);											// 서버's 클라이언트 목록에서 해당 클라이언트(fd) 제거
	close(fd);														// fd 닫기 -> 클라이언트 소켓 닫기
}

```
### ./command/Join.cpp
```cpp
#include "../includes/Command.hpp"

void Command::join(int fd, std::vector<std::string> cmdVector)
{
	// /JOIN <#channel> [<key>]
	std::cout << "#JOIN" << std::endl;
	std::cout << "#cmdVector.size() : " << cmdVector.size() << std::endl;

	Client &client = _server.getClientList().find(fd)->second;
	if (cmdVector.size() < 2)
	{
		ERROR_needmoreparams_461(client);
		return;
	}

	std::vector<std::string> joinChannelArgv;
	std::vector<std::string>::iterator iter;
	if (cmdVector[1].find(',') != std::string::npos)
	{
		joinChannelArgv= split(cmdVector[1], ',');
		iter = joinChannelArgv.begin();
		std::cout << "#Channel 2개" << std::endl;
	}
	else
	{
		joinChannelArgv.push_back(cmdVector[1]);
		iter = joinChannelArgv.begin();
		std::cout << "#Channel 1개" << std::endl;
	}

	std::vector<std::string> joinKeyArgv;
	std::vector<std::string>::iterator keyIter;

	if (joinChannelArgv.size() > 1)
	{
		std::cout << "#Channel 2개 경우" << std::endl;
		if(cmdVector.size() >= 3)
		{
			if (cmdVector[2] == "")
			{
				joinKeyArgv.push_back("");
			}
			else
			{
				joinKeyArgv = split(cmdVector[2], ',');
			}
			keyIter = joinKeyArgv.begin();
			std::cout << "#Channel 2개 + Key 2개" << std::endl;
			std::cout << "#key = " << *keyIter << std::endl;
		}
	}
	else	// JOIN <#channel> <key> 중 key는 keyIter로 지정해야 함
	{
		std::cout << "#Channel 1개 경우" << std::endl;
		if (cmdVector.size() >= 3)	// JOIN <#channel> <key> 3개 이상인 경우
		{
			joinKeyArgv.push_back(cmdVector[2]);	// key를 joinKeyArgv에 추가
			keyIter = joinKeyArgv.begin();
			std::cout << "#Channel 1개 + Key 1개" << std::endl;
			std::cout << "#key = " << *keyIter << std::endl;
		}
		else						// JOIN <#channel> <' '> -> key가 없는 경우
		{
			joinKeyArgv.push_back("");
			keyIter = joinKeyArgv.begin();
			std::cout << "#Channel 1개 + Key 0개" << std::endl;
		}
	}

	while (iter != joinChannelArgv.end())
	{
		// 채널 이름이 # 또는 &로 시작하지 않는 경우
		// if (iter->at(0) != '#' && iter->at(0) != '&')
		if ((*iter)[0] != '#' && (*iter)[0] != '&')
		{
			ERROR_nosuchchannel_403(client, *iter);
			iter++;
			if (cmdVector.size() > 2 && keyIter != joinKeyArgv.end())
				keyIter++;
			continue;
		}
		std::cout << "#채널 이름 인가 통과" << std::endl;
		std::map<std::string, Channel*> &channelList = _server.getChannelList();
		std::map<std::string, Channel*>::iterator channelIt = channelList.find(*iter);
		// 채널이 존재 할 경우
		if (channelIt != channelList.end())
		{
			std::cout << "#채널이 존재함" << std::endl;
			Channel *channel = channelIt->second;
			// 채널에 클라이언트가 있는지 확인
			if (channel->diffClientInChannel(fd))
			{
				ERROR_useronchannel_443(client, client.getNickname(), channel->getChannelName());

				std::cout << "#채널에 클라이언트가 이미 있음" << std::endl;
				// 이미 채널에 있는 경우
				iter++;
				if (cmdVector.size() > 2 || keyIter != joinKeyArgv.end())
				{
					keyIter++;
				}
				continue;
			}
			std::cout << "#채널에 클라이언트가 없음" << std::endl;
			if (channel->diffMode('k'))
			{
				std::cout << "#join에서 key 체크" << std::endl;
				if (joinKeyArgv.empty())
				{
					ERROR_badchannelkey_475(client, *iter);
					return ;
				}
				else if (cmdVector.size() <= 2 || keyIter == joinKeyArgv.end() || (keyIter != joinKeyArgv.end() && channel->diffKey(*keyIter) == false))	// 태현 수정, key가 없거나 key가 틀릴 때
				{
					ERROR_badchannelkey_475(client, *iter);
					iter++;
					if (cmdVector.size() > 2 || keyIter != joinKeyArgv.end())
					{
						keyIter++;
					}
					continue;
				}
			}
			std::cout << "#key 체크 통과" << std::endl;
			// invite mode 일 때
			if (channel->diffMode('i'))
			{
				std::cout << "#join에서 invite 체크" << std::endl;
				if (channel->diffInvite(fd) == false)	
				{
					ERROR_inviteonlychan_473(client, *iter);
					iter++;
					if (cmdVector.size() > 2 || keyIter != joinKeyArgv.end())
					{
						keyIter++;
					}
					continue;
				}
			}
			std::cout << "#invite 체크 통과" << std::endl;
			// LIMIT 모드일 때
			if (channel->diffMode('l'))
			{
				std::cout << "#join에서 limit 체크" << std::endl;
				if (channel->getFdListClient().size() >= channel->getLimit())
				{
					ERROR_channelisfull_471(client, *iter);
					iter++;
					if (cmdVector.size() > 2 || keyIter != joinKeyArgv.end())
					{
						keyIter++;
					}
					continue;
				}
			}
			std::cout << "#limit 체크 통과" << std::endl;
			std::string channelName = (*channelIt).second->getChannelName();
			client.appendChannelList(channelName);						// operator인 client가 속한 channelList에 '#genral, #random' 추가
			(*channelIt).second->appendFdListClient(fd);				// #general, #random 등 실제 채널에 fd 추가 (이름으로 직접 접근 ㄴㄴ 서버에 저장된 채널리스트를 iter로 순회하며 채널 접근)
			messageAllChannel(fd, channelName, "JOIN", "");				// 채널에 JOIN 메시지 전송 -> "야 채널에 누구 참여했다"
			topicMessage(fd, channelName);								// fd에게 채널's TOPIC 메시지 전송 -> "야 신삥 우리 채널에 주제는 ~ 라고 해"
		}
		else // 채널이 존재하지 않을 경우
		{
			std::cout << "#채널이 존재하지 않음" << std::endl;
			_server.appendNewChannel(fd, *iter);					// 채널 없으면 생성
			_server.findChannel(*iter)->appendFdListClient(fd);		// 새로 만들어진 채널's 클라이언트 리스트 중 클라이언트(fd주인) 추가
			client.appendChannelList(*iter);						// client가 속한 channelList에 '#채널' 추가
			messageAllChannel(fd, *iter, "JOIN", "");
		}
		nameListMsg(fd, *iter);
		iter++;
		if (cmdVector.size() > 2 || keyIter != joinKeyArgv.end())
			keyIter++;
	}
}
```
### ./command/Privmsg.cpp
```cpp
#include "../includes/Command.hpp"

void Command::privmsg(int fd, std::vector<std::string> cmdVector)
{
	Client &client = _server.getClientList().find(fd)->second;
	if (cmdVector.size() < 3) // 명령어에 필요한 인자가 부족한 경우 :
	{
		ERROR_needmoreparams_461(client);
		return;
	}
	std::vector<std::string> msgArgv1 = split(cmdVector[1], ',');
	std::vector<std::string>::iterator msgArgv1Iter = msgArgv1.begin();
	for (; msgArgv1Iter != msgArgv1.end(); msgArgv1Iter++) // 채널 목록을 순회
	{
		if ((*msgArgv1Iter)[0] == '#' || (*msgArgv1Iter)[0] == '&') // 채널인 경우 :
		{
			std::vector<std::string>::iterator channel_iter = client.findChannel(*msgArgv1Iter);
			if (channel_iter == client.getChannelList().end())
			{
				ERROR_cantsendtochan_404(client, *msgArgv1Iter);
				return;
			}
			else
			{
				messageAllChannel(fd, *msgArgv1Iter, "PRIVMSG", channelMessage(2, cmdVector));
			}

		}
		else
		{
			std::map<int, Client>::iterator client_iter = _server.findClient(*msgArgv1Iter);
			if (client_iter != _server.getClientList().end())
			{
				std::string message = channelMessage(2, cmdVector);
				client_iter->second.appendReciveBuf(makeMsgForm(fd, cmdVector[0]) + " PRIVMSG " + client.getNickname() + " :" + message + "\r\n");
			}
			else
			{
				ERROR_nosuchnick_401(client_iter->second, *msgArgv1Iter);
				continue;
			}
		}
	}
}

```
### ./command/Nick.cpp
```cpp
#include "../includes/Command.hpp"


void Command::nick(int fd, std::vector<std::string> cmdVector)
{
	// "/NICK <nickname>"
	std::map<int, Client>& clientList = _server.getClientList();
	std::map<int, Client>::iterator iter;
	std::vector<std::string> channelList;
	std::vector<std::string>::iterator channelIter;

	// ==== 인가 확인 작업 ====
	iter = clientList.find(fd);
	if (!(iter->second.getRegiPass()))	// Client가 pass 인증이 안되어있으면
	{
		ERROR_notregistered_451(iter->second);
		send(fd, iter->second.getReciveBuf().c_str(), iter->second.getReciveBuf().length(), 0);
		iter->second.resetClient();	// 그 클라이언트 상태 초기화
		clientList.erase(fd);		// 클라이언트 리스트에서 삭제
		close(fd);					// 그 클라이언트 소켓 닫기
		return;
	}

	if (cmdVector.size() < 2)
	{
		ERROR_nonicknamegiven_431(iter->second);
		return;
	}

	while (1)	// 닉네임이 중복되지 않도록 처리
	{
		std::map<int, Client>::iterator findIter;
		
		findIter = _server.findClient(cmdVector[1]);
		if (findIter != _server.getClientList().end())
			cmdVector[1] = findIter->second.getNickname() + "_";
		else
			break ;
	}

	if (nickNameValidate(cmdVector[1]) == false)
	{
		ERROR_erroneusnickname_432(iter->second);
		iter->second.appendReciveBuf("/NICK <nickname> First Letter is not digit and length is under 10.\r\n");
		return;
	}
	
	if (nicknameDuplicate(cmdVector[1], clientList) == false)
	{
		ERROR_nicknameinuse_433(iter->second);
		return;
	}
	// ==== 통과 ====

	// ==== 닉네임 변경 로직 ====
	std::string oldNick = iter->second.getNickname();
	channelList = iter->second.getChannelList();
	channelIter = channelList.begin();
	_sendNickList.clear();

	if (channelList.size() == 0)		// 아무런 채널에 가입되어있지 않은 경우
	{
		std::string prefix;
		prefix = (":" + oldNick + "!" + iter->second.getUsername() + "@" + iter->second.getServername());
		iter->second.appendReciveBuf(prefix + " " + cmdVector[0] + " :" + cmdVector[1] + "\r\n");
	}
	else								// 채널에 1개 이상 가입되어 있는 경우
	{
		while (channelIter != channelList.end())
		{
			std::cout << "#채널 Iter 순회->" << std::endl;
			Channel* channel = _server.findChannel(*channelIter);
			if (channel != NULL)
			{
				messageAllChannel(fd, channel->getChannelName(), "NICK", cmdVector[1]);
			}
			channelIter++;
		}
	}
	iter->second.setNickname(cmdVector[1]);	// iter == clientList의 iter
	iter->second.setRegiNick(true);
}

bool Command::nickNameValidate(std::string nickname)
{
	if (nickname.length() == 0)
		return (false);
	if (nickname.length() > 9)
		return (false);
	if (nickname[0] >= '0' && nickname[0] <= '9')
		return (false);
	for (size_t i = 1; i < nickname.length(); i++)	// 첫글자는 숫자가 아니어야 하고, 길이는 9이하
	{
		if (!isalnum(nickname[i]) && !isSpecialChar(nickname[i]))
			return (false);
	}
	return (true);
}

bool Command::nicknameDuplicate(std::string nickname, std::map<int, Client>& clientList)
{
	std::map<int, Client>::iterator iter;

	iter = clientList.begin();
	while (iter != clientList.end())
	{
		if (iter->second.getNickname() == nickname)
			return (false);
		iter++;
	}
	return (true);
	std::cout << "#nick중복" << std::endl;
}

```
### ./command/Mode.cpp
```cpp
#include "../includes/Command.hpp"

void Command::mode(int fd, std::vector<std::string> cmdVector)
{	// "/MODE <channel>	 <+/- i, t, k, l, o>   <k,l,o 에 해당하는 values 순서지켜서!!>"
	// ex) "MODE #channel +itkl 1234 2"
	std::cout << "#MODE" << std::endl;
	
	// ** 채널모드 '조회' 출력 결과 <-> 채널모드 '설정' 출력 결과 = 다름!!! **
	// 채널 조회란? 채널 모드를 조회하려면 단순히 MODE 명령어 뒤에 채널 이름만 입력
		// MODE #channel
		// 324 #example +kt secret
	// 채널 설정이란? 채널 모드를 설정할 때는 MODE 명령어 뒤에 채널 이름과 설정하고자 하는 모드를 지정
		// MODE #channel +o nickname
		// :nickname!user@host MODE #channel +o othernickname
	
	Client &client = _server.getClientList().find(fd)->second;
	if (cmdVector.size() < 2)
	{
		ERROR_needmoreparams_461(client);
		return;
	}
	std::string argvChannelName = cmdVector[1];

    if (client.getNickname() == argvChannelName)
        return;

	Channel *channel = _server.findChannel(argvChannelName);

	if (channel == NULL)
	{	// /Mode 인자인 '#channel'을 서버에 저장된 채널 리스트에서 못 찾았을 때
		ERROR_nosuchchannel_403(client, argvChannelName);	// (Client &, std::string)
		return;
	}

	// 채널 조회	ex) MODE #channel
	if ((channel != NULL) && (cmdVector.size() == 2))
	{	// /Mode 인자인 '#channel'을 서버에 저장된 채널 리스트에서 찾았고!
		// and, "/Mode #channel" 입력됐을 때
        std::string modeParams = "";
		std::string limitValue = "";
		if (channel->getMode().find('t') != std::string::npos)
		{
			modeParams += "";
		}
        if (channel->getMode().find('k') != std::string::npos)
		{
			if (channel->diffOperator(fd))	// 오퍼레이터일 때
				modeParams += channel->getKey() + " ";
			else							// 오퍼레이터가 아닐 때 -> 키 조회 불가
				modeParams += "<key> ";
		}
        if (channel->getMode().find('l') != std::string::npos)
		{
			std::ostringstream oss;	// ostringstream은 output stream의 약자로, 문자열을 출력하기 위한 스트림
            oss << channel->getLimit();
			limitValue += oss.str();
		}			
		if (modeParams.empty() && limitValue.empty())	// 토픽, 키, limit '없을 때'
			client.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " 324 " + client.getNickname() + " " + argvChannelName + " :+" + channel->getMode() + "\r\n");
		else											// 토픽, 키, limit '있을 떄'
			client.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " 324 " + client.getNickname() + " " + argvChannelName + " +" + channel->getMode() + " " + modeParams + ":" + limitValue + "\r\n");
        return;
	}

	std::string modeArgv = cmdVector[2];	// ex) <+/- i, t, k, l, o>
	if (modeArgv.length() == 1)				// MODE #gen b 이렇게만 들어왔을 때 종료
		return;


	if (channel != NULL && !channel->diffOperator(fd))
	{	// 채널이 존재하고, 채널 오퍼레이터가 아닐 때
		ERROR_chanoprivsneeded_482(client, argvChannelName);	// (Client &, std::string)
		return;
	}

	std::string message = "";
	std::string plus_message = "";
    std::vector<std::string> modeValueList;	// <t,k,l,o 에 해당하는 values>
    unsigned int modeValueCnt = 3;
	// "/Mode #channel +i <modeValueList>" 이므로 Value는 4부터 시작이므로, 3으로 초기화 해서, Value 만나면 그때서야 확신 갖고 ++증가
	char sign = '\0';

	size_t idx = 0;
	while (idx < modeArgv.length() && (modeArgv[idx] == '+' || modeArgv[idx] == '-'))
	{
		sign = modeArgv[idx];
		idx++;
	}
	if (modeArgv.length() == 1)							// +혹은 -만 입력됐을 때 종료
		return;

	// 채널모드 설정 ex) "+o nickname"
	for (size_t i = idx; i < modeArgv.length(); i++)
    {
        if (modeArgv[i] == '+' || modeArgv[i] == '-')
        {
            sign = modeArgv[i];
            continue;
        }

        bool isSetMode = false;							// 모드 '정상' 설정됐는지 여부
        if (modeArgv[i] == 'i')
        {
            if (sign == '+' && channel->diffMode('i'))	// +들어왔는데 이미 채널에 i 모드가 설정되어 있을 때
			{
				std::cout << "+인데 i모드 설정 되어 있음" << std::endl;
				continue;
			}
            if (sign == '-' && !channel->diffMode('i'))	// -들어왔는데 채널에 i 모드가 설정되어 있지 않을 때
                continue;
            channel->setMode('i', sign, fd);
            isSetMode = true;
        }
        else if (modeArgv[i] == 't')					// 설정 허용만, /TOPIC 해야 비로소 토픽 설정됨
        {
            if (sign == '+' && channel->diffMode('t'))
                continue;
            if (sign == '-' && !channel->diffMode('t'))
                continue;
            channel->setMode('t', sign, fd);
            isSetMode = true;
        }
        else if (modeArgv[i] == 'k')
        {
            if (sign == '-' && channel->diffMode('k') == false)
			{
				std::cout << "#-인데 k모드 설정 안되어 있음" << std::endl;
				continue;
			}
            if (cmdVector.size() > modeValueCnt)
            {
                if (sign == '+')
                {
                    channel->setKey(cmdVector[modeValueCnt]);
					channel->setMode('k', sign, fd);
					isSetMode = true;
                	modeValueList.push_back(cmdVector[modeValueCnt]);	// <t,k,l,o 에 해당하는 values> 저장
                	modeValueCnt++;
                }
            }
			if (sign == '-')
			{
				channel->setKey("");
				channel->setMode('k', sign, fd);
				isSetMode = true;
			}
        }
        else if (modeArgv[i] == 'l')
        {
            if (sign == '-' && channel->diffMode('l') == false)			//해제 부호인데, 설정 안되어 있으면 해제ㄴㄴ 무시
			{
				std::cout << "#-인데 l모드 설정 안되어 있음" << std::endl;
				continue;
			}
            if (cmdVector.size() > modeValueCnt)
            {
                std::string limitValue = cmdVector[modeValueCnt].c_str();	//  <t,k,l,o 에 해당하는 values> 중 ValueCnt ++증가된 상태
                bool isDigit = true;
                for (size_t j = 0; j < limitValue.length(); ++j)
                {
                    if (!isdigit(limitValue[j]))
                    {
                        isDigit = false;
                        break;
                    }
                }
                if (isDigit == false)
                {
                    modeValueCnt++;
                    continue;
                }
                int limit = atoi(limitValue.c_str());
                if (limit < 0)
                {
                    modeValueCnt++;
                    continue;
                }
                if (sign == '+')
                {
                    channel->setLimit(limit);
					channel->setMode('l', sign, fd);
					isSetMode = true;
                	modeValueList.push_back(cmdVector[modeValueCnt]);
                	modeValueCnt++;
                }
            }
			if (sign == '-')
			{
				channel->setLimit(0);
				channel->setMode('l', sign, fd);
				isSetMode = true;
			}
        }
        else if (modeArgv[i] == 'o')
        {
            if (cmdVector.size() <= modeValueCnt)	
            {
				continue;				// /Mode #channel +o 입력했는데, nickname이 없을 때 +o 무시
            }
            std::map<int, Client>::iterator target = _server.findClient(cmdVector[modeValueCnt]);	// +o 뒤에 오는 "nickname" 찾는다
            if (target == _server.getClientList().end())	// nickname 못 찾았을 때 에러
            {
				ERROR_nosuchnick_401(client, cmdVector[modeValueCnt]);
                return;
            }
            else	// nickname 찾았을 때
            {
                if (client.getNickname() == target->second.getNickname())	// 자기 자신에게는 +o 불가
                {
                    return;
                }
				if (!(channel->diffClientInChannel(target->second.getClientFd())))	// 채널에 없는 클라이언트에게 +o 불가
                {
					ERROR_usernotinchannel_441(client, cmdVector[modeValueCnt], cmdVector[1]);
                    return;
                }
                else if (sign == '+')
                {
					std::cout << "#타켓 fd : " << target->second.getClientFd() << std::endl;
					plus_message = target->second.getNickname();
					std::cout << "#타겟 닉네임 :[nickname] " << target->second.getNickname() << std::endl;
					channel->setMode('o', sign, target->second.getClientFd());
					if (channel->diffOperator(target->second.getClientFd()))
						std::cout << "#오퍼레이터 추가 완료" << std::endl;
					else
						std::cout << "#오퍼레이터 추가 실패" << std::endl;
                    isSetMode = true;
                    modeValueCnt++;
                }
                else if (sign == '-')
                {
					if (!channel->diffOperator(fd))
					{
						ERROR_chanoprivsneeded_482(client, argvChannelName);
						return;
					}
					std::cout << "#타켓 fd : " << target->second.getClientFd() << std::endl;
					plus_message = target->second.getNickname();
					std::cout << "#타겟 닉네임 :[nickname] " << target->second.getNickname() << std::endl;
                    // channel->removeOperatorFd(target->second.getClientFd()); -> setMode(, ,타겟 fd)
					channel->setMode('o', sign, target->second.getClientFd());
					if (channel->diffOperator(target->second.getClientFd()))
						std::cout << "#타겟 오퍼레이터 삭제 안 됨" << std::endl;
					else
						std::cout << "#타겟 오퍼레이터 삭제 됨" << std::endl;
					if (channel->diffOperator(fd))
						std::cout << "#방장 권한 유지" << std::endl;
					else
						std::cout << "#방장 권한 삭제됨" << std::endl;
                    isSetMode = true;
                    modeValueCnt++;
                }
            }
        }
        else		// <+/- i, t, k, l, o> 중에 없으면 에러
        {
			ERROR_unknownmode_472(client, modeArgv[i]);
            continue;
        }
        if (isSetMode)	// 모드 '정상' 설정하고 끝났다면
        {
            if (message.empty())
                message += sign;	// ex) '+' 차곡차곡
            message += modeArgv[i];	// ex) +'itkl' 차곡차곡
        }
    }
	
	// 방장이 아닐 때 추가 인자 붙여주지 않는다 && 방장일 때 +kl 1234 2 추가 인자 붙여준다
	if (channel->diffOperator(fd) == true)
	{
		for (size_t i = 0; i < modeValueList.size(); ++i)
		{
			if (!modeValueList[i].empty())			// 비어있지 않을 때
				message += " " + modeValueList[i];	// ex) "+l -k 2 key"
		}
	}
	if (message.empty())
		return;

	plus_messageAllChannel(fd, cmdVector[1], "MODE", message, plus_message);	// #채널에 MODE와 메세지 전달
}

```
### ./.vscode/main.cpp.code-snippets
```code-snippets
{
	// Place your version_2 작업 영역 snippets here. Each snippet is defined under a snippet name and has a scope, prefix, body and 
	// description. Add comma separated ids of the languages where the snippet is applicable in the scope field. If scope 
	// is left empty or omitted, the snippet gets applied to all languages. The prefix is what is 
	// used to trigger the snippet and the body will be expanded and inserted. Possible variables are: 
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. 
	// Placeholders with the same ids are connected.
	// Example:
	// "Print to console": {
	// 	"scope": "javascript,typescript",
	// 	"prefix": "log",
	// 	"body": [
	// 		"console.log('$1');",
	// 		"$2"
	// 	],
	// 	"description": "Log output to console"
	// }
}
```
### ./.vscode/settings.json
```json
{
	"files.associations": {
		"__bit_reference": "cpp",
		"__config": "cpp",
		"__hash_table": "cpp",
		"__locale": "cpp",
		"__node_handle": "cpp",
		"__split_buffer": "cpp",
		"__threading_support": "cpp",
		"__tree": "cpp",
		"__verbose_abort": "cpp",
		"array": "cpp",
		"bitset": "cpp",
		"cctype": "cpp",
		"clocale": "cpp",
		"cmath": "cpp",
		"complex": "cpp",
		"cstdarg": "cpp",
		"cstddef": "cpp",
		"cstdint": "cpp",
		"cstdio": "cpp",
		"cstdlib": "cpp",
		"cstring": "cpp",
		"ctime": "cpp",
		"cwchar": "cpp",
		"cwctype": "cpp",
		"execution": "cpp",
		"initializer_list": "cpp",
		"ios": "cpp",
		"iosfwd": "cpp",
		"iostream": "cpp",
		"istream": "cpp",
		"limits": "cpp",
		"locale": "cpp",
		"map": "cpp",
		"mutex": "cpp",
		"new": "cpp",
		"optional": "cpp",
		"ostream": "cpp",
		"ratio": "cpp",
		"sstream": "cpp",
		"stdexcept": "cpp",
		"streambuf": "cpp",
		"string": "cpp",
		"string_view": "cpp",
		"tuple": "cpp",
		"typeinfo": "cpp",
		"unordered_map": "cpp",
		"variant": "cpp",
		"vector": "cpp",
		"algorithm": "cpp",
		"__bits": "cpp",
		"__debug": "cpp",
		"__errc": "cpp",
		"__mutex_base": "cpp",
		"__nullptr": "cpp",
		"__string": "cpp",
		"__tuple": "cpp",
		"atomic": "cpp",
		"chrono": "cpp",
		"compare": "cpp",
		"concepts": "cpp",
		"exception": "cpp",
		"memory": "cpp",
		"system_error": "cpp",
		"type_traits": "cpp",
		"deque": "cpp",
		"fstream": "cpp",
		"iomanip": "cpp",
		"stack": "cpp"
	}
}
```
### ./.vscode/launch.json
```json
{
	"version": "0.2.0",
	"configurations": [
		{
			"name": "Debug",
			"type": "lldb",
			"request": "launch",
			"program": "${workspaceFolder}/ircserv",
			"args": [
				"4000",
				"1234"
			],
			"cwd": "${workspaceFolder}",
			"preLaunchTask": "build",
			// "postDebugTask": "clean"
		}
	],
	"inputs": [
		{
			"id": "executableArgs",
			"type": "promptString",
			"description": "인자를 입력해 주세요.\n",
			"default": ""
		}
	]
}
```
### ./.vscode/tasks.json
```json
{
	"version": "2.0.0",
	"tasks": [
		{
			"label": "build",
			"type": "shell",
			"command": "make",
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"problemMatcher": [],
			"presentation": {
				"close": false,
				"reveal": "silent",
				"panel": "shared",
				"focus": false
			}
		},
		{
			"label": "clean",
			"type": "shell",
			"command": "make fclean",
			"problemMatcher": [],
			"presentation": {
				"close": true,
				"reveal": "silent",
				"panel": "shared",
				"focus": false
			}
		}
	]
}
```
### ./src/Util.cpp
```cpp
#include "../includes/Util.hpp"

bool isSpecialChar(char c)
{
	if (c == '_' || c == '|' || c == '[' || c == ']' || c == '{' || c == '}' || c == '\\')
	{
		return (true);
	}
	return (false);
}

std::vector<std::string> split(std::string str, char delim)
{
	std::vector<std::string> tmpVector;
	std::stringstream ss;
	std::string buffer;

	ss << str;
	while (getline(ss, buffer, delim))
	{
		tmpVector.push_back(buffer);
	}
	return (tmpVector);
}

std::string Command::makeMsgForm(int fd, std::string command)
{	// 접두사 구문 함수
	// ex) :<닉네임>!<사용자 아이디>@<호스트네임>
	
	std::map<int, Client>& clientList = _server.getClientList();
	std::map<int, Client>::iterator iter = clientList.find(fd);
	Client &client = iter->second;
	std::string prefix;
	
	if (command == "PRIVMSG" || command == "JOIN" || command == "QUIT" || command == "PART" || command == "NICK" || command == "MODE" || command == "KICK")
	{	// 클라이언트 -> 클라이언트 == ex) :yournick!user@host
		prefix = (":" + client.getNickname() + "!" + client.getUsername() + "@" + client.getServername());
		// <prefix>   ::= <servername> | <nick> [ '!' <user> ] [ '@' <host> ]
	}
	else if (command == "KICK")	// 태현 추가
	{
		prefix = (":" + client.getNickname());
	}
	else
	{	// 서버 -> 서버 == ex) :servername
		prefix = (":" + std::string(PREFIX_SERVERNAME));
	}
	return (prefix);
}

void Command::messageAllChannel(int fd, std::string channelName, std::string command, std::string message)
{	// 채널 전체에 귓속말, PRIVMSG 중에서 reciver -> channel인 경우
	// 다만 자신에게는 PRIVMSG 내용이 출력되지 않음
	// 입력 인자는, /PRIVMSG #channel :message
	std::map<std::string, Channel*>& channelList = _server.getChannelList();

	if (channelList.find(channelName) == channelList.end())
		return ;
	Channel *channel = channelList.find(channelName)->second;
	std::vector<int> fdList = channel->getFdListClient();		// #channelName에 있는 모든 fd 리스트
	std::vector<int>::iterator fd_iter = fdList.begin();


	while (fd_iter != fdList.end())								// #channelName에 있는 fd 전부 순회
	{
		Client& targetClient = _server.getClientList().find(*fd_iter)->second;
		if ((fd == (*fd_iter)) && (command == "PRIVMSG")) // 자신에게는 보내지 않음
		{
			fd_iter++;
			continue ;
		}
	
		if (command == "PRIVMSG" || command == "JOIN" || command == "TOPIC")
		{	// "#채널" 있을 때 == channelName + " :"
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " " + channelName + " :" + message + "\r\n");			
			fd_iter++;
		}
		else if (command == "KICK")
		{
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " " + channelName + " " + message + " :" + _server.getClientList().find(fd)->second.getNickname() + "\r\n");
			fd_iter++;
		}
		else if (command == "PART")
		{
			if (message == "NO REASON")
			{
				targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " :" + channelName + "\r\n");
				fd_iter++;
			}
			else
			{
				targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " " + channelName + " :" + message + "\r\n");
				fd_iter++;
			}
		}
		else if (command == "NICK")
		{
			_sendNickIter = _sendNickList.begin();
			bool isSendNick = false;
			// ==== nick 메세지 보냈는지 확인하는 인가 작업 ====
			// 만약에 NICK 메세지를 보냈다면, 그 클라이언트(fd)에게는 보내지 않음

			while (_sendNickIter != _sendNickList.end())
			{
				std::cout << "#nick 인가 검사 시작" << std::endl;
				if (*_sendNickIter == targetClient.getClientFd())	// 만약에 nick 메세지를 이미 보냈던 클라이언트라면
				{
					_sendNickIter = _sendNickList.end();			// 반복문 종료
					isSendNick = true;								// 이미 보냈음
					fd_iter++;										// #채널 다음 사람으로 넘어가~ 지금 이 사람은 무시해~
				}
				else
				{
					_sendNickIter++;								// 계속 확인해
				}
			}
			// ==== 통과 ====

			if (isSendNick == true)	// 이미 보냈던 클라이언트라면
			{
				continue ;			// 다음 클라이언트로 넘어가~
			}

			std::cout << "#인가 검사 통과" << std::endl;
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " :" + message + "\r\n");
			_sendNickList.push_back(targetClient.getClientFd());	// nick 메세지 받은 클라이언트도 보낸 리스트에 추가
			fd_iter++;
		}
		else
		{	// "#채널" 없을 때 == command + " :" 
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " :" + message + "\r\n");
			fd_iter++;
		}
	}
}

void Command::plus_messageAllChannel(int fd, std::string channelName, std::string command, std::string message, std::string plus_message)
{	// 특정 명령어를 위한 함수: MODE
	std::map<std::string, Channel*>& channelList = _server.getChannelList();

	if (channelList.find(channelName) == channelList.end())
		return ;
	Channel *channel = channelList.find(channelName)->second;
	std::vector<int> fdList = channel->getFdListClient();
	std::vector<int>::iterator fd_iter = fdList.begin();

	while (fd_iter != fdList.end())
	{
		Client& targetClient = _server.getClientList().find(*fd_iter)->second;
		if ((fd == (*fd_iter)) && (command == "PRIVMSG")) // 자신에게는 보내지 않음
		{
			fd_iter++;
			continue ;
		}

		if (command == "MODE")
		{
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " " + channelName + " " + message + " :" + plus_message + "\r\n");
			fd_iter++;
		}
		else
		{	// "#채널" 없을 때 == command + " :" 
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " :" + message + "\r\n");
			fd_iter++;
		}
	}
}

std::string Command::channelMessage(int index, std::vector<std::string> command_vec)
{	// 채널 메시지란? :<메시지> 이런 형태로 출력
	std::string message = "";
	for (size_t i = index; i < command_vec.size(); i++)
	{
		message += command_vec[i];
		if (i != command_vec.size() - 1)
			message += " ";
	}
	// 만약 메시지가 ':'로 시작하면 ':' 제거
	if (message[0] == ':')
		message = message.substr(1, message.length() - 1); // ':' 제거
	// 만약 메시지가 비어있으면 NO REASON 추가
	if (message.length() == 0)
		message = "NO REASON"; // NO REASON
	return (message);
}

void Command::topicMessage(int fd, std::string channelName)
{	// 채널의 토픽을 출력하는 함수
	std::map<std::string, Channel *>& channelList = _server.getChannelList();	// 전체 채널 리스트
	Channel *channel = channelList.find(channelName)->second;					// 채널 이름으로 채널 찾기
	
	std::string topic = channel->getTopic();									// 채널의 토픽 가져오기
	
	// ==== 토픽 없으면 ====
	if (topic.length() == 0)
		return;

	// ==== 토픽 있으면 ====
	topic = topic.substr(1, topic.length() - 1);								// ':' 제거
	Client &client = _server.getClientList().find(fd)->second;					//	fd로 클라이언트 찾기
	client.appendReciveBuf("332 " + client.getNickname() + " " + channelName + " :" + topic + "\r\n");	// 토픽 출력
}

void Command::nameListMsg(int fd, std::string channelName)
{	// 채널의 클라이언트 리스트를 출력하는 함수
	std::map<std::string, Channel *>& channelList = _server.getChannelList();		// 전체 채널 리스트

	if (channelList.find(channelName) == channelList.end())						
		return;

	Channel *channel = channelList.find(channelName)->second;						// 채널 이름으로 채널 찾기
	std::vector<int> clientFdList = channel->getFdListClient();						// 그 채널에 클라이언트 리스트 찾기
	std::vector<int>::iterator iter;
	std::string message;

	iter = clientFdList.begin();
	while (iter != clientFdList.end())												// #channelName의 클라이언트 리스트 순회
	{
		Client &client = _server.getClientList().find(*iter)->second;				// #channelName에 속한 모든 클라이언트 다 돌거임 (iter++)
		if (channel->diffOperator(client.getClientFd()))							// 만약 오퍼레이터면(방장이면)
			message += "@";
		
		message += client.getNickname();											// 메세지에 닉네임 추가
		
		if (iter != clientFdList.end() - 1)											// 마지막이 아니면 " " 붙여서 또 추가의 여지 남김(while이니까)
			message += " ";
		
		iter++;
	}
	Client &client = _server.getClientList().find(fd)->second;						// 명령어 사용하려는 fd 클라이언트에게
	client.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " 353 " + client.getNickname() + " = " + channelName + " :" + message + "\r\n");	// 채널의 클라이언트 리스트 (== mesaage) 주고
	client.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " 366 " + client.getNickname() + " " + channelName + " :End of /NAMES list.\r\n");	// 끝내기
}

std::string Command::intToString(int value)
{
	std::string str;
	std::stringstream ss;

	ss << value;	// 임시 스트림 객체에 int값 넣기
	ss >> str;		// 임시 스트림 객체에서 string으로 변환
	return (str);	// string 반환
}

```
### ./src/Client.cpp
```cpp
#include "../includes/Client.hpp"

Client::Client(int fd)
{
	_fd = fd;
	_nickName = "*";
	_isRegiPass = false;
	_isRegiNick = false;
	_isRegiUser = false;	
	_reciveBuf = "";
	_userName = "";
	_hostName = "";
	_serverName = "";
	_eofBuffer.str("");
	_eofFlag = false;
}

Client::Client()
{
	_fd = -1;
	_nickName = "*";
	_isRegiPass = false;
	_isRegiNick = false;
	_isRegiUser = false;
	_reciveBuf = "";
	_userName = "";
	_hostName = "";
	_serverName = "";
	_eofBuffer.str("");
	_eofFlag = false;
}

Client::Client(const Client &ref)
{
	_fd = ref._fd;
	_nickName = ref._nickName;
	_userName = ref._userName;
	_hostName = ref._hostName;
	_serverName = ref._serverName;
	_realName = ref._realName;
	_reciveBuf = ref._reciveBuf;
	_isRegiPass = ref._isRegiPass;
	_isRegiNick = ref._isRegiNick;
	_isRegiUser = ref._isRegiUser;
	_channelList = ref._channelList;
}

Client::~Client()
{
}

int	Client::getClientFd()
{
	return (_fd);
}

std::vector<std::string> &Client::getChannelList()
{
	return (_channelList);
}

std::string Client::getNickname()
{
	return (_nickName);
}

std::string Client::getUsername()
{
	return (_userName);
}

std::string Client::getHostname()
{
	return (_hostName);
}

std::string Client::getServername()
{
	return (_serverName);
}

std::string Client::getRealname()
{
	return (_realName);
}

std::string Client::getReciveBuf()
{
	return (_reciveBuf);
}

bool Client::getIsRegist()
{
	if (_isRegiPass && _isRegiNick && _isRegiUser)
		return (true);
	return (false);
}

bool Client::getRegiPass()
{
	return (_isRegiPass);
}

bool Client::getRegiNick()
{
	return (_isRegiNick);
}

bool Client::getRegiUser()
{
	return (_isRegiUser);
}

std::stringstream &Client::getEofBuffer()
{
	return (_eofBuffer);
}

bool Client::getEofFlag()
{
	return (_eofFlag);
}

void Client::setRegiPass(bool status)
{
	_isRegiPass = status;
}

void Client::setRegiNick(bool status)
{
	_isRegiNick = status;
}

void Client::setRegiUser(bool status)
{
	_isRegiUser = status;
}

void Client::setRegiAll(bool status)
{
	_isRegiPass = status;
	_isRegiNick = status;
	_isRegiUser = status;
}

void Client::setNickname(std::string setName)
{
	_nickName = setName;
}

void Client::setUserinfo(std::string inputUserName, std::string inputHostName, std::string inputServerName, std::string inputRealName)
{
	_userName = inputUserName;
	_hostName = inputHostName;
	_serverName = inputServerName;
	_realName = inputRealName;
}

void Client::appendReciveBuf(std::string inputBuffer)
{
	std::cout << "appendReciveBuf : " << inputBuffer << std::endl;
	_reciveBuf.append(inputBuffer);
}

void Client::appendChannelList(std::string channelName)
{
	_channelList.push_back(channelName);
}

// clear
void Client::clearReciveBuf()
{
	_reciveBuf.clear();
	std::cout << _reciveBuf << std::endl;
}

void Client::clearAllChannel()
{
	_channelList.clear();
}

void Client::resetClient()
{	// 클라이언트 정보 초기화 -> 다른 클라이언트가 또 쓸 수 있게
	setRegiAll(false);
	clearAllChannel();
	clearReciveBuf();
	_fd = -1;
	_nickName = "";
	_userName = "";
	_hostName = "";
	_serverName = "";
	_realName = "";
}

void Client::deleteChannel(std::string delChannel)
{
	std::vector<std::string>::iterator iter;

	iter = findChannel(delChannel);
	if (iter != _channelList.end())
	{
		_channelList.erase(iter);		// vector의 '특정 위치'에 있는 원소를 삭제
	}
}

std::vector<std::string>::iterator Client::findChannel(std::string targetChannel)
{	// "/JOIN #channel" -> 채널은 string으로 등록
	std::vector<std::string>::iterator iter;

	iter = _channelList.begin();
	while (iter != _channelList.end())
	{
		if (*(iter) == targetChannel)	// vector의 특정 위치에 *을 붙여야 실제 string 값을 가져올 수 있음
			return (iter);
		iter++;
	}
	return (_channelList.end());		// _channelList.end()는 '벡터의 마지막 원소 다음 위치'를 가리키는 반복자
}

void Client::setEofBuffer(std::stringstream &buffer)
{
	_eofBuffer.str(buffer.str());
}

void Client::setEofFlag(bool flag)
{
	_eofFlag = flag;
}

```
### ./src/Error.cpp
```cpp
#include "../includes/Error.hpp"

void ERROR_nosuchnick_401(Client &client, std::string nickname)
{
    client.appendReciveBuf("401 " + client.getNickname() + " " + nickname + " :" + ERR_NOSUCHNICK);
}

void ERROR_nosuchchannel_403(Client &client, std::string channel)
{
    client.appendReciveBuf("403 " + client.getNickname() + " " + channel + " :" + ERR_NOSUCHCHANNEL);
}

void ERROR_cantsendtochan_404(Client &client, std::string channel)
{
	client.appendReciveBuf("404 " + client.getNickname() + " " + channel + " :" + ERR_CANNOTSENDTOCHAN);
}

void ERROR_usernotinchannel_441(Client &client, std::string nickname, std::string channel)
{
    client.appendReciveBuf("441 " + client.getNickname() + " " + nickname + " " + channel + " :" + ERR_USERNOTINCHANNEL);
}

void ERROR_notonchannel_442(Client &client, std::string channel)
{
    client.appendReciveBuf("442 " + client.getNickname() + " " + channel + " :" + ERR_NOTONCHANNEL);
}

void ERROR_useronchannel_443(Client &client, std::string nickname, std::string channel)
{
    client.appendReciveBuf("443 " + client.getNickname() + " " + nickname + " " + channel + " :" + ERR_USERONCHANNEL);
}

void ERROR_nonicknamegiven_431(Client &client)
{
    client.appendReciveBuf("431 :" + std::string(ERR_NONICKNAMEGIVEN));
}

void ERROR_erroneusnickname_432(Client &client)
{
    client.appendReciveBuf("432 :" + std::string(ERR_ERRONEUSNICKNAME));
}

void ERROR_nicknameinuse_433(Client &client)
{
    client.appendReciveBuf("433 :" + std::string(ERR_NICKNAMEINUSE));
}

void ERROR_notregistered_451(Client &client)
{
    client.appendReciveBuf("451 :" + std::string(ERR_NOTREGISTERED));
}

void ERROR_needmoreparams_461(Client &client)
{
    client.appendReciveBuf("461 :" + std::string(ERR_NEEDMOREPARAMS));
}

void ERROR_alreadyregistred_462(Client &client)
{
    client.appendReciveBuf("462 :" + std::string(ERR_ALREADYREGISTRED));
}

void ERROR_passwdmismatch_464(Client &client)
{
    client.appendReciveBuf("464 :" + std::string(ERR_PASSWDMISMATCH));
}

void ERROR_channelisfull_471(Client &client, std::string channel)
{
    client.appendReciveBuf("471 " + client.getNickname() + " " + channel + " :" + ERR_CHANNELISFULL);
}

void ERROR_unknownmode_472(Client &client, char mode)
{
    client.appendReciveBuf("472 " + client.getNickname() + " " + mode + " :" + ERR_UNKNOWNMODE);
}

void ERROR_inviteonlychan_473(Client &client, std::string channel)
{
    client.appendReciveBuf("473 " + client.getNickname() + " " + channel + " :" + ERR_INVITEONLYCHAN);
}

void ERROR_badchannelkey_475(Client &client, std::string channel)
{
    client.appendReciveBuf("475 " + client.getNickname() + " " + channel + " :" + ERR_BADCHANNELKEY);
}

void ERROR_chanoprivsneeded_482(Client &client, std::string channel)
{
    client.appendReciveBuf("482 " + client.getNickname() + " " + channel + " :" + ERR_CHANOPRIVSNEEDED);
}

void ERROR_unknowncommand_421(Client &client, std::string command)
{
    client.appendReciveBuf("421 " + client.getNickname() + " " + command + " :" + ERR_UNKNOWNCOMMAND);
}

```
### ./src/Channel.cpp
```cpp
#include "../includes/Channel.hpp"

Channel::Channel(const std::string &channelName, int fd) 
{
    _channelName = channelName;
    _inviteStatus = false;
    _topicStatus = false;
    _keyStatus = false;
    _limitStatus = false;
	_limit = 0;

    _operatorFdList.push_back(fd);	// operator는 channel을 처음 만든 client
}

Channel::Channel() 
{
	_channelName = "";
	_inviteStatus = false;
	_topicStatus = false;
	_keyStatus = false;
	_limitStatus = false;
	_limit = 0;
}

Channel::Channel(const Channel &other)
{
	(*this) = other;
}

Channel &Channel::operator=(const Channel &other)
{
	_channelName = other._channelName;
	_operatorFdList = other._operatorFdList;
	_clientFdList = other._clientFdList;
	_inviteFdList = other._inviteFdList;
	_topic = other._topic;
	_key = other._key;
	_inviteStatus = other._inviteStatus;
	_topicStatus = other._topicStatus;
	_keyStatus = other._keyStatus;
	_limitStatus = other._limitStatus;
	_limit = other._limit;

	return (*this);
}

Channel::~Channel()
{
}

std::string Channel::getChannelName()
{
    return (_channelName);
}

std::vector<int> Channel::getFdListClient()
{
    return (_clientFdList);
}

std::vector<int> Channel::getFdListOperator()
{
    return (_operatorFdList);
}

std::string Channel::getMode()
{
    std::string mode;

    if (_topicStatus == true)
        mode += "t";
    if (_inviteStatus == true)
        mode += "i";
    if (_limitStatus == true)
        mode += "l";
    if (_keyStatus == true)
        mode += "k";

    return (mode);
}

unsigned int Channel::getLimit()
{
    return (_limit);
}

std::string Channel::getKey()
{
	return (_key);
}

std::string Channel::getTopic()
{
    return (_topic);
}

std::vector<int>::iterator Channel::findIterClient(int fd)
{	// fd가 clientList에 있는지 확인
	std::vector<int>::iterator iter;

	iter = std::find(_clientFdList.begin(), _clientFdList.end(), fd);
	if (iter != _clientFdList.end())
		return (iter);
	return (_clientFdList.end());
}

void Channel::setChannelName(std::string &channelName)
{
    _channelName = channelName;
}

void Channel::setMode(unsigned char mode, char sign, int fd)
{
	if (mode == 'i')
	{
		if (sign == '+')
			_inviteStatus = true;
		else if (sign == '-')
			_inviteStatus = false;
	}
	else if (mode == 't')
	{
		if (sign == '+')
			_topicStatus = true;
		else if (sign == '-')
			_topicStatus = false;
	}
	else if (mode == 'l')
	{
		if (sign == '+')
			_limitStatus = true;
		else if (sign == '-')
			_limitStatus = false;
	}
	else if (mode == 'k')
	{
		if (sign == '+')
			_keyStatus = true;
		else if (sign == '-')
			_keyStatus = false;
	}
	else if (mode == 'o')
    {
        setOperator(fd, sign);
    }
}

void Channel::setOperator(int fd, char sign)
{
    if (sign == '+')
    {
        addOperatorFd(fd);
    }
    else if (sign == '-')
    {
        removeOperatorFd(fd);
    }
}

void Channel::setLimit(unsigned int limit)
{
    _limit = limit;
}

void Channel::setTopic(std::string topic)
{
    _topic = topic;
}

void Channel::setKey(std::string key)
{
    _key = key;
}

void Channel::appendFdListClient(int fd)
{
    _clientFdList.push_back(fd);
}

void Channel::removeFdListClient(int fd)
{
    std::vector<int>::iterator iter;
	
	iter = findIterClient(fd);
    if (iter != _clientFdList.end())
        _clientFdList.erase(iter);
}

void Channel::addOperatorFd(int fd)
{
	std::vector<int>::iterator iter;

	iter = std::find(_operatorFdList.begin(), _operatorFdList.end(), fd);
	if (iter == _operatorFdList.end())	// op fd가 list안에 없으면 end()를 반환 -> 추가
		_operatorFdList.push_back(fd);
}

void Channel::removeOperatorFd(int fd)
{
    std::vector<int>::iterator iter;
	
	iter = std::find(_operatorFdList.begin(), _operatorFdList.end(), fd);
    if (iter != _operatorFdList.end())
        _operatorFdList.erase(iter);
}

void Channel::removeInviteFd(int fd)
{
	std::vector<int>::iterator iter;
	
	iter = std::find(_inviteFdList.begin(), _inviteFdList.end(), fd);
	if (iter != _inviteFdList.end())
		_inviteFdList.erase(iter);
}

void Channel::appendFdListInvite(int fd)
{
	std::vector<int>::iterator iter;

	iter = std::find(_inviteFdList.begin(), _inviteFdList.end(), fd);
	if (iter == _inviteFdList.end())									// invite fd가 list안에 없으면 end()를 반환 -> 추가
		_inviteFdList.push_back(fd);
}

bool Channel::diffInvite(int fd)
{
	std::vector<int>::iterator iter;

	iter = std::find(_inviteFdList.begin(), _inviteFdList.end(), fd);	// fd가 inviteList에 있는지 확인
	if (iter != _inviteFdList.end())
		return (true);
	return (false);
}

bool Channel::diffKey(std::string key)
{
    if (_key == key)
        return (true);
    return (false);
}

bool Channel::diffOperator(int fd)
{
	std::vector<int>::iterator iter;

	iter = std::find(_operatorFdList.begin(), _operatorFdList.end(), fd);	// fd가 operator인지 확인
	if (iter != _operatorFdList.end())
		return (true);
	return (false);
}

bool Channel::diffMode(unsigned char mode)
{
    if (mode == 'i')
        return (_inviteStatus);	// invite 상태를 반환. 예를 들어 +i였으면 true, -i였으면 false
    else if (mode == 't')
        return (_topicStatus);
    else if (mode == 'l')
        return (_limitStatus);
    else if (mode == 'k')
        return (_keyStatus);

	return (false);	// error: i, t, l, k가 아닌 경우가 들어왔을 때
}

bool Channel::diffClientInChannel(int fd)
{	// fd가 clientList에 있는지/없는지'만' 확인 -> 있으면 true, 없으면 false
    std::vector<int>::iterator iter;
	
	iter = findIterClient(fd);
    if (iter != _clientFdList.end())	
        return (true);
    return (false);
}

```
### ./src/Command.cpp
```cpp
#include "../includes/Command.hpp"

Command::Command(Server &server) : _server(server)
{
}

Command::~Command()
{
}

void printCmdVector(std::vector<std::string> cmdVector)
{
	std::cout << "cmdVector: ";
	for (std::vector<std::string>::iterator it = cmdVector.begin(); it != cmdVector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void Command::run(int fd, int data_bite)
{
	std::cout << "#command run" << std::endl;

	std::stringstream				serverMsg;	// server에 저장된 메시지
	std::string						cmdBuffer;
	std::vector<std::string>		cmdVector;
	std::map<int, Client>::iterator	iter;		// clients를 순회하기 위한 iterator
	std::map<int, Client>& clientList = _server.getClientList();	// 서버에 저장된 client 목록
	serverMsg << _server.getMessage(fd, data_bite);


	//만약 "CAP LS"라는 문자열이 들어올 경우 아무것도 하지 않는 코드
	if (serverMsg.str().find("CAP LS") != std::string::npos)
		return ;
	
	// \n이 없는경우 eof발생이라 판단
	if (serverMsg.str().find("\n") == std::string::npos)
	{
		clientList[fd].getEofBuffer() << serverMsg.str();
		clientList[fd].setEofFlag(true);
		return;
	}

	std::string irssiTest = serverMsg.str();	// irssi 전용
	if (irssiTest.find("PASS") != std::string::npos &&	\
        irssiTest.find("NICK") != std::string::npos &&	\
        irssiTest.find("USER") != std::string::npos)
        irssiSignUp(fd, irssiTest);
	else
	{	// irssi가 아닌 경우
		    // eofFlag가 true인 경우 eofBuffer를 serverMsg의 앞쪽에 붙임
		if (clientList[fd].getEofFlag() == true)
		{
			std::stringstream temp;
			temp << clientList[fd].getEofBuffer().str() << serverMsg.str();
			serverMsg.str(temp.str());
			clientList[fd].setEofFlag(false);
			clientList[fd].getEofBuffer().str(""); // eofBuffer 초기화
		}
		while (getline(serverMsg, cmdBuffer, ' '))	// 명령어 파싱
		{
			size_t pos = cmdBuffer.find_last_not_of("\r\n");
			// find_last_not_of는 특정 문자 집합에 속하지 않는 마지막 문자의 위치를 반환하는 함수
			// Hello, World\r\n -> 'd'의 위치를 반환
			std::string command = cmdBuffer.substr(0, pos + 1);
			// 처음부터 ~ 마지막 문자 (인덱스+1)까지의 문자열을 command에 저장

			if (cmdVector.empty())
			{	// "JOIN #general" 중 -> 처음 "JOIN"만 -> 4글자 for()로 toupper 적용
				for (size_t i = 0; i < command.size(); i++)
					command[i] = std::toupper(command[i]);
			}
			cmdVector.push_back(command);
		}
	}
	std::cout << "#printCmdVector" << std::endl;
	printCmdVector(cmdVector);
	iter = clientList.find(fd);
	if (iter == clientList.end())
		return ;
	if ((iter != clientList.end()) && !(iter->second.getIsRegist())) // 클라이언트가 등록되어 있지 않은 경우
	{
		std::cout << "#signUp" << std::endl;
		signUp(fd, iter, cmdVector, clientList);
	}
	else	// 클라이언트가 등록되어 있는 경우
	{
		std::cout << "#signIn" << std::endl;
		signIn(fd, cmdVector);
	}
}

void Command::irssiSignUp(int fd, std::string irssiFullCommand)
{
    std::stringstream ss(irssiFullCommand);
    std::string line;

    while (std::getline(ss, line, '\n'))	// 개행문자를 기준으로 명령어를 '반복해서' 나눔
	{	// 1차례: PASS 1234\n
		// 2차례: NICK kwon\n
		// 3차례: USER <username> <hostname> <servername> :<realname>\n
    	std::vector<std::string> cmdVector;
        std::stringstream tmp(line);		// 개행까지 받은 걸 임시로 저장 ex) PASS 1234\n
        std::string cmd;

		while (tmp >> cmd)						// stringstream을 이용해 공백을 기준으로 명령어를 나눔
		{
			if (cmdVector.empty())
				cmdVector.push_back(cmd); // 첫 번째 명령어 저장, 예: "USER"
			else if (cmdVector[0] == "USER")
			{
                std::string username, hostname, servername, realname;
				std::stringstream userStream;
				size_t usernamePos = tmp.str().find("USER");
				std::string userStr = tmp.str().substr(usernamePos + 4);
				userStream << userStr;
				userStream >> username >> hostname >> servername; // 다음 세 파라미터를 읽음
				getline(userStream, realname); // 실제 이름은 콜론을 포함하여 저장

				//realname 에 공백만 자르기 위해
				size_t pos = realname.find_first_not_of(" "); // 공백이 아닌 첫 문자의 위치
				realname = realname.substr(pos); // 공백이 아닌 첫 문자부터 끝까지의 문자열을 반환
                cmdVector.push_back(username);
                cmdVector.push_back(hostname);
                cmdVector.push_back(servername);
                cmdVector.push_back(realname); // 실제 이름은 콜론을 포함하여 저장
                break; // 더 이상의 파싱은 필요 없음
			}
			else
				cmdVector.push_back(cmd);
		}

        if (!cmdVector.empty())
		{	// ==== 대문자로 변환 ====
            std::string command = cmdVector[0];
            for (size_t i = 0; i < command.length(); i++)
                command[i] = std::toupper(command[i]);
			// ==== 대문자 변경 완료 ====

			// ex) cmdVector = {PASS, 1234}
            if (command == "PASS")
                pass(fd, cmdVector);
            else if (command == "NICK")
                nick(fd, cmdVector);
            else if (command == "USER")
                user(fd, cmdVector);
        }
    }
	std::map<int, Client>& clientList = _server.getClientList();
	std::map<int, Client>::iterator iter = clientList.find(fd);
	iter = clientList.find(fd);
	if (iter != clientList.end())
	{
		if (iter->second.getIsRegist())
			iter->second.appendReciveBuf(":IRC 001 " + iter->second.getNickname() + " :Welcome to the Interget Relay Network " + iter->second.getNickname() + "!" + iter->second.getUsername() + "@" + iter->second.getHostname() + "\r\n");
	}
}

void Command::signUp(int fd, std::map<int, Client>::iterator iter, std::vector<std::string>& cmdVector, std::map<int, Client>& clientList)
{

	if (cmdVector.size() > 0)
	{
		if (cmdVector[0] == "PASS")
		{
			pass(fd, cmdVector);
		}
		else if (cmdVector[0] == "NICK")
		{
			nick(fd, cmdVector);
		}
		else if (cmdVector[0] == "USER")
		{
			user(fd, cmdVector);
		}
		else
		{
			notRegister(fd, iter, clientList);
		}
	}
	iter = clientList.find(fd);
	if (iter != clientList.end())
	{
		if (iter->second.getIsRegist())
			iter->second.appendReciveBuf(":IRC 001 " + iter->second.getNickname() + " :Welcome to the Interget Relay Network " + iter->second.getNickname() + "!" + iter->second.getUsername() + "@" + iter->second.getHostname() + "\r\n");
	}
}

void Command::notRegister(int fd, std::map<int, Client>::iterator iter, std::map<int, Client>& clientList)
{
	iter->second.appendReciveBuf(iter->second.getNickname() + " :");
	iter->second.appendReciveBuf(ERR_NOTREGISTERED);
	send(fd, iter->second.getReciveBuf().c_str(), iter->second.getReciveBuf().length(), 0);
	iter->second.resetClient();
	clientList.erase(fd);
	close(fd);
}

void Command::signIn(int fd, std::vector<std::string>& cmdVector)
{
	if (cmdVector.size() > 0)
	{
		if (cmdVector[0] == "USER")
			user(fd, cmdVector);
		else if (cmdVector[0] == "NICK")
			nick(fd, cmdVector);
		else if (cmdVector[0] == "PASS")
			pass(fd, cmdVector);
		else if (cmdVector[0] == "PRIVMSG")
			privmsg(fd, cmdVector);
		else if (cmdVector[0] == "QUIT")
			quit(fd, cmdVector);
		else if (cmdVector[0] == "PART")
			part(fd, cmdVector);
		else if (cmdVector[0] == "JOIN")
			join(fd, cmdVector);
		else if (cmdVector[0] == "KICK")
			kick(fd, cmdVector);
		else if (cmdVector[0] == "MODE")
			mode(fd, cmdVector);
		else if (cmdVector[0] == "TOPIC")
			topic(fd, cmdVector);
		else if (cmdVector[0] == "INVITE")
			invite(fd, cmdVector);
		else if (cmdVector[0] == "LIST")
			list(fd, cmdVector);
		else if (cmdVector[0] == "PING")
			ping(fd, cmdVector);
		else if (cmdVector[0] == "WHOIS")
			;
		else if (cmdVector[0] == "WHO")
			;
		else
        {
            // 등록되어 있지 않은 명령어의 경우 에러처리
            std::map<int, Client>& clientList = _server.getClientList();
            std::map<int, Client>::iterator iter = clientList.find(fd);
            if (iter != clientList.end())
                ERROR_unknowncommand_421(iter->second, cmdVector[0]);
        }
	}
}

```
### ./src/Server.cpp
```cpp
#include "../includes/Server.hpp"
#include "../includes/Channel.hpp"
#include "../includes/Client.hpp"
#include "../includes/Command.hpp"

Server::Server(int portNum, std::string password)
{
	_command = new Command(*this);					// Command 객체 생성 -> 왜? 전방선언
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
	kqueueInit();									// kq에 serverSock(리스닝소켓) 등록
	execute();
}

void Server::setServerSock()
{
	int opiton = 1;
	_serverSock = socket(PF_INET, SOCK_STREAM, 0);
	std::cout << "#1_socket 생성 : " << _serverSock << std::endl;
	if (_serverSock == -1)
		throw std::runtime_error("socket error");
	if (setsockopt(_serverSock, SOL_SOCKET, SO_REUSEADDR, &opiton, sizeof(opiton)) == -1)
	{
		close(_serverSock);
		throw std::runtime_error("setsockopt error");
	}
	std::cout << "#2_setsockopt 완료" << std::endl;
}

void Server::setServerAddr()
{
	memset(&_serverAddr, 0, sizeof(_serverAddr));
	_serverAddr.sin_family = AF_INET;
	_serverAddr.sin_addr.s_addr = INADDR_ANY;
	_serverAddr.sin_port = htons(_portNum);
	std::cout << "#3_setServerAddr 완료" << std::endl;
}

void Server::setServerBind()
{
	if (bind(_serverSock, (struct sockaddr *)&_serverAddr, sizeof(_serverAddr)) == -1)
	{
		close(_serverSock);
		throw std::runtime_error("bind error");
	}
	std::cout << "#4_bind 완료" << std::endl;
}

void Server::setServerListen()
{
	std::cout << "#5_listen 시작" << std::endl;
	if (listen(_serverSock, MAX_CONNECTION) == -1)
	{
		close(_serverSock);
		throw std::runtime_error("listen error");
	}
	std::cout << "#5_listen 완료" << std::endl;
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
	std::cout << "#6_kqueue 초기화 완료" << std::endl;
}

#include <fstream>

void Server::execute()
{
	int _eventCnt;

	_eventCnt = 0;
	std::cout << "#7_execute 시작" << "\n=== === === ===\n\n" << std::endl;
	while (1)
	{
		_eventCnt = kevent(_kq, &_changeList[0], _changeList.size(), _eventList, 256, NULL);
		// Kq를 통해 생성된 이벤트 큐(kevent)를 식별할 것이고,
		// changeList에 있는 이벤트들을 _changeList.size()만큼 감시하고,
		// 실제로 이벤트가 발생한 것이 있으면, eventList[256]에 이벤트들을 저장한다 ->
		// 저장하고, 그 수만큼을 반환
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
					std::cout << "_curr_event->data : " << _curr_event->data << std::endl;
					_command->run(_curr_event->ident, _curr_event->data);
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
		// delete 하는 이유
		// Server::appendNewChannel(int fd, std::string& channelName) 에서
 		// ( ... , 'new Channel'(channelName, fd)));
		// new로 동적할당했기 때문에 Channel 은 꼭 delete 할것!!
		channelIter++;
	}

	_clientList.clear();
	_channelList.clear();
														// clear()는 map의 모든 요소를 제거함
	delete _command;									// new Command(*this); 생성자에서 동적할당했었음
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

std::string Server::getMessage(int clientSock, int data_bite)
{
    std::string message;
    char buf[data_bite + 1];										// line max_len == 510 (512 - "\r\n") + 1 for '\0'
    int n = recv(clientSock, buf, data_bite, 0);	// 512 characters 까지만
    if (n <= 0)
    {
        if (n < 0)
            std::cerr << "client read error!" << std::endl;
        disconnectClient(clientSock);
    }
    else if (n > 512) 									// 메시지가 510자를 초과하는 경우
	{
		buf[510] = '\r';							//실제 글자 번째인 511번째에 '\r'을 넣어줌
		buf[511] = '\n';							//실제 글자 번째인 512번째에 '\n'을 넣어줌
		buf[512] = '\0';

		message = std::string(buf, 513);			// 'std::string(buf, 513);' -> buf의 513개의 문자를 message에 저장
	}
	else
	{
		buf[n] = '\0';
		message = buf;
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

```
