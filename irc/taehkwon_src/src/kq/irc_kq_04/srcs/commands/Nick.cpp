#include "../../includes/Command.hpp"
#include "../../includes/Util.hpp"

void Command::nick(int fd, std::vector<std::string> command_vec)
{
	/* NICK <nickname> */
	std::map<int, Client> &clients = _server.getClients();
	std::map<int, Client>::iterator iter = clients.find(fd);
	if (!iter->second.getPassRegist()) // 암호가 등록되지 않은 경우 :
	{
		// ERR_NOTREGISTERED = "You have not registered\r\n"
		err_notregistered_451(iter->second);
		// 클라이언트에게 에러 메시지 전송
		send(fd, iter->second.getClientRecvBuf().c_str(), iter->second.getClientRecvBuf().length(), 0);
		// 클라이언트 초기화
		iter->second.clearClient();
		// 클라이언트 삭제
		clients.erase(fd);
		// 파일 디스크립터 닫기
		close(fd);
		return;
	}
	if (command_vec.size() < 2) // 명령어에 필요한 인자가 부족한 경우 :
	{
		// ERR_NONICKNAMEGIVEN = "No nickname given\r\n"
		err_nonicknamegiven_431(iter->second);
		return;
	}
	if (command_vec[1] == "_") // _로 시작하는 닉네임은 이미 등록된 클라이언트의 닉네임을 의미 :
	{
		while (1)
		{
			// 이미 등록된 클라이언트의 닉네임을 찾아서 command_vec[1]에 저장
			std::map<int, Client>::iterator client = _server.findClient(command_vec[1]);
			if (client != _server.getClients().end()) // 클라이언트가 존재하는 경우 :
				// command_vec[1]에 클라이언트의 닉네임을 저장
				command_vec[1] = client->second.getNickname() + "_";
			else
				break;
		}
	}
	if (!checkNicknameValidate(command_vec[1])) // 닉네임이 유효하지 않은 경우 :
	{
		// ERR_ERRONEUSNICKNAME = "Erroneous nickname\r\n"
		err_erroneusnickname_432(iter->second);
		// 클라이언트에게 에러 메시지 전송
		iter->second.appendClientRecvBuf("/NICK <nickname> First Letter is not digit and length is under 10.\r\n");
		return;
	}
	if (!checkNicknameDuplicate(command_vec[1], _server.getClients())) // 닉네임이 중복된 경우 :
	{
		// ERR_NICKNAMEINUSE = "Nickname is already in use\r\n"
		err_nicknameinuse_433(iter->second);
		return;
	}
	std::string old_nickname = iter->second.getNickname();
	if (old_nickname == "Client") // 기본 닉네임인 경우 :
	{
		// 기본 닉네임을 변경
		old_nickname = iter->second.getNickname();
	}
	std::vector<std::string> channelList = iter->second.getChannelList();  // 클라이언트가 속한 채널 리스트
	std::vector<std::string>::iterator channel_iter = channelList.begin(); // 채널 리스트의 시작
	// 채널 리스트를 순회하며 닉네임 변경 메시지 전송
	for (; channel_iter != channelList.end(); channel_iter++)
	{
		Channel *channel = _server.findChannel(*channel_iter);
		if (channel) // 채널이 존재하는 경우
		{
			// 채널에 닉네임 변경 메시지 전송
			msgToAllChannel(fd, channel->getChannelName(), "NICK", old_nickname + " " + command_vec[1]);
		}
	}
	// 닉네임 변경
	iter->second.setNickname(command_vec[1]);
	// 닉네임 변경 메시지 전송
	iter->second.appendClientRecvBuf(":" + old_nickname + " NICK " + iter->second.getNickname() + "\r\n");
	// 클라이언트에게 닉네임 변경 메시지 전송
	iter->second.setNickRegist(true);
}

bool Command::checkNicknameValidate(std::string nickname)
{
	if (nickname.length() == 0 || nickname.length() > 9)
		return (false);
	if (nickname[0] >= '0' && nickname[0] <= '9')
		return (false);
	for (size_t i = 1; i < nickname.length(); i++)
	{
		if (!isalnum(nickname[i]) && !isSpecial(nickname[i]))
			return (false);
	}
	return (true);
}

bool Command::checkNicknameDuplicate(std::string nickname, std::map<int, Client> &Clients)
{
	std::map<int, Client>::iterator iter = Clients.begin();
	for (; iter != Clients.end(); iter++)
	{
		std::string clientNickname = iter->second.getNickname();
		bool isSame = true;
		if (clientNickname.length() != nickname.length())
			continue;
		for (size_t i = 0; i < nickname.length(); ++i)
		{
			if (std::toupper(nickname[i]) != std::toupper(clientNickname[i]))
			{
				isSame = false;
				break;
			}
		}
		if (isSame)
			return (false);
	}
	return (true);
}