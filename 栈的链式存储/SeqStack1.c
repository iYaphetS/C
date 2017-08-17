#include "SeqStack1.h"
//�������β������ջ��(β����ɾ)
Stack *init_Stack()
{
	Stack *stack = calloc(1, sizeof(Stack));
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}
void push_Stack(Stack *stack, void *data)
{
	if (NULL == stack)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}	
	//�ҵ�ָ��ջ��ָ��
	LinkNode *pCur = &stack->head;
	for(int i = 0; i < stack->size; i++)
	{
		pCur = pCur->next;
	}
	LinkNode *pNew = (LinkNode *)data;//Ԫ��ָ��ǿת��LinkNode*ָ��
	pCur->next = pNew;
	stack->size++;
}
void pop_Stack(Stack *stack)
{
	if (NULL == stack)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	/*LinkNode *pCur = &stack->head;
	//�ҵ�ָ��ջ����ǰһ���ڵ��ָ��
	for (int i = 0; i < stack->size - 1; i++)
	{
		pCur = pCur->next;
	}
	pCur->next = NULL;*/
	stack->size--;

}
void* top_Stack(Stack *stack)
{
	if (NULL == stack)
	{
		return NULL;
	}
	//�ҵ�ָ��ջ��Ԫ�ص�ָ��
	LinkNode *pCur = &stack->head;
	for(int i = 0; i < stack->size; i++)
	{
		pCur = pCur->next;
	}
	return pCur;
}


int size_Stack(Stack *stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	return stack->size;
}
void destory_Stack(Stack *stack)
{
	if (NULL == stack)
	{
		return;
	}
	free(stack);
}