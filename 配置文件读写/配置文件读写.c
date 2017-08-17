#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#pragma warning(disable:4996)

int main()
{
	char cmd[64] = {0};

	while (1)
	{
		menu();
		scanf("%s", cmd);
		if (strcmp(cmd, "1") == 0)
			write_file();
		else if (strcmp(cmd, "2") == 0)
			read_file();
		else if (strcmp(cmd, "3") == 0)
			system("cls");
		else if (strcmp(cmd, "4") == 0)
			exit(0);
		else
			printf("invalid cmd\n");		
	}

	return 0;
}