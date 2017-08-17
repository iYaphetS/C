#include <stdio.h>
#pragma warning(disable:4996)
//计算一个无符号的数中，二进制位中值为 1 的个数
//提示： >>

int count_one_bits(unsigned int tmp)
{
	int count = 0;
	/*while (tmp)
	{
		if ((tmp & 01) == 1)
			count++;
		tmp >>= 1;//temp = temp >> 1;//注意是无符号数
	}*/
	while (tmp)
	{
		tmp = tmp & (tmp - 1);//每运算一次将tmp二进制位上（从右向左）1变成0，知道tmp变成0
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