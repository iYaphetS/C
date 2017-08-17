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
	/*流程：（默认节点第一次入栈flag = false 第二次入栈flag = true）
	1.将根节点入栈
	2.进入一个循环（栈为空退出循环）
		2.1-获得栈顶元素，并将其弹出
		2.2-如果弹出的元素的flag = true就输出这个元素，continue
			如果弹出的元素的flag = false就把当前节点flag = true
			然后拿出当前节点的左孩子和右孩子，一起压入栈中（压入
			的规则：例如你需要先序遍历，就让压入的节点弹出来的顺序
			是符合二叉树的先序遍历）
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
		//入栈 右 左 根-------出栈  根  左  右（先序）
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