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
	pNode pCur = phead;//����ͷ�ڵ��ǲ����ģ�pCurֻ��һ�������Ľڵ�ָ�����
	pNode pNew = NULL;
	int num = 0;

	while (1)
	{
		printf("���������ݣ�");
		scanf("%d", &num);
		if (num < 0)
			break;
		pNew = (pNode)malloc(sizeof(Node));
		if (pNew == NULL)
			break;
		pNew->data = num;
		
		//ǧ��Ҫ����дpNew = pCur->next;
		//����pNew�����˶ѿռ䣬�����ı�pNewָ�򣬳���һ��Ұָ��
		pCur->next = pNew;//����pcur��pnew֮��Ĺ�ϵ
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
//�����ݵ���x�ĵ�һ���ڵ�ǰ�����һ������Ϊy�Ľڵ�,���û�о���β������
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
		pPre = pPre->next;//ָ��ı䣬����һ���ڵ��ƶ�
		pCur = pCur->next;
	}
		
	pNew->data = y;
	pPre->next = pNew;
	pNew->next = pCur;

	return 0;
}
//*********��һ�ֺ�巨ʵ��Ԫ�ص�ǰ��ͺ��
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
		pPre = pPre->next;//ָ��ı䣬����һ���ڵ��ƶ�
		pCur = pCur->next;
	}

	pNew->data = y;
	pNew->next = pCur->next;
	pCur->next = pNew;
	//ǰ��Ԫ�أ��������ݣ��൱�ڽ����˵�ǰ�ڵ����½ڵ㣩��������ݾͲ��ý�������
	int temp = pNew->data;
	pNew->data = pCur->data;
	pCur->data = temp;

	return 0;
}

//ɾ������Ϊx�ĵ�һ���ڵ�
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
		printf("û���ҵ�ֵΪ%d�Ľڵ�\n", x);
	}
	return 0;
}
//ɾ��Ԫ�ص���һ�ַ���
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
			pCur->data = pCur->next->data;//Ҫɾ���Ľڵ�pCur��pCur��һ���ڵ㽻��
			pCur->next = t->next;
			free(t);//ɾ��t�൱��ɾ��pCur
			flag = 1;
			break;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (flag == 0)
	{
		printf("û���ҵ�ֵΪ%d�Ľڵ�\n", x);
	}
	return 0;
}

//ɾ���������ݵ���x�Ľڵ�
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
		printf("û���ҵ�ֵΪ%d�Ľڵ�\n", x);
	}
	return 0;
}

//����-----����----ѡ������
/*
for(int i = 0; i < n -1; i++)
{
	for(int j = i + 1; j < n; j++)
	{
		//����
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
		for (q = p->next; q!= NULL; q = q->next)//��һ����ѭ����������һ���ڵ�
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
//��������---����---ð������
/*for (int i = 0; i < n - 1; i++)
{
	for (int j = 0; j < n - i - 1; j++)
	{
		//����
	}
}*/
int SListNodeSort_(pNode phead)
{
	if (phead == NULL && phead->next == NULL && phead->next->next == NULL)
		return -1;
	pNode p, q;
	pNode pTail;//βָ��
	for (p = phead->next; p->next != NULL; p = p->next);
	pTail = p;

	for (p = phead->next; p->next != NULL; p = p->next)
	{
		for (q = phead->next; q != pTail; q = q->next)//��һ�������ѭ���������ڶ����ڵ㣬������һ��Ϊptail
		{
			pNode t = q->next;
			if (q->data > t->data)//����������ڵ�ָ��t��q->next->data====q����һ���ڵ�->data
			{
				//printf("%d\n", q->next->data);
				//����ֻ��һ��������������������ݣ���Ҫ�ڵ����彻������ָ���򽻻������߽�������ݷ�װ�ɽṹ�壬�ṹ�彻��
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
//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
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


	printf("\n���������\n");
	SListPrint(phead);

	SListNodeInsert(phead, 4, 9);
	printf("\n��ֵΪ%d�ڵ�ǰ����ֵΪ%d�ڵ�����������\n", 4, 9);
	SListPrint(phead);

	SListNodeDel(phead, 3);
	printf("\nɾ��ֵΪ%d�ĵ�һ���ڵ�����������\n", 3);
	SListPrint(phead);

	SListNodeDel_(phead, 5);
	printf("\nɾ��ֵΪ%d�����нڵ�����������\n", 5);
	SListPrint(phead);

	SListNodeSort_(phead);
	printf("\n��������Ľ����\n");
	SListPrint(phead);

	SListNodeReverse(phead);
	printf("\n���õĽ����\n");
	SListPrint(phead);

	SListNodeSort_(phead);
	SListNodeInsertPro(phead, 6);
	printf("\n���Ѿ�����������в���Ԫ��%d�Ľ����\n", 6);
	SListPrint(phead);

	SListNodeDestroy(phead);



	return 0;
}