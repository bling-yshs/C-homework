#include <stdio.h>
int isPrime(int number1)
{
    int i, flag = 0, j = 0;

    for (i = 2; i <= number1 / 2; ++i)
    {
        // 符合该条件不是素数
        if (number1 % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int solve(int n)
{
    int a = 2;
    int b = n - 2;
    int k = 0; //素数对有几对
    while (a <= b)
    {
        if (isPrime(a) == 1 && isPrime(b) == 1)
        {
            if (a + b == n)
            {
                k++;
            }
        }
        a++;
        b--;
        if (a > b)
        {
            break;
        }
    }
    return k;
}

int main()
{
    int y;
    int n = 0;
    scanf("%d", &n);
    y = solve(n);
    printf("%d", y);
}
