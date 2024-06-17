#include "../../includes/Command.hpp"
#include "../../includes/Util.hpp"

void Command::join(int fd, std::vector<std::string> command_vec)
{
	/* JOIN <channel> (<options>) */
	if (command_vec.size() < 2) // 명령어에 인자가 부족할 때 :
	{
		// ERR_NEEDMOREPARAMS = ":<server> 461 <nickname> JOIN :Not enough parameters"
		err_needmoreparams_461(_server.getClients().find(fd)->second);
		return;
	}
	std::vector<std::string> joinChannel = split(command_vec[1], ',');
	std::vector<std::string>::iterator iter = joinChannel.begin();
	std::vector<std::string> joinKey;
	std::vector<std::string>::iterator keyIter;
	if (command_vec.size() > 2) // (<options>)가 존재할 때 :
	{
		// <options> = <key>
		joinKey = split(command_vec[2], ',');
		keyIter = joinKey.begin();
	}
	std::map<int, Client> &clients = _server.getClients();
	Client &client = clients.find(fd)->second;
	while (iter != joinChannel.end()) // 채널이름이 여러개일 경우를 대비하여 ','로 구분 -
	{
		if ((*iter)[0] != '#' && (*iter)[0] != '&') // 채널 이름이 # 또는 &로 시작하지 않을 때 :
		{
			// ERR_NOSUCHCHANNEL = ":<server> 403 <nickname> <channel> :No such channel"
			err_nosuchchannel_403(client, *iter);
			iter++;
			if (command_vec.size() > 2 || keyIter != joinKey.end()) // (<options>)가 존재할 때 :
			{
				// key처리
				keyIter++;
			}
			continue;
		}
		std::map<std::string, Channel *> &channelList = _server.getChannelList();
		std::map<std::string, Channel *>::iterator channelIt = channelList.find(*iter);
		if (channelIt != channelList.end()) // 채널이 존재할 경우 :
		{
			Channel *channel = channelIt->second;
			if (channel->checkClientInChannel(fd)) // 이미 채널에 존재할 경우 :
			{
				// 접속 무시
				iter++;
				if (command_vec.size() > 2 || keyIter != joinKey.end()) // (<options>)가 존재할 때 :
				{
					// key처리
					keyIter++;
				}
				continue;
			}
			if (channel->checkMode(INVITE)) // INVITE 모드일 때 :
			{
				if (!channel->checkInvite(fd)) // INVITE가 없을 때 :
				{
					// ERR_INVITEONLYCHAN = ":<server> 473 <nickname> <channel> :Cannot join channel (+i)"
					err_inviteonlychan_473(client, *iter);
					iter++;
					if (command_vec.size() > 2 || keyIter != joinKey.end()) // (<options>)가 존재할 때 :
					{
						// key처리
						keyIter++;
					}
					continue;
				}
			}
			if (channel->checkMode(KEY)) // KEY 모드일 때 :
			{
				if (command_vec.size() <= 2 || keyIter == joinKey.end() || !channel->checkKey(*keyIter)) // KEY가 일치하지 않을 때 :
				{
					// ERR_BADCHANNELKEY = ":<server> 475 <nickname> <channel> :Cannot join channel (+k)"
					err_badchannelkey_475(client, *iter);
					iter++;
					if (command_vec.size() > 2 || keyIter != joinKey.end()) // (<options>)가 존재할 때 :
					{
						// key처리
						keyIter++;
					}
					continue;
				}
			}
			if (channel->checkMode(LIMIT)) // LIMIT 모드일 때 :
			{
				if (channel->getClientFdList().size() >= channel->getLimit()) // LIMIT을 초과할 때 :
				{
					// ERR_CHANNELISFULL = ":<server> 471 <nickname> <channel> :Cannot join channel (+l)"
					err_channelisfull_471(client, *iter);
					iter++;
					if (command_vec.size() > 2 || keyIter != joinKey.end()) // (<options>)가 존재할 때 :
					{
						// KEY 처리
						keyIter++;
					}
					continue;
				}
			}
			std::string channelName = (*channelIt).second->getChannelName();
			(*channelIt).second->appendClientFdList(fd);
			// 채널에 클라이언트 추가
			client.appendChannelList(channelName);
			// JOIN 메시지 전송
		}
		else // 채널이 존재하지 않을 경우 :
		{
			_server.appendNewChannel(*iter, fd); // 채널 생성
			_server.findChannel(*iter)->appendClientFdList(-1); // 봇 추가
			_server.findChannel(*iter)->appendClientFdList(fd); // 채널에 클라이언트 추가
			client.appendChannelList(*iter);					// 클라이언트에 채널 추가
			msgToAllChannel(fd, *iter, "JOIN", "");				// JOIN 메시지 전송
			_server.findChannel(*iter)->addOperatorFd(fd);		// 채널 오퍼레이터 추가
		}
		nameListMsg(fd, *iter); // 채널에 있는 클라이언트 리스트 전송
		// 채널에 봇이 있을 경우 봇 메시지 전송
		msgToAllChannel(-1, *iter, "PRIVMSG", _server.findChannel(*iter)->getBot()->introduce());
		iter++;
0		if (command_vec.size() > 2 || keyIter != joinKey.end()) // (<options>)가 존재할 때 :
		{
			// key처리
			keyIter++;
		}
	}
}

void Command::topicMsg(int fd, std::string channelName)
{
	std::map<std::string, Channel *> &channelList = _server.getChannelList();
	Channel *channel = channelList.find(channelName)->second;
	std::string topic = channel->getTopic();
	if (topic.length() == 0)
	{
		return;
	}
	topic = topic.substr(1, topic.length() - 1);
	Client &client = _server.getClients().find(fd)->second;
	client.appendClientRecvBuf("332 " + client.getNickname() + " " + channelName + " :" + topic + "\r\n");
}
