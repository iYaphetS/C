#pragma once

//ͨ�ű��ļӽ��ܵĽṹ�嶨��

//�ӽ��ܺ������Ͷ���
typedef int(*PENCFILE)(unsigned char *src, int src_len, unsigned char *dest, int *dest_len);

typedef int(*PDESFILE)(unsigned char *src, int src_len, unsigned char *dest, int *dest_len);

typedef struct CEncDesProtocol
{
	PENCFILE enc_file;
	PDESFILE des_file;

}CEncDesProtocol;

//ͨ�ű���ʼ���ӽ��ܽṹ���ʼ������
void setED(CEncDesProtocol *ED, PENCFILE enc, PDESFILE des);