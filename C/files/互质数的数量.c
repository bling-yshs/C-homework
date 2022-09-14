#include <stdio.h>
int coPrime(int a, int b)
{
    //求a与b的最大公约数
    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    if (a == 1) //如果最大公约数为1，说明互质
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int solve(int n, int k)
{
    int totalCoPrime = 0;
    for (int m = 1; m <= n / k; m++)
    {
        for (int a = 2; a < n; a++)
        {
            int b = a + k * m;
            if (b > n) // b的上限是n
            {
                break;
            }
            if (coPrime(a, b)) //如果a与b互质
            {
                totalCoPrime++;
            }
        }
    }
    return totalCoPrime;
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int k = 2;
    scanf("%d %d", &n, &k);
    int totalSum = solve(n, k);
    printf("%d", totalSum);
}