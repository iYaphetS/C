#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	char c;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

void countLeafNode(TreeNode *root, int *num)
{
	if (root == NULL)
	{
		return;
	}
	if (root->lchild == NULL && root->rchild == NULL)
	{
		(*num)++;//Òª´øÀ¨ºÅ
	}
	countLeafNode(root->lchild, num);
	countLeafNode(root->rchild, num);
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


	A.lchild = &B;
	A.rchild = &F;

	B.lchild = &C;
	B.rchild = &D;

	D.lchild = &E;
	F.lchild = &G;

	int num = 0;
	countLeafNode(&A, &num);
	printf("num = %d\n", num);

}

int main()
{
	test();
	return 0;
}