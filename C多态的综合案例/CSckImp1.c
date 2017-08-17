#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//ͨ�ź�����ʵ��
typedef struct Handle
{
	char ip[32];
	unsigned short port;
	char *str;
	int len;
}Handle;

//Ϊ����ṹ�����ռ䣬��ʼ��ip���Ͷ˿ں�
int socket_init(void **handle)
{
	int ret = 0;
	if (handle == NULL)
	{
		ret = -1;
		goto END;
	}
	Handle *temp = (Handle *)calloc(1, sizeof(Handle));

	if (temp == NULL)
	{
		ret = -2;
		goto END;
	}
	strcpy(temp->ip, "255.255.255.255");
	temp->port = 8888;

	*handle = temp;
		
END:
	return ret;
}

//��ʼ��������ݣ��ⲿ�����ݷ��͸����
int send_data(void *handle, char *buf, int len)
{
	int ret = 0;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		goto END;
	}
	Handle *temp = (Handle *)handle;
	temp->str = (char *)calloc(1, len);
	if (temp->str == NULL)
		ret = -2;
	memcpy(temp->str, buf, len);
	temp->len = len;

END:
	return ret;
}

//�ⲿ���ܾ������������
int recv_data(void *handle, char *buf, int *len)
{
	int ret = 0;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		goto END;
	}
	Handle *temp = (Handle *)handle;
	if (temp->len == 0)//�����û������
	{
		ret = -2;
		goto END;
	}
	memcpy(buf, temp->str, temp->len);
	*len = temp->len;
END:
	return ret;

}

//���������Ķѿռ��ͷ�
int socket_destory(void **handle)
{
	int ret = 0;
	if (handle == NULL)
	{
		ret = -1;
		goto END;
	}

	Handle *temp = (Handle *)handle;
	if (temp->str != NULL)
	{
		free(temp->str);
		temp->str = NULL;
	}
	free(temp);
	*handle = NULL;
END:
	return ret;
}