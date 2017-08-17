#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef struct TreeNode
{
	char c;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

//创建二叉树
TreeNode *createBiTree()
{
	char c;
	scanf("%c", &c);
	getchar();//在（循环）输入字符的时候，
	//因为scanf是以空格回车作为字符串的结束标志的，但是这个空格回车已经写入
	//到了缓冲区，所以要通过getchar()接受这个空格或者回车，不然循环到下次
	//c存到的字符就是空格或者回车了
	//还可以通过fflush(stdin);来刷新（清空）缓冲区解决这种问题
	if ('#' == c)//#代表父节点没有子节点，即是叶子节点,返回空
	{
		return NULL;
	}

	TreeNode *node = (TreeNode *)calloc(1, sizeof(TreeNode));
	node->c = c;
	node->lchild = createBiTree();
	node->rchild = createBiTree();
	return node;
}
//销毁二叉树
void freeBiTree(TreeNode *root)
{
	if (NULL == root)
	{
		return;
	}
	//先创建的后释放
	freeBiTree(root->lchild);
	freeBiTree(root->rchild);
	free(root);
}
void recursionBiTree(TreeNode *root)
{
	//先序遍历
	if (NULL == root)
	{
		return;
	}
	printf("%c--", root->c);
	recursionBiTree(root->lchild);
	recursionBiTree(root->rchild);
	
}
int main()
{
	TreeNode *root = createBiTree();
	recursionBiTree(root);
	freeBiTree(root);
	return 0;
}
