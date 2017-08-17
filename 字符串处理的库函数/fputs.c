#include <stdio.h>

int main()
{
	char s[100] = "sfsa";

	fputs(s, stdout);//不会再尾部加上\0
	//fputs(str, filename);

	return 0;
}