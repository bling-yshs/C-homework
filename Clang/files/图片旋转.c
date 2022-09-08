#include <stdio.h>
int main(int argc, char const *argv[])
{
    //输入初始图像
    int hang = 3;
    int lie = 4;
    scanf("%d %d", &hang, &lie);
    int pic[hang][lie];
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            scanf("%d", &pic[i][j]);
        }
    }
    for (int j = 0; j < lie; j++)
    {
        for (int i = 0; i < hang; i++)
        {
            if (i == hang - 1)
            {
                printf("%d", pic[hang - i - 1][j]);
                continue;
            }
            printf("%d ", pic[hang - i - 1][j]);
        }
        printf("\n");
    }
}
