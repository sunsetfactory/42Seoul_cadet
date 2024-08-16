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

	// std::string PREFIX_SERVERNAME = "localhost.42seoul.kr";
	
	if (command == "PRIVMSG" || command == "JOIN" || command == "QUIT" || command == "PART" || command == "NICK" || command == "MODE" || command == "KICK")
	{
		prefix = (":" + client.getNickname() + "!" + client.getUsername() + "@" + client.getServername());
	}
	else if (command == "KICK")	// 태현 추가
		prefix = (":" + client.getNickname());
	else
		prefix = (":" + std::string(PREFIX_SERVERNAME));
	return (prefix);
}

void Command::messageAllChannel(int fd, std::string channelName, std::string command, std::string message)
{
	std::map<std::string, Channel*>& channelList = _server.getChannelList();

	if (channelList.find(channelName) == channelList.end())
		return ;
	Channel *channel = channelList.find(channelName)->second;
	std::vector<int> fdList = channel->getFdListClient();
	std::vector<int>::iterator fd_iter = fdList.begin();

	while (fd_iter != fdList.end())
	{
		std::cout << "#fd_iter : " << *fd_iter << std::endl;
		Client& targetClient = _server.getClientList().find(*fd_iter)->second;
		if ((fd == (*fd_iter)) && (command == "PRIVMSG"))
		{
			fd_iter++;
			continue ;
		}
	
		if (command == "PRIVMSG" || command == "JOIN" || command == "TOPIC")
		{
			std::cout << "#targetClient.getNickname() : " << targetClient.getNickname() << std::endl;
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " " + channelName + " :" + message + "\r\n");
			std::cout << "#targetClient.getReciveBuf() : " << targetClient.getReciveBuf() << std::endl;
			fd_iter++;
		}
		else if (command == "KICK")
		{
			std::cout << "#targetClient.getNickname() : " << targetClient.getNickname() << std::endl;
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " " + channelName + " " + message + " :" + _server.getClientList().find(fd)->second.getNickname() + "\r\n");
			std::cout << "#targetClient.getReciveBuf() : " << targetClient.getReciveBuf() << std::endl;
			fd_iter++;
		}
		else if (command == "PART")
		{
			if (message == "NO REASON")
			{
				std::cout << "#message - NO : " << message << std::endl;
				std::cout << "#targetClient.getNickname() : " << targetClient.getNickname() << std::endl;
				targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " :" + channelName + "\r\n");
				std::cout << "#targetClient.getReciveBuf() : " << targetClient.getReciveBuf() << std::endl;
				fd_iter++;
			}
			else
			{
				std::cout << "#message - OK : " << message << std::endl;
				std::cout << "#targetClient.getNickname() : " << targetClient.getNickname() << std::endl;
				targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " " + channelName + " :" + message + "\r\n");
				std::cout << "#targetClient.getReciveBuf() : " << targetClient.getReciveBuf() << std::endl;
				fd_iter++;
			}
		}
		else
		{
			std::cout << "#targetClient.getNickname() : " << targetClient.getNickname() << std::endl;
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " :" + message + "\r\n");
			std::cout << "#targetClient.getReciveBuf() : " << targetClient.getReciveBuf() << std::endl;
			fd_iter++;
		}
	}
}

void Command::plus_messageAllChannel(int fd, std::string channelName, std::string command, std::string message, std::string plus_message)
{
	std::map<std::string, Channel*>& channelList = _server.getChannelList();

	if (channelList.find(channelName) == channelList.end())
		return ;
	Channel *channel = channelList.find(channelName)->second;
	std::vector<int> fdList = channel->getFdListClient();
	std::vector<int>::iterator fd_iter = fdList.begin();

	while (fd_iter != fdList.end())
	{
		std::cout << "#fd_iter : " << *fd_iter << std::endl;
		Client& targetClient = _server.getClientList().find(*fd_iter)->second;
		if ((fd == (*fd_iter)) && (command == "PRIVMSG")) // 자신에게는 보내지 않음
		{
			fd_iter++;
			continue ;
		}

		if (command == "MODE")
		{
			std::cout << "#targetClient.getNickname() : " << targetClient.getNickname() << std::endl;
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " " + channelName + " " + message + " :" + plus_message + "\r\n");
			std::cout << "#targetClient.getReciveBuf() : " << targetClient.getReciveBuf() << std::endl;
			fd_iter++;
		}
		else
		{	// "#채널" 없을 때 == command + " :" 
			std::cout << "#targetClient.getNickname() : " << targetClient.getNickname() << std::endl;
			targetClient.appendReciveBuf(makeMsgForm(fd, command) + " " + command + " :" + message + "\r\n");
			std::cout << "#targetClient.getReciveBuf() : " << targetClient.getReciveBuf() << std::endl;
			// prefix = (":" + client->getNickname() + "!" + client->getUsername() + "@" + client->getServername());
			// <message>  ::= [':' <prefix> <SPACE> ] <command> <params> <crlf>
			// == " : name ! user @ host PRIVMSG #channel : message \r\n"
			// 2.3.1 Message format in 'pseudo' BNF -> [page 8]
			fd_iter++;
		}
	}
}

std::string Command::channelMessage(int index, std::vector<std::string> command_vec)
{
	std::string message = "";
	for (size_t i = index; i < command_vec.size(); i++)
	{
		message += command_vec[i];
		if (i != command_vec.size() - 1)
			message += " ";
	}
	if (message[0] == ':')
		message = message.substr(1, message.length() - 1);
	if (message.length() == 0)
		message = "NO REASON";
	return (message);
}

void Command::topicMessage(int fd, std::string channelName)
{
	std::map<std::string, Channel *>& channelList = _server.getChannelList();
	Channel *channel = channelList.find(channelName)->second;
	
	std::string topic = channel->getTopic();

	if (topic.length() == 0)
		return;

	topic = topic.substr(1, topic.length() - 1);
	Client &client = _server.getClientList().find(fd)->second;
	client.appendReciveBuf("332 " + client.getNickname() + " " + channelName + " :" + topic + "\r\n");
}

void Command::nameListMsg(int fd, std::string channelName)
{
	std::map<std::string, Channel *>& channelList = _server.getChannelList();

	if (channelList.find(channelName) == channelList.end())						
		return;

	Channel *channel = channelList.find(channelName)->second;
	std::vector<int> clientFdList = channel->getFdListClient();
	std::vector<int>::iterator iter;
	std::string message;

	iter = clientFdList.begin();
	while (iter != clientFdList.end())
	{
		Client &client = _server.getClientList().find(*iter)->second;
		if (channel->diffOperator(client.getClientFd()))
			message += "@";
		
		message += client.getNickname();
		
		if (iter != clientFdList.end() - 1)
			message += " ";
		
		iter++;
	}
	Client &client = _server.getClientList().find(fd)->second;
	client.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " 353 " + client.getNickname() + " = " + channelName + " :" + message + "\r\n");	// 채널의 클라이언트 리스트 (== mesaage) 주고
	client.appendReciveBuf(":" + std::string(PREFIX_SERVERNAME) + " 366 " + client.getNickname() + " " + channelName + " :End of /NAMES list.\r\n");	// 끝내기
}

std::string Command::intToString(int value)
{
	std::string str;
	std::stringstream ss;

	ss << value;
	ss >> str;
	return (str);
}