#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ջ����ʽ�洢
typedef struct LinkNode
{
	struct LinkNode *next;
}LinkNode;

typedef struct Stack
{
	LinkNode head;
	int size;
}Stack;

#ifdef __cplusplus
extern "C" {
#endif
	//����ĳ�ʼ��
	Stack *init_Stack();
	void push_Stack(Stack *stack, void *data);
	void pop_Stack(Stack *stack);
	void* top_Stack(Stack *stack);
	int size_Stack(Stack *stack);
	void destory_Stack(Stack *stack);

#ifdef __cplusplus
}
#endif