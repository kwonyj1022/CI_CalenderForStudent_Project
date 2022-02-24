#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#pragma warning (disable : 4996)

void ShowHomeWork(void)
{
    const UINT default_cp = GetConsoleOutputCP();
    char str[15] = { 0 };
    FILE* fp = fopen("homework.txt", "r");
    while (!feof(fp))
    {
        char arr[12];
        fgets(arr, sizeof(arr), fp);
        //printf("%s", arr);
        char arr2[15];
        strcpy(arr2, arr);
        arr2[10] = '.';
        arr2[11] = 't';
        arr2[12] = 'x';
        arr2[13] = 't';
        arr2[14] = '\0';
        FILE* hw = fopen(arr2, "r");
        if (hw == NULL)
            continue;
        if (strcmp(str, arr2) == 0)
        {
            fclose(hw);
            break;
        }
        strcpy(str, arr2);
        int ch;
        arr[10] = 0;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("[%s 과제] \n", arr);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        SetConsoleOutputCP(CP_UTF8);

        while((ch = fgetc(hw)) != EOF)
        {
            fputc(ch,stdout);
        }
        SetConsoleOutputCP(default_cp);
        printf("\n\n");
        fclose(hw);
    }
    printf("\n\n\n\n");
    printf("뒤로 >> press BACK_SPACE");
    fclose(fp);
}