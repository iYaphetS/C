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
	/*Ҫ��
	�ļ����ڣ��޸�key���õ�val��������"wb"��ʽ���ļ����ݻ����
	�ļ������ڣ������ļ���������"rb"��ʽ�򿪣����ʧ��
	û�ж�Ӧ��key�����ļ�ĩβ׷����Ӧ�ļ�ֵ��
	�ļ���ȡ������ʱ�����ö����洢
	*/
	FILE *fp = fopen(CFGPATH, "rb");
	if (fp == NULL)//�ļ�������
	{
		fp = fopen(CFGPATH, "wb");
		if (fp == NULL)
		{
			perror("file create fiald\n");
			ret = -1;
			goto END;
		}
	}
	//�ߵ������ȷ���ļ�����
	char buf[1024] = {0};//�洢��ȡ�ļ�ÿ������
	char *p = NULL;
	char *temp = NULL;//�����������ݶ��洢�������ʱ�ѿռ䣬����д�뵽�ļ�
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
			strcat(temp, s);//��Ӧ�Ķѿռ�Ҫ��գ�����ѿռ䶼���������ݣ�׷�����ݻ�������
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

	if (flag == 0)//û���ҵ���Ӧ��key�����ļ�β��׷�Ӽ�ֵ��
	{
		temp = (char *)realloc(p, (n + 1) * 1024);
		memset(temp + n * 1024, 0, sizeof((n + 1) *1024));//*****
		if (temp == NULL)
			printf("reallocc filad\n");
		char s[1024] = { 0 };
		sprintf(s, "%s = %s\n", key, val);//****��\n���ϣ���Ȼд��һ��
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
	char buf[1024] = { 0 };//�洢��ȡ�ļ�ÿ������
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