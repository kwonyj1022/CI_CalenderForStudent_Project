#include <stdio.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable : 4996)

void PassWord(void)
{
	int count = 1;

	FILE* fp = fopen("password.txt", "r");
	if (fp == NULL)
	{
		gotoxy(30, 20, "비밀번호를 설정하세요 : ");
		char arr[100];
		fgets(arr,sizeof(arr),stdin);
		FILE* fn = fopen("password.txt", "w+");
		fputs(arr,fn);
		fclose(fn);
		gotoxy(30, 21,"비밀번호 설정이 완료되었습니다!");
		Sleep(1000);
	}
	else
	{
		while (1)
		{
			gotoxy(30, 20, "비밀번호를 입력하세요 : ");
			char arr1[100];
			char arr2[100];
			fgets(arr1, sizeof(arr1), stdin);
			for (int i = 0; i < sizeof(arr1); i++)
			{
				if (arr1[i] == '\n')
					arr1[i] = '\0';
			}
			int c;
			fgets(arr2, sizeof(arr2), fp);
			for (int i = 0; i < sizeof(arr2); i++)
			{
				if (arr2[i] == '\n')
					arr2[i] = '\0';
			}
			if (strcmp(arr1, arr2) == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				gotoxy(30, 21, "올바른 비밀번호를 입력하셨습니다!");
				fclose(fp);
				Sleep(1000);
				return;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("\a");
				gotoxy(30, 22, "잘못된 비밀번호를 입력하셨습니다. 틀린횟수 : ");
				printf("%d\n", count);
				count++;
				if (count == 4)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					gotoxy(30, 24, "프로그램을 종료합니다.");
					fclose(fp);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					exit(1);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				gotoxy(30, 24, "※ 비밀번호 3회 오류시 프로그램을 종료합니다.");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				gotoxy(5, 35, "재시도 >> prees ENTER");
				getchar();
				init();
				system("cls");
				outline();

			}
		}
	}
	return;
}