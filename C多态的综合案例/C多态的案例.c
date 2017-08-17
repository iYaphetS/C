#include <stdio.h>
#include <string.h>

#include "framework.h"//����CSocketProtocol  CEncDesProtocol
#include "CSckImp1.h"//����socket_init, send_data, recv_data, socket_destory����
#include "CHwImp.h"//����enc_file, des_file����


int main()
{
	CSocketProtocol sp;
	setSP(&sp, socket_init, send_data, recv_data, socket_destory);
	CEncDesProtocol ed;
	setED(&ed, enc_file, des_file);

	//����Ϊ�򵥵��ַ���
	char send_buf[] = "hello";
	int send_len = strlen(send_buf);

	char recv_buf[1024] = {0};
	int recv_len = 0;

	int ret = framework(&sp, &ed, send_buf, send_len, recv_buf, &recv_len);
	if (ret != 0)
	{
		printf("framework err:%d\n", ret);
		return -1;
	}

	printf("���ܵ��ı�����Ϣ��%s, ���ȣ�%d\n", recv_buf, recv_len);

	return 0;
}