#include <stdio.h>

int main()
{
	char s[100] = "sfsa";

	fputs(s, stdout);//������β������\0
	//fputs(str, filename);

	return 0;
}