#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

//�ṹ�����ͣ�ÿ����ʦ������ѧ��
typedef struct Teacher
{
	char *tName; //��ʦ���֣���Ҫ��̬����ռ�
	char **stu;  //����ѧ������Ҫ��̬����ռ䣬��������
	int age;
}Teacher;

//��createTeacher�з���ռ�
int createTeacher(Teacher **p/*out*/, int n1, int n2)
{
	Teacher *temp = (Teacher *)calloc(n1, sizeof(Teacher));

	int i,j;
	for (i = 0; i < n1; i++)
	{
		temp[i].tName = (char *)calloc(100, sizeof(char));
		temp[i].stu = (char **)calloc(n2, sizeof(char*));
		for (j = 0; j < n2; j++)
		{
			temp[i].stu[j] = (char *)calloc(100, sizeof(char));
		}
	}

	*p = temp;
	return 0;
}

//����Ա��ֵ
void initTeacher(Teacher *p, int n1, int n2)
{
	int i, j, k = 0;
	char *buf[3] = {"����ʦ", "����ʦ", "����ʦ"};
	char *buf1[9] = { "С��", "С��", "С��" ,"С��", "С��", "С��", "С��", "С��", "С��" };
	int num[3] = { 20, 30, 40 };
	for (i = 0 ; i < n1; i++)
	{
		strcpy(p[i].tName, buf[i]);
		for (j = 0; j < n2 && k < 3 * n2; j++, k++)
		{
			strcpy(p[i].stu[j], buf1[k]);
		}
		p[i].age = num[i];
	}
	
	return;
}

//��ӡ�ṹ���Ա��Ϣ
void printTeacher(Teacher *p, int n1, int n2)
{
	int i, j;
	for (i = 0; i < n1; i++)
	{
		printf("��ʦ��%s\n", p[i].tName);
		printf("ѧ����");
		for (j = 0; j < n2; j++)
		{			
			printf("%s\t", p[i].stu[j]);
		}
		printf("\n");
		printf("���䣺%d\n", p[i].age);

	}
	return;
}


//���ݵ�ʦ��������, ����
void sortTeacher(Teacher *p, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(p[i].tName, p[j].tName) < 0)
			{
				Teacher temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
		
	return;
}

//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
void freeTeacher(Teacher **p, int n1, int n2)
{
	Teacher *temp = *p;

	int i, j;
	if (temp != NULL)
	{
		for (i = 0; i < n1; i++)
		{	
			if (temp[i].tName != NULL)
			{
				free(temp[i].tName);
				temp[i].tName = NULL;
			}
			for (j = 0; j < n2; j++)
			{
				if (temp[i].stu[j] != NULL)
				{
					free(temp[i].stu[j]);
					temp[i].stu[j] = NULL;
				}
			}
			if (temp[i].stu != NULL)
			{
				free(temp[i].stu);
				temp[i].stu = NULL;
			}			
		}
		free(temp);
		*p = NULL;
	}

	return;
}

int main(void)
{
	int ret = 0;
	int n1 = 3; //��ʦ����
	int n2 = 3; //ѧ��
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //����Ա��ֵ

	//��ӡ��Ա������ǰ
	printf("����ǰ��\n");
	printTeacher(p, n1, n2);

	//���ݵ�ʦ��������, ����
	sortTeacher(p, n1);

	//��ӡ��Ա�������
	printf("\n�����\n");
	printTeacher(p, n1, n2);

	//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
	freeTeacher(&p, n1, n2);

	return 0;
}