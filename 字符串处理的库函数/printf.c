#include <stdio.h>

int main()
{
	
	printf("%c %c\n", 's', 12);
	printf("%d %ld\n", 100, 100L);
	printf("%10d\n", 100);//右对齐，不足十位补齐空格
	printf("[%-10d]\n", 100);//左对齐，不足十位的补齐空格
	printf("%010d\n", 100);//右对齐，不足十位的补足0，左对齐就不能这样，否则数值发生改变了
	printf("%d %o %x %X %#x %#X\n", 100, 100, 100, 100, 100, 100);
	printf("[%6.2f]\n", 9.22);//%m.nf总长度m，小数n位，右对齐不足补足空格
	printf("a=%db=%*dc=%d\n", 200, 10, 30, 20);//*表示跳过对应的变量值
	//output a = 200 b =          30  c = 20;
	printf("%s\n", "abc");


	return 0;
}