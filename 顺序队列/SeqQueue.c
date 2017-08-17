#include "SeqQueue.h"
//˳����еĳ�ʼ��
int init_SqeQueue(SqeQueue * squeue)
{
	if (NULL == squeue)
	{
		return -1;
	}
	SQueue * queue = calloc(1, sizeof(SQueue));
	if (NULL == queue)//�ڴ����ʧ��
	{
		return -2;
	}
	memset(queue->data, 0, sizeof(void *) * MAXSIZE);
	queue->size = 0;
	*squeue = queue;
	return 0;
}
//���
int push_SqeQueue(SqeQueue queue, void *data)
{
	if (NULL == queue)
	{
		return -1;
	}
	if (NULL == data)
	{
		return -2;
	}
	SQueue *sque = (SQueue *)queue;
	if (sque->size == MAXSIZE)
	{
		return -3;
	}
	sque->data[sque->size] = data;
	sque->size++;
	return 0;
}
//����
int pop_SqeQueue(SqeQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}
	SQueue *sque = (SQueue *)queue;
	if (sque->size == 0)
	{
		return -2;
	}
	for (int i = 0; i < sque->size; i++)
	{
		sque->data[i] = sque->data[i + 1];
	}
	sque->size--;
	return 0;

}
//��ö�ͷԪ��
void* fornt_SqeQueue(SqeQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}
	SQueue *sque = (SQueue *)queue;
	return sque->data[0];
}
//��ö�βԪ��
void* back_SqeQueue(SqeQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}
	SQueue *sque = (SQueue *)queue;
	return sque->data[sque->size - 1];
}
//��ö��д�С
int size_SqeQueue(SqeQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}
	SQueue *sque = (SQueue *)queue;
	return sque->size;
}
//���ٶ���
int destory_SqeQueue(SqeQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}
	SQueue *sque = (SQueue *)queue;
	free(sque);
	return 0;
}