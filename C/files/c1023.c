#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("Outputs:\n");
    printf("——————————————\n\n");

    char str[8];
    scanf("%s", str);

    char a[2];
    for (int i = 0; i < 2; i++)
    {
        a[i] = str[i];
    }
    char b[2];
    for (int i = 0; i < 2; i++)
    {
        b[i] = str[i + 3];
    }
    char c[2];
    for (int i = 0; i < 2; i++)
    {
        c[i] = str[i + 6];
    }

    
    printf("\n\n——————————————");
    return 0;
}