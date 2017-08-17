#include <stdio.h>

#include "LinkList.h"

typedef struct Person
{
	LinkNode node;
	char name[64];
	int age;
}Person;

void my_foreach(void *data)
{
	Person *ps = (Person *)data;
	printf("name = %s age = %d\n", ps->name, ps->age);
}
void test()
{
	LinkList *list = init_LinkList();

	Person p1 = { NULL, "A", 10 };
	Person p2 = { NULL, "B", 20 };
	Person p3 = { NULL, "C", 30 };
	Person p4 = { NULL, "D", 40 };
	Person p5 = { NULL, "F", 50 };

	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 0, &p3);
	insert_LinkList(list, 0, &p4);
	insert_LinkList(list, 0, &p5);

	foreach_LinkList(list, my_foreach);
	printf("===============\n");
	reveser_LinkList(list);
	foreach_LinkList(list, my_foreach);
	printf("===============\n");
	remove_LinkList(list, 0);
	foreach_LinkList(list, my_foreach);
	printf("===============\n");
	remove_LinkList(list, 0);
	foreach_LinkList(list, my_foreach);
	printf("===============\n");
	remove_LinkList(list, 0);
	foreach_LinkList(list, my_foreach);
	printf("===============\n");

	destory_LinkList(list);


}
int main()
{
	test();
	return 0;
}