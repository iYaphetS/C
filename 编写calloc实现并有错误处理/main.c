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
    //�޷��ŵ�int���40���ڵ�temp���������������ˣ����һ����С����
    //����Ҫ�ж���˵Ľ���Ƿ������û���������ռ䲢��գ����߷���NULL
    if(temp / rmemb == size)
    {
        p = malloc(rmemb * size);
        memset(p, 0, rmemb * size);
    }
    return p;
}

int main23()
{
    /*
    ��дcalloc��ʵ��,ͨ������mallocִ�з���,����memset���ڴ�����Ϊ00��Ĵ���Ӧ��û���κ���������������©��,������������size\_t�ö���λ��ʾ,���붼Ӧ������������
    �⺯��calloc����������:

     void *calloc(size_t rmemb, size_t Size) ;
     ���ݿ��ĵ�: ������callocΪһ����������ڴ�,��������rmemb��Ԫ��,ÿ��Ԫ��Ϊsize�ֽڡ��ڴ�����Ϊ00,���rmemb��sizeΪ0,��calloc����NULL��


     ��Ϊ�ο�,����malloc��memset��������:

     void malloc(size_t Size) ;
      void memset(void *s, int c, size_t n);
*/
    int *p = mycalloc(2000000000, sizeof(int));
    free(p);
    return 0;
}