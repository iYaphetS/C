#include <stdio.h>
#include "CSocketProtocol.h"

//ͨ�Žṹ���Ա������ʼ��
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
