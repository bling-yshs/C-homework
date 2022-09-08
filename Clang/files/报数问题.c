#include <stdio.h>
int main()
{
    int num[20];
    int n;
    int *p;
    p = num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        num[i] = i + 1;
    }
    int m = 0; //退出的人数
    int k = 0; //目前报数的数
    int i = 0; //目前轮次进行到第几个数
    while (m < n - 1)
    {
        if (*(p + i) != 0)
        {
            k++;
        }
        if (k == 3)
        {
            *(p + i) = 0; //叫到3的数变为0
            m++;
            k = 0;
        }
        i++;
        if (i == n)
        {
            i = 0;
        }
    }
    i = 0;

    //找出不是0的数
    while (*(p + i) == 0)
    {
        i++;
    }
    printf("%d", i + 1);
    return 0;
}
