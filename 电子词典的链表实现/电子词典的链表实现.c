#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

typedef struct word_t
{
	char *key;
	char **trans;//为每个意思都单独申请堆空间存放
	unsigned int count;//解释的个数
	struct word_t *next;
}word_t;

word_t *readdata_createSpace(FILE *fp)
{
	if (fp == NULL)
		return NULL;
	int line = 0;//文件行数
	
	word_t *pHead = (word_t*)calloc(1, sizeof(word_t));
	word_t *pNew = NULL;
	word_t *temp = pHead;

	char buf[1024] = { 0 };
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		char word[1024] = { 0 };
		char translate[1024] = { 0 };
		if (line % 2 == 0)
		{
			//分配结构体内存空间
			pNew = (word_t*)calloc(1, sizeof(word_t));
			if (pNew == NULL)
			{
				printf("calloc fiald\n");
				break;
			}
			sscanf(buf, "#%[^\n]", word);
			//分配key对应的内存空间
			pNew->key = calloc(1, strlen(word) + 1);
			strcpy(pNew->key, word);
		}
		else
		{
			pNew->count = 0;
			sscanf(buf, "%*[^:]:%[^\n]", translate);

			char *f = translate;
			int n = 0;//@的个数，单词翻译的的个数， 比@多一个
			while (*f)
			{
				if (*f == '@')
					n++;
				f++;
			}
			//先为二级指针trans根据每个单词个数分配一片指针数组
			pNew->trans = calloc(n + 1, sizeof(char *));

			char *k = strtok(translate, "@");
			while (k)
			{
				//然后对指针数组每个成员分配内存空间，并将每个翻译分别拷贝到对应内存空间
				pNew->trans[pNew->count] = calloc(1, strlen(k) + 1);
				strcpy(pNew->trans[pNew->count], k);
				pNew->count++;
				k = strtok(NULL, "@");
			}

		}		
		line++;
		memset(buf, 0, sizeof(buf));

		temp->next = pNew;
		pNew->next = NULL;
		temp = pNew;
	}

	return pHead;
	/*
	
	*/
}

void search(char *buf, word_t *t)
{
	if (buf == NULL || t == NULL )
	{
		return;
	}
	word_t *pHead = t;
	word_t *temp = pHead->next;

	unsigned int i, ret = 0;
	while (temp != NULL)
	{
		if (strcmp(buf, temp->key) == 0)
		{
			for (i = 0; i < temp->count; i++)
			{
				printf("%d. %s\n", i + 1, temp->trans[i]);
			}
			ret = 1;
			break;
		}
		temp = temp->next;
	}
	if (ret == 0)
	{
		printf("not found\n");
	}

}

void freespace(word_t **pt)
{
	if (pt == NULL )
	{
		return;
	}
	word_t *del = *pt;
	word_t *temp = *pt;
	unsigned int i;
	while(temp != NULL)
	{
		temp = temp->next;
		if (del->key != NULL)
		{
			free(del->key);
			del->key = NULL;
		}
		if (del->trans != NULL)
		{
			for (i = 0; i < del->count; i++)
			{
				free(del->trans[i]);
				del->trans[i] = NULL;
			}
			free(del->trans);
			del->trans = NULL;
		}
		free(del);
		del = NULL;
		del = temp;
	}
	*pt = NULL;
}



int main()
{
	long start_ms = 0;//记录函数执行的开始时间
	long end_ms = 0;//记录函数执行的结束时间

	start_ms = clock();
	FILE *fp = fopen("dict.txt", "r");
	if (fp == NULL)
		return -1;	
	word_t *t = readdata_createSpace(fp);//返回结构体类型的头节点的的指针
	end_ms = clock();
	printf("open_dict used %ld ms\n\n", end_ms - start_ms);//打印函数执行时间，单位：毫秒

	char buf[1024] = { 0 };
	while (1)
	{
		printf("please input word:");
		scanf("%s", buf);
		if (strcmp(buf, "exit-command") == 0)
			break;
		printf("translate:\n");
		start_ms = clock();
		search(buf, t);
		end_ms = clock();
		printf("search_dict used %ld ms\n\n", end_ms - start_ms);//打印函数执行时间，单位：毫秒
	}

	start_ms = clock();
	freespace(&t);
	end_ms = clock();
	printf("free_dict used %ld ms\n", end_ms - start_ms);//打印函数执行时间，单位：毫秒

	fclose(fp);
	return 0;
}



