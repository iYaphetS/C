#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

/*
1. 文件练习（需要封装合适函数，无需分文件）
struct student
{
char name[20];
int age;
};
//1、循环输入结构体信息，当输入age小于0时，则结束输入
//2、查询所有用户信息
//3、输入要删除的姓名，然后把文件中相应的名字的结构删除
//4、不可以使用第二个文件，只用一个文件来完成这个任务
//5、需要使用的文件核心操作函数fwrite、fread
void menu()
{
printf("**************************\n");
printf("* 1 输入信息\n");
printf("* 2 查询信息\n");
printf("* 3 删除用户\n");
printf("* 4 清除屏幕\n");
printf("* 5 退出程序\n");
printf("**************************\n");
}
*/
typedef struct student
{
	char name[20];
	int age;
}STU;
void input_info()
{
	FILE *fp = fopen("stu.dat", "wb");
	if (fp == NULL)
	{
		perror("open file fiald");
		return;
	}

	STU *p = NULL;
	STU *temp = NULL;
	int n = 0;
	while (1)
	{
		temp = (STU *)realloc(p, (n + 1) * sizeof(STU));
		scanf("%s %d", temp[n].name, &temp[n].age);		
		if (temp[n].age < 0)
			break;
		n++;
		p = temp;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		//printf("%s %d\n", temp[i].name, temp[i].age);
		fwrite(&temp[i], 1, sizeof(STU), fp);
		//fflush(fp);
	}
	fclose(fp);
	free(temp);
	return;
}

void check_info()
{
	FILE *fp = fopen("stu.dat", "rb");
	if (fp == NULL)
	{
		perror("open file fiald");
		return;
	}

	STU s = {0};
	while (fread(&s, sizeof(STU), 1, fp) != 0)
	{
		printf("name = %s age = %d\n", s.name, s.age);

		memset(&s, 0, sizeof(s));
	}
	//int i;
	//for (i = 0; i < 2; i++)
	//{
	//	fscanf(fp, "%s %d", s.name, &s.age);
	//	printf("name = %s age = %d\n", s.name, s.age);
	//}
	fclose(fp);
	return;

}

void delete_info()
{
	FILE *fp = fopen("stu.dat", "rb");//不能写成wb+模式，一打开文件，文件数据长度会被截断为0
	//rb+模式，写文件时，并不会将文件截断为0，只是文件游标在什么位置就将写入的内容覆盖掉原来的内容
	//例如  
	/*
	a 12
	b 13
	c 14
	-------delete a---文件游标已经设置到文件开始
	b 13
	c 14
	c 14
	*/
	if (fp == NULL)
	{
		perror("open file fiald");
		return;
	}
	char name[64] = {0};
	printf("please input delete usename:");
	scanf("%s", name);
	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	
	int n = size / sizeof(STU);
	rewind(fp);

	STU *temp = (STU *)calloc(n, sizeof(STU));	
	fread(temp, sizeof(STU), n, fp);
	//rewind(fp);
	fclose(fp);

	fp = fopen("stu.dat", "wb");

	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(temp[i].name, name) != 0)
			fwrite(&temp[i], sizeof(STU), 1, fp);
	}

	fclose(fp);
	
	return;
}
void clear_screen()
{
	system("cls");
	return;
}
void exit_info()
{
	exit(-1);
}
void menu()
{
	printf("**************************\n");
	printf("* 1 输入信息\n");
	printf("* 2 查询信息\n");
	printf("* 3 删除用户\n");
	printf("* 4 清除屏幕\n");
	printf("* 5 退出程序\n");
	printf("**************************\n");

		
}
int main()
{
	
	char buf[64] = { 0 };
	while (1)
	{
		menu();
		printf("cmd:");
		scanf("%s", buf);
		if (strcmp(buf, "1") == 0)
			input_info();
		else if (strcmp(buf, "2") == 0)
			check_info();
		else if (strcmp(buf, "3") == 0)
			delete_info();
		else if (strcmp(buf, "4") == 0)
			clear_screen();
		else if (strcmp(buf, "5") == 0)
			exit_info();
		else
			printf("invalid cmd\n");
	}

	return 0;
}