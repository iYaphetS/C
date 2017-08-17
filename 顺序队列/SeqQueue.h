#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1024
typedef struct SQueue
{
	void *data[MAXSIZE];
	int size;
}SQueue;

typedef void * SqeQueue;

#ifdef __cplusplus
extern "C" {
#endif
	//˳����еĳ�ʼ��
	int init_SqeQueue(SqeQueue * squeue);
	//���
	int push_SqeQueue(SqeQueue queue, void *data);
	//����
	int pop_SqeQueue(SqeQueue queue);
	//��ö�ͷԪ��
	void* fornt_SqeQueue(SqeQueue queue);
	//��ö�βԪ��
	void* back_SqeQueue(SqeQueue queue);
	//��ö��д�С
	int size_SqeQueue(SqeQueue queue);
	//���ٶ���
	int destory_SqeQueue(SqeQueue queue);

#ifdef __cplusplus
}
#endif