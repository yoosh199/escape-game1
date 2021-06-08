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
#define OK 8
#define NO 9
#define EASYMAPROW 50
#define EASYMAPCOLUMN 15



char easyMap[EASYMAPCOLUMN][EASYMAPROW] = {
	{"1111111111111111111111111111111111111111111111111"},
	{"1000000000000000000000000000000000000000000000e01"},
	{"1000000000000000000000000000000100000000000000001"},
	{"1000000000000000000000000000000100000000000000001"},
	{"1000000000000000000000000000000100000000000000001"},
	{"1000000000000000000000100010000100000000000000001"},
	{"1000000000000000000001010000000100000100000000001"},
	{"100000000000000000000000s000000100000100000000001"},
	{"1000000000000000000000100010000000000001111100001"},
	{"1000000000000000000000000000000000000000000100001"},
	{"1000000000000000000000000000000000000000000100001"},
	{"1000000000000000000000000000000000000000000100001"},
	{"1000000000000000000000000000000000000000000100001"},
	{"1000000000000000000000000000000000000000000000001"},
	{"1111111111111111111111111111111111111111111111111"}
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
int mapMove(int x,int y);

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
	system("mode con cols=50 lines=30 | title escape");
	
	printf("-------------------------------------------------\n");
	printf("--------------------------WW---------------------\n");
	printf("-------------------------WKOX--------------------\n");
	printf("-----------------------WK0xokW-------------------\n");
	printf("---------------------N0xooookW-------------------\n");
	printf("-------------------WKxoooooxXNNW-----------------\n");
	printf("------------------WOoooooldKKkKW-----------------\n");
	printf("------------------KdloddoldOkokXW----------------\n");
	printf("----------------WW0doodxdoodoooxK----------------\n");
	printf("----------------NOOkoooxkkxxooookN---------------\n");
	printf("---------------WXxodoodxkOOkxdooxX---------------\n");
	printf("-------------WW-WOooodkkkOK0OxooOW---------------\n");
	printf("-----------------WKxddxOKXXXOdxKW----------------\n");
	printf("-------------------WX00KNWNXKXW------------------\n");
	printf("--------------------WWWWWWWWWW-------------------\n");
	printf("-------------------------------------------------\n");
}

int gameMenu() {
	int x = 23;
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
		int x = 23;
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
	int start_x, start_y;
	if (set == EASY) {
		for (int i = 0; i < EASYMAPCOLUMN; i++) {
			for (int j = 0; j < EASYMAPROW; j++) {
				if (easyMap[i][j] == 's') {
					start_x = j;
					start_y = i;
				}
			}
		
		}
		int n = 0;
		for (int k = start_y; k < start_y+3; k++) {
			gotoxy(23, 5 + n);
			for (int h = start_x; h < start_x+3; h++) {
				printf("%c", easyMap[k - 1][h - 1]);
			}
			printf("\n");
			n++;
	
		}
		int key;
		while (1) {
			key = keyInput();
			
			if (key == UP) {
				if (easyMap[start_y - 1][start_x] == '0') {
					system("cls");
					easyMap[start_y][start_x] = '0';
					start_y -= 1;
					easyMap[start_y][start_x] = 's';
					n = 0;
					for (int k = start_y; k < start_y + 3; k++) {
						gotoxy(23, 5 + n);
						for (int h = start_x; h < start_x + 3; h++) {
							printf("%c", easyMap[k - 1][h - 1]);
						}
						n++;

					}
				}
				else if (easyMap[start_y - 1][start_x] == 'e') {
					//성공
				}
			}
			else if (key == DOWN) {
				if (easyMap[start_y + 1][start_x] == '0') {
					system("cls");
					easyMap[start_y][start_x] = '0';
					start_y += 1;
					easyMap[start_y][start_x] = 's';
					n = 0;
					for (int k = start_y; k < start_y + 3; k++) {
						gotoxy(23, 5 + n);
						for (int h = start_x; h < start_x + 3; h++) {
							printf("%c", easyMap[k - 1][h - 1]);
						}
						n++;

					}
				}
				

			}
			else if (key == LEFT) {
				if (easyMap[start_y][start_x-1] == '0') {
					system("cls");
					easyMap[start_y][start_x] = '0';
					start_x -= 1;
					easyMap[start_y][start_x] = 's';
					n = 0;
					for (int k = start_y; k < start_y + 3; k++) {
						gotoxy(23, 5 + n);
						for (int h = start_x; h < start_x + 3; h++) {
							printf("%c", easyMap[k - 1][h - 1]);
						}
						n++;

					}
				}
				

			}
			else if (key == RIGHT) {
				if (easyMap[start_y][start_x + 1] == '0') {
					system("cls");
					easyMap[start_y][start_x] = '0';
					start_x += 1;
					easyMap[start_y][start_x] = 's';
					n = 0;
					for (int k = start_y; k < start_y + 3; k++) {
						gotoxy(23, 5 + n);
						for (int h = start_x; h < start_x + 3; h++) {
							printf("%c", easyMap[k - 1][h - 1]);
						}
						n++;

					}
				}
				
			}
		}
		
	}
}

