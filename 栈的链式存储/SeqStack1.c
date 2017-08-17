#include "SeqStack1.h"
//把链表的尾部当成栈顶(尾部增删)
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
	//找到指向栈顶指针
	LinkNode *pCur = &stack->head;
	for(int i = 0; i < stack->size; i++)
	{
		pCur = pCur->next;
	}
	LinkNode *pNew = (LinkNode *)data;//元素指针强转成LinkNode*指针
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
	//找到指向栈顶的前一个节点的指针
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
	//找到指向栈顶元素的指针
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