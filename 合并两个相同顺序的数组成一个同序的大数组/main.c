#include <stdio.h>


#define LEN (sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0]))

int main9()
{
    /*
用代码实现 合并两个<前提条件：增序有序>的数组arr1,arr2到arr3中并且保持元素增序有序。
int arr1[] = {1,2,5,7,8};int arr2[]={2,3,4,6,9};
合并后arr3结果为{1,2,2,3,4,5,6,7,8,9};
*/
    //方法分析：先定义一个两个数组长度之和的变长数组，然后将两个数组中每个元素依次比较
    //较小的就放在新数组中，并把较小数的数组下标加1，后面同理直到某一个数组的元素全部放到新数组中结束
    //然后将没有放完的数组元素追加放到新数组中
    int a[] = {2, 6, 8, 18};
    int b[] = {1, 3, 4, 7, 10, 16};
    int len1 = sizeof(a) / sizeof(a[0]);
    int len2 = sizeof(b) / sizeof(b[0]);

    int c[LEN];//变长数组不能初始化，宏定义的，scanf输入的数组长len都可以作为数组长度

    int i,j,k = 0;

    for(i = 0,j = 0;i < len1 && j < len2;)
    {
        //if(a[i] < a[j])
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    if(k == len1)
    {
        while(j < len2)
            c[k++] = b[j++];
    }
    else
    {
        while(i < len1)
            c[k++] = a[i++];
    }


    for(k = 0; k < LEN; k++)
    {
        printf("c[%d] = %d\n", k, c[k]);
    }

    return 0;
}