#include <stdio.h>
#include <string.h>
#pragma once
#pragma execution_character_set("UTF-8")

int main()
{
	char buf[1024] = "¹þ¹þ";

	printf("%d\n", strlen(buf));

	return 0;
}