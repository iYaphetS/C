#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024
//栈的信息
typedef struct SeqStack
{
	void *data[MAXSIZE];
	int size;
}SeqStack;

typedef void* Stack;

#ifdef __cplusplus
extern "C"{
#endif
	//栈的初始化
	Stack init_Stack();
	//压栈
	void push_Stack(Stack stack, void *data);
	//出栈
	void pop_Stack(Stack stack);
	//从栈顶弹出元素
	void* top_Stack(Stack stack);
	//获得栈元素的个数
	int size_Stack(Stack stack);
	//销毁栈
	void destroy_Stack(Stack stack);

#ifdef __cplusplus
}
#endif // __cpluscplus
