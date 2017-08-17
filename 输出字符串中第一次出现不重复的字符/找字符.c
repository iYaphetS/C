#include <stdio.h>
#include <string.h>

/*
* 输入一个字符串，输出其中第一次出现的不重复的字符
* 例如: 输入 aabccdeff 则输出 b
*/
int main1()
{
    char *s = "1aaCbcbfAAccddhh";

    int len = strlen(s);

    int i, j;
    int flag;
    for (i = 0; i < len; i++)
    {
        flag = 0;
        for (j = 0; j < len; j++)
        {
            if (j == i)
                //j++;//可能访问溢出
                continue;
            if (s[i] == s[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%c\n",s[i]);
            break;
        }
    }
    return 0;
}

int main()
{
    char *s = "112D33aabbcc";

    int num[256] = {0};
    int index[256] = {0};

    int len = strlen(s);

    int i;
    for (i = 0; i < len; i++)
    {
        num[s[i]]++;//记录每个字符出现的个数
        index[s[i]] = i;//记录每个字符的最后出现的下标
    }

    int min = len;
    for (i = 0; i < len; i++)
    {
        if (num[s[i]] == 1 )
        {
            min = index[s[i]];
            break;
        }
    }

    printf("%c", s[min]);


    return 0;
}
