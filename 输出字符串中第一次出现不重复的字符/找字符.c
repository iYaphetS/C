#include <stdio.h>
#include <string.h>

/*
* ����һ���ַ�����������е�һ�γ��ֵĲ��ظ����ַ�
* ����: ���� aabccdeff ����� b
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
                //j++;//���ܷ������
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
        num[s[i]]++;//��¼ÿ���ַ����ֵĸ���
        index[s[i]] = i;//��¼ÿ���ַ��������ֵ��±�
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
