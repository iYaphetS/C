#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void *mycalloc(size_t rmemb, size_t size)
{
    void * p = NULL;
    if(rmemb == 0 && size == 0)
    {
        return NULL;
    }
    int temp = rmemb * size;
    //无符号的int最大40多亿当temp超过这个数就溢出了，变成一个很小的数
    //所以要判断相乘的结果是否溢出，没有溢出分配空间并清空，否者返回NULL
    if(temp / rmemb == size)
    {
        p = malloc(rmemb * size);
        memset(p, 0, rmemb * size);
    }
    return p;
}

int main()
{
    /*
    编写calloc的实现,通过调用malloc执行分配,调用memset将内存设置为00你的代码应该没有任何由算术溢出引起的漏洞,且无论数据类size\_t用多少位表示,代码都应该正常工作。
    库函数calloc有如下声明:

     void *calloc(size_t rmemb, size_t Size) ;
     根据库文档: “函数calloc为一个数组分配内存,该数组有rmemb个元素,每个元素为size字节。内存设置为00,如果rmemb或size为0,则calloc返回NULL。


     作为参考,函数malloc和memset声明如下:

     void malloc(size_t Size) ;
      void memset(void *s, int c, size_t n);
*/
    int *p = mycalloc(2000000000, sizeof(int));
    free(p);
    return 0;
}