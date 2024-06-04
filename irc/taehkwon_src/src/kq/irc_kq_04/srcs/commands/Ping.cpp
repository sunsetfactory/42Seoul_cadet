#include "../../includes/Command.hpp"
#include "../../includes/Util.hpp"

void Command::ping(int fd, std::vector<std::string> command_vec)
{
	/* PING <token> */
	std::map<int, Client> &clients = _server.getClients();
	std::map<int, Client>::iterator iter = clients.find(fd);

	if (command_vec.size() < 2) // 명령어에 필요한 인자가 부족한 경우 :
	{
		// ERR_NEEDMOREPARAMS = "Not enough parameters\r\n"
		err_needmoreparams_461(iter->second);
		// 클라이언트에게 에러 메시지 전송
		iter->second.appendClientRecvBuf("/PING <token>\r\n");
		return;
	}
	// 클라이언트에게 PONG 메시지 전송
	iter->second.appendClientRecvBuf("PONG " + command_vec[1] + "\r\n");
}
