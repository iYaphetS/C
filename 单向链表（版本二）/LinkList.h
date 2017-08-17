#pragma once 

#include <stdlib.h>
//链表节点的信息
typedef struct LinkNode
{
	struct LinkNode *next;
}LinkNode;

//链表的信息
typedef struct LinkList
{
	LinkNode head;
	int size;
}LinkList;

//可对linklist进行数据保密封装 typedef void * LinkList
#ifdef __cplusplus
extern "C" {
#endif
	LinkList *init_LinkList();
	void insert_LinkList(LinkList *list, int pos, void *data);
	void remove_LinkList(LinkList *list, int pos);
	void foreach_LinkList(LinkList *list, void(*foreach)(void *));
	void destory_LinkList(LinkList *list);
	void reveser_LinkList(LinkList *list);

#ifdef __cpluscplus
}
#endif


