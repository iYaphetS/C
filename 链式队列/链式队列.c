#include "LinkQueue.h"

typedef struct Person
{
	LNode node;
	char name[64];
	int age;
}Person;
void test()
{
	int ret = 0;
	LinkQueue  queue = NULL;
	ret = init_LinkQueue(&queue);
	if (ret < 0)
	{
		printf("func init_LinkQueue err:%d\n", ret);
		return;
	}
	Person p1 = { NULL, "A", 10 };
	Person p2 = { NULL, "B", 20 };
	Person p3 = { NULL, "C", 30 };
	Person p4 = { NULL, "D", 40 };
	ret = push_LinkQueue(queue, &p1);
	if (ret < 0)
	{
		printf("func push_LinkQueue err:%d\n", ret);
	}
	push_LinkQueue(queue, &p2);
	push_LinkQueue(queue, &p3);
	push_LinkQueue(queue, &p4);
	Person *f = (Person *)front_LinkQueue(queue);
	printf("对头：name = %s age = %d\n", f->name, f->age);
	Person *b = (Person *)back_LinkQueue(queue);
	printf("队尾：name = %s age = %d\n", b->name, b->age);

	while (size_LinkQueue(queue) > 0)
	{
		Person *t = (Person *)front_LinkQueue(queue);
		printf("name = %s age = %d\n", t->name, t->age);
		pop_LinkQueue(queue);
	}
	ret = destory_LinkQueue(queue);
	if (ret < 0)
	{
		printf("func destory_LinkQueue err:%d\n", ret);
	}
	queue = NULL;
	printf("成功\n");
}
int main()
{
	test();
	return 0;
}