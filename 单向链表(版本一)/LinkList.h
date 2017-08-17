#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//节点数据信息
typedef struct LinkNode
{
	void *data;//存放数据的首地址
	struct LinkNode * next;
}LinkNode;

//链表整体的信息
typedef struct LinkList
{
	LinkNode head;//拿到头节点就拿到了整个链表
	//与动态数组不同，数组需要void **p存放连续多个的void *（每个数据的首地址）数组的地址
	//才能拿到整个数组的信息，而链表只需要头结点
	int size;//链表有效元素的个数
}LinkList;

typedef void * LList;

typedef void * LNode;

typedef void(*FOREACH)(void *data);
typedef bool(*COMPARY)(void *data1, void *data2);
#ifdef __cplusplus
extern "C" {
#endif
	//链表的初始化
	LList LinkList_init();
	//节点插入
	void  LinkList_insert(LList *list, int pos, void *data);
	//元素删除
	void LinkList_delete(LList *list, int pos);
	//链表遍历
	void LinkList_foreach(LList *list, FOREACH foreach);
	//逆序遍历调用recursion_foreach函数（递归遍历节点）
	void LinkList_reverse_foreach(LList *list, FOREACH foreach);
	//链表的销毁
	void LinkList_destroy(LList *list);
	//根据数据查找节点
	void* LinkList_searchNodeByval(LList *list, void *data, COMPARY compary);
	//递归遍历
	void recursion_foreach(LNode node, FOREACH foreach);
	//冒泡排序
	void LinkList_BubbleSort(LList *list, int(*compare)(void*, void*));
	//选择排序
	void LinkList_SelectionSort(LList *list, int(*compare)(void*, void*));
	//链表逆序
	void LinkList_reverse(LList *list);


#ifdef __cplusplus
}
#endif




