#include "LinkList.h"

LinkList *init_LinkList()
{
	LinkList *list = (LinkList *)calloc(1, sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}
void insert_LinkList(LinkList *list, int pos, void *data)
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	if (pos < 0 || pos > list->size - 1)
	{
		pos = list->size;
	}
	//找到要插入节点的前一个节点
	LinkNode *pCur = &list->head;
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	//传来的数据指针，指向不是简单全是数据的结构体，而是第一个成员是4个字节的指针将数据结构体串起来
	//这个指针放在结构体第一个成员，结构体的地址（data）就是这个指针的地址
	LinkNode *newnode = (LinkNode *)data;
	newnode->next = pCur->next;
	pCur->next = newnode;
	list->size++;
}
void remove_LinkList(LinkList *list, int pos)
{
	if (NULL == list)
	{
		return;
	}
	if (pos < 0 || pos > list->size - 1)
	{
		pos = list->size;
	}
	//找到要删除的节点的前一个节点
	LinkNode *pCur = &list->head;
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	//记录要删除的节点
	LinkNode *pDel = pCur->next;
	pCur->next = pDel->next;
	list->size--;
}
void foreach_LinkList(LinkList *list, void(*foreach)(void *))
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == foreach)
	{
		return;
	}
	LinkNode *pCur = list->head.next;
	while (pCur != NULL)
	{
		foreach(pCur);
		pCur = pCur->next;
	}
}
void reveser_LinkList(LinkList *list)
{
	if (NULL == list)
	{
		return;	
	}
	if (list->size < 2)
	{
		return;
	}
	LinkNode *p = list->head.next;
	LinkNode *q = p->next;
	LinkNode *t = NULL;
	while (q != NULL)
	{
		t = q->next;
		q->next = p;
		p = q;
		q = t;
	}
	list->head.next->next = NULL;
	list->head.next = p;
}

void destory_LinkList(LinkList *list)
{
	if (NULL == list)
	{
		return;
	}
	free(list);
}