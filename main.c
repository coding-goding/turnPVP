#define _CRT_SECRUE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

#define VER "0.0.0"

void CursorView();
void gotoxy(int x, int y);

typedef struct character {
	char type;
	int damage;
	bool active;
}ch;


int main() {
	bool a = false;
	if (a == true) {
		printf("a");
	}
	else {
		printf("b");
	}
	CursorView();

}

void gotoxy(int x, int y) { //Ŀ�� �̵�
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}