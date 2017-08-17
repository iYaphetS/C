#include <stdio.h>
#include <ctype.h>
#pragma warning(disable:4996)

void dele_space(char *s)
{
	char *p = s;
	char *q = s;
	
	while (*p)
	{
		if (isspace(*p))
			p++;
		else
			*q++ = *p++;
	}
	*q = '\0';
}
int main()
{
	char s[] = " hehk kauh j jy ";
	dele_space(s);
	printf("%s\n", s);
	return 0;
}