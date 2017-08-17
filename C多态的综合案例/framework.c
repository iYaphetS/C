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
	//Ϊ����ṹ�����ռ䣬��ʼ��ip���Ͷ˿ں�
	ret = sp->socket_init(&hd);
	if (ret != 0)
		goto END;

	//��������ǰ����
	char buf1[1024] = {0};//���Ҫ���͵����ĵĻ�����
	int len1;
	ret = ed->enc_file(send_buf, send_len, buf1, &len1);
	if (ret != 0)
		goto END;
	//������������
	//��ʼ��������ݣ��ⲿ�����ݷ��͸����
	ret = sp->send_data(hd, buf1, len1);
	if (ret != 0)
		goto END;

	char buf2[1024] = { 0 };//���Ҫ���ܵ����ĵĻ�����
	int len2;
	//������������
	//�ⲿ���ܾ������������
	ret = sp->recv_data(hd, buf2, &len2);
	if (ret != 0)
		goto END;

	//���������ݽ���
	ret = ed->des_file(buf2, len2, recv_buf, recv_len);
	if (ret != 0)
		goto END;


END:
	return ret;

}

