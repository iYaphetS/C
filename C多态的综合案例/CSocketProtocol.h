#pragma once

//����ͨ�Žṹ��

//ͨ�ź������Ͷ���
typedef int(*PSOCKET_INIT)(void **handle);

typedef int(*PSEND_DATA)(void *handle, char *buf, int len);

typedef int(*PRECV_DATA)(void *handle, char *buf, int *len);

typedef int(*PSOCKET_DESTORY)(void **handle);

typedef struct CSocketProtocol
{
	//���庯��ָ�����
	PSOCKET_INIT socket_init;
	PSEND_DATA send_data;
	PRECV_DATA recv_data;
	PSOCKET_DESTORY socket_destory;
}CSocketProtocol;

//ͨ�Žṹ���ʼ������������
void setSP(CSocketProtocol *SP, PSOCKET_INIT init, PSEND_DATA send, PSEND_DATA recv, PSOCKET_DESTORY destory);
