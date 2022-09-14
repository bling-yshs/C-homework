#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int n = 5;
    int m = 3;
    //输入两个数，n和m
    scanf("%d %d", &n, &m);

    char *arr[n];
    for (int i = 0; i < n; i++)
    {
        //输入字符串到arr
        arr[i] = malloc(sizeof(char));
        scanf("%s", arr[i]);
    }

    //输入两个数字，交换arr数组里的两个字符串
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        char *temp = arr[a - 1];
        arr[a - 1] = arr[b - 1];
        arr[b - 1] = temp;
    }

    //输出arr
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
}