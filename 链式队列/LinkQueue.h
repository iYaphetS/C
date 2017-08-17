#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LNode
{
	struct LNode *next;
}LNode;

typedef struct LQueue
{
	LNode head;
	int size;
	LNode *rear;
}LQueue;

typedef void * LinkNode;
typedef void * LinkQueue;

#ifdef __cplusplus
extern "C" {
#endif
	//链式队列的初始化
	int init_LinkQueue(LinkQueue *lqueue);
	//入队
	int push_LinkQueue(LinkQueue lqueue, void *data);
	//出队
	int pop_LinkQueue(LinkQueue lqueue);
	//获得对头元素
	LinkNode front_LinkQueue(LinkQueue lqueue);
	//获得队尾元素
	LinkNode back_LinkQueue(LinkQueue lqueue);
	//队的大小
	int size_LinkQueue(LinkQueue lqueue);
	//队的销毁
	int destory_LinkQueue(LinkQueue lqueue);

#ifdef __cplusplus
}
#endif