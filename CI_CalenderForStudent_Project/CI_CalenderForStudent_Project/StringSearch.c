#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

void StringSearch(void)
{
    int a = 0;
    const UINT default_cp = GetConsoleOutputCP();
    char ans[300] = { 0 };
    char str[300];
    char cmp[15];
    int num = 0;
    int input;
    int ch;
	printf("\n\t검색할 단어를 입력하세요 : ");
    gets(ans);
    system("cls");
	FILE* fp = fopen("homework.txt", "r");
    if (fp == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        printf("검색할 수 있는 과제가 없습니다.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return;
    }
	while (!feof(fp))
	{
        int fpos;
        int k = 0;
        int n = 0;
        char arr[12];
        fgets(arr, sizeof(arr), fp);
        char arr2[15];
        strcpy(arr2, arr);
        arr2[10] = '.';
        arr2[11] = 't';
        arr2[12] = 'x';
        arr2[13] = 't';
        arr2[14] = '\0';
        if (strcmp(cmp, arr2) == 0)
            break;
        strcpy(cmp, arr2);
        FILE* hw = fopen(arr2, "r");
        if (hw == NULL)
            continue;
        arr[10] = 0;
        while (!feof(hw))
        {
            fgets(str, sizeof(str), hw);
            if (strstr(str, ans) != NULL)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                printf("\"%s\"가 있는 과제 : ", ans);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                printf("[%s 과제] \n", arr);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("\n");
                fseek(hw, 0, SEEK_SET);
                fpos = ftell(hw);
                while ((ch = fgetc(hw)) != EOF)
                    putchar(ch);
                printf("\n\n\n\n");
                a++;
                break;
            }
        }
        n++;
        if (n == 3)
        {
            fclose(fp);
            fclose(hw);
        }
        
	}
    if (a == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        printf("검색하신 단어가 없습니다.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return;
    }

    
}