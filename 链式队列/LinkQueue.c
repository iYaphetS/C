#include "LinkQueue.h"
//链式队列的初始化
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
//入队
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
//出队
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
	if (queue->size == 1)//当只有一个节点的时候，出队，会导致队尾指针变化
	{
		LNode *pDel = queue->head.next;
		queue->rear = &queue->head;
		queue->size--;
	}
	//当只有一个节点，队尾指针指向这个节点，删除后，该节点不存在，指向就要改变了	
	LNode *pDel = queue->head.next;//缓存要删除的节点的下一个节点
	queue->head.next = pDel->next;
	queue->size--;

}
//获得对头元素
LinkNode front_LinkQueue(LinkQueue lqueue)
{
	if (NULL == lqueue)
	{
		return NULL;
	}
	LQueue * queue = (LQueue *)lqueue;
	return queue->head.next;
}
//获得队尾元素
LinkNode back_LinkQueue(LinkQueue lqueue)
{
	if (NULL == lqueue)
	{
		return NULL;
	}
	LQueue * queue = (LQueue *)lqueue;
	return queue->rear;
}
//队的大小
int size_LinkQueue(LinkQueue lqueue)
{
	if (NULL == lqueue)
	{
		return NULL;
	}
	LQueue * queue = (LQueue *)lqueue;
	return queue->size;
}
//队的销毁
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