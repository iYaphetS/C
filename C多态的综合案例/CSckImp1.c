#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//通信函数的实现
typedef struct Handle
{
	char ip[32];
	unsigned short port;
	char *str;
	int len;
}Handle;

//为句柄结构体分配空间，初始化ip，和端口号
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

//初始化句柄内容，外部将数据发送给句柄
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

//外部接受句柄发出的内容
int recv_data(void *handle, char *buf, int *len)
{
	int ret = 0;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		goto END;
	}
	Handle *temp = (Handle *)handle;
	if (temp->len == 0)//句柄里没有内容
	{
		ret = -2;
		goto END;
	}
	memcpy(buf, temp->str, temp->len);
	*len = temp->len;
END:
	return ret;

}

//将句柄申请的堆空间释放
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