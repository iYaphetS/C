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
	//顺序队列的初始化
	int init_SqeQueue(SqeQueue * squeue);
	//入队
	int push_SqeQueue(SqeQueue queue, void *data);
	//出队
	int pop_SqeQueue(SqeQueue queue);
	//获得对头元素
	void* fornt_SqeQueue(SqeQueue queue);
	//获得队尾元素
	void* back_SqeQueue(SqeQueue queue);
	//获得队列大小
	int size_SqeQueue(SqeQueue queue);
	//销毁队列
	int destory_SqeQueue(SqeQueue queue);

#ifdef __cplusplus
}
#endif