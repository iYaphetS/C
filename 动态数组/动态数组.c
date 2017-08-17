#include "DynamicArray.h"

typedef struct Person
{
	char name[64];
	int age;
}Person;

//��DynamicArray.h�����˴�ӡ��������ʽ���β����ͣ� ����ֵ���ͣ�
//�����������Լ���ӡ��Ӧ����
//typedef void(*myforeach)(void *);
void my_arrprint(void * data)
{
	Person * ps = (Person *)data;
	printf("name = %s age = %d\n", ps->name, ps->age);
}
void test()
{
	//��ʼ����̬���飨�����ڴ�ռ䣩
	DArray * Array = Array_init();//****
	Person p1 = { "A", 10 };
	Person p2 = { "B", 20 };
	Person p3 = { "C", 30 };
	Person p4 = { "D", 40 };
	Person p5 = { "E", 50 };

	Array_insert(Array, 0, &p1);
	Array_insert(Array, 0, &p2);
	Array_insert(Array, 0, &p3);
	Array_insert(Array, 66, &p4);
	Array_insert(Array, 0, &p5);
	Array_foreach(Array, my_arrprint);
	printf("============\n");

	Array_delete(Array, 2);
	Array_foreach(Array, my_arrprint);
	printf("============\n");
	Array_delete(Array, 3);
	Array_foreach(Array, my_arrprint);
	printf("============\n");
	Array_delete(Array, 0);
	Array_foreach(Array, my_arrprint);

	Array_destory(Array);
	Array = NULL;

}

int main()
{
	test();
	return 0;
}