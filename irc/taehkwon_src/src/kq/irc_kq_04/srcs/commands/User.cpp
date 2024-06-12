#include "../../includes/Command.hpp"
#include "../../includes/Util.hpp"

void Command::user(int fd, std::vector<std::string> command_vec)
{
	/* USER <username> <hostname> <servername> <:realname> */
	std::map<int, Client> &clients = _server.getClients();
	std::map<int, Client>::iterator iter = clients.find(fd);
	if (iter->second.getUserRegist()) // 이미 등록된 유저인 경우 :
	{
		// ERR_ALREADYREGISTRED = "You may not reregister\r\n"
		err_alreadyregistred_462(iter->second);
		return;
	}
	if (!iter->second.getPassRegist()) // 암호가 등록되지 않은 경우 :
	{
		// ERR_NOTREGISTERED = "You have not registered\r\n"
		err_notregistered_451(iter->second);
		// 클라이언트에게 에러 메시지 전송
		iter->second.appendClientRecvBuf("\r\n");
		send(fd, iter->second.getClientRecvBuf().c_str(), iter->second.getClientRecvBuf().length(), 0);
		// 클라이언트 초기화
		iter->second.clearClient();
		// 클라이언트 삭제
		clients.erase(fd);
		// 파일 디스크립터 닫기
		close(fd);
		return;
	}
	if (command_vec.size() < 5 || !checkRealname(command_vec[4])) // 명령어에 필요한 인자가 부족한 경우 :
	{
		// ERR_NEEDMOREPARAMS = "Not enough parameters\r\n"
		err_needmoreparams_461(iter->second);
		// 클라이언트에게 에러 메시지 전송
		iter->second.appendClientRecvBuf("/USER <username> <hostname> <servername> <:realname>\r\n");
		return;
	}
	std::string realname;
	// realname을 command_vec[4]부터 command_vec의 끝까지 저장 :
	for (size_t i = 4; i < command_vec.size(); i++) // realname을 command_vec[4]부터 command_vec의 끝까지 저장 :
	{
		// realname에 command_vec[i] 저장
		realname += command_vec[i];
		if (i != command_vec.size() - 1) // 마지막이 아닌 경우 :
		{
			// realname에 공백 추가
			realname += " ";
		}
	}
	// 클라이언트에게 환영 메시지 전송
	iter->second.setUser(command_vec[1], command_vec[2], command_vec[3], realname);
	// 클라이언트 등록 완료
	iter->second.setUserRegist(true);
}

bool Command::checkRealname(std::string realname)
{
	if (realname.length() == 0)
		return (false);
	if (realname[0] != ':')
		return (false);
	return (true);
}