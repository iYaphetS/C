#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable:4996)
//编写一个函数。其参数为一个字符串，函数删除字符串中的空格

void deleteSpace1(char *buf)
{

	char *s = buf;
	s = s + strlen(s) - 1;
	while (isspace(*s))
	{
		*s = '\0';
		s--;
	}
	s = buf;
	while (isspace(*s))
		s++;
	strcpy(buf, s);
}

void deleteSpace2(char *buf)
{
	char *t = buf;
	char *p = buf;
	char *q = buf;

	q = buf + strlen(buf) - 1;
	while (isspace(*p))
		p++;
	while (isspace(*q))
	{
		*q = '\0';
		q--;
	}	
	strcpy(t, p);

}
int main()
{
	char buf[] = "   hello i k  ";

	//deleteSpace1(buf);
	
	deleteSpace2(buf);

	printf("%s\n", buf);

	return 0;
}