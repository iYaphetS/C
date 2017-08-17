#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	char c;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

void recursionForeachTree(TreeNode *root)//为什么传指针不传节点，节约内存提高效率
{
	if (root == NULL)
	{
		return;
	}
	//先序遍历
	recursionForeachTree(root->lchild);
	printf("%c ", root->c);
	recursionForeachTree(root->rchild);
}

void test()
{
	TreeNode A = { 'A', NULL, NULL };
	TreeNode B = { 'B', NULL, NULL };
	TreeNode C = { 'C', NULL, NULL };
	TreeNode D = { 'D', NULL, NULL };
	TreeNode E = { 'E', NULL, NULL };
	TreeNode F = { 'F', NULL, NULL };
	TreeNode G = { 'G', NULL, NULL };

	//建立节点之间的关系
	A.lchild = &B;
	A.rchild = &F;

	B.lchild = &C;
	B.rchild = &D;
	
	D.lchild = &E;
	F.lchild = &G;

	recursionForeachTree(&A);
	printf("\n");
}

int main()
{
	test();
	return 0;
}