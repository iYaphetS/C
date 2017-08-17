#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

//第一天1棵，荷花数目每天都是翻倍的，到第30满了，求第23天占几分之几
int count(int n)
{
	if (n == 1)
		return 1;
	return count(n - 1) * 2;

}

//求一个数的二进制数
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
//数转二进制
void dec2bin(int n)
{
	for (int i = 31; i >= 0; --i)
	{
		printf("%d", n >> i & 1);
	}
}

//字符串反转
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
	printf("%d分之一\n", n);

	dec_to_bit(5);
	printf("\n");

	char str[] = "hello";
	char buf[100] = {0};
	inverse(str, buf);
	printf("%s", buf);
	return 0;
}
//五只猴子分桃。
//半夜，第一只猴子先起来，它把桃分成了相等的五堆，多出一只。于是，它吃掉了一个，拿走了一堆； 
//第二只猴子起来一看，只有四堆桃。于是把四堆合在一起，分成相等的五堆，又多出一个。于是，它也吃掉了一个，拿走了一堆；
//.....其他几只猴子也都是 这样分的。
//问：这堆桃至少有多少个？

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
	//src桃子的数目（采用的是穷举的算法，就是一个个数去试，当然是符合规定的数）
	//进行分解桃子数
	if (count == 0)//递归终止条件是这个数能够进行分解了5次
		return src;
	if ((n - 1) % 5 == 0)
	{
		//如果能分解，就将剩下的再进行分解
		return Recursion(src, (n - 1) / 5 * 4, count - 1);
	}
	else
	{
		//如果不能分解就将桃子数加5，
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
f arr[2];//定义一个数组，每个成员都是函数指针
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
	//求1到n的和
	//1.-----递归	
	ret = sum1(n);
	sum2(n);
	printf("%d\n", ret);
	printf("%d\n", sumofn);
	//2.-----循环
	ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret += i;
	}
	printf("%d\n", ret);
	//3.-----算术公式
	printf("%d\n", n * (n + 1) / 2);
	//4.------函数指针
	arr[0] = fun1;
	arr[1] = fun2;
	printf("%d\n", fun2(n));
}

/*
当时的情况是这样的：
第一天悟空吃掉桃子总数一半多一个，第二天又将剩下的桃子吃掉一半多一个，以后每天吃掉前一天剩下的一半多一个，
到第n天准备吃的时候只剩下一个桃子。
聪明的你，请帮悟空算一下，他第一天开始吃的时候桃子一共有多少个呢？
*/
//第几天	1    2    3	  4    ...   n
//	个数							 1
//day		n    n-1  n-2  n-3       1
int calc_peach(int n)//day n  -----第一天   day  n-1 第二天
{

	if (n == 1)//最后一天
		return 1;
	else
		//求calc_peach(n) = (calc_peach(n - 1) + 1) * 2----第一天总个数
		return (calc_peach(n - 1) + 1) * 2;
}

//阶乘
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

