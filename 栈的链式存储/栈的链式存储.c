#include "SeqStack1.h"

typedef struct Person
{
	LinkNode node;
	char name[64];
	int age;
}Person;
void test()
{
	Stack *stack = init_Stack();

	Person p1 = { NULL, "A", 10 };
	Person p2 = { NULL, "B", 20 };
	Person p3 = { NULL, "C", 30 };
	Person p4 = { NULL, "D", 40 };
	Person p5 = { NULL, "E", 50 };

	push_Stack(stack, &p1);
	push_Stack(stack, &p2);
	push_Stack(stack, &p3);
	push_Stack(stack, &p4);
	push_Stack(stack, &p5);

	while (stack->size > 0)
	{
		Person *temp = (Person *)top_Stack(stack);
		printf("name = %s age = %d\n", temp->name, temp->age);
		pop_Stack(stack);
	}

	destory_Stack(stack);
	stack = NULL;

}
int main()
{
	test();
	return 0;
}