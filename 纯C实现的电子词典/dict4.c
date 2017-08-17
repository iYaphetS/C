#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
char *key;
char **trans;
unsigned int count;
}word_t;

word_t *readdata_createSpace(FILE *fp, unsigned int *pindex)
{
    if(fp == NULL || pindex == NULL)
        return NULL;
    int index = 0;//结构体下标
    int line = 0;//文件行数
    word_t *t = NULL;
    word_t *p = NULL;//用于接结构体指针t进行realloc返回值
    char buf[1024] = {0};
    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        char word[1024] = {0};
        char translate[1024] = {0};
        if(line % 2 == 0)
        {
            //分配结构体内存空间
            p = realloc(t, (index + 1)*sizeof(word_t));
            if(p == NULL)
            {
                printf("realloc fiald\n");
                break;
            }
            sscanf(buf, "#%[^\n]", word);
            //分配key对应的内存空间
            p[index].key = calloc(1, strlen(word) + 1);
            strcpy(p[index].key, word);
        }
        else
        {
            p[index].count = 0;
            sscanf(buf, "%*[^:]:%[^\n]", translate);

            char *f = translate;
            int n = 0;//@的个数，单词翻译的的个数， 比@多一个
            while(*f)
            {
                if(*f == '@')
                    n++;
                f++;
            }
            //先为二级指针trans根据每个单词个数分配一片指针数组
            p[index].trans = calloc(n + 1, sizeof(char *));

            char *k = strtok(translate, "@");
            while(k)
            {
                //然后对指针数组每个成员分配内存空间，并将每个翻译分别拷贝到对应内存空间
                p[index].trans[p[index].count] = calloc(1, strlen(k) + 1);
                strcpy( p[index].trans[p[index].count], k);
                p[index].count++;
                k = strtok(NULL, "@");
            }

            index++;
        }

        t = p;
        line++;
        memset(buf, 0, sizeof(buf));
    }
    *pindex = index;
    return p;
}

void search(char *buf, word_t *t, unsigned int index)
{
    if(buf == NULL || t == NULL || index < 0)
    {
        return;
    }
    unsigned int i,j,ret = 0;
    for(i = 0; i < index; i++)
    {
        if(strcmp(buf, t[i].key) == 0)
        {
            for(j = 0; j < t[i].count; j++)
            {
                printf("%d. %s\n", j+1, t[i].trans[j]);
            }
            ret = 1;
            break;
        }
    }
    if(ret == 0)
    {
        printf("not found\n");
    }
}

void freespace(word_t **pt, unsigned int index)
{
    if(pt == NULL || index < 0)
    {
        return;
    }
    word_t *t = *pt;
    unsigned int i,j;
    for(i = 0; i < index; i++)
    {
        if(t[i].key != NULL)
        {
            free(t[i].key);
            t[i].key = NULL;
        }
        if(t[i].trans != NULL)
        {
            for(j = 0; j < t[i].count; j++)
            {
                free(t[i].trans[j]);
                t[i].trans[j] = NULL;
            }
            free(t[i].trans);
            t[i].trans = NULL;
        }

    }
    free(t);
    t = NULL;
}



int main()
{

    FILE *fp = fopen("dict.txt", "r");

    char buf[1024] = {0};
    unsigned int index = 0;//结构体下标

    word_t *t = readdata_createSpace(fp, &index);

    while(1)
    {
        printf("please input word:");
        scanf("%s", buf);
        if(strcmp(buf, "exit-command") == 0)
            break;
        printf("translate:\n");
        search(buf, t, index);
    }

    freespace(&t, index);

    fclose(fp);
    return 0;
}



