#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable:4996)
/*
��ֵ�ԣ�"key = value"���ַ������ڿ����о���ʹ��
Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡ
Ҫ��2����д��������
Ҫ��3����ֵ���м������n��ո���ȥ���ո�

�ο��⺯����strncpy(), strlen(), strstr(), ����ʹ��sscanf()����


���ܣ�
��ֵ�ԣ���key = value�����ַ������Ӽ�key���Ҷ�Ӧ��ֵvalue
������
keyval����ֵ�ԣ���key = value�����ַ���
pkey����
buf��ƥ�������Ӧ������
len��ƥ�������Ӧ���ݵĳ���
����ֵ��
�ɹ���0
ʧ�ܣ���0
*/
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *  valuebuf, int * valuebuflen)
{
	int keylen = 0;//���ĳ���
	int keyvallen = 0;//ֵ�ĳ���
	//���Ҽ�ֵ���ַ������Ƿ��ж�Ӧ�ļ��ַ�����û���ҵ�����-1
	char *s = strstr(keyvaluebuf, keybuf);
	if (s == NULL)
		return -1;
	//�õ����ַ����ĳ���
	char *temp = s;
	while (!isspace(*temp))
	{
		keylen++;
		temp++;
	}
	s += keylen;
	//�ҵ�ֵ�ַ������׵�ַ
	while (isspace(*s) || *s == '=')		
		s++;
	temp = s;
	//�õ�ֵ�ַ����ĳ���
	while (!isspace(*temp) && *temp)
	{
		keyvallen++;
		temp++;
	}
	//*temp = '\0';sָ����ַ����ǳ����ַ��������޸�
	
	strncpy(valuebuf, s, keyvallen);
	*(valuebuf + keyvallen) = '\0';
	*valuebuflen = keyvallen;

	return 0;
}

int main(void)
{
	char buf[128] = { 0 };
	int len = 0;

	// ��"key1 =    valude1"�в���"key1"ƥ����ַ�����
	//����ҵ�����ȡ=������ַ���������ȥ������ո�
	int ret = getKeyByValue("key1 =    valude1   ", "key1", buf, &len);
	//���ú�����buf="valude1", len=7
	if (ret != 0)
	{
		printf("û���ҵ�����Ӧ��ֵ\n");
	}
	printf("%s, %d\n", buf, len);

	return 0;
}
