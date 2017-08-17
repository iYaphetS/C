#pragma once 

#include <stdlib.h>
//����ڵ����Ϣ
typedef struct LinkNode
{
	struct LinkNode *next;
}LinkNode;

//�������Ϣ
typedef struct LinkList
{
	LinkNode head;
	int size;
}LinkList;

//�ɶ�linklist�������ݱ��ܷ�װ typedef void * LinkList
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


