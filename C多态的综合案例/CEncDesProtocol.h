#pragma once

//通信报文加解密的结构体定义

//加解密函数类型定义
typedef int(*PENCFILE)(unsigned char *src, int src_len, unsigned char *dest, int *dest_len);

typedef int(*PDESFILE)(unsigned char *src, int src_len, unsigned char *dest, int *dest_len);

typedef struct CEncDesProtocol
{
	PENCFILE enc_file;
	PDESFILE des_file;

}CEncDesProtocol;

//通信报初始化加解密结构体初始化声明
void setED(CEncDesProtocol *ED, PENCFILE enc, PDESFILE des);