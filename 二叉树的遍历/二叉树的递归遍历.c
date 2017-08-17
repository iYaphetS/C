#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	char c;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

void recursionForeachTree(TreeNode *root)//Ϊʲô��ָ�벻���ڵ㣬��Լ�ڴ����Ч��
{
	if (root == NULL)
	{
		return;
	}
	//�������
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

	//�����ڵ�֮��Ĺ�ϵ
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