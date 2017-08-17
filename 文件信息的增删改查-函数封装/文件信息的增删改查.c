#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

/*
1. �ļ���ϰ����Ҫ��װ���ʺ�����������ļ���
struct student
{
char name[20];
int age;
};
//1��ѭ������ṹ����Ϣ��������ageС��0ʱ�����������
//2����ѯ�����û���Ϣ
//3������Ҫɾ����������Ȼ����ļ�����Ӧ�����ֵĽṹɾ��
//4��������ʹ�õڶ����ļ���ֻ��һ���ļ�������������
//5����Ҫʹ�õ��ļ����Ĳ�������fwrite��fread
void menu()
{
printf("**************************\n");
printf("* 1 ������Ϣ\n");
printf("* 2 ��ѯ��Ϣ\n");
printf("* 3 ɾ���û�\n");
printf("* 4 �����Ļ\n");
printf("* 5 �˳�����\n");
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
	FILE *fp = fopen("stu.dat", "rb");//����д��wb+ģʽ��һ���ļ����ļ����ݳ��Ȼᱻ�ض�Ϊ0
	//rb+ģʽ��д�ļ�ʱ�������Ὣ�ļ��ض�Ϊ0��ֻ���ļ��α���ʲôλ�þͽ�д������ݸ��ǵ�ԭ��������
	//����  
	/*
	a 12
	b 13
	c 14
	-------delete a---�ļ��α��Ѿ����õ��ļ���ʼ
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
	printf("* 1 ������Ϣ\n");
	printf("* 2 ��ѯ��Ϣ\n");
	printf("* 3 ɾ���û�\n");
	printf("* 4 �����Ļ\n");
	printf("* 5 �˳�����\n");
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