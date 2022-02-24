#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "MakeHomeWork.h"
#include "PrintCalender2022.h"
#include "ShowDayDiff.h"
#include "PassWord.h"
#include "ShowHomeWork.h"
#include "StringSearch.h"
#include "DeleteHomework.h"
#pragma warning(disable : 4996)

#define CALENDAR 114    // ㄱ
#define HOMEWORK 115    // ㄴ
#define SEARCH 52       // 4
#define ESC 27          // ESC
#define BACK 8          // Backspace
#define ADD 49          // 1
#define DELETE 50       // 2
#define COMPLETE 51     // 3

#define width 100
#define height 40

/* 사용하는 변수 선언 */
int input;

/* 좌표를 변경하고 좌표에 문자를 나타낼 수 있는 함수 */
void gotoxy(int x, int y, char* s)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", s);
}

/* 커서를 없애는 함수 */
void init()
{
    system("mode con cols=50 lines 50 | title Calender for students");
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

/* 필요한 함수 호출 */            //?
void outline();
void password_screen();
void initial_screen();
void calendar();
void homework();
void print_calendar();
void add_hw();
void delete_hw();
void complete_hw();
void search();
void clear();
void status();

int main(void)
{
    init();
    password_screen();
}

void outline(void)
{
    int i;
    for (i = 1; i < width; i++)
    {
        gotoxy(i, 0, "-");
        gotoxy(i, height, "-");
    }
    for (i = 1; i < height; i++)
    {
        gotoxy(0, i, "|");
        gotoxy(width, i, "|");
    }
}

void password_screen(void)
{
    init();
    system("cls");
    outline();
    PassWord();
    clear();
    while (1)
    {
        status();
    }
}

void initial_screen(void)
{
    init();
    system("cls");
    outline();
    gotoxy(10, 10, "          C A L E N D A R          ");
    gotoxy(40, 20, "ㄱ. 달력 출력");
    gotoxy(40, 22, "ㄴ. 과제 관리");
    gotoxy(3, height - 1, "종료 >> press ESC");

    while (1) {
        if (_kbhit())
        {
            input = _getch();
            if (input == ESC)
                exit(0);
            else if (input == CALENDAR)
                calendar();
            else if (input == HOMEWORK)
                homework();
            else
                continue;
        }
    }
}

void calendar(void)
{
    init();
    system("cls");
    outline();
    int month;
    gotoxy(3, 1, "뒤로 >> press BACK_SPACE_BAR");
    gotoxy(3, height - 1, "종료 >> press ESC");
    gotoxy(40, 5, "          C A L E N D A R          ");
    gotoxy(15, 8, "   원하는 달을 입력하세요(1~12) : ");
    scanf("%d", &month);
    PrintCalender2022(month);
    while (getchar() != '\n'); // 입력한 숫자에 해당하는 달력 출력하는 함수 (1 -> 1월 / 2 -> 2월 / ... 12 -> 12월 / else -> 다시 입력하세요 출력)
    while (1)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == BACK)
                initial_screen();
            else if (input == ESC)
                exit(0);
        }
    }
}

void homework(void)
{
    init();
    system("cls");
    outline();

    gotoxy(3, 1, "뒤로 >> press BACK_SPACE_BAR");
    gotoxy(3, height - 1, "종료 >> press ESC");
    gotoxy(10, 10, "          과 제 관 리          ");
    gotoxy(40, 20, "1. 과제 입력"); //과제 입력
    gotoxy(40, 22, "2. 과제 출력"); //과제 삭제
    gotoxy(40, 24, "3. 과제 삭제"); //과제 완료
    gotoxy(40, 26, "4. 검색");

    while (1)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == BACK)
                initial_screen();
            else if (input == ESC)
                exit(0);
            else if (input == ADD)
                MakeHomeWork();
            else if (input == DELETE)
                delete_hw();
            else if (input == COMPLETE)
                complete_hw();
            else if (input == SEARCH)
                search();
            else
                continue;
        }
    }
}

void print_calendar(void)
{
    init();
    system("cls");
    outline();

    gotoxy(3, 1, "뒤로 >> press BACK_SPACE_BAR");
    gotoxy(3, height - 1, "종료 >> press ESC");
    //    달력출력함수 (이준혁)
    gotoxy(40, 33, "ㄱ. 달력 출력");
    gotoxy(40, 35, "ㄴ. 과제 관리");

    while (1)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == CALENDAR)
                calendar();
            else if (input == HOMEWORK)
                homework();
            else if (input == BACK)
                calendar();
            else if (input == ESC)
                exit(0);
            else
                continue;
        }
    }
}

void delete_hw(void)
{
    system("cls");
    ShowHomeWork();

    while (1)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == BACK)
                homework();
            else if (input == ESC)
                exit(0);
            else
                continue;
        }
    }
}

void complete_hw(void)
{
    system("cls");
    DeleteHomework();
    initial_screen();
}

void search(void)
{
    system("cls");
    StringSearch();
    while (1)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == BACK)
                homework();
            else if (input == ESC)
                exit(0);
            else
                continue;
        }
    }
}

void clear(void)
{
    init();
    system("cls");
    outline();
}

void status(void)
{
    init();
    system("cls");
    outline();
    gotoxy(2, 2, "Press ENTER to start");

    printf("\n\n\n");
    ShowDayDiff();

    while (1)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == 13)
                initial_screen();
        }
    }
}