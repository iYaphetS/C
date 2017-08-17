#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//---------------------
typedef struct man_info
{
    char *name;
    int  age;
}info;

void inupt_info(info **s, int num)
{
    info *p = *s;
    p = calloc(num, sizeof(info));
    if(p == NULL)
    {
        printf("p == NULL\n");
        return;
    }

    for(int i = 0; i < num; i++)
    {
        char buf[1024] = {0};
        scanf("%s %d", buf, &p[i].age);

        p[i].name = calloc(1, sizeof(strlen(buf)) + 1);
        if(p[i].name == NULL)
        {
            printf("p[i].name == NULL\n");
            break;
        }
        strcpy(p[i].name, buf);
    }
    *s = p;//将开辟的堆空间的首地址赋给*s，*s也指向这片空间
    return;


}
void output_info(info *s, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("%s %d\n", s[i].name, s[i].age);
    }

}

void free_info(info **s, int num)
{
    info *p = *s;

    for(int i = 0; i < num; i++)
    {
        if(p[i].name != NULL)
        {
            free(p[i].name);
            p[i].name = NULL;
        }
    }
    free(p);
    p = NULL;
}

int main28()
{
    /*    课堂代码完善。
    从屏幕上输入一个数 n
    然后输入n个人基本信息(姓名 身高)
         待输入完成之后  将所有的信息全部打印出
         3
         zhangsan 170
         lisi 190
         wanger 175

         第1个人的姓名:zhangsan 身高:170
         第2个人的姓名:lisi     身高:190
         第1个人的姓名:wanger   身高:175
    要求:使用以下形式的结构体
         struct Info_t
    {
        char *name;
        int  age;
      int num;
      };
      */
    int num;
    scanf("%d", &num);

    info *ptr = NULL;
    inupt_info(&ptr, num);

    output_info(ptr, num);

    free_info(&ptr, num);


    return 0;
}