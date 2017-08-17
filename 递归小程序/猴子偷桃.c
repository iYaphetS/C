#include <stdio.h>

/*
当时的情况是这样的：
第一天悟空吃掉桃子总数一半多一个，第二天又将剩下的桃子吃掉一半多一个，以后每天吃掉前一天剩下的一半多一个，
到第n天准备吃的时候只剩下一个桃子。
聪明的你，请帮悟空算一下，他第一天开始吃的时候桃子一共有多少个呢？
*/
//第几天	1    2    3	  4    ...   n
//		最多                      1
//day	n    n-1  n-2  n-3        1
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

