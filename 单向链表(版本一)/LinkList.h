#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//�ڵ�������Ϣ
typedef struct LinkNode
{
	void *data;//������ݵ��׵�ַ
	struct LinkNode * next;
}LinkNode;

//�����������Ϣ
typedef struct LinkList
{
	LinkNode head;//�õ�ͷ�ڵ���õ�����������
	//�붯̬���鲻ͬ��������Ҫvoid **p������������void *��ÿ�����ݵ��׵�ַ������ĵ�ַ
	//�����õ������������Ϣ��������ֻ��Ҫͷ���
	int size;//������ЧԪ�صĸ���
}LinkList;

typedef void * LList;

typedef void * LNode;

typedef void(*FOREACH)(void *data);
typedef bool(*COMPARY)(void *data1, void *data2);
#ifdef __cplusplus
extern "C" {
#endif
	//����ĳ�ʼ��
	LList LinkList_init();
	//�ڵ����
	void  LinkList_insert(LList *list, int pos, void *data);
	//Ԫ��ɾ��
	void LinkList_delete(LList *list, int pos);
	//�������
	void LinkList_foreach(LList *list, FOREACH foreach);
	//�����������recursion_foreach�������ݹ�����ڵ㣩
	void LinkList_reverse_foreach(LList *list, FOREACH foreach);
	//���������
	void LinkList_destroy(LList *list);
	//�������ݲ��ҽڵ�
	void* LinkList_searchNodeByval(LList *list, void *data, COMPARY compary);
	//�ݹ����
	void recursion_foreach(LNode node, FOREACH foreach);
	//ð������
	void LinkList_BubbleSort(LList *list, int(*compare)(void*, void*));
	//ѡ������
	void LinkList_SelectionSort(LList *list, int(*compare)(void*, void*));
	//��������
	void LinkList_reverse(LList *list);


#ifdef __cplusplus
}
#endif




