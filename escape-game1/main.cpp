#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SUBMIT 5

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
void gameMenu();
int keyInput();
void cursorView();

int main() {

	gameTitle();
	
	gameMenu();

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

void gameMenu() {
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