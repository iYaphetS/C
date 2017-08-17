#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
char *key;
char **trans;
unsigned int count;
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
        char translate[1024] = {0};
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
            p[index].count = 0;
            sscanf(buf, "%*[^:]:%[^\n]", translate);

            char *f = translate;
            int n = 0;//单词翻译的的个数， 比@多一个
            while(*f)
            {
                if(*f == '@')
                    n++;
                f++;
            }

            p[index].trans = calloc(n + 1, sizeof(char *));

            char *k = strtok(translate, "@");
            while(k)
            {
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

    fclose(fp);


    memset(buf, 0, sizeof(buf));
    while(1)
    {
        printf("please input word:");
        scanf("%s", buf);
        if(strcmp(buf, exit-command) == 0)
            break;
        printf("translate:\n");
    }
    int i,j;
    for(i = 0; i < index; i++)
    {
        if(strcmp(buf, t[i].key) == 0)
        {
            for(j = 0; j < t[i].count; j++)
            {
                printf("%d. %s\n", j+1, t[i].trans[j]);
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

    return 0;
}



