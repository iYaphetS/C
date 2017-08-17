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
	//�ҵ�Ҫ����ڵ��ǰһ���ڵ�
	LinkNode *pCur = &list->head;
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	//����������ָ�룬ָ���Ǽ�ȫ�����ݵĽṹ�壬���ǵ�һ����Ա��4���ֽڵ�ָ�뽫���ݽṹ�崮����
	//���ָ����ڽṹ���һ����Ա���ṹ��ĵ�ַ��data���������ָ��ĵ�ַ
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
	//�ҵ�Ҫɾ���Ľڵ��ǰһ���ڵ�
	LinkNode *pCur = &list->head;
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	//��¼Ҫɾ���Ľڵ�
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