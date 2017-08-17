#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct word_t
{
    char *key;
    char *content;
}word_t;


//方法一先读一遍文件算出文件行数

int main()
{

    FILE *fp = fopen("dict.txt", "r");

    char buf[1024] = {0};
    int count = 0;//计算文件行数
    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        count++;
    }
    //printf("%d\n", count);
    fclose(fp);

    fp = fopen("dict.txt", "r");

    word_t *t = calloc(count / 2, sizeof(word_t));
    int index = 0;
    int line = 0;
    memset(buf, 0, sizeof(buf));
    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        char word[1024] = {0};
        char trans[1024] = {0};
        if(line % 2 == 0)
        {
            sscanf(buf, "#%[^\n]", word);
            t[index].key = calloc(1, strlen(word) + 1);
            strcpy(t[index].key, word);
        }
        else
        {
            sscanf(buf, "%*[^:]:%[^\n]", trans);
            t[index].content = calloc(1, strlen(trans) + 1);
            strcpy(t[index].content, trans);
            index++;
        }
        line++;
        memset(buf, 0, sizeof(buf));
    }
    fclose(fp);

    memset(buf, 0, sizeof(buf));
    printf("please input word:");
    scanf("%s", buf);
    printf("trans:\n");

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


