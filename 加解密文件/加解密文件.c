#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "des.h"
#include "des_file.h"
#pragma warning(disable:4996)

int main()
{
	char cmd[64];
	while (1)
	{
		menu();
		printf("cmd:");
		scanf("%s", cmd);
		if (strcmp(cmd, "1") == 0)
			DesEncfile();
		else if (strcmp(cmd, "2") == 0)
			DesDecfile();
		else if (strcmp(cmd, "3") == 0)
			system("cls");
		else if (strcmp(cmd, "4") == 0)
			exit(0);
		else
			printf("invalide cmd\n");
	}

	return 0;
}