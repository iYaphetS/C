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

//����������
TreeNode *createBiTree()
{
	char c;
	scanf("%c", &c);
	getchar();//�ڣ�ѭ���������ַ���ʱ��
	//��Ϊscanf���Կո�س���Ϊ�ַ����Ľ�����־�ģ���������ո�س��Ѿ�д��
	//���˻�����������Ҫͨ��getchar()��������ո���߻س�����Ȼѭ�����´�
	//c�浽���ַ����ǿո���߻س���
	//������ͨ��fflush(stdin);��ˢ�£���գ������������������
	if ('#' == c)//#�����ڵ�û���ӽڵ㣬����Ҷ�ӽڵ�,���ؿ�
	{
		return NULL;
	}

	TreeNode *node = (TreeNode *)calloc(1, sizeof(TreeNode));
	node->c = c;
	node->lchild = createBiTree();
	node->rchild = createBiTree();
	return node;
}
//���ٶ�����
void freeBiTree(TreeNode *root)
{
	if (NULL == root)
	{
		return;
	}
	//�ȴ����ĺ��ͷ�
	freeBiTree(root->lchild);
	freeBiTree(root->rchild);
	free(root);
}
void recursionBiTree(TreeNode *root)
{
	//�������
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
