#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
    int year;
    int month;
    int day;
} nyr, yrn, ryn;

int isnyr(int a2, int b2, int c2)
{

    if (nyr.month > b2)
    {
        return 0;
    }
    if (nyr.day > c2)
    {
        return 0;
    }
    nyr.year = a2;
    nyr.month = b2;
    nyr.day = c2;
    return 1;
}

int isyrn(int a2, int b2, int c2)
{

    if (yrn.month > a2)
    {
        return 0;
    }
    if (yrn.day > b2)
    {
        return 0;
    }
    yrn.year = c2;
    yrn.month = a2;
    yrn.day = b2;
    return 1;
}

int isryn(int a2, int b2, int c2)
{

    if (ryn.month > b2)
    {
        return 0;
    }
    if (ryn.day > a2)
    {
        return 0;
    }
    ryn.year = c2;
    ryn.month = b2;
    ryn.day = a2;
    return 1;
}

int main(int argc, char const *argv[])
{
    char date[8];
    // input 8 char
    for (int i = 0; i < 8; i++)
    {
        scanf("%c", &date[i]);
    }
    char a1[3], b1[3], c1[3];

    //忽略掉'/'字符，将日期分割成三个字符串
    a1[0] = date[0];
    a1[1] = date[1];
    a1[2] = '\0';
    b1[0] = date[3];
    b1[1] = date[4];
    b1[2] = '\0';
    c1[0] = date[6];
    c1[1] = date[7];
    c1[2] = '\0';
    //将字符串转换成整数
    int a2 = atoi(a1);
    int b2 = atoi(b1);
    int c2 = atoi(c1);

    //判断日期是否合法
    if (isnyr(a2, b2, c2))
    {
        if (nyr.year >= 60)
        {
            nyr.year += 1900;
        }
        else
        {
            nyr.year += 2000;
        }
        printf("%d-%02d-%02d\n", nyr.year, nyr.month, nyr.day);
    }
    if (isyrn(a2, b2, c2))
    {
        if (yrn.year >= 60)
        {
            yrn.year += 1900;
        }
        else
        {
            yrn.year += 2000;
        }
        printf("%d-%02d-%02d\n", yrn.year, yrn.month, yrn.day);
    }
    if (isryn(a2, b2, c2))
    {
        if (ryn.year >= 60)
        {
            ryn.year += 1900;
        }
        else
        {
            ryn.year += 2000;
        }
        printf("%d-%02d-%02d\n", ryn.year, ryn.month, ryn.day);
    }
    //比较年份与月份，从小到大排列
    if (nyr.year > yrn.year)
    {
        struct book temp;
        temp = nyr;
        nyr = yrn;
        yrn = temp;
    }
    if (nyr.year > ryn.year)
    {
        struct book temp;
        temp = nyr;
        nyr = ryn;
        ryn = temp;
    }
    if (yrn.year > ryn.year)
    {
        struct book temp;
        temp = yrn;
        yrn = ryn;
        ryn = temp;
    }
    if (nyr.year == yrn.year)
    {
        if (nyr.month > yrn.month)
        {
            struct book temp;
            temp = nyr;
            nyr = yrn;
            yrn = temp;
        }
        if (nyr.month == yrn.month)
        {
            if (nyr.day > yrn.day)
            {
                struct book temp;
                temp = nyr;
                nyr = yrn;
                yrn = temp;
            }
        }
    }
    if (nyr.year == ryn.year)
    {
        if (nyr.month > ryn.month)
        {
            struct book temp;
            temp = nyr;
            nyr = ryn;
            ryn = temp;
        }
        if (nyr.month == ryn.month)
        {
            if (nyr.day > ryn.day)
            {
                struct book temp;
                temp = nyr;
                nyr = ryn;
                ryn = temp;
            }
        }
    }
    if (yrn.year == ryn.year)
    {
        if (yrn.month > ryn.month)
        {
            struct book temp;
            temp = yrn;
            yrn = ryn;
            ryn = temp;
        }
        if (yrn.month == ryn.month)
        {
            if (yrn.day > ryn.day)
            {
                struct book temp;
                temp = yrn;
                yrn = ryn;
                ryn = temp;
            }
        }
    }
    //输出
    printf("%d-%02d-%02d\n", nyr.year, nyr.month, nyr.day);
    printf("%d-%02d-%02d\n", yrn.year, yrn.month, yrn.day);
    printf("%d-%02d-%02d", ryn.year, ryn.month, ryn.day);

    return 0;
}