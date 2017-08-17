#include "SeqQueue.h"

typedef struct Person
{
	char name[64];
	int age;
}Person;
void test()
{
	int ret = 0;
	SqeQueue sque = NULL;
	ret = init_SqeQueue(&sque);
	if (ret < 0)
	{
		printf("func init_SqeQueue err:%d\n", ret);
	}
	Person p1 = { "A", 10 };
	Person p2 = { "B", 20 };
	Person p3 = { "C", 30 };
	Person p4 = { "D", 40 };
	ret = push_SqeQueue(sque, &p1);
	if (ret < 0)
	{
		printf("func push_SqeQueue err:%d\n", ret);
	}
	push_SqeQueue(sque, &p2);
	push_SqeQueue(sque, &p3);
	push_SqeQueue(sque, &p4);

	Person *t1 = (Person *)fornt_SqeQueue(sque);
	printf("name = %s age = %d\n", t1->name, t1->age);
	Person *t2 = (Person *)back_SqeQueue(sque);
	printf("name = %s age = %d\n", t2->name, t2->age);
	printf("=============\n");
	while(size_SqeQueue(sque))
	{
		Person *t = (Person *)fornt_SqeQueue(sque);
		printf("name = %s age = %d\n", t->name, t->age);
		ret = pop_SqeQueue(sque);
		if (ret < 0)
		{
			printf("func pop_SqeQueue err:%d\n", ret);
		}
	}	
	ret = destory_SqeQueue(sque);
	if (ret < 0)
	{
		printf("func destory_SqeQueue err:%d\n", ret);
	}
	printf("³É¹¦\n");
}
int main()
{
	test();
	return 0;
}