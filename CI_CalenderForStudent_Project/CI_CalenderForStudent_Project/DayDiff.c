#include <stdio.h>
#include <time.h>
#include "DayDiff.h"
#pragma warning (disable:4996)

int to_day(int y, int m, int d)
{
    int mon[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int day = 0;
    int i;
    for (i = 1; i < y; i++) 
    {
        day += (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) ? 366 : 365;
    }
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) mon[2]++;
    for (i = 1; i < m; i++) 
    {
        day += mon[i];
    }
    return day + d;
}
int diff(int y1, int m1, int d1, int y2, int m2, int d2)
{
    int a = to_day(y1, m1, d1);
    int b = to_day(y2, m2, d2);
    return b - a;
}

int DayDiff(int year, int month, int day) // 인자로 받은 날짜와 오늘 날짜의 차이를 출력
{
    struct tm* t;
    time_t base = time(NULL);
    t = localtime(&base);

    int todayYear = t->tm_year + 1900;
    int todayMonth = t->tm_mon + 1;
    int todayDay = t->tm_mday;

    int n = diff(todayYear, todayMonth, todayDay, year, month, day);

    return n;
    
}
