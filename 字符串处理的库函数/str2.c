#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main()
{
	
	/*
	
    有一个字符数组
    整数是任意的，中间可能是* + - /
    char a[100] = "43+56="
    写一个程序，将结算的结果追加到字符串a的后面
    程序执行完成后a的值是"43+56=99"
    
	*/
	//分析，由于要追加，就要有两个字符数组来分别存储计算表达式和运算结果
	char buf1[100] = { 0 };
	char buf2[100] = { 0 };
	int num1 = 0;
	int num2 = 0;

	//scanf("%s", buf1);
	fgets(buf1, sizeof(buf1), stdin);//fgets会把回车当成字符串的一部分实际输入的是24+23=\n\0实际有效字符是7个

	printf("%d\n", strlen(buf1));
	buf1[strlen(buf1) - 1] = '\0';

	sscanf(buf1, "%d+%d=", &num1, &num2);//将字符串中字符格式化控制符存放在变量中

	sprintf(buf2, "%d", num1 + num2);//将变量以格式化方式存放到变量中

	strcat(buf1, buf2);

	printf("%s\n", buf1);
	
	/*字符串已经确定，不用手动从屏幕输入
		char a[100] = "43+56=";
    char s[100] = {0};
    int num1, num2;
    sscanf(a, "%d+%d=", &num1, &num2);
    
    sprintf(s, "%d", num1 + num2);

    strcat(a, s);

    printf("%s" , a);
	
	*/


	return 0;
}