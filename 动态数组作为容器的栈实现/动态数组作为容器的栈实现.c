#include "DynamicArray.h"
#include "SeqStack2.h"

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
	seqStack * stack = init_SeqStack();//****
	Person p1 = { "A", 10 };
	Person p2 = { "B", 20 };
	Person p3 = { "C", 30 };
	Person p4 = { "D", 40 };
	Person p5 = { "E", 50 };

	push_seqStack(stack, &p1);
	push_seqStack(stack, &p2);
	push_seqStack(stack, &p3);
	push_seqStack(stack, &p4);
	push_seqStack(stack, &p5);
	printf("============\n");

	pop_seqStack(stack);
	pop_seqStack(stack);	
	while (size_seqStack(stack) > 0)
	{
		Person *temp = (Person *)top_seqStack(stack);
		printf("name = %s age = %d\n", temp->name, temp->age);
		pop_seqStack(stack);
	}

	destory_seqStack(stack);
	stack = NULL;

}

int main()
{
	test();
	return 0;
}