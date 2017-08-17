#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	char c;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

int BitreeHigh(TreeNode * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int lefthigh = BitreeHigh(root->lchild);
	int righthigh = BitreeHigh(root->rchild);
	return lefthigh >= righthigh ? lefthigh + 1 : righthigh + 1;
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

	printf("%d\n", BitreeHigh(&A));
}

int main()
{
	test();
	return 0;
}