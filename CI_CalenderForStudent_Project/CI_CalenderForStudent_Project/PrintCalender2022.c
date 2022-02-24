#include <stdio.h>
#include <conio.h>
#include "PrintCalender2022.h"

void PrintCalender2022(int month) // ����ϰ��� �ϴ� �� �Է�
{
    init();

    int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int sum = 365;
    int check = 0;
    printf("\n\n");
    printf("\t\t�Ͽ���\t������\tȭ����\t������\t�����\t�ݿ���\t�����\n");
    printf("\t\t======================================================\n");

    for (int i = 1; i < 2022; i++)
    {
        if (isyoon(i))
            sum += 366;
        else
            sum  += 365;
    }
    for (int i = 0; i < month - 1; i++) 
    {
        sum += arr[i];
    }
    int k = sum % 7;

    printf("\t\t");
    for (int i = 0; i < k; i++) 
    {
        printf("\t");
    }

    for (int i = 1; i <= arr[month - 1]; i++)
    {
        printf("%d\t", i);
        if (k == 6) {
            k = -1;
            printf("\n\t\t");
        }
        k++;
    }
    printf("\n");

}

int isyoon(int a) // ���� �� ���
{
    if ((a % 4 == 0) && !(a % 100 == 0) || (a % 400 == 0)) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}


    