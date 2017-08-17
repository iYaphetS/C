#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01()
{
	char s[10] = {0};

	gets(s);
	for (int i = 0; i < 10; i++)
	{	
		printf("%d\n", s[i]);
	}
	printf("--------------\n");
	printf("%s\n", s);
	return 0;
}

//gets和 scanf都存在缓冲区溢出的问题，如果出现输入的字符串大于数组的长度
//就会导致程序崩溃
//scanf将空格当成结束标志，而gets不会

//fgets函数是读取文件，解决了缓冲区溢出的问题

//关于输入字符串，输入有效的总比数组长度少一，是因为字符串是以0结尾的，占一位

int main02()
{
	char s[10] = {0};
	fgets(s, sizeof(s) - 1, stdin);

	for (int i = 0; i < 10; i++)
	{	
		printf("%d\n", s[i]);
	}
	printf("-----------");
	printf("%s\n", s);
	return 0;
}

int main03()
{
	//put函数与printf不同，它会字符串尾部自动加上‘\n’
	char s[] = "hello world";
	puts(s);
	//fput是对文件操作输出的
	fputs(s, stdout);


	return 0;
}


//字符串操作包含于string.h 文件中
int main04()
{
	char s[100] = "leo hello";

	int len = strlen(s);//得到字符串长度，返回的书字符串 有效字符串的数量不包含字符串结尾的0

	printf("len = %d, slen = %d\n", len, sizeof(s));


	return 0;
}

int main05()
{
	char s1[1024] = "hello adu";

	char s2[] = " how are you";
	strcat(s1, s2);



	printf("%s\n", s1);

	return 0;
}

int main06()
{
	char s1[1024] = "sfuhua";
	char s2[1000] = "fjhudquha";

	strncat(s1, s2, 5);

	puts(s1);
	return 0;
}

int main07()
{	
	char s1[100] = "abcd";
	char s2[10] = "abcdf";
	if (!strcmp(s1, s2))
	{
		printf("s1, s2字符串相同\n");
	}else
	{
		printf("s1, s2字符串不相同\n");
	}
	return 0;
}

int main08()
{
	char s1[100] = "suhaufu";
	char s2[10] = "suhau";

	if (!strncmp(s1, s2, 5))
	{	
		printf("s1, s2字符串相同\n");
	}else
	{
		printf("s1, s2字符串不相同\n");
	}
	return 0;
}

int main09()
{
	char s1[1024] = "ahdu7u";

	char s2[100] = {0};

	strcpy(s2, s1);

	puts(s2);

	return 0;
}

int main10()
{
	char s1[100] = "jjdiajduq";
	char s2[100] = {0};

	strncpy(s2, s1, 5);

	puts(s2);

	return 0;
}

int main11()
{
	char s1[100] = "i";
	char s2[100] = "csdn";

	

	char s[1024] = {0};

	sprintf(s,"%s love %s", s1, s2);

	puts(s);

	sprintf(s, "%10.3f", 3.141592);//%m.nf输出方式是将浮点数保留小数n位按m位输出（

	//其中包括小数点），右对齐的方式，不足m位最前补足空格

	puts(s);

	return 0;

}

//重点sscanf的用法
int main()
{

	char *string;
	int num = 0;

	int ret = 0;

	char  buf1[100] = { 0 };
	char  buf2[100] = { 0 };
	char  buf3[100] = { 0 };
	char  buf4[100] = { 0 };
	//1.截取长字符串中的短字符串
	string = "i love china 123";
	ret = sscanf(string, "%s %s %s %d", buf1, buf2, buf3, &num);

	printf("%d, %s, %s, %s, %d\n\n", ret, buf1, buf2, buf3, num);

	//2.取指定长度的字符串
	string = "helloworld";
	ret = sscanf(string, "%9s", buf1);

	printf("%d, %s\n\n", ret, buf1);

	//3.取到指定字符为止的字符串
	string = "share/hehe";
	ret = sscanf(string, "%[^/]", buf1);

	printf("%d, %s\n\n", ret, buf1);

	//4.取到指定字符集为止的字符串
	string = "12345ABabc";
	ret = sscanf(string, "%[^A-Z]", buf1);

	printf("%d, %s\n\n", ret, buf1);

	//5.取仅包含指定字符集的字符串
	string = "0234ASDazx";
	ret = sscanf(string, "%[0-9]%[A-Z]%[a-z]", buf1, buf2, buf3);

	printf("%d %s, %s, %s\n\n", ret, buf1, buf2, buf3);

	ret = sscanf(string, "%d%[A-Z]%[a-z]", &num, buf2, buf3);
	printf("%d, %d, %s, %s\n\n", ret, num, buf2, buf3);

	//6.获取指定字符中间的字符串
	string = "sss<hah>qeb";
	ret = sscanf(string, "%*[^<]<%[^>]", buf1);//%*[^<]去掉*的内容直到<

	printf("%d, %s\n\n", ret, buf1);

	//7.指定要跳过的字符串
	string = "djauhABjdku";
	//ret = sscanf(string, "%sAB%s", buf1, buf2);ERRO
	ret = sscanf(string, "%[a-z]AB%[a-z]", buf1, buf2);

	printf("%d, %s, %s\n\n", ret, buf1, buf2);

	//8.分割以某个字符隔开的字符串

	string = "tom-sary-tim123";
	ret = sscanf(string, "%[^-]-%[^-]-%[^-]", buf1, buf2, buf3);

	printf("%d, %s, %s, %s\n\n", ret, buf1, buf2, buf3);

	//9.提取邮箱的地址
	string = "Email:wencheng20@126.com";
	ret = sscanf(string, "%*[^:]:%s", buf1);

	printf("%d, %s\n\n", ret, buf1);

	ret = sscanf(string, "%*[^:]:%[^@]@%[^.]",buf1, buf2);

	printf("%d, %s, %s\n\n", ret, buf1, buf2);

	//10过滤掉不要的字符串
	string = "android iphone wp";
	ret = sscanf(string, "%s %*s %s", buf1, buf2);

	printf("%d, %s, %s\n\n", ret, buf1, buf2);


	//将7与10进行比较,我们可以看出，sscanf以%s输入输入数据与scanf是相同的，当遇到空格时代表字符串的结束
	//这就是为什么10可以用%s而7却要使用%[a-z]



	return 0;
}