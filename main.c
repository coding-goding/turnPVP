#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

#define VER "0.1.0"

typedef struct player {
	int turn;
	int max_turn;
	bool is_playing;
}pl;

typedef struct chA {
	int backstab;
	int damage;
	int range;
}assassin;
typedef struct chB {
	int damage;
}builder;
typedef struct chC {
	int range;
	int debuff;
	int penalty;
	int count;
}conductor;
typedef struct chD {
	int passiveHeal;
	int range;
	int activeHeal;
}doctor;
typedef struct chE {
	int immune;
	int range;
	int damage;
}elephant;
typedef struct chF {
	int selfHeal;
	int japDamage;
	int hookDamage;
	int UpppercutDamage;
}fighter;
typedef struct chG {
	int avoidChance;
	int zero;
	int one;
	int three;
	int five;
	int ten;
	int die;
}gambler;
typedef struct chH {
	int killHeal;
	int rangeThree;
	int rangeTwo;
	int rangeOne;
}hunter;
typedef struct chI {
	int plusTurn;
}inventor;

typedef struct agents {
	char type;
	int health;
	int maxHealth;
	int activeCost;
	int moveType;
	int moveTime;
	int x;
	int y;
	bool is_dead;
	assassin a;
	builder b;
	conductor c;
}agent;

void CursorView();
void gotoxy(int x, int y);
void printBoard(int map[10][20], agent p1A, agent p1B, agent p2A, agent p2B);
int(*getMap(int mapType))[20];

int main() {
	int (*map)[20] = getMap(2);
	agent p1A;
	p1A.x = 0;
	p1A.y = 4;
	p1A.type = 'A';
	agent p2A;
	p2A.x = 19;
	p2A.y = 4;
	p2A.type = 'C';
	printBoard(map, p1A, p1A, p2A, p2A);
	CursorView();
}

void gotoxy(int x, int y) { //Ä¿¼­ ÀÌµ¿
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ä¿¼­ ±½±â (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void printBoard(int map[10][20], agent p1A, agent p1B, agent p2A, agent p2B) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] == 0) {
				if (p1A.x == j && p1A.y == i) {
					printf("%c ", p1A.type);
				}
				else if (p1B.x == j && p1B.y == i) {
					printf("%c ", p1B.type);
				}
				else if (p2A.x == j && p2A.y == i) {
					printf("%c ", p2A.type);
				}
				else if (p2B.x == j && p2B.y == i) {
					printf("%c ", p2B.type);
				}
				else {
					printf("* ");
				}
			}
			else if (map[i][j] == 1) {
				printf("# ");
			}
		}
		printf("\n");
	}
}

int(*getMap(int mapType))[20]{
	static int map[10][20];
	int land = 0;
	if (mapType == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				map[i][j] = 0;
			}
		}
	}
	if (mapType == 2) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				if (i < 5 && j == 4) {
					land = 1;
				}
				else if (i < 5 && j == 14) {
					land = 1;
				}
				else if (i >= 5 && j == 9) {
					land = 1;
				}
				else {
					land = 0;
				}
				map[i][j] = land;
				
			}
		}
	}
	if (mapType == 3) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				if (i < 3 && j > 4 && j < 15) {
					land = 1;
				}
				else if (i > 6 && j > 4 && j < 15) {
					land = 1;
				}
				else {
					land = 0;
				}
				map[i][j] = land;
			}
		}
	}
	return map;
}