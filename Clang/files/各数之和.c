#include <stdio.h>
#include <math.h>
int solve(int n)
{
    
    int d = log10(n); // n = 36
    int sum = 0;
    int b;
    int c = n;
    do
    {
        sum = 0;
        for (int i = 0; i <= d; i++)
        {
            b = c % 10; // b = 6 b = 3%10
            sum += b;   // sum = 6
            c = c / 10; // c = 3
        }
        c = sum;
    } while (sum >= 10);

    printf("%d", sum);
}

int main()
{
    solve(999);
}

// for (int i = 0; i <= d; i++)
// {
//     b = n % 10; // b = 6 b = 3%10
//     sum += b;   // sum = 6
//     n = n / 10; // c = 3
// }
