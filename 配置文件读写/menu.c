#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#include "cfg.h"

void menu()
{
	printf("==================\n");
	printf("*1 д�����ļ�\n");
	printf("*2 �������ļ�\n");
	printf("*3 ����\n");
	printf("*4 �˳�\n");
	printf("==================\n");

}

void write_file()
{
	char key[64] = {0};
	char val[128] = { 0 };

	printf("please input key:");
	scanf("%s", key);
	printf("please input value:");
	scanf("%s", val);

	int ret = write_cfg_file(key, val);
	if (ret != 0)
	{
		printf("write_cfg_file err: %d\n", ret);
		return;
	}
	printf("д������ݣ�%s = %s\n", key, val);

}

void read_file()
{
	char key[64] = { 0 };
	char val[128] = { 0 };
	int len = 0;

	printf("please input key:");
	scanf("%s", key);

	int ret = read_cfg_file(key, val, &len);
	if (ret != 0)
	{
		printf("read_cfg_file err: %d\n", ret);
		return;
	}
	if (val == "\0")
	{
		printf("û�ж�Ӧ��key\n" );
	}
	else
		printf("��ȡ�����ݣ�%s = %s\n", key, val);
}