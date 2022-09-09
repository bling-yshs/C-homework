#include <stdio.h>
#include <math.h>

void solve(int n)
{
    int max = sqrt(n);
    int a = 0, b = 0, c = 0, d = 0;
    for (; a <= max; a++)
    {
        b = a;
        for (; b <= max; b++)
        {
            c = b;
            for (; c <= max; c++)
            {
                d = c;
                for (; d <= max; d++)
                {
                    if (a * a + b * b + c * c + d * d != n)
                    {
                        continue;
                    }
                    if (a * a + b * b + c * c + d * d == n)
                    {
                        printf("%d %d %d %d\n", a, b, c, d);
                        return;
                    }
                }
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d/n", &n);
    solve(n);
    return 0;
}