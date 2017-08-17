#include "LinkQueue.h"
//��ʽ���еĳ�ʼ��
int init_LinkQueue(LinkQueue *lqueue)
{
	if (NULL == lqueue)
	{
		return -1;
	}
	LQueue *queue = (LQueue *)calloc(1, sizeof(LQueue));
	if (NULL == queue)
	{
		return -2;
	}
	queue->head.next = NULL;
	queue->size = 0;
	queue->rear = &queue->head;
	*lqueue = queue;
	return 0;
}
//���
int push_LinkQueue(LinkQueue lqueue, void *data)
{
	if (NULL == lqueue)
	{
		return -1;
	}
	if (NULL == data)
	{
		return -2;
	}
	LQueue * queue = (LQueue *)lqueue;
	LNode * newNode = (LNode *)data;
	queue->rear->next = newNode;
	queue->rear = newNode;
	newNode->next = NULL;
	queue->size++;
	return 0;
}
//����
int pop_LinkQueue(LinkQueue lqueue)
{
	if (NULL == lqueue)
	{
		return -1;
	}
	LQueue * queue = (LQueue *)lqueue;
	if (queue->size == 0)
	{
		return 0;
	}
	if (queue->size == 1)//��ֻ��һ���ڵ��ʱ�򣬳��ӣ��ᵼ�¶�βָ��仯
	{
		LNode *pDel = queue->head.next;
		queue->rear = &queue->head;
		queue->size--;
	}
	//��ֻ��һ���ڵ㣬��βָ��ָ������ڵ㣬ɾ���󣬸ýڵ㲻���ڣ�ָ���Ҫ�ı���	
	LNode *pDel = queue->head.next;//����Ҫɾ���Ľڵ����һ���ڵ�
	queue->head.next = pDel->next;
	queue->size--;

}
//��ö�ͷԪ��
LinkNode front_LinkQueue(LinkQueue lqueue)
{
	if (NULL == lqueue)
	{
		return NULL;
	}
	LQueue * queue = (LQueue *)lqueue;
	return queue->head.next;
}
//��ö�βԪ��
LinkNode back_LinkQueue(LinkQueue lqueue)
{
	if (NULL == lqueue)
	{
		return NULL;
	}
	LQueue * queue = (LQueue *)lqueue;
	return queue->rear;
}
//�ӵĴ�С
int size_LinkQueue(LinkQueue lqueue)
{
	if (NULL == lqueue)
	{
		return NULL;
	}
	LQueue * queue = (LQueue *)lqueue;
	return queue->size;
}
//�ӵ�����
int destory_LinkQueue(LinkQueue lqueue)
{
	if (NULL == lqueue)
	{
		return -1;
	}
	LQueue * queue = (LQueue *)lqueue;
	free(queue);
	return 0;
}