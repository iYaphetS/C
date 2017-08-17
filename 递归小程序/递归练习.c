#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

//��һ��1�ã��ɻ���Ŀÿ�춼�Ƿ����ģ�����30���ˣ����23��ռ����֮��
int count(int n)
{
	if (n == 1)
		return 1;
	return count(n - 1) * 2;

}

//��һ�����Ķ�������
int dec_to_bit(int num)
{
	//if (num == 1)
	if(num >= 2)
	{
		dec_to_bit(num / 2);
		//printf("%d", num);
		//return 0;
	}
	//dec_to_bit(num / 2);
	printf("%d", num % 2);
	return 0;
}
//��ת������
void dec2bin(int n)
{
	for (int i = 31; i >= 0; --i)
	{
		printf("%d", n >> i & 1);
	}
}

//�ַ�����ת
void inverse(char *str, char *buf)
{
	if (*str == '\0')
		return;
	inverse(str + 1, buf);

	strncat(buf, str, 1);
}


int main1()
{
	int n = count(30) / count(23);
	printf("%d��֮һ\n", n);

	dec_to_bit(5);
	printf("\n");

	char str[] = "hello";
	char buf[100] = {0};
	inverse(str, buf);
	printf("%s", buf);
	return 0;
}
//��ֻ���ӷ��ҡ�
//��ҹ����һֻ�����������������ҷֳ�����ȵ���ѣ����һֻ�����ǣ����Ե���һ����������һ�ѣ� 
//�ڶ�ֻ��������һ����ֻ���Ķ��ҡ����ǰ��ĶѺ���һ�𣬷ֳ���ȵ���ѣ��ֶ��һ�������ǣ���Ҳ�Ե���һ����������һ�ѣ�
//.....������ֻ����Ҳ���� �����ֵġ�
//�ʣ�����������ж��ٸ���

/*
int count = 5;

int Recursion(int n,int count)
{
	if (count == 0)
		return 1;
	if ((n - 1) % 5 == 0)
	{
		//--count;
		return Recursion((n - 1) / 5 * 4,count-1);
	}
	else
	{
		//count = 5;
		return 0;
	}
}
*/

int Recursion(int src, int n, int count)
{
	//src���ӵ���Ŀ�����õ�����ٵ��㷨������һ������ȥ�ԣ���Ȼ�Ƿ��Ϲ涨������
	//���зֽ�������
	if (count == 0)//�ݹ���ֹ������������ܹ����зֽ���5��
		return src;
	if ((n - 1) % 5 == 0)
	{
		//����ֽܷ⣬�ͽ�ʣ�µ��ٽ��зֽ�
		return Recursion(src, (n - 1) / 5 * 4, count - 1);
	}
	else
	{
		//������ֽܷ�ͽ���������5��
		return Recursion(src + 5, src + 5, 5);
	}
}

int main2()
{
	/*for (int i = 6;; i += 5)
	{
	int temp = i;
	int j = 0;
	for (; j < 5; ++j)
	{
	if ((temp - 1) % 5 == 0)
	{
	temp = (temp - 1) / 5 * 4;
	}
	else
	{
	break;
	}
	}
	if (j == 5)
	{
	printf("%d\n", i);
	break;
	}
	}*/

	/*for (int i = 6;; i += 5)
	{
	if (Recursion(i,5))
	{
	printf("%d\n", i);
	break;
	}
	}*/
	printf("%d\n", Recursion(6, 6, 5));
	return 0;
}
int sum1(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n + sum1(n - 1);
}
int sumofn = 0;
int sum2(int n)
{
	sumofn += n;
	--n&&sum2(n);
	return 0;
}

typedef int(*f)(int);
f arr[2];//����һ�����飬ÿ����Ա���Ǻ���ָ��
int fun1(int n)
{
	return 0;
}
int fun2(int n)
{
	return n + arr[!!(n - 1)](n - 1);
}
int main3()
{
	int n = 10;
	int ret = 0;
	//��1��n�ĺ�
	//1.-----�ݹ�	
	ret = sum1(n);
	sum2(n);
	printf("%d\n", ret);
	printf("%d\n", sumofn);
	//2.-----ѭ��
	ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret += i;
	}
	printf("%d\n", ret);
	//3.-----������ʽ
	printf("%d\n", n * (n + 1) / 2);
	//4.------����ָ��
	arr[0] = fun1;
	arr[1] = fun2;
	printf("%d\n", fun2(n));
}

/*
��ʱ������������ģ�
��һ����ճԵ���������һ���һ�����ڶ����ֽ�ʣ�µ����ӳԵ�һ���һ�����Ժ�ÿ��Ե�ǰһ��ʣ�µ�һ���һ����
����n��׼���Ե�ʱ��ֻʣ��һ�����ӡ�
�������㣬��������һ�£�����һ�쿪ʼ�Ե�ʱ������һ���ж��ٸ��أ�
*/
//�ڼ���	1    2    3	  4    ...   n
//	����							 1
//day		n    n-1  n-2  n-3       1
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

