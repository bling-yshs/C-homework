#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int year;
    int month;
    int day;
} fulldate;

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

    //将三种情况依次赋值，四是为了排序的时候方便覆盖元素
    fulldate date1[4];

    // a[0]为年月日, a[1]为月日年, a[2]为日月年
    date1[0].year = a2;
    date1[0].month = b2;
    date1[0].day = c2;
    date1[1].year = c2;
    date1[1].month = a2;
    date1[1].day = b2;
    date1[2].year = c2;
    date1[2].month = b2;
    date1[2].day = a2;

    //为年份加上前缀
    for (int i = 0; i < 3; i++)
    {
        if (date1[i].year >= 60)
        {
            date1[i].year += 1900;
        }
        else
        {
            date1[i].year += 2000;
        }
    }
    //将date1按日期排序
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            if (date1[j].year > date1[j + 1].year)
            {
                fulldate temp = date1[j];
                date1[j] = date1[j + 1];
                date1[j + 1] = temp;
            }
            else if (date1[j].year == date1[j + 1].year)
            {
                if (date1[j].month > date1[j + 1].month)
                {
                    fulldate temp = date1[j];
                    date1[j] = date1[j + 1];
                    date1[j + 1] = temp;
                }
                else if (date1[j].month == date1[j + 1].month)
                {
                    if (date1[j].day > date1[j + 1].day)
                    {
                        fulldate temp = date1[j];
                        date1[j] = date1[j + 1];
                        date1[j + 1] = temp;
                    }
                }
            }
        }
    }
    //检查日期是否合法
    int wrongdate = 0;

    for (int i = 2; i >= 0; i--) //从末端开始检查比较方便
    {
        //判断是否为闰年
        int isLeapYear = 0;
        if (date1[i].year % 4 == 0 && date1[i].year % 100 != 0)
        {
            isLeapYear = 1;
        }
        else if (date1[i].year % 400 == 0)
        {
            isLeapYear = 1;
        }

        //判断日期是否合法
        if (date1[i].month == 0 || date1[i].day == 0)
        {
            wrongdate++;
            date1[i] = date1[i + 1];
            continue;
        }

        if (date1[i].month > 12 || date1[i].day > 31)
        {
            wrongdate++;
            date1[i] = date1[i + 1];
            continue;
        }

        if (date1[i].month % 2 == 0 && date1[i].month < 8 && date1[i].day > 30)
        {
            wrongdate++;
            date1[i] = date1[i + 1];
            continue;
        }
        if (date1[i].month % 2 == 1 && date1[i].month > 7 && date1[i].day > 30)
        {
            wrongdate++;
            date1[i] = date1[i + 1];
            continue;
        }
        if (isLeapYear == 1 && date1[i].month == 2 && date1[i].day > 29)
        {
            wrongdate++;
            date1[i] = date1[i + 1];
            continue;
        }
        if (isLeapYear == 0 && date1[i].month == 2 && date1[i].day > 28)
        {
            wrongdate++;
            date1[i] = date1[i + 1];
            continue;
        }
    }

    //删除重复的日期
    for (int i = 3 - wrongdate - 1; i >= 1; i--)
    {
        if (date1[i].year == date1[i - 1].year && date1[i].month == date1[i - 1].month && date1[i].day == date1[i - 1].day)
        {
            wrongdate++;
            date1[i] = date1[i + 1];
        }
    }

    for (int i = 0; i < 3 - wrongdate; i++)
    {
        printf("%d-%02d-%02d\n", date1[i].year, date1[i].month, date1[i].day);
    }

    return 0;
}