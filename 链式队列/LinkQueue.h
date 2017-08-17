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
	//��ʽ���еĳ�ʼ��
	int init_LinkQueue(LinkQueue *lqueue);
	//���
	int push_LinkQueue(LinkQueue lqueue, void *data);
	//����
	int pop_LinkQueue(LinkQueue lqueue);
	//��ö�ͷԪ��
	LinkNode front_LinkQueue(LinkQueue lqueue);
	//��ö�βԪ��
	LinkNode back_LinkQueue(LinkQueue lqueue);
	//�ӵĴ�С
	int size_LinkQueue(LinkQueue lqueue);
	//�ӵ�����
	int destory_LinkQueue(LinkQueue lqueue);

#ifdef __cplusplus
}
#endif