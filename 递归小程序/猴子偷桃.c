#include <stdio.h>

/*
��ʱ������������ģ�
��һ����ճԵ���������һ���һ�����ڶ����ֽ�ʣ�µ����ӳԵ�һ���һ�����Ժ�ÿ��Ե�ǰһ��ʣ�µ�һ���һ����
����n��׼���Ե�ʱ��ֻʣ��һ�����ӡ�
�������㣬��������һ�£�����һ�쿪ʼ�Ե�ʱ������һ���ж��ٸ��أ�
*/
//�ڼ���	1    2    3	  4    ...   n
//		���                      1
//day	n    n-1  n-2  n-3        1
int calc_peach(int n)//day n  -----��һ��   day  n-1 �ڶ���
{
	
	if (n == 1)//���һ��
		return 1;
	else
		//��calc_peach(n) = (calc_peach(n - 1) + 1) * 2----��һ���ܸ���
		return (calc_peach(n - 1) + 1) * 2;
}

//�׳�
int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return factorial(n - 1) * n;

}
int main()
{
	//printf("%d\n", calc_peach(4));
	//printf("%d\n", factorial(4));

	int i, count = 1;
	for (i = 0; i < 3; i++)
	{
		count = (count + 1) * 2;
	}
	printf("%d\n", count);

	

	return 0;
}

