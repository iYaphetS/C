#include "DynamicArray.h"

typedef struct Person
{
	char name[64];
	int age;
}Person;

//在DynamicArray.h定义了打印函数的形式（形参类型， 返回值类型）
//在主函数中自己打印相应数据
//typedef void(*myforeach)(void *);
void my_arrprint(void * data)
{
	Person * ps = (Person *)data;
	printf("name = %s age = %d\n", ps->name, ps->age);
}
void test()
{
	//初始化动态数组（分配内存空间）
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