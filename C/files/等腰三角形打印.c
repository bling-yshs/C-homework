#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d", &n);
    //总共的数字数量
    int totalNum = 8 + (n - 3) * 4;

    //创建一个数组，长度为数字数量的总和
    int num[totalNum];
    int b = 0;
    int d = 10;
    int f = 100;
    for (int i = 0; i < totalNum;)
    {
        int c = i + 1;
        if (c < 10)
        {
            num[i] = c;
            i += 1;
        }
        if (c >= 10 && d < 100)
        {
            num[i] = d / 10;
            num[i + 1] = d % 10;
            d++;
            i += 2;
        }
        if (d >= 100)
        {
            num[i] = f / 100;
            num[i + 1] = f / 10 % 10;
            num[i + 2] = f % 10;
            f++;
            i += 3;
        }
    }

    int totalNumInLastLine = 5 + (n - 3) * 2;//最后一行的数字数量

    char finalarray[n][totalNumInLastLine];//新的二维数组，用于替换与打印

    // fill the array with .
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < totalNumInLastLine; j++)
        {
            finalarray[i][j] = '.';
        }
    }

    int num2 = 0; //原数组当前元素的下标

    // 1到倒数第二行替换
    for (; num2 < n - 1; num2++)
    {
        int number = num[num2] + 48;
        finalarray[num2][n - num2 - 1] = number;
    }

    //最后一行的替换
    for (int num3 = 0; num3 < totalNumInLastLine; num3++)
    {
        int number = num[num2] + 48;
        finalarray[n - 1][num3] = number;
        num2++;
    }

    //反向倒数第二行到第二行的替换
    int jishu1 = 2;
    for (int num4 = n - 2; num4 > 0; num4--)
    {
        int number = num[num2] + 48;
        finalarray[num4][totalNumInLastLine - jishu1] = number;
        jishu1++;
        num2++;
    }

    // print the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (totalNumInLastLine - n + 1 + i); j++)
        {
            printf("%c", finalarray[i][j]);
        }
        printf("\n");
    }
    return 0;
}
