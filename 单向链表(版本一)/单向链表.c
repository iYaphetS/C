#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "LinkList.h"


typedef struct Person
{
	char name[64];
	int age;
}Person;
//��������
int mycomparebyName(void *data1, void *data2)
{
	Person *d1 = (Person *)data1;
	Person *d2 = (Person *)data2;

	return strcmp(d1->name, d2->name);
}
//��������
int mycomparebyAge(void *data1, void *data2)
{
	Person *d1 = (Person *)data1;
	Person *d2 = (Person *)data2;

	if (d1->age == d2->age)
	{
		return 0;
	}
	else if (d1->age > d2->age)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void mylsit_print(void * data)
{
	if (NULL == data)
	{
		return;
	}
	Person *ps = data;
	printf("%s %d\n", ps->name, ps->age);
}
/*
int my_compary(void *data1, void *data2)
{
	int ret = 0;
	int *num = (int *)data1;
	Person *ps2 = data2;
	if (*num == ps2->age)
	{
		ret = 0;
	}
	else
	{
		ret = -1;
	}
	return ret;
}
*/
bool my_compary(void *data1, void *data2)
{	
	Person *ps1 = data1;
	Person *ps2 = data2;
	
	return strcmp(ps1->name, ps2->name) == 0 && ps1->age == ps2->age;
			
}
void test()
{
	//������Ϣ�ĳ�ʼ����Ϊ������ڴ�ռ䣩
	LList * mylist = LinkList_init();

	Person p1 = { "A", 10 };
	Person p2 = { "B", 20 };
	Person p3 = { "C", 30 };
	Person p4 = { "D", 40 };
	Person p5 = { "F", 50 };

	LinkList_insert(mylist, 0, &p1);//10
	LinkList_insert(mylist, 0, &p2);//20 10
	LinkList_insert(mylist, 0, &p3);//30 20 10
	LinkList_insert(mylist, 3, &p4);//30 20 10 40
	LinkList_insert(mylist, 0, &p5);//50 30 20 10 40
	printf("======����======\n");
	LinkList_foreach(mylist, mylsit_print);
	printf("======�������======\n");
	LinkList_reverse_foreach(mylist, mylsit_print);
	printf("=======����=====\n");
	LinkList_reverse(mylist);
	LinkList_foreach(mylist, mylsit_print);
	printf("======��������======\n");
	LinkList_BubbleSort(mylist, mycomparebyName);
	LinkList_foreach(mylist, mylsit_print);
	printf("======��������======\n");
	LinkList_SelectionSort(mylist, mycomparebyAge);
	LinkList_foreach(mylist, mylsit_print);
	/*
	{
		mylsit_print(pnode->data);
	int a = 10;//д��void *��10------�������----����д������10�����ڴ��޷�����
	void *p = &a;
	LinkNode * pnode = LinkList_searchNodeByval(mylist, p, my_compary);
	if (NULL != pnode)
	}
	*/
	printf("======���ҽڵ�======\n");
	Person p6 = { "G", 50 };
	Person *ret = (Person *)LinkList_searchNodeByval(mylist, &p6, my_compary);
	if (ret != NULL)
	{
		printf("name = %s age = %d\n", ret->name, ret->age);
	}	
	printf("======ɾ���ڵ�======\n");
	LinkList_delete(mylist, 0);
	LinkList_foreach(mylist, mylsit_print);
	printf("======ɾ���ڵ�======\n");
	LinkList_delete(mylist, 2);
	LinkList_foreach(mylist, mylsit_print);
	printf("=======ɾ���ڵ�=====\n");
	LinkList_delete(mylist, 6);
	LinkList_foreach(mylist, mylsit_print);
	printf("======ɾ���ڵ�======\n");
	LinkList_delete(mylist, 0);
	LinkList_foreach(mylist, mylsit_print);
	printf("=======��������=====\n");
	LinkList_destroy(mylist);

}
int main()
{
	test();
	return 0;
}