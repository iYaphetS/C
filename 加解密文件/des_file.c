#include <stdio.h>
#include "des.h"
#pragma warning(disable:4996)

void menu()
{
	printf("=================\n");
	printf("*1 �����ļ�\n");
	printf("*2 �����ļ�\n");
	printf("*3 ����\n");
	printf("*4 �˳�\n");
	printf("=================\n");
}

void DesEncfile()
{
	char src_path[64] = {0};
	char des_path[64] = {0};
	printf("������Ҫ���ܵ��ļ�����");
	scanf("%s", src_path);
	printf("��������ܺ���ļ�����");
	scanf("%s", des_path);

	FILE *fp1 = fopen(src_path, "rb");
	if (fp1 == NULL)
	{
		printf("%s file open fiald\n", src_path);
		goto END;
	}

	FILE *fp2 = fopen(des_path, "wb");
	if (fp1 == NULL)
	{
		printf("%s file open fiald\n", des_path);
		goto END;
	}

	int ret = 0;
	int len = 0;
	unsigned char buf[4 * 1024] = {0};
	unsigned char det[8 * 1024] = { 0 };//��ʱ��ż��ܺ���ļ����ݣ��������ݻ���
	int det_len = 0;
	while ( (len = fread(buf, 1, sizeof(buf), fp1)) != 0 )
	{
		if (len == 4 * 1024)
		{
			ret = DesEnc_raw(buf, len, det, &det_len);
			if (ret != 0)
			{
				perror("file des fiald\n");
				goto END;
			}
			fwrite(det, 1, det_len, fp2);
		}
		else
		{
			ret = DesEnc(buf, len, det, &det_len);
			if (ret != 0)
			{
				perror("file des fiald\n");
				goto END;
			}
			fwrite(det, 1, det_len, fp2);
		}

	}
END:
	if (fp1 != NULL)
	{
		fclose(fp1);
		fp1 = NULL;
	}
	if (fp2 != NULL)
	{
		fclose(fp2);
		fp2 = NULL;
	}

}

void DesDecfile()
{
	char src_path[64] = { 0 };
	char des_path[64] = { 0 };
	printf("������Ҫ���ܵ��ļ�����");
	scanf("%s", src_path);
	printf("��������ܺ���ļ�����");
	scanf("%s", des_path);

	FILE *fp1 = fopen(src_path, "rb");
	if (fp1 == NULL)
	{
		printf("%s file open fiald\n", src_path);
		goto END;
	}

	FILE *fp2 = fopen(des_path, "wb");
	if (fp1 == NULL)
	{
		printf("%s file open fiald\n", des_path);
		goto END;
	}

	int ret = 0;
	int len = 0;
	unsigned char buf[4 * 1024] = { 0 };
	unsigned char det[8 * 1024] = { 0 };//��ʱ��Ž��ܺ���ļ����ݣ��������ݻ���
	int det_len = 0;
	while ((len = fread(buf, 1, sizeof(buf), fp1)) != 0)
	{
		if (len == 4 * 1024)
		{
			ret = DesDec_raw(buf, len, det, &det_len);
			if (ret != 0)
			{
				perror("file des fiald\n");
				goto END;
			}
			fwrite(det, 1, det_len, fp2);
		}
		else
		{
			ret = DesDec(buf, len, det, &det_len);
			if (ret != 0)
			{
				perror("file des fiald\n");
				goto END;
			}
			fwrite(det, 1, det_len, fp2);
		}

	}
END:
	if (fp1 != NULL)
	{
		fclose(fp1);
		fp1 = NULL;
	}
	if (fp2 != NULL)
	{
		fclose(fp2);
		fp2 = NULL;
	}
}