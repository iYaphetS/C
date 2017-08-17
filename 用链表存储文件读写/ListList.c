#include "LinkList.h"
LList init_LinkList()
{
	LinkList *list = (LinkList *)calloc(1, sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}
int insert_LinkList(LList * list, int pos, void *data)
{
	if (NULL == list)
	{
		return -1;
	}
	LinkList *List = (LinkList *)list;
	if (pos < 0 || pos > List->size - 1)
	{
		pos = List->size;
	}

	//找到要插入位置的前一个节点
	LinkNode *pCur = &List->head;
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	
	LinkNode * NewNode = (LinkNode *)calloc(1, sizeof(LinkNode));
	NewNode->data = data;

	NewNode->next = pCur->next;
	pCur->next = NewNode;
	List->size++;
	return 0;
}
int delete_LinkList(LList *list, int pos)
{
	if (NULL == list)
	{
		return -1;
	}
	LinkList *List = (LinkList *)list;

	if (pos < 0 || pos > List->size - 1)
	{
		return -2;
	}
	if (List->size == 0)
	{
		return 0;
	}
	LinkNode *pCur = &List->head;
	//找到要删除的节点的上一个节点
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	LinkNode *pDel = pCur->next;
	//由于节点结构体中数据指针data是指向用户创建的堆空间
	//所以在释放节点前要将data指向的堆空间也要是释放，不然内存泄漏
	free(pDel->data);
	pDel->data = NULL;

	pCur->next = pDel->next;
	free(pDel);
	List->size--;
	return 0;
}
int size_LinkList(LList *list)
{
	if (NULL == list)
	{
		return -1;
	}
	LinkList *List = (LinkList *)list;
	
	return List->size;
}
int foreach_LinkList(LList *list, FOREACH foreach)
{
	if (NULL == list)
	{
		return -1;
	}
	LinkList *List = (LinkList *)list;
	LinkNode *pCur = List->head.next;
	while (pCur != NULL)
	{
		foreach(pCur->data);
		pCur = pCur->next;
	}
	return 0;
}
void* firstnode_LinkList(LList *list)
{
	if (NULL == list)
	{
		return NULL;
	}
	LinkList *List = (LinkList *)list;
	LinkNode *pCur = List->head.next;

	return pCur->data;
}

int destory_LinkList(LList *list)
{
	if (NULL == list)
	{
		return -1;
	}
	LinkList *List = (LinkList *)list;
	LinkNode *pCur = List->head.next;//头结点在链表的信息结构体中，不要多次释放
	while (pCur != NULL)
	{
		LinkNode *temp = pCur->next;
		free(pCur->data);
		pCur->data = NULL;
		free(pCur);
		pCur = NULL;
		pCur = temp;
	}
	free(List);

	return 0;
}