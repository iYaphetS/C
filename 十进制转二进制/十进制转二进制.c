#include <stdio.h>

/*
* ʵ��һ��ʮ����ת�����Ƶĺ���������һ��ʮ���������Զ�������ʽ���
* void dec2bin(int n);
*/
void dec2bin(int n)
{
	/*char buf[100] = {0};
	int i;
	for (i = 0; n ; i++ )
	{
		buf[i] = n % 2 + '0';
		n /= 2;
	}
	//ת���ַ���Ҳ��Ҫ����
	printf("%s\n", buf);
	*/
	int i;
	for (i = 31; i >= 0; i--)
	{
		printf("%d", n >> i & 01);
	}
	printf("\n");
}
int main()
{
	int num = 123;
	dec2bin(num);
	return 0;
}