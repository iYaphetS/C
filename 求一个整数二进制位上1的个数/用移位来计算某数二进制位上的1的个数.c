#include <stdio.h>
#pragma warning(disable:4996)
//����һ���޷��ŵ����У�������λ��ֵΪ 1 �ĸ���
//��ʾ�� >>

int count_one_bits(unsigned int tmp)
{
	int count = 0;
	/*while (tmp)
	{
		if ((tmp & 01) == 1)
			count++;
		tmp >>= 1;//temp = temp >> 1;//ע�����޷�����
	}*/
	while (tmp)
	{
		tmp = tmp & (tmp - 1);//ÿ����һ�ν�tmp������λ�ϣ���������1���0��֪��tmp���0
		count++;
	}
	return count;
}
int main()
{
	unsigned int num;
	printf("please input num:");
	scanf("%d", &num);

	int count = count_one_bits(num);

	printf("%d\n", count);
	
	return 0;
}