#include "../../includes/Command.hpp"
#include "../../includes/Util.hpp"

void Command::pass(int fd, std::vector<std::string> command_vec)
{
	/* PASS <password> */
	std::map<int, Client> &clients = _server.getClients();
	std::map<int, Client>::iterator iter = clients.find(fd);
	std::string password = _server.getPassword();
	if (iter->second.getPassRegist()) // 이미 등록된 클라이언트
	{
		// ERR_ALREADYREGISTRED = "You may not reregister\r\n"
		err_alreadyregistred_462(iter->second);
		return;
	}
	if (command_vec.size() < 2) // 명령어에 필요한 인자가 부족한 경우
	{
		// ERR_NEEDMOREPARAMS = "Not enough parameters\r\n"
		err_needmoreparams_461(iter->second);
		return;
	}
	if (strcmp(command_vec[1].c_str(), password.c_str()) != 0) // 비밀번호가 틀린 경우
	{
		// ERR_PASSWDMISMATCH = "Password incorrect\r\n"
		err_passwdmismatch_464(iter->second);
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
	iter->second.setPassRegist(true);
}