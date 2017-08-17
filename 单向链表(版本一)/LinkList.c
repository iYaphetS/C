#include "LinkList.h"

//LinkList�����ڶѿռ䣬�ڵ�ṹ����ջ��
LList LinkList_init()
{
	//��ΪLinkList����ǽڵ㣨���ǽڵ�ָ�룩�������ڴ�ռ��оͰ�����ͷ����ڴ�ռ�
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
	//size���������Ч�ڵ�
	if (pos < 0 || pos > List->size - 1)
	{
		pos = List->size;
	}
	LinkNode * pCur = &List->head;//����һ����ʱ�ڵ�ָ��ͷ���
	//�ҵ�Ҫ����λ�õ�ǰһ���ڵ�
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	LinkNode *pNew = (LinkNode *)calloc(1, sizeof(LinkNode));
	pNew->data = data;//�ⲿ���ݵĵ�ַ���ڵ�������ָ��
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
	//ɾ��һ��Ԫ�أ�Ҫ�ҵ�ɾ���ĸýڵ��ǰһ���ڵ�ָ��Ҫɾ�Ľڵ����һ���ڵ�
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

	LinkNode *pCur = List->head.next;//ͷ����next��һ��ָ����һ���ڵ��ָ�룬ע�ⲻ��ȡ��ַ
	while (pCur != NULL)
	{
		foreach(pCur->data);
		pCur = pCur->next;
	}
}
//�����������
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
//ð������
void LinkList_BubbleSort(LList *list, int(*compare)(void*,void*))
{
	if (NULL == list)
	{
		return;
	}
	LinkList *List = (LinkList *)list;

	LinkNode *p = NULL;
	LinkNode *q = NULL;
	//�ҵ�βָ��
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
		tail = q;//��һ��ѭ��q��tail�����һ���ڵ㣩ǰһ���ڵ�ֹͣ��
				 //��ֵ��tai��ǰ�ƶ�һ��λ��	
	}
#endif
	//�Ľ�
	int flag = 0;//Ĭ��û���ź�
	for (p = List->head.next; p->next != NULL && flag == 0; p = p->next)
	{
		flag = 1;//����Ϊ�ź��ˣ�����������forѭ����
		//ѭ�����������ж϶���������˵�����������Ѿ��������
		//���ѭ���Ѿ�û�б�Ҫ����
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
		tail = q;//��һ��ѭ��q��tail�����һ���ڵ㣩ǰһ���ڵ�ֹͣ��
				 //��ֵ��tai��ǰ�ƶ�һ��λ��	
	}
}
//ѡ������
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
	//�Ľ�
	for (p = List->head.next; p->next != NULL; p = p->next)
	{
		LinkNode *r = p;//Ĭ��p��������ÿ��Ԫ�رȽϺ�Ľ������󣬻�����С��
		for (q = p->next; q->next != NULL; q = q->next)
		{
			if (compare(p->data, q->data) > 0)
			{
				r = q;
			}
		}
		//����ڲ�ѭ��������rû�б����¸�ֵ��Ҳ��û�б�Ҫ����
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
	LinkNode *pCur = List->head.next;//ͷ����ǵ����洢��������Ϣ�ṹ���У����Դӵ�һ����Ч�ڵ㿪ʼɾ��
	LinkNode *temp = NULL;//���Ҫɾ���Ľڵ����һ���ڵ�
	while (pCur != NULL)
	{
		temp = pCur->next;
		free(pCur);
		pCur = NULL;
		pCur = temp;
	}
	free(List);
}