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
    int date[3] = { 0 };    // date[0]�� ����, date[1]�� ��, date[2]�� ���� ��Ÿ��
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
                printf("�� %d�� ���� ������ �ֽ��ϴ�!", n);// DayDiff �Լ� ȣ��
            else if (n == 1)
                printf("�� ������ �Ϸ� ���� ������ �ֽ��ϴ�");
            else if (n == 0)
                printf("�� ���� ������ ������ �ֽ��ϴ�!");
            else if (n < 0);
            printf("\n");
            a = n;
        }
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        printf("\t�Էµ� ������ �����ϴ�\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return;
    }
    fclose(pFile);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return;
}