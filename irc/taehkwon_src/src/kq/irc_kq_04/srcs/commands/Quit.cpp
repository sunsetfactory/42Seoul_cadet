#include "../../includes/Command.hpp"
#include "../../includes/Util.hpp"

// 주석 모음

void Command::quit(int fd, std::vector<std::string> command_vec)
{
	/* QUIT */
	std::map<int, Client> &clients = _server.getClients();
	std::map<int, Client>::iterator client_iter = clients.find(fd);
	std::vector<std::string> channelList = client_iter->second.getChannelList();
	std::vector<std::string>::iterator channel_iter = channelList.begin();
	for (; channel_iter != channelList.end(); channel_iter++) // 클라이언트를 참가한 모든 채널에서 제거 -
	{
		Channel *channel = _server.findChannel(*channel_iter);
		if (!channel) // 채널에 없으면 :
		{
			// 다음 채널로 이동 (continue;)
			continue;
		}
		// 채널에서 클라이언트 제거
		channel->removeClientFdList(fd);
		// 채널에서 오퍼레이터 제거
		channel->removeOperatorFd(fd);
		// 채널에서 보이스드 제거
		msgToAllChannel(fd, channel->getChannelName(), "QUIT", channelMessage(1, command_vec));
		if (channel->getClientFdList().size() == 1) // 채널에 남은 클라이언트가 없으면 :
		{
			// 채널 제거
			_server.removeChannel(channel->getChannelName());
			delete channel;
		}
	}
	// 클라이언트 초기화
	client_iter->second.clearClient();
	// 클라이언트 삭제
	clients.erase(fd);
	// 파일 디스크립터 닫기
	close(fd);
}
