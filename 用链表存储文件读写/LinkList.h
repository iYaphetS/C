#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct LinkNode
{
	void *data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkList
{
	LinkNode head;
	int size;
}LinkList;

typedef void * LNode;
typedef void * LList;
typedef void(*FOREACH)(void *);

#ifdef __cplusplus
extern "C" {
#endif
	LList init_LinkList();
	int insert_LinkList(LList * list, int pos, void *data);
	int delete_LinkList(LList *list, int pos);
	int size_LinkList(LList *list);
	int foreach_LinkList(LList *list, FOREACH foreach);
	void * firstnode_LinkList(LList *list);
	int destory_LinkList(LList *list);

#ifdef __cplusplus
}
#endif