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
		gotoxy(30, 20, "��й�ȣ�� �����ϼ��� : ");
		char arr[100];
		fgets(arr,sizeof(arr),stdin);
		FILE* fn = fopen("password.txt", "w+");
		fputs(arr,fn);
		fclose(fn);
		gotoxy(30, 21,"��й�ȣ ������ �Ϸ�Ǿ����ϴ�!");
		Sleep(1000);
	}
	else
	{
		while (1)
		{
			gotoxy(30, 20, "��й�ȣ�� �Է��ϼ��� : ");
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
				gotoxy(30, 21, "�ùٸ� ��й�ȣ�� �Է��ϼ̽��ϴ�!");
				fclose(fp);
				Sleep(1000);
				return;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("\a");
				gotoxy(30, 22, "�߸��� ��й�ȣ�� �Է��ϼ̽��ϴ�. Ʋ��Ƚ�� : ");
				printf("%d\n", count);
				count++;
				if (count == 4)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					gotoxy(30, 24, "���α׷��� �����մϴ�.");
					fclose(fp);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					exit(1);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				gotoxy(30, 24, "�� ��й�ȣ 3ȸ ������ ���α׷��� �����մϴ�.");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				gotoxy(5, 35, "��õ� >> prees ENTER");
				getchar();
				init();
				system("cls");
				outline();

			}
		}
	}
	return;
}