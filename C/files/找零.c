#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int bills[n];

    //初始化输入
    for (int i = 0; i < n; i++)
    {
        bills[i] = i;
    }


    for (int j = 0; j < n; j++)
    {
        scanf("%d", &bills[j]);
    }

    //主体判断
    int get = 0;
    int five = 0;
    int ten = 0;
    int twenty = 0;
    for (int i = 0; i < n; i++)
    {
        get = bills[i];
        if (get == 5)
        {
            five++;
            continue;
        }
        if (get == 10)
        {
            if (five >= 1)
            {
                five--;
                ten++;
            }
            else
            {
                printf("false");
                goto out;
            }
        }
        if (get == 20)
        {
            if (ten >= 1 && five >= 1)
            {
                twenty++;
                ten--;
                five--;
                continue;
            }
            if (five >= 3)
            {
                twenty++;
                five -= 3;
                continue;
            }
            //如果都不满足的话
            printf("false");
            goto out;
        }
    }
    printf("true");
out:
    return 0;
}