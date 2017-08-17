#include <stdio.h>
#pragma warning(disable:4996)
#include <string.h>

int main()
{
	/*
	从屏幕输入两个字符串，比较是否相同，关于字符比较和字符串的比较是不同的，字符可以用==或strcmp，但是字符串只能用strcmp
	*/
	char s1[100] = {0};
	char s2[100] = {0};
	//涉及到字符串的比较，追加，拷贝，都要有两个字符数组来存储这两个字符串

	fgets(s1, sizeof(s1) - 1, stdin);//把回车当成字符串的一部分,所以有效字符的长度实际是strlen(s1) - 1
	s1[strlen(s1) - 1] = '\0';
	//scanf("%s", s1);
	fgets(s2, sizeof(s2) - 1, stdin);
	s2[strlen(s2) - 1] = '\0';
	//scanf("%s", s2);
	if (0 == strcmp(s1, s2))
	{
		printf("字符串相同\n");
		strcat(s1, s2);
	}
	else
	{	
		printf("字符串不相同\n");
		//strcat(s1, s2);
		strcpy(s1, s2);
	}

	printf("%s", s1);


	return 0;
}