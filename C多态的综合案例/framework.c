#include <stdio.h>
#include "CSocketProtocol.h"
#include "CEncDesProtocol.h"

int framework(CSocketProtocol *sp, CEncDesProtocol *ed, 
	char *send_buf, int send_len, char *recv_buf, int *recv_len)
{
	int ret = 0;
	if (sp == NULL || ed == NULL)
	{
		ret = -1;
		goto END;
	}
	void *hd;
	//为句柄结构体分配空间，初始化ip，和端口号
	ret = sp->socket_init(&hd);
	if (ret != 0)
		goto END;

	//发送数据前加密
	char buf1[1024] = {0};//存放要发送的密文的缓冲区
	int len1;
	ret = ed->enc_file(send_buf, send_len, buf1, &len1);
	if (ret != 0)
		goto END;
	//发送密文数据
	//初始化句柄内容，外部将数据发送给句柄
	ret = sp->send_data(hd, buf1, len1);
	if (ret != 0)
		goto END;

	char buf2[1024] = { 0 };//存放要接受的密文的缓冲区
	int len2;
	//接受密文数据
	//外部接受句柄发出的内容
	ret = sp->recv_data(hd, buf2, &len2);
	if (ret != 0)
		goto END;

	//将密文数据解密
	ret = ed->des_file(buf2, len2, recv_buf, recv_len);
	if (ret != 0)
		goto END;


END:
	return ret;

}

