#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:4996)

#define CFGPATH "cfg.dat"
void deleteSpace(char *buf)
{
	char *t = buf;
	char *p = buf;
	char *q = buf;

	q = buf + strlen(buf) - 1;
	while (isspace(*p))
		p++;
	while (isspace(*q))
	{
		*q = '\0';
		q--;
	}
	strcpy(t, p);

}
int write_cfg_file(char *key, char *val)
{
	int ret = 0;
	/*要求：
	文件存在，修改key对用的val，不能用"wb"方式，文件内容会清空
	文件不存在，创建文件，不能用"rb"方式打开，会打开失败
	没有对应的key，在文件末尾追加相应的键值对
	文件读取到的零时数据用堆来存储
	*/
	FILE *fp = fopen(CFGPATH, "rb");
	if (fp == NULL)//文件不存在
	{
		fp = fopen(CFGPATH, "wb");
		if (fp == NULL)
		{
			perror("file create fiald\n");
			ret = -1;
			goto END;
		}
	}
	//走到这里就确定文件存在
	char buf[1024] = {0};//存储读取文件每行数据
	char *p = NULL;
	char *temp = NULL;//将处理后的数据都存储到这个零时堆空间，便于写入到文件
	int flag = 0;
	char key_[64] = {0};
	char val_[128] = {0};
	int n = 0;
	while (fgets(buf, sizeof(buf), fp))
	{		
		sscanf(buf, "%[^=]=%[^\n]", key_, val_);
		deleteSpace(key_);
		if (strcmp(key, key_) == 0)
		{
			temp = (char *)realloc(p, (n + 1) * 1024);
			memset(temp + n * 1024, 0, sizeof((n + 1) * 1024));//*****

			char s[1024] = { 0 };
			sprintf(s, "%s = %s\n", key, val);
			strcat(temp, s);//对应的堆空间要清空，如果堆空间都是垃圾数据，追加数据会访问溢出
			p = temp;
			n++;
			flag = 1;
		}
		else
		{
			temp = (char *)realloc(p, (n + 1) * 1024);
			if (temp == NULL)
				printf("realloc fiald\n");
			memset(temp + n * 1024, 0, sizeof((n + 1) * 1024));//*****

			strcat(temp, buf);
			p = temp;
			n++;
		}
		memset(buf, 0, sizeof(buf));		
	}

	if (flag == 0)//没有找到对应的key就在文件尾部追加键值对
	{
		temp = (char *)realloc(p, (n + 1) * 1024);
		memset(temp + n * 1024, 0, sizeof((n + 1) *1024));//*****
		if (temp == NULL)
			printf("reallocc filad\n");
		char s[1024] = { 0 };
		sprintf(s, "%s = %s\n", key, val);//****，\n加上，不然写到一行
		strcat(temp, s);
		n++;
		p = temp;
	}
	if(fp != NULL)
		fclose(fp);
	fp = NULL;

	fp = fopen(CFGPATH, "wb");
	if (fp == NULL)
	{
		perror("file open fiald\n");
		ret = -2;
		goto END;
	}
	fputs(temp, fp);
END:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
	free(temp);
	return ret;
}

int read_cfg_file(char *key, char *val, int *len)
{
	int ret = 0;

	FILE *fp = fopen(CFGPATH, "rb");
	if (fp == NULL)
	{
		perror("file open fiald\n");
		ret = -1;
		goto END;
	}
	char buf[1024] = { 0 };//存储读取文件每行数据
	char key_[64] = { 0 };
	char val_[128] = { 0 };
	while (fgets(buf, sizeof(buf) - 1, fp))
	{
		sscanf(buf, "%[^=]=%[^\n]", key_, val_);
		deleteSpace(key_);
		if (strcmp(key, key_) == 0)
		{
			deleteSpace(val_);
			strcpy(val, val_);
			*len = strlen(buf);
		}
		memset(buf, 0, sizeof(buf));

	}

END:
	if (fp != NULL)
	{
		fclose(fp);
	}

	return ret;
}