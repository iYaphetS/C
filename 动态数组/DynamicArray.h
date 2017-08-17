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
//�����c++��������ʹ�ô˴��룬���߱�������c����˴���
#ifdef __cplusplus
extern "C" {
#endif
	//��̬����ĳ�ʼ��
	DArray  Array_init();
	//����
	void Array_insert(DArray darray, int pos, void * data);
	//ɾ��
	void Array_delete(DArray darray, int pos);
	//����
	void Array_foreach(DArray darray, myforeach foreach);
	//����
	void Array_destory(DArray darray);


#ifdef __cplusplus
}
#endif