#include <stdio.h>
#include "CSocketProtocol.h"

//通信结构体成员变量初始化
void setSP(CSocketProtocol *SP, PSOCKET_INIT init,
	PSEND_DATA send, PSEND_DATA recv, PSOCKET_DESTORY destory)
{
	if (SP == NULL ||init == NULL || send == NULL || recv == NULL || destory == NULL)
		return;
	SP->socket_init = init;
	SP->send_data = send;
	SP->recv_data = recv;
	SP->socket_destory = destory;
}
