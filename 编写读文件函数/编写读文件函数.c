#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*
已知 char **p = NULL; int lines 编写读文件函数，从文件中读取内容，为每一行内容按大小分配空间。
void readFile(char ***p,int *line);

文件内容参考《demo.txt》

提示：
首先扫描文件行数，根据行数给指针p分配指针数组空间。
再根据每行内容，动态分配空间，存放每行内容。
*/

void readFile(char ***p, int *line)
{
	FILE *fp = fopen("demo.txt", "r");

	char **pbuf = NULL;
	char buf[1024] = { 0 };
	int countline = 0;
	while (fgets(buf, sizeof(buf) - 1, fp))
	{
		countline++;
		memset(buf, 0, sizeof(buf));
	}
	pbuf = (char **)calloc(countline, sizeof(char *));
	rewind(fp);

	int index = 0;
	while (fgets(buf, sizeof(buf) - 1, fp))
	{
		int size = strlen(buf);
		pbuf[index] = (char *)calloc(1, size + 1);
		strcpy(pbuf[index], buf);
		index++;
	}

	*p = pbuf;
	*line = countline;
	fclose(fp);

}

void print_file(char **p, int lines)
{
	int i;
	for (i = 0; i < lines; i++)
	{
		printf("%s", p[i]);
	}
}

void free_mem(char ***p, int lines)
{
	char **temp = *p;
	int i;
	if (temp != NULL)
	{
		for (i = 0; i < lines; i++)
		{
			if (temp[i] != NULL)
			{
				free(temp[i]);
				temp[i] = NULL;;
			}
		}	
		free(temp);
		*p = NULL;
	}
}
int main()
{
	char **p = NULL;
	int lines = 0;

	readFile(&p, &lines);
	print_file(p, lines);
	free_mem(&p, lines);

	return 0;
}