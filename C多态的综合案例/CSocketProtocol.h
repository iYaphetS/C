#pragma once

//定义通信结构体

//通信函数类型定义
typedef int(*PSOCKET_INIT)(void **handle);

typedef int(*PSEND_DATA)(void *handle, char *buf, int len);

typedef int(*PRECV_DATA)(void *handle, char *buf, int *len);

typedef int(*PSOCKET_DESTORY)(void **handle);

typedef struct CSocketProtocol
{
	//定义函数指针变量
	PSOCKET_INIT socket_init;
	PSEND_DATA send_data;
	PRECV_DATA recv_data;
	PSOCKET_DESTORY socket_destory;
}CSocketProtocol;

//通信结构体初始化函数的声明
void setSP(CSocketProtocol *SP, PSOCKET_INIT init, PSEND_DATA send, PSEND_DATA recv, PSOCKET_DESTORY destory);
