#include "SeqStack.h"

typedef struct Person
{
	char name[64];
	int age;
}Person;

void test()
{
	Stack stack = init_Stack();
	Person p1 = { "A", 10 };
	Person p2 = { "B", 20 };
	Person p3 = { "C", 30 };
	Person p4 = { "D", 40 };
	Person p5 = { "E", 50 };

	push_Stack(stack, &p1);
	push_Stack(stack, &p2);
	push_Stack(stack, &p3);
	push_Stack(stack, &p4);
	push_Stack(stack, &p5);

	while (stack->size > 0)//或者size_Stack(stack) > 0
	{
		Person *temp = (Person *)top_Stack(stack);
		printf("name = %s, age = %d\n", temp->name, temp->age);
		pop_Stack(stack);
	}
	destroy_Stack(stack);
	stack = NULL;
}
int main()
{
	test();
	return 0;
}