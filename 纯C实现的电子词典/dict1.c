#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct word_t
{
    char *key;
    char *content;
}word_t;


//方法二边读变申请结构体内存空间

int main()
{

    FILE *fp = fopen("dict.txt", "r");

    char buf[1024] = {0};

    word_t *t = NULL;
    word_t *p = NULL;
    int index = 0;//结构体下标
    int line = 0;//文件行数

    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        char word[1024] = {0};
        char trans[1024] = {0};
        if(line % 2 == 0)
        {
            p = realloc(t, (index + 1)*sizeof(word_t));
            if(p == NULL)
            {
                printf("realloc fiald\n");
                break;
            }
            sscanf(buf, "#%[^\n]", word);
            p[index].key = calloc(1, strlen(word) + 1);
            strcpy(p[index].key, word);
        }
        else
        {
            sscanf(buf, "%*[^:]:%[^\n]", trans);
            p[index].content = calloc(1, strlen(trans) + 1);
            strcpy(p[index].content, trans);
            index++;
        }

        t = p;
        line++;
        memset(buf, 0, sizeof(buf));
    }

    fclose(fp);

    memset(buf, 0, sizeof(buf));
    printf("please input word:");
    scanf("%s", buf);
    printf("translate:\n");

    int i;
    for(i = 0; i < index; i++)
    {
        if(strcmp(buf, t[i].key) == 0)
        {
            char *p = strtok(t[i].content, "@");
            while(p)
            {
                printf("%s\n", p);
                p = strtok(NULL, "@");
            }
        }
    }
    for(i = 0; i < index; i++)
    {
        if(t[i].key != NULL)
        {
            free(t[i].key);
            t[i].key = NULL;
        }
        if(t[i].content != NULL)
        {
            free(t[i].content);
            t[i].content = NULL;
        }

    }
    free(t);
    t = NULL;

    return 0;
}


