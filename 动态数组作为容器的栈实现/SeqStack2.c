#include "SeqStack2.h"
seqStack * init_SeqStack()
{
	return Array_init();
}
void push_seqStack(seqStack *stack, void *data)
{
	Array_insert(stack, 0, data);
}

void pop_seqStack(seqStack *stack)
{
	Array_delete(stack, 0);
}

void* top_seqStack(seqStack *stack)
{
	Stack *seqstack = (Stack *)stack;
	return seqstack->pArry[0];
	
}

int size_seqStack(seqStack *stack)
{
	Stack *seqstack = (Stack *)stack;
	return seqstack->size;
}
void destory_seqStack(seqStack *stack)
{
	Array_destory(stack);
}