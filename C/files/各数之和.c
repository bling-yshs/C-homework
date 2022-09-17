#include <stdio.h>
#include <math.h>
int solve(int n)
{
    
    int d = log10(n); //求出有几位数
    int sum = 0;
    int b;
    do
    {
        sum = 0;
        for (int i = 0; i <= d; i++)
        {
            b = n % 10;
            sum += b;
            n = n / 10;
        }
        n = sum;
    } while (sum >= 10);
    return sum;
}

int main()
{
    solve(999);
}