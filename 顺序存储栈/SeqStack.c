#include "SeqStack.h"
//栈的初始化
Stack init_Stack()
{
	SeqStack *stack = (SeqStack *)calloc(1, sizeof(SeqStack));
	memset(stack, 0, MAXSIZE * sizeof(void *));
	stack->size = 0;
	return stack;
}
//压栈
void push_Stack(Stack stack, void *data)
{
	if (NULL == stack)
	{
		return;
	}
	if (NULL == data)
	{
		return;	
	}
	SeqStack *seqstack = (SeqStack *)stack;
	if (seqstack->size == MAXSIZE)
	{
		return;
	}
	seqstack->data[seqstack->size] = data;
	seqstack->size++;
}
//出栈
void pop_Stack(Stack *stack)
{
	if (NULL == stack)
	{
		return;
	}
	SeqStack *seqstack = (SeqStack *)stack;
	if (seqstack->size == 0)
	{
		return;
	}
	seqstack->size--;
}
//从栈顶弹出元素
void* top_Stack(Stack *stack)
{
	if (NULL == stack)
	{
		return NULL;
	}
	SeqStack *seqstack = (SeqStack *)stack;

	if (seqstack->size == 0)
	{
		return NULL;
	}
	return seqstack->data[seqstack->size - 1];
}
//获得栈元素的个数
int size_Stack(Stack *stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	SeqStack *seqstack = (SeqStack *)stack;

	return seqstack->size;
}
//销毁栈
void destroy_Stack(Stack stack)
{
	if (NULL == stack)
	{
		return;
	}
	SeqStack *seqstack = (SeqStack *)stack;

	free(seqstack);
}