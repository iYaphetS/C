#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	char c;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

TreeNode *copyBiTree(TreeNode * root)
{
	if (root == NULL)
	{
		return NULL;
	}
	TreeNode * leftchild = copyBiTree(root->lchild);
	TreeNode * rightchild = copyBiTree(root->rchild);

	TreeNode *curNode = calloc(1, sizeof(TreeNode));
	curNode->c = root->c;
	curNode->lchild = leftchild;
	curNode->rchild = rightchild;
	return curNode;
}

void freeBiTree(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	freeBiTree(root->lchild);
	freeBiTree(root->rchild);
	printf("释放：%c ", root->c);
	free(root);
	root = NULL;
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

	TreeNode *newroot = copyBiTree(&A);
	
	freeBiTree(newroot);
	printf("\n");
}

int main()
{
	test();
	return 0;
}