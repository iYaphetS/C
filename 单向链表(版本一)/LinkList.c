#include "LinkList.h"

//LinkList申请在堆空间，节点结构体在栈区
LList LinkList_init()
{
	//因为LinkList存的是节点（不是节点指针），申请内存空间中就包含了头结点内存空间
	LinkList * linklist = (LinkList *)calloc(1, sizeof(LinkList));
	linklist->size = 0;
	linklist->head.next = NULL;
	return linklist;

}
void  LinkList_insert(LList *list, int pos, void *data)
{
	if (NULL == list || NULL == data)
	{
		return;
	}
	LinkList *List = (LinkList *)list;
	//size是链表的有效节点
	if (pos < 0 || pos > List->size - 1)
	{
		pos = List->size;
	}
	LinkNode * pCur = &List->head;//定义一个零时节点指向头结点
	//找到要插入位置的前一个节点
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	LinkNode *pNew = (LinkNode *)calloc(1, sizeof(LinkNode));
	pNew->data = data;//外部数据的地址给节点中数据指针
	pNew->next = pCur->next;
	pCur->next = pNew;

	List->size++;
}
void	 LinkList_delete(LList *list, int pos)
{
	if (NULL == list)
	{
		return;
	}
	LinkList * List = (LinkList *)list;
	if (pos < 0 || pos >= List->size)
	{
		return;
	}
	if (List->size == 0)
	{
		return;
	}
	LinkNode *pCur = &List->head;
	//删除一个元素，要找到删除的该节点的前一个节点指向要删的节点的下一个节点
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	LinkNode *ptemp = pCur->next;
	pCur->next = ptemp->next;
	free(ptemp);

	List->size--;


}
void* LinkList_searchNodeByval(LList *list, void *data, COMPARY compary)
{
	if (NULL == list || NULL == compary)
	{
		return NULL;
	}
	LinkList *List = (LinkList *)list;
	LinkNode *pCur = List->head.next;
	for (int i = 0; i < List->size; i++)
	{		
		if (compary(data, pCur->data))
		{
			//return pCur;
			break;
		}
			
		pCur = pCur->next;
	}
	if (NULL == pCur)
	{
		return NULL;
	}
	return pCur->data;
	

}
void LinkList_foreach(LList *list, FOREACH foreach)
{
	if (NULL == list || NULL == foreach)
	{
		return;
	}
	LinkList *List = (LinkList *)list;

	LinkNode *pCur = List->head.next;//头结点的next是一个指向下一个节点的指针，注意不用取地址
	while (pCur != NULL)
	{
		foreach(pCur->data);
		pCur = pCur->next;
	}
}
//逆序遍历链表
void recursion_foreach(LNode node, FOREACH foreach)
{
	if (NULL == node || NULL == foreach)
	{
		return;
	}
	LinkNode *pNode = (LinkNode *)node;
	if (NULL == pNode)
	{
		return;
	}
	recursion_foreach(pNode->next, foreach);

	foreach(pNode->data);
}

void LinkList_reverse_foreach(LList *list, FOREACH foreach)
{
	if (NULL == list || NULL == foreach)
	{
		return;
	}
	LinkList *List = (LinkList *)list;
	LinkNode *pCur = List->head.next;
	recursion_foreach(pCur, foreach);
	/*
	if (pCur == NULL)
		return;
	LinkList_inveser_foreach((LList *)pCur, foreach);
	foreach(pCur->data);
	*/
}
//冒泡排序
void LinkList_BubbleSort(LList *list, int(*compare)(void*,void*))
{
	if (NULL == list)
	{
		return;
	}
	LinkList *List = (LinkList *)list;

	LinkNode *p = NULL;
	LinkNode *q = NULL;
	//找到尾指针
	LinkNode *tail = List->head.next;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
#if 0
	for (p = List->head.next; p->next != NULL; p = p->next)
	{
		for (q = List->head.next; q != tail; q = q->next)
		{
			LinkNode *t = q->next;
			if (compare(q->data, t->data) > 0)
			{
				void *temp = NULL;
				temp = q->data;
				q->data = t->data;
				t->data = temp;
			}				 
		}
		tail = q;//第一次循环q在tail（最后一个节点）前一个节点停止，
				 //赋值给tai向前移动一个位置	
	}
#endif
	//改进
	int flag = 0;//默认没有排好
	for (p = List->head.next; p->next != NULL && flag == 0; p = p->next)
	{
		flag = 1;//设置为排好了，如果在下面的for循环中
		//循环结束条件判断都不成立，说明所有数据已经排序好了
		//外层循环已经没有必要继续
		for (q = List->head.next; q != tail; q = q->next)
		{
			LinkNode *t = q->next;
			if (compare(q->data, t->data) > 0)
			{
				flag = 0;
				void *temp = NULL;
				temp = q->data;
				q->data = t->data;
				t->data = temp;
			}
		}
		tail = q;//第一次循环q在tail（最后一个节点）前一个节点停止，
				 //赋值给tai向前移动一个位置	
	}
}
//选择排序
void LinkList_SelectionSort(LList *list, int(*compare)(void*, void*))
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == compare)
	{
		return;
	}
	LinkList *List = (LinkList *)list;
	LinkNode *p = NULL;
	LinkNode *q = NULL;
#if 0
	for (p = List->head.next; p->next != NULL; p = p->next)
	{
		for (q = p->next; q->next != NULL; q = q->next)
		{
			if (compare(p->data, q->data) > 0)
			{
				void *temp = NULL;
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
#endif
	//改进
	for (p = List->head.next; p->next != NULL; p = p->next)
	{
		LinkNode *r = p;//默认p是与后面的每个元素比较后的结果（最大，或者最小）
		for (q = p->next; q->next != NULL; q = q->next)
		{
			if (compare(p->data, q->data) > 0)
			{
				r = q;
			}
		}
		//如果内层循环结束后，r没有被重新赋值，也就没有必要交换
		if (r != p)
		{
			void *temp = NULL;
			temp = p->data;
			p->data = q->data;
			q->data = temp;
		}
	}


}
void LinkList_reverse(LList *list)
{
	if (NULL == list)
	{
		return;
	}
	LinkList *List = (LinkList *)list;
	if (List->size == 1)
	{
		return;
	}
	LinkNode *pPre = NULL;
	LinkNode *pCur = List->head.next;
	LinkNode *pNext = NULL;
	while (pCur != NULL)
	{
		pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	List->head.next = pPre;

}
void LinkList_destroy(LList *list)
{
	if(NULL == list)
	{
		return;
	}
	LinkList *List = (LinkList *)list;
	LinkNode *pCur = List->head.next;//头结点是单独存储在链表信息结构体中，所以从第一个有效节点开始删除
	LinkNode *temp = NULL;//存放要删除的节点的下一个节点
	while (pCur != NULL)
	{
		temp = pCur->next;
		free(pCur);
		pCur = NULL;
		pCur = temp;
	}
	free(List);
}