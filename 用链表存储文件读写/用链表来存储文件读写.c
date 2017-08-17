#include <stdio.h>
#pragma warning(disable:4996)
#include "LinkList.h"

typedef struct cfgINFO
{
	char key[64];
	char value[128];
}cfgINFO;
void myforeach(void *data)
{
	cfgINFO * info = (cfgINFO *)data;
	printf("%s=%s\n", info->key, info->value);
}
int main()
{
	FILE *fp = fopen("cfg.txt", "rb");

	LList *list = (LList *)init_LinkList();
	if (list == NULL)
	{
		return;
	}
	char buf[1024] = {0};
	while (fgets(buf, sizeof(buf) - 1, fp) != NULL)
	{
		cfgINFO *info = (cfgINFO *)calloc(1, sizeof(cfgINFO));
		sscanf(buf, "%[^=]=%[^\n]", info->key, info->value);
		insert_LinkList(list, size_LinkList(list), info);
	}
	foreach_LinkList(list, myforeach);
	printf("==========\n");
	delete_LinkList(list, 0);
	foreach_LinkList(list, myforeach);

	fclose(fp);

	fp = fopen("cfg.txt", "wb");

	//for (int i = 0; i < size_LinkList(list); i++)//i++�� size--�����º���Ľڵ��������
	while(size_LinkList(list) > 0)
	{
		//�õ���һ����Ч�ڵ�
		cfgINFO * info = (cfgINFO *)firstnode_LinkList(list);
		fprintf(fp, "%s = %s\n", info->key, info->value);
		delete_LinkList(list, 0);
	}

	destory_LinkList(list);
	fclose(fp);

	return 0;
}

