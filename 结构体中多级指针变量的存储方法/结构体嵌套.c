#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

//结构体类型，每个导师有三个学生
typedef struct Teacher
{
	char *tName; //导师名字，需要动态分配空间
	char **stu;  //三个学生，需要动态分配空间，堆区数组
	int age;
}Teacher;

//在createTeacher中分配空间
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

//给成员赋值
void initTeacher(Teacher *p, int n1, int n2)
{
	int i, j, k = 0;
	char *buf[3] = {"刘老师", "王老师", "李老师"};
	char *buf1[9] = { "小米", "小明", "小花" ,"小华", "小李", "小王", "小刘", "小可", "小美" };
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

//打印结构体成员信息
void printTeacher(Teacher *p, int n1, int n2)
{
	int i, j;
	for (i = 0; i < n1; i++)
	{
		printf("老师：%s\n", p[i].tName);
		printf("学生：");
		for (j = 0; j < n2; j++)
		{			
			printf("%s\t", p[i].stu[j]);
		}
		printf("\n");
		printf("年龄：%d\n", p[i].age);

	}
	return;
}


//根据导师名字排序, 降序
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

//释放空间，在函数内部把p赋值为NULL
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
	int n1 = 3; //导师个数
	int n2 = 3; //学生
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //给成员赋值

	//打印成员，排序前
	printf("排序前：\n");
	printTeacher(p, n1, n2);

	//根据导师名字排序, 降序
	sortTeacher(p, n1);

	//打印成员，排序后
	printf("\n排序后：\n");
	printTeacher(p, n1, n2);

	//释放空间，在函数内部把p赋值为NULL
	freeTeacher(&p, n1, n2);

	return 0;
}