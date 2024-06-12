#include "../../includes/Command.hpp"
#include "../../includes/Util.hpp"

// PART <channel> <nickname> (<reasons, ...>)
// 명령어에 인자가 부족할 경우 :
// ERR_NEEDMOREPARAMS = ":<server> 461 <nickname> PART :Not enough parameters"
// 채널이름이 여러개일 경우를 대비하여 ','로 구분 -
// 나가려는 채널의 수만큼 반복 -
// 클라이언트가 채널에 존재할 경우 :
// 채널에 메시지 전송
// 채널에서 클라이언트 제거
// 채널에서 오퍼레이터 제거
// 클라이언트의 채널 목록에서 채널 제거
// 채널에 클라이언트가 1명일 경우 :
// 채널 제거
// 클라이언트가 채널에 존재하지 않을 경우 :
// 채널이 존재할 경우 :
// ERR_NOTONCHANNEL = ":<server 442 <nickname> <channel> :You're not on that channel"
// 채널이 존재하지 않을 경우 :
// ERR_NOSUCHCHANNEL = ":<server> 403 <nickname> <channel> :No such channel"

void Command::part(int fd, std::vector<std::string> command_vec)
{
	/* PART <channel> <nickname> (<reasons, ...>) */
	std::map<int, Client> &clients = _server.getClients();
	std::map<int, Client>::iterator client_iter = clients.find(fd);
	if (command_vec.size() < 2) // 명령어에 인자가 부족할 경우 :
	{
		// ERR_NEEDMOREPARAMS = ":<server> 461 <nickname> PART :Not enough parameters"
		err_needmoreparams_461(client_iter->second);
		return;
	}
	std::istringstream iss(command_vec[1]);
	std::string buffer;
	std::vector<std::string> vec;
	while (getline(iss, buffer, ',')) // 채널이름이 여러개일 경우를 대비하여 ','로 구분 -
		vec.push_back(buffer);
	std::vector<std::string>::iterator vec_iter = vec.begin();
	for (; vec_iter != vec.end(); vec_iter++) // 나가려는 채널의 수만큼 반복 -
	{
		std::vector<std::string>::iterator channelList = client_iter->second.findChannel(*vec_iter);
		if (channelList != client_iter->second.getChannelList().end()) // 클라이언트가 채널에 존재할 경우 :
		{
			Channel *channel = _server.findChannel(*channelList);
			// 채널에 메시지 전송
			msgToAllChannel(fd, *vec_iter, "PART", channelMessage(2, command_vec));
			// 채널에서 클라이언트 제거
			channel->removeClientFdList(fd);
			// 채널에서 오퍼레이터 제거
			channel->removeOperatorFd(fd);
			// 클라이언트의 채널 목록에서 채널 제거
			client_iter->second.removeChannel(*channelList);
			if (channel->getClientFdList().size() == 1) // 채널에 클라이언트가 1명일 경우 :
			{
				// 채널 제거
				_server.removeChannel(channel->getChannelName());
				delete channel;
			}
		}
		else // 클라이언트가 채널에 존재하지 않을 경우 :
		{
			if (_server.findChannel(*vec_iter)) // 채널이 존재할 경우 :
			{
				// ERR_NOTONCHANNEL = ":<server 442 <nickname> <channel> :You're not on that channel"
				err_notonchannel_442(client_iter->second, *vec_iter);
			}
			else // 채널이 존재하지 않을 경우 :
			{
				// ERR_NOSUCHCHANNEL = ":<server> 403 <nickname> <channel> :No such channel"
				err_nosuchchannel_403(client_iter->second, *vec_iter);
			}
		}
	}
}