#include <stdio.h>


#define LEN (sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0]))

int main9()
{
    /*
�ô���ʵ�� �ϲ�����<ǰ����������������>������arr1,arr2��arr3�в��ұ���Ԫ����������
int arr1[] = {1,2,5,7,8};int arr2[]={2,3,4,6,9};
�ϲ���arr3���Ϊ{1,2,2,3,4,5,6,7,8,9};
*/
    //�����������ȶ���һ���������鳤��֮�͵ı䳤���飬Ȼ������������ÿ��Ԫ�����αȽ�
    //��С�ľͷ����������У����ѽ�С���������±��1������ͬ��ֱ��ĳһ�������Ԫ��ȫ���ŵ��������н���
    //Ȼ��û�з��������Ԫ��׷�ӷŵ���������
    int a[] = {2, 6, 8, 18};
    int b[] = {1, 3, 4, 7, 10, 16};
    int len1 = sizeof(a) / sizeof(a[0]);
    int len2 = sizeof(b) / sizeof(b[0]);

    int c[LEN];//�䳤���鲻�ܳ�ʼ�����궨��ģ�scanf��������鳤len��������Ϊ���鳤��

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