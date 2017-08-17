#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DynamicArry
{
	void **pArry;
	int capacity;
	int size;
}DynamicArray;

typedef void * DArray;
typedef void(*myforeach)(void *);
//如果在c++编译器中使用此代码，告诉编译器用c编译此代码
#ifdef __cplusplus
extern "C" {
#endif
	//动态数组的初始化
	DArray  Array_init();
	//插入
	void Array_insert(DArray darray, int pos, void * data);
	//删除
	void Array_delete(DArray darray, int pos);
	//遍历
	void Array_foreach(DArray darray, myforeach foreach);
	//销毁
	void Array_destory(DArray darray);


#ifdef __cplusplus
}
#endif