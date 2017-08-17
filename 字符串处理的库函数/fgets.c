#include <stdio.h>


int main()
{
	char s[100] = { 0 };

	fgets(s, sizeof(s) - 1, stdin);

	

	printf("[%s]\n", s);

	fputs(s, stdout);
	/*output
	aafac jkdnj13as n`3
	[aafac jkdnj13as n`3
	]
	aafac jkdnj13as n`3
	请按任意键继续. . .
	
	可以知道回车也是字符串s的一部分，因为fputs不会再尾部加回车的，但是继续跑到下一行说明回车在
	字符串s中
	
	
	*/


	return 0;
}