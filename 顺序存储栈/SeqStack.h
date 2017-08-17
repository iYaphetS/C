#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024
//ջ����Ϣ
typedef struct SeqStack
{
	void *data[MAXSIZE];
	int size;
}SeqStack;

typedef void* Stack;

#ifdef __cplusplus
extern "C"{
#endif
	//ջ�ĳ�ʼ��
	Stack init_Stack();
	//ѹջ
	void push_Stack(Stack stack, void *data);
	//��ջ
	void pop_Stack(Stack stack);
	//��ջ������Ԫ��
	void* top_Stack(Stack stack);
	//���ջԪ�صĸ���
	int size_Stack(Stack stack);
	//����ջ
	void destroy_Stack(Stack stack);

#ifdef __cplusplus
}
#endif // __cpluscplus
