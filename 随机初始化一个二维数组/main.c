#include <stdio.h>

int main()
{
    /*
���������ʼ��һ����ά���� ���Ҵ�ӡ�����ά����.
*/

    srand((unsigned)time(NULL));//include <time.h>
    int i,j;
    int arr[3][5] = {0};
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 5; j++)
        {
            arr[i][j] = rand() % 100 + 1;
            printf("arr[%d][%d] = %d ", i, j, arr[i][j]);
        }
    }
    return 0;
}