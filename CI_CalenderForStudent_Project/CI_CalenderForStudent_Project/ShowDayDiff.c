#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "DayDiff.h"
#pragma warning (disable : 4996)
void ShowDayDiff() 
{

    char str_tmp[1024];
    char* p;
    int date[3] = { 0 };    // date[0]은 연도, date[1]은 월, date[2]는 일을 나타냄
    int cnt;
    FILE* pFile = NULL;
    int a = -1;
    fopen_s(&pFile, "homework.txt", "r");
    if (pFile != NULL)
    {
        while (!feof(pFile)) 
        {
            fgets(str_tmp, 1024, pFile);

            cnt = 0;
            p = strtok(str_tmp, " ");
            while (p != NULL) {
                date[cnt] = atoi(p);
                cnt++;
                p = strtok(NULL, " ");
            }
            printf("\t");
            int n = DayDiff(date[0], date[1], date[2]);
            if (a == n)
            {
                printf("\n");
                break;
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            if (n != 1)
                printf("※ %d일 남은 과제가 있습니다!", n);// DayDiff 함수 호출
            else if (n == 1)
                printf("※ 마감이 하루 남은 과제가 있습니다");
            else if (n == 0)
                printf("※ 오늘 마감인 과제가 있습니다!");
            else if (n < 0);
            printf("\n");
            a = n;
        }
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        printf("\t입력된 과제가 없습니다\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return;
    }
    fclose(pFile);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return;
}