#include <stdio.h>
#include <math.h>
int solve(int n)
{
    int d, sum, b;
    do
    {
        d = log10(n); //求出有几位数
        sum = 0;
        for (int i = 0; i <= d; i++)
        {
            b = n % 10;
            sum += b;
            n = n / 10;
        }
        n = sum;
    } while (sum >= 10); //有两位数就继续循环
    return sum;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    printf("%d", solve(n));
}