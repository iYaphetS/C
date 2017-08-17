#include "SeqStack.h"
#include <stdbool.h>

typedef struct BiTreeNode
{
	char c;
	struct BiTreeNode *lchild;
	struct BiTreeNode *rchild;
}BiTreeNode;
typedef struct Info
{
	BiTreeNode *node;
	bool flag;
}Info;

Info * createInfoMem(BiTreeNode *node, bool flag)
{
	Info *info = (Info *)calloc(1, sizeof(Info));
	info->node = node;
	info->flag = flag;
	return info;
}
void NoRecursion(BiTreeNode *root)
{
	/*���̣���Ĭ�Ͻڵ��һ����ջflag = false �ڶ�����ջflag = true��
	1.�����ڵ���ջ
	2.����һ��ѭ����ջΪ���˳�ѭ����
		2.1-���ջ��Ԫ�أ������䵯��
		2.2-���������Ԫ�ص�flag = true��������Ԫ�أ�continue
			���������Ԫ�ص�flag = false�Ͱѵ�ǰ�ڵ�flag = true
			Ȼ���ó���ǰ�ڵ�����Ӻ��Һ��ӣ�һ��ѹ��ջ�У�ѹ��
			�Ĺ�����������Ҫ�������������ѹ��Ľڵ㵯������˳��
			�Ƿ��϶����������������
	*/
	Stack stack = init_Stack();
	push_Stack(stack, createInfoMem(root, false));

	while (size_Stack(stack) > 0)
	{
		Info *temp = (Info *)top_Stack(stack);
		pop_Stack(stack);
		if (temp->flag)
		{
			printf("%c ", temp->node->c);
			free(temp);
			continue;
		}
		//��ջ �� �� ��-------��ջ  ��  ��  �ң�����
		if (temp->node->rchild != NULL)
		{
			push_Stack(stack, createInfoMem(temp->node->rchild, false));

		}
		if (temp->node->lchild != NULL)
		{
			push_Stack(stack, createInfoMem(temp->node->lchild, false));

		}
		temp->flag = true;
		push_Stack(stack, temp);	
	}
	destroy_Stack(stack);
}
int main()
{
	BiTreeNode A = { 'A', NULL, NULL };
	BiTreeNode B = { 'B', NULL, NULL };
	BiTreeNode C = { 'C', NULL, NULL };
	BiTreeNode D = { 'D', NULL, NULL };
	BiTreeNode E = { 'E', NULL, NULL };
	BiTreeNode F = { 'F', NULL, NULL };
	BiTreeNode G = { 'G', NULL, NULL };

	A.lchild = &B;
	A.rchild = &F;

	B.lchild = &C;
	B.rchild = &D;

	D.lchild = &E;
	F.lchild = &G;
	NoRecursion(&A);
	printf("\n");
	return 0;
}