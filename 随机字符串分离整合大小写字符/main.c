#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void TransString(char *pstr,char len)
{
   //方法一冒泡排序，条件筛选，前面的字符是大写，下一个字符是小写，就将他交换
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(isupper(pstr[j]) && islower(pstr[j + 1]))
            {
                char temp = pstr[j];
                pstr[j] = pstr[j + 1];
                pstr[j + 1] = temp;
            }

        }
    }
    //方法二遍历字符串，遇到大写字符，将它放到零时变量中，将后面的字符串整体向前移动
    //然后将它放到字符尾部
//    int num = 0;
//    char *p = pstr;
//    while(*p)
//    {
//        if(islower(*p))
//            num++;
//        p++;
//    }
//    p = pstr;
//    int count = 0;
//    while(*p)
//    {
//        if(isupper(*p))
//        {
//            char temp = *p;
//            for(int i = 0; i < len - count - 1; i++)
//                p[i] = p[i + 1];
//            p[len - count - 1] = temp;
//        }
//        else
//        {
//            p++;
//            count++;//计算小写字母的个数
//        }
//        if(count == num)
//            break;
//    }

}

int main42()
{
/*
将一串随机形成的字符串中的大写字母按照原来的顺序放置到字符串后半部分
小写字母置于字符串前半部分。
形如 AbCdefGHijLKdfkjf
     ACGHLKbdefijdfkjf
函数原型如下 int TransString(char *pstr,char len);
实现上述函数对字符串进行转换  提示额外空间尽量少。
*/
    char buf[100] = "AbCdefGHijLKdfkjf";
    int len = strlen(buf);
    TransString(buf, len);

    printf("%s\n", buf);

}