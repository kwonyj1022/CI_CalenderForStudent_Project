#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable : 4996)
void DeleteHomework(void)
{
	char arr[12];
	char ch;
	char input;
	system("cls");
	printf("\n\t������ ������ ��¥�� �Է��ϼ���(ex. 2022 04 12) : ");
	fgets(arr, sizeof(arr), stdin);
	arr[10] = 0;
	char arr2[15];
	strcpy(arr2, arr);
	arr2[10] = '.';
	arr2[11] = 't';
	arr2[12] = 'x';
	arr2[13] = 't';
	arr2[14] = '\0';
	FILE* fp = fopen(arr2, "r");
	if (fp == NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("\n\n\n �ش糯¥�� ������ �����ϴ�!");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		_getch();
		return;
	}
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("\n[%s ����]\n", arr);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while ((ch = fgetc(fp)) != EOF)
		putchar(ch);
	fclose(fp);
	int result = remove(arr2);
	if (result == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("\n\n\n ������ ���� �Ǿ����ϴ�!");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		_getch();
	}

	return;
	
}