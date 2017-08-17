#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node
{
	int data;
	struct node * next;
}Node, * pNode;

pNode SListCreat()
{
	pNode phead = NULL;

	phead = (pNode)malloc(sizeof(Node));
	if (phead == NULL)
		return NULL;
	pNode pCur = phead;//由于头节点是不动的，pCur只是一个辅助的节点指针变量
	pNode pNew = NULL;
	int num = 0;

	while (1)
	{
		printf("请输入数据：");
		scanf("%d", &num);
		if (num < 0)
			break;
		pNew = (pNode)malloc(sizeof(Node));
		if (pNew == NULL)
			break;
		pNew->data = num;
		
		//千万不要这样写pNew = pCur->next;
		//本来pNew分配了堆空间，这样改变pNew指向，成了一个野指针
		pCur->next = pNew;//建立pcur和pnew之间的关系
		pNew->next = NULL;
		pCur = pNew;

	}
	return phead;

}
int SListPrint(pNode phead)
{
	if (phead == NULL)
		return -1;
	pNode tmp = phead->next;

	printf("phead->");
	while (tmp != NULL)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");

	return 0;
}
//在数据等于x的第一个节点前面插入一个数据为y的节点,如果没有就在尾部插入
int SListNodeInsert(pNode phead, int x, int y)
{
	if (phead == NULL)
		return -1;
	pNode pPre = phead;
	pNode pCur = phead->next;
	pNode pNew = (pNode)malloc(sizeof(Node));

	if (pNew == NULL)
		return -2;
	
	while (pCur != NULL)
	{
		if (pCur->data == x)			
			break;
		pPre = pPre->next;//指向改变，向下一个节点移动
		pCur = pCur->next;
	}
		
	pNew->data = y;
	pPre->next = pNew;
	pNew->next = pCur;

	return 0;
}
//*********用一种后插法实现元素的前插和后插
int SListNodeInsert_pro(pNode phead, int x, int y)
{
	if (phead == NULL)
		return -1;
	pNode pPre = phead;
	pNode pCur = phead->next;
	pNode pNew = (pNode)malloc(sizeof(Node));

	if (pNew == NULL)
		return -2;

	while (pCur != NULL)
	{
		if (pCur->data == x)
			break;
		pPre = pPre->next;//指向改变，向下一个节点移动
		pCur = pCur->next;
	}

	pNew->data = y;
	pNew->next = pCur->next;
	pCur->next = pNew;
	//前插元素，交换数据（相当于交换了当前节点与新节点），后插数据就不用交换数据
	int temp = pNew->data;
	pNew->data = pCur->data;
	pCur->data = temp;

	return 0;
}

//删除数据为x的第一个节点
int SListNodeDel(pNode phead, int x)
{
	if (phead == NULL)
		return -1;
	pNode pPre = phead;
	pNode pCur = phead->next;
	int flag = 0;
	while (pCur != NULL)
	{
		if (pCur->data == x)
		{
			pPre->next = pCur->next;
			free(pCur);
			flag = 1;
			break;
		}
		pPre = pPre->next;
		pCur = pCur->next;			
	}
	if (flag == 0)
	{
		printf("没有找到值为%d的节点\n", x);
	}
	return 0;
}
//删除元素的另一种方法
int SListNodeDel_pro(pNode phead, int x)
{
	if (phead == NULL)
		return -1;
	pNode pPre = phead;
	pNode pCur = phead->next;
	int flag = 0;
	while (pCur != NULL)
	{
		if (pCur->data == x)
		{
			pNode t = pCur->next;
			pCur->data = pCur->next->data;//要删除的节点pCur与pCur下一个节点交换
			pCur->next = t->next;
			free(t);//删除t相当于删除pCur
			flag = 1;
			break;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (flag == 0)
	{
		printf("没有找到值为%d的节点\n", x);
	}
	return 0;
}

//删除所有数据等于x的节点
int SListNodeDel_(pNode phead, int x)
{
	if (phead == NULL)
		return -1;
	pNode pPre = phead;
	pNode pCur = phead->next;
	int flag = 0;
	while (pCur != NULL)
	{
		if (pCur->data == x)
		{
			pPre->next = pCur->next;
			free(pCur);
			flag = 1;
			pCur = pPre->next;
			continue;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (flag == 0)
	{
		printf("没有找到值为%d的节点\n", x);
	}
	return 0;
}

//排序-----升序----选择排序
/*
for(int i = 0; i < n -1; i++)
{
	for(int j = i + 1; j < n; j++)
	{
		//交换
	}
}
*/
int SListNodeSort(pNode phead)
{
	if (phead == NULL && phead->next == NULL && phead->next->next == NULL)
		return -1;
	pNode p, q;

	for (p = phead->next; p->next != NULL; p = p->next)
	{
		for (q = p->next; q!= NULL; q = q->next)//第一次能循环到倒数第一个节点
		{
			if (p->data > q->data)
			{
				int temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
				
		}
		
	}
	return 0;
}
//链表排序---升序---冒泡排序
/*for (int i = 0; i < n - 1; i++)
{
	for (int j = 0; j < n - i - 1; j++)
	{
		//交换
	}
}*/
int SListNodeSort_(pNode phead)
{
	if (phead == NULL && phead->next == NULL && phead->next->next == NULL)
		return -1;
	pNode p, q;
	pNode pTail;//尾指针
	for (p = phead->next; p->next != NULL; p = p->next);
	pTail = p;

	for (p = phead->next; p->next != NULL; p = p->next)
	{
		for (q = phead->next; q != pTail; q = q->next)//第一次最大能循环到倒数第二个节点，倒数第一个为ptail
		{
			pNode t = q->next;
			if (q->data > t->data)//如果不借助节点指针t，q->next->data====q的下一个节点->data
			{
				//printf("%d\n", q->next->data);
				//这是只有一个数据情况，如果多个数据，就要节点整体交换，再指针域交换，或者将多个数据封装成结构体，结构体交换
				int temp = q->data;
				q->data = t->data;
				t->data = temp;
			}
		}
		pTail = q;
	}
	return 0;
}
int SListNodeReverse(pNode phead)
{
	if (phead == NULL && phead->next == NULL && phead->next->next == NULL)
		return -1;

	pNode p = phead->next;
	pNode q = phead->next->next;
	pNode t = NULL;
	while (q != NULL)
	{
		t = q->next;

		q->next = p;

		p = q;

		q = t;
	}
	phead->next->next = NULL;
	phead->next = p;

	return 0;
}
//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
int SListNodeInsertPro(pNode phead, int x)
{
	if (phead == NULL)
		return -1;

	pNode pPre = phead;
	pNode pCur = phead->next;
	pNode pNew = (pNode)malloc(sizeof(Node));

	while (pCur != NULL)
	{
		if (pCur->data >= x)
			break;
		pPre = pPre->next;
		pCur = pCur->next;
	}
	pNew->data = x;
	pPre->next = pNew;
	pNew->next = pCur;

	return 0;

}


int SListNodeDestroy(pNode phead)
{
	if (phead == NULL)
		return -1;
	pNode tmp = NULL;

	while (phead != NULL)
	{
		tmp = phead->next;
		free(phead);
		phead = NULL;

		phead = tmp;
	}
	return 0;
}
int main()
{
	pNode phead = NULL;
	phead = SListCreat();


	printf("\n链表遍历：\n");
	SListPrint(phead);

	SListNodeInsert(phead, 4, 9);
	printf("\n在值为%d节点前插入值为%d节点后链表遍历：\n", 4, 9);
	SListPrint(phead);

	SListNodeDel(phead, 3);
	printf("\n删除值为%d的第一个节点后链表遍历：\n", 3);
	SListPrint(phead);

	SListNodeDel_(phead, 5);
	printf("\n删除值为%d的所有节点后链表遍历：\n", 5);
	SListPrint(phead);

	SListNodeSort_(phead);
	printf("\n升序排序的结果：\n");
	SListPrint(phead);

	SListNodeReverse(phead);
	printf("\n逆置的结果：\n");
	SListPrint(phead);

	SListNodeSort_(phead);
	SListNodeInsertPro(phead, 6);
	printf("\n在已经升序的链表中插入元素%d的结果：\n", 6);
	SListPrint(phead);

	SListNodeDestroy(phead);



	return 0;
}