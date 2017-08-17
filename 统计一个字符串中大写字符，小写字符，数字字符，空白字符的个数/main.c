
#include <stdio.h>
#include <ctype.h>

int main8()
{
    /*
给定一串字符串\(长度为n\)
统计其中出现的大写字母、小写字母、数字字符、空白字符\(' ','\n'、'\t'等\)等的数量。
*/
    char s[] = "2267s j54u wj 398\t\n";
    int number[10] = {0};//计数0-9各个数字出现的次数
    int count1 = 0, count2 = 0, count3 = 0;//分别计数大写字母小写字母空白字符的个数
    int len = strlen(s);

    for(int i = 0; i < len; i++)
    {
        if(islower(s[i]))//小写字母
            count1++;
        if(isupper(s[i]))//大写字母
            count2++;
        if(isdigit(s[i]))
            //if(s[i] >= '0' && s[i] <= '9')
            number[s[i] - '0']++;
        //if(s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        if(isspace(s[i]))//空白字符
            count3++;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("number[%d] = %d\n", i, number[i]);
    }
    printf("%d %d %d\n", count1, count2, count3);
    return 0;
}