#include <stdio.h>
#include <string.h>
#include <Windows.h>

#pragma warning(disable : 4996)
void MakeHomeWork(void)
{
	init();
	system("cls");
	outline();
	gotoxy(10,12,"과제를 입력하실 날짜를 말씀하세요(ex. 2022 05 26) : "); // goto 10 12
	char* arr = (char*)malloc(sizeof(char) * 20);
	fgets(arr, 15, stdin);

	for (int i = 0; i < 11; i++)
	{
		if (arr[i] == '\n')
		{
			arr[i] = '.';
			arr[i + 1] = 't';
			arr[i + 2] = 'x';
			arr[i + 3] = 't';
			arr[i + 4] = '\0';
		}
	}
	char noTxtarr[11];
	strncpy(noTxtarr, arr, 10);
	noTxtarr[10] = '\0';
	FILE* fh = fopen("homework.txt", "a+");
	char arr3[12];
	strcpy(arr3, noTxtarr);
	arr3[10] = '\n', arr3[11] = '\0';
	fputs(arr3, fh);
	FILE* fp = fopen(arr, "w");
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("[%s 과제]", noTxtarr);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("(※ 입력완료시 ENTER를 눌러주세요)\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	char* arr2 = (char*)malloc(sizeof(char) * 1024);
	fgets(arr2, 1024, stdin);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("\n\n%s에 과제가 저장되었습니다. ", noTxtarr);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	fputs(arr2, fp);
	free(arr);
	free(arr2);
	fclose(fp);
	fclose(fh);
	return;

}

