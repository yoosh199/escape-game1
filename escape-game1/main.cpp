#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SUBMIT 5
#define EASY 6
#define HARD 7
#define EASYMAPROW 30
#define EASYMAPCOLUMN 15

char easyMap[EASYMAPCOLUMN][EASYMAPROW] = {
	{"00000000000000000000000000000"},
	{"00000000000000000000000000e00"},
	{"00000000000100000000000000000"},
	{"00000000000100000000000000000"},
	{"00000000000100000000000000000"},
	{"00000000000100000000000000000"},
	{"00000000000100000100000000000"},
	{"00000000000100s00100000000000"},
	{"00000000000000000001111100000"},
	{"00000000000000000000000100000"},
	{"00000000000000000000000100000"},
	{"00000000000000000000000100000"},
	{"00000000000000000000000100000"},
	{"00000000000000000000000000000"},
	{"00000000000000000000000000000"}
};

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

void setColor(int foreground, int background);
void gameTitle();
void gotoxy(int x, int y);
int gameMenu();
int keyInput();
void cursorView();
int game(int menu);
void map(int set);


int main() {

	gameTitle();
	
	int menu = gameMenu();
	int set = game(menu);
	map(set);

	return 0;
}

void setColor(int foreground, int background) {
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}

void gameTitle() {
	cursorView();
	printf("			----------------------------------------\n");
	printf("			---------------------WW-----------------\n");
	printf("			--------------------WKOX----------------\n");
	printf("			------------------WK0xokW---------------\n");
	printf("			----------------N0xooookW---------------\n");
	printf("			--------------WKxoooooxXNNW-------------\n");
	printf("			-------------WOoooooldKKkKW-------------\n");
	printf("			-------------KdloddoldOkokXW------------\n");
	printf("			-----------WW0doodxdoodoooxK------------\n");
	printf("			-----------NOOkoooxkkxxooookN-----------\n");
	printf("			----------WXxodoodxkOOkxdooxX-----------\n");
	printf("			--------WW-WOooodkkkOK0OxooOW-----------\n");
	printf("			------------WKxddxOKXXXOdxKW------------\n");
	printf("			--------------WX00KNWNXKXW--------------\n");
	printf("			---------------WWWWWWWWWW---------------\n");
	printf("			----------------------------------------\n");
}

int gameMenu() {
	int x = 42;
	int y = 18;
	gotoxy(x-2, y);
	printf("> 시작");
	gotoxy(x, y+1);
	printf("정보");
	gotoxy(x, y+2);
	printf("종료");
	gotoxy(x - 2, y);

	
	while (1) {
		int key = keyInput();
		if (key == UP) {
			if (y == 19 || y == 20) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
		}
		else if (key == DOWN) {
			if (y == 18 || y == 19) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
		}
		else if (key == LEFT) {

		}
		else if (key == RIGHT) {

		}
		else if (key == SUBMIT) {
			if (y == 18) {
				//시작
				return 1;
			}
			else if (y == 19) {
				//정보
				return 2;
			}
			else if (y == 20) {
				//종료
				return 0;
			}
		}

	}
	
	

}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int keyInput() {
	char input = _getch();
	if (input == 'o') {
		return UP;
	}
	else if (input == 'l') {
		return DOWN;
	}
	else if (input == 'k') {
		return LEFT;
	}
	else if (input == ';') {
		return RIGHT;
	}
	else if (input == ' ') {
		return SUBMIT;
	}

}

void cursorView() {
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int game(int menu) {
	system("cls");
	
	if (menu == 0) {
		printf("감사합니다.");
	
	}
	else if (menu == 1) {
		int x = 42;
		int y = 18;
		gotoxy(x-2, y);
		printf("> 쉬움");
		gotoxy(x , y+1);
		printf("어려움");

		while (1) {
			int key = keyInput();
			if (key == UP) {
				if (y == 19) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, --y);
					printf(">");
				}
			}
			else if (key == DOWN) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			else if (key == SUBMIT) {
				if (y == 18) {
					return EASY;
				}
				else if (y == 19) {
					return HARD;
				}
			}
		}
		
	
	}
	else if (menu == 2) {
		gotoxy(10, 10);
		printf("제작자 : 유시현");
		
	}
	Sleep(1000);
	return 0;
}

void map(int set) {
	system("cls");
	if (set == EASY) {
		for (int i = 0; i < EASYMAPCOLUMN; i++) {
			for (int j = 0; j < EASYMAPROW; j++) {
				printf("%c", easyMap[i][j]);
			}
			printf("\n");
		}
	}
}