#include "DynamicArray.h"

//动态数组的初始化
DArray  Array_init()
{
	DynamicArray * dArray = calloc(1, sizeof(DynamicArray));
	dArray->capacity = 5;
	dArray->size = 0;
	dArray->pArry = calloc(dArray->capacity, sizeof(void *));
	return dArray;
}
//插入
void Array_insert(DArray darray, int pos, void * data)
{
	if (NULL == darray || NULL == data)
	{
		return;
	}
	DynamicArray * dArray = (DynamicArray *)darray;
	if (dArray->size == dArray->capacity)
	{
		int newcapacity = dArray->capacity * 2;
		void **newspace = calloc(newcapacity, sizeof(void *));//****
		memcpy(newspace, dArray->pArry, sizeof(void *) * dArray->capacity);
		free(dArray->pArry);
		dArray->capacity = newcapacity;
		dArray->pArry = newspace;
	}
	if (pos < 0 || pos > dArray->size - 1)
	{
		pos = dArray->size;
	}
	//pos从0开始计算， size是元素的个数， capacity是最大能容纳元素的个数
	for (int i = dArray->size - 1; i >= pos; i--)
	{
		dArray->pArry[i + 1] = dArray->pArry[i];
	}
	dArray->pArry[pos] = data;
	dArray->size++;
}
//删除
void Array_delete(DArray darray, int pos)
{
	if (NULL == darray)
	{
		return;
	}
	DynamicArray *dArray = (DynamicArray *)darray;
	if (pos < 0 || pos > dArray->size - 1)
	{
		pos = dArray->size;
	}
	//dArray->size - 1是数组的最后一个元素，删除最后一个元素是直接将数组长度-1即可
	for (int i = pos; i < dArray->size - 1; i++)
	{
		dArray->pArry[i] = dArray->pArry[i + 1];
	}
	dArray->size--;
}
//遍历
void Array_foreach(DArray darray, myforeach foreach)
{
	if (NULL == darray || NULL == foreach)
	{
		return;
	}
	DynamicArray *dArray = (DynamicArray *)darray;

	for (int i = 0; i < dArray->size; i++)
	{
		foreach(dArray->pArry[i]);
	}

}
//销毁
void Array_destory(DArray darray)
{
	if (NULL == darray)
	{
		return;
	}
	DynamicArray *dArray = (DynamicArray *)darray;

	free(dArray->pArry);
	dArray->pArry = NULL;
	free(dArray); 

}