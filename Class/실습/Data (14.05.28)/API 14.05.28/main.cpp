#include <stdio.h>
#include <Windows.h>

#pragma warning (disable : 4996)

#define SIZE 19

void gotoxy(int x, int y);
void MakePlane();
void Menu();
void InputXY(int BackPlane[SIZE][SIZE], int x, int y);
void PutStone(int BackPlane[SIZE][SIZE]);
void Check_3(int BackPlane[SIZE][SIZE]);

int CheckStone = 0;
int WhiteStone = 0;
int BlackStone = 0;
int Break_x;
int count[3] = {3, 4, 5};

int main()
{
	int BackPlane[SIZE][SIZE] = { 0 };
	static int x = 0, y = 0;
	static int r_x, r_y, r_turn;
	int sel;

	MakePlane();
	while (1){
		Menu();
		gotoxy(45, 8);
		printf("기능을 선택해 주세요.");
		scanf("%d", &sel);
		fflush(stdin);
		switch (sel)
		{
		case 1:
			while (1){
				InputXY(BackPlane, x, y);
				Check_3(BackPlane);
				PutStone(BackPlane);
				if (Break_x == -1) break;
			}
			break;
		}
		return 0;
	}
}
void gotoxy(int x, int y)
{
	COORD pos = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void MakePlane()
{
	int i, j;

	printf("┌");
	for (i = 0; i < 17; ++i) {
		printf("┬");
	}
	printf("┐\n");

	for (i = 0; i < 17; ++i){
		printf("├");
		for (j = 0; j < 17; ++j){
			printf("┼");
		}
		printf("┤\n");
	}

	printf("└");
	for (i = 0; i < 17; ++i) {
		printf("┴");
	}
	printf("┘\n");

}

void Menu(){
	gotoxy(45, 3);
	printf("1. Play");
}

void InputXY(int BackPlane[SIZE][SIZE], int x, int y)
{
	gotoxy(0, 23);
	printf("x y 좌표를 입력하세요: ");
	scanf("%d %d", &x, &y);

	if (x != -1){
		while ((x < 0 || x > 18) && (y < 0 || y > 18)){
			gotoxy(0, 23);
			printf("x y 좌표를 입력하세요: ");
			scanf("%d %d", &x, &y);
		}
		if (BackPlane[y][x] == 0 || BackPlane[y][x] == 3 || BackPlane[y][x] == 4){
			if (CheckStone == 0){
				BackPlane[y][x] = 1;
				CheckStone = 1;
				++BlackStone;
			}
			else {
				BackPlane[y][x] = 2;
				CheckStone = 0;
				++WhiteStone;
			}
		}
		else {
			gotoxy(0, 22);
			printf("돌이 이미 놓여져 있습니다.");
		}
	}
	Break_x = x;
}

void PutStone(int BackPlane[SIZE][SIZE])
{
	int i, j;

	for (i = 0; i < 19; ++i){
		for (j = 0; j < 19; ++j){
			if (BackPlane[j][i] == 1){
				gotoxy(i * 2, j);
				printf("●");
			}
			else if (BackPlane[j][i] == 2){
				gotoxy(i * 2, j);
				printf("○");
			}
			else if (BackPlane[j][i] == 3){
				gotoxy(i * 2, j);
				printf("1");
			}
			else if (BackPlane[j][i] == 4){
				gotoxy(i * 2, j);
				printf("2");
			}
			else if (BackPlane[j][i] == 5){
				gotoxy(i * 2, j);
				printf("3");
			}
		}
	}
}

void Check_3(int BackPlane[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
			// 검은돌 ●●●
			if (BackPlane[i][j] == 1 && BackPlane[i][j + 1] == 1 && BackPlane[i][j + 2] == 1){
				if (BackPlane[i][j + 3] == 0 || BackPlane[i][j - 1] == 0){
					if (j == 0){
						BackPlane[i][j + 3] = 3;
					}
					else if (j == 16){
						BackPlane[i][j - 1] = 3;
					}
					else {
						BackPlane[i][j - 1] = 3;
						BackPlane[i][j + 3] = 4;
					}
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j] == 1 && BackPlane[i + 2][j] == 1){
				if (BackPlane[i + 3][j] == 0 || BackPlane[i - 1][j] == 0){
					if (j == 0){
						BackPlane[i + 3][j] = 3;
					}
					else if (j == 16){
						BackPlane[i - 1][j] = 3;
					}
					else {
						BackPlane[i - 1][j] = 3;
						BackPlane[i + 3][j] = 4;
					}
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j + 1] == 1 && BackPlane[i + 2][j + 2] == 1){
				if (BackPlane[i + 3][j + 3] == 0 || BackPlane[i - 1][j - 1] == 0){
					if (j == 0){
						BackPlane[i + 3][j + 3] = 3;
					}
					else if (j == 16){
						BackPlane[i - 1][j - 1] = 3;
					}
					else {
						BackPlane[i - 1][j - 1] = 3;
						BackPlane[i + 3][j + 3] = 4;
					}
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j - 1] == 1 && BackPlane[i + 2][j - 2] == 1){
				if (BackPlane[i + 3][j - 3] == 0 || BackPlane[i + 1][j - 1] == 0){
					if (j == 0){
						BackPlane[i + 3][j - 3] = 3;
					}
					else if (j == 18){
						BackPlane[i + 1][j - 1] = 3;
					}
					else {
						BackPlane[i + 1][j - 1] = 3;
						BackPlane[i + 3][j - 3] = 4;
					}
				}
			}
			// 한칸 떨어진 3개 ●● ●
			if (BackPlane[i][j] == 1 && BackPlane[i][j + 1] == 1 && BackPlane[i][j + 3] == 1){
				if (BackPlane[i][j + 2] == 0){
					BackPlane[i][j + 2] = 3;
				}
				if (BackPlane[i][j - 1] == 0){
					BackPlane[i][j - 1] = 4;
				}
				if (BackPlane[i][j + 4] == 0){
					BackPlane[i][j + 4] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j] == 1 && BackPlane[i + 3][j] == 1){
				if (BackPlane[i + 2][j] == 0){
					BackPlane[i + 2][j] = 3;
				}
				if (BackPlane[i - 1][j] == 0){
					BackPlane[i - 1][j] = 4;
				}
				if (BackPlane[i + 4][j] == 0){
					BackPlane[i + 4][j] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j + 1] == 1 && BackPlane[i + 3][j + 3] == 1){
				if (BackPlane[i + 2][j + 2] == 0){
					BackPlane[i + 2][j + 2] = 3;
				}
				if (BackPlane[i - 1][j - 1] == 0){
					BackPlane[i - 1][j - 1] = 4;
				}
				if (BackPlane[i + 4][j + 4] == 0){
					BackPlane[i + 4][j + 4] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j - 1] == 1 && BackPlane[i + 3][j - 3] == 1){
				if (BackPlane[i + 2][j - 2] == 0){
					BackPlane[i + 2][j - 2] = 3;
				}
				if (BackPlane[i + 1][j - 1] == 0){
					BackPlane[i + 1][j - 1] = 4;
				}
				if (BackPlane[i + 4][j - 4] == 0){
					BackPlane[i + 4][j - 4] = 5;
				}
			}
			// 한칸 떨어진 3개 ● ●●
			if (BackPlane[i][j] == 1 && BackPlane[i][j + 2] == 1 && BackPlane[i][j + 3] == 1){
				if (BackPlane[i][j + 1] == 0){
					BackPlane[i][j + 1] = 3;
				}
				if (BackPlane[i][j - 1] == 0){
					BackPlane[i][j - 1] = 4;
				}
				if (BackPlane[i][j + 4] == 0){
					BackPlane[i][j + 4] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j] == 1 && BackPlane[i + 3][j] == 1){
				if (BackPlane[i + 1][j] == 0){
					BackPlane[i + 1][j] = 3;
				}
				if (BackPlane[i - 1][j] == 0){
					BackPlane[i - 1][j] = 4;
				}
				if (BackPlane[i + 4][j] == 0){
					BackPlane[i + 4][j] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j + 2] == 1 && BackPlane[i + 3][j + 3] == 1){
				if (BackPlane[i + 1][j + 1] == 0){
					BackPlane[i + 1][j + 1] = 3;
				}
				if (BackPlane[i - 1][j - 1] == 0){
					BackPlane[i - 1][j - 1] = 4;
				}
				if (BackPlane[i + 4][j + 4] == 0){
					BackPlane[i + 4][j + 4] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j - 2] == 1 && BackPlane[i + 3][j - 3] == 1){
				if (BackPlane[i + 1][j - 1] == 0){
					BackPlane[i + 1][j - 1] = 3;
				}
				if (BackPlane[i + 1][j - 1] == 0){
					BackPlane[i + 1][j - 1] = 4;
				}
				if (BackPlane[i + 4][j - 4] == 0){
					BackPlane[i + 4][j - 4] = 5;
				}
			}
			// 흰돌 ○○○
			if (BackPlane[i][j] == 2 && BackPlane[i][j + 1] == 2 && BackPlane[i][j + 2] == 2){
				if (BackPlane[i][j - 1] == 0 || BackPlane[i][j + 3] == 0){
					if (j == 0){
						BackPlane[i][j + 3] = 3;
					}
					else if (j == 16){
						BackPlane[i][j - 1] = 3;
					}
					else {
						BackPlane[i][j - 1] = 3;
						BackPlane[i][j + 3] = 4;
					}
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j] == 2 && BackPlane[i + 2][j] == 2){
				if (BackPlane[i - 1][j] == 0 || BackPlane[i + 3][j] == 0){
					if (j == 0){
						BackPlane[i + 3][j] = 3;
					}
					else if (j == 16){
						BackPlane[i - 1][j] = 3;
					}
					else {
						BackPlane[i - 1][j] = 3;
						BackPlane[i + 3][j] = 4;
					}
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j + 1] == 2 && BackPlane[i + 2][j + 2] == 2){
				if (BackPlane[i + 3][j + 3] == 0 || BackPlane[i - 1][j - 1] == 0){
					if (j == 0){
						BackPlane[i + 3][j + 3] = 3;
					}
					else if (j == 16){
						BackPlane[i - 1][j - 1] = 3;
					}
					else {
						BackPlane[i - 1][j - 1] = 3;
						BackPlane[i + 3][j + 3] = 4;
					}
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j - 1] == 2 && BackPlane[i + 2][j - 2] == 2){
				if (BackPlane[i + 3][j - 3] == 0 || BackPlane[i + 1][j - 1] == 0){
					if (j == 0){
						BackPlane[i + 3][j - 3] = 3;
					}
					else if (j == 16){
						BackPlane[i + 1][j - 1] = 3;
					}
					else {
						BackPlane[i + 1][j - 1] = 3;
						BackPlane[i + 3][j - 3] = 4;
					}
				}
			}
			// 한칸 떨어진 3개 ○○ ○
			if (BackPlane[i][j] == 1 && BackPlane[i][j + 1] == 1 && BackPlane[i][j + 3] == 1){
				if (BackPlane[i][j + 2] == 0){
					BackPlane[i][j + 2] = 3;
				}
				if (BackPlane[i][j - 1] == 0){
					BackPlane[i][j - 1] = 4;
				}
				if (BackPlane[i][j + 4] == 0){
					BackPlane[i][j + 4] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j] == 1 && BackPlane[i + 3][j] == 1){
				if (BackPlane[i + 2][j] == 0){
					BackPlane[i + 2][j] = 3;
				}
				if (BackPlane[i - 1][j] == 0){
					BackPlane[i - 1][j] = 4;
				}
				if (BackPlane[i + 4][j] == 0){
					BackPlane[i + 4][j] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j + 1] == 1 && BackPlane[i + 3][j + 3] == 1){
				if (BackPlane[i + 2][j + 2] == 0){
					BackPlane[i + 2][j + 2] = 3;
				}
				if (BackPlane[i - 1][j - 1] == 0){
					BackPlane[i - 1][j - 1] = 4;
				}
				if (BackPlane[i + 4][j + 4] == 0){
					BackPlane[i + 4][j + 4] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j - 1] == 1 && BackPlane[i + 3][j - 3] == 1){
				if (BackPlane[i + 2][j - 2] == 0){
					BackPlane[i + 2][j - 2] = 3;
				}
				if (BackPlane[i + 1][j - 1] == 0){
					BackPlane[i + 1][j - 1] = 4;
				}
				if (BackPlane[i + 4][j - 4] == 0){
					BackPlane[i + 4][j - 4] = 5;
				}
			}
			// 한칸 떨어진 3개 ○ ○○
			if (BackPlane[i][j] == 1 && BackPlane[i][j + 2] == 1 && BackPlane[i][j + 3] == 1){
				if (BackPlane[i][j + 1] == 0){
					BackPlane[i][j + 1] = 3;
				}
				if (BackPlane[i][j - 1] == 0){
					BackPlane[i][j - 1] = 4;
				}
				if (BackPlane[i][j + 4] == 0){
					BackPlane[i][j + 4] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j] == 1 && BackPlane[i + 3][j] == 1){
				if (BackPlane[i + 1][j] == 0){
					BackPlane[i + 1][j] = 3;
				}
				if (BackPlane[i - 1][j] == 0){
					BackPlane[i - 1][j] = 4;
				}
				if (BackPlane[i + 4][j] == 0){
					BackPlane[i + 4][j] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j + 2] == 1 && BackPlane[i + 3][j + 3] == 1){
				if (BackPlane[i + 1][j + 1] == 0){
					BackPlane[i + 1][j + 1] = 3;
				}
				if (BackPlane[i - 1][j - 1] == 0){
					BackPlane[i - 1][j - 1] = 4;
				}
				if (BackPlane[i + 4][j + 4] == 0){
					BackPlane[i + 4][j + 4] = 5;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j - 2] == 1 && BackPlane[i + 3][j - 3] == 1){
				if (BackPlane[i + 1][j - 1] == 0){
					BackPlane[i + 1][j - 1] = 3;
				}
				if (BackPlane[i + 1][j - 1] == 0){
					BackPlane[i + 1][j - 1] = 4;
				}
				if (BackPlane[i + 4][j - 4] == 0){
					BackPlane[i + 4][j - 4] = 5;
				}
			}
		}
	}
}