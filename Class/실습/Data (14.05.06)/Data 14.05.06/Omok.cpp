#include <stdio.h>
#include <Windows.h>

#pragma warning (disable : 4996)

#define SIZE 19

void gotoxy(int x, int y);
void MakePlane();
void Menu();
void InputXY(int BackPlane[SIZE][SIZE], int x, int y);
void PutStone(int BackPlane[SIZE][SIZE]);
void CountStone(int BackPlane[SIZE][SIZE]);
void Check_3(int BackPlane[SIZE][SIZE]);
void CountMax(int BackPlane[SIZE][SIZE]);

int CheckStone = 0;
int WhiteStone = 0;
int BlackStone = 0;
int Break_x;
int hcount_w;
int hcount_b;
int wcount_w;
int wcount_b;
int dcount_w;
int dcount_b;
int rdcount_w;
int rdcount_b;
int ltemp_w;
int ltemp_b;
int dtemp_w;
int dtemp_b;
int rdtemp_w;
int rdtemp_b;

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
				//CountStone(BackPlane);
				CountMax(BackPlane);
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
	gotoxy(45, 4);
	printf("2. Save");
	gotoxy(45, 5);
	printf("3. Load");
	gotoxy(45, 6);
	printf("4. Back_Stone");
	gotoxy(45, 7);
	printf("5. Return");
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
				printf("★");
			}
			else if (BackPlane[j][i] == 4){
				gotoxy(i * 2, j);
				printf("☆");
			}
		}
	}
}

void CountStone(int BackPlane[SIZE][SIZE])
{
	// 가로
	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
			if (BackPlane[i][j] == 1){
				wcount_w++;
			}
			else if (BackPlane[i][j] == 2){
				wcount_b++;
			}
			// 세로
			if (BackPlane[j][i] == 1){
				hcount_w++;
			}
			else if (BackPlane[j][i] == 2){
				hcount_b++;
			}

			if ( wcount_w > ltemp_w ){
				ltemp_w = wcount_w;
			}
			if ( wcount_b > ltemp_b ){
				ltemp_b = wcount_b;
			}
			if (hcount_w > ltemp_w){
				ltemp_w = wcount_w;
			}
			if (hcount_b > ltemp_b){
				ltemp_b = wcount_b;
			}
		}
		hcount_w = 0;
		hcount_b = 0;
		wcount_w = 0;
		wcount_b = 0;
		gotoxy(40,20);
		printf("%d %d", ltemp_w, ltemp_b); // 가로 세로 통틀어서 한줄에 가장 많이 놓인 돌의 개수
	}
	
	// 대각선
	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
			if (BackPlane[i][j] == 1){
				dcount_w++;
				for (int k = 1; k < SIZE - j; ++k){
					if (BackPlane[i + k][j + k] == 1){
						dcount_w++;
					}
				}
			}
			else if (BackPlane[i][j] == 2){
				dcount_b++;
				for (int k = 1; k < SIZE - j; ++k){
					if (BackPlane[i + k][j + k] == 2){
						dcount_b++;
					}
				}
			}
			if ( dcount_w > dtemp_w ){
				dtemp_w = dcount_w;
			}
			if ( dcount_b > dtemp_b ){
				dtemp_b = dcount_b;
			}
		}
		dcount_w = 0;
		dcount_b = 0;
		gotoxy(40, 19);
		printf("%d %d", dtemp_w, dtemp_b); // ↘ 대각선 돌의 갯수
	}
	
	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
			if (BackPlane[i][j] == 1){
				rdcount_w++;
				for (int k = SIZE; k != 0; --k){
					if (BackPlane[i + k][j - k] == 1){
						rdcount_w++;
					}
				}
			}
			else if (BackPlane[i][j] == 2){
				rdcount_b++;
				for (int k = SIZE; k != 0; --k){
					if (BackPlane[i + k][j - k] == 2){
						rdcount_b++;
					}
				}
			}
			if (rdcount_w > rdtemp_w){
				rdtemp_w = rdcount_w;
			}
			if (rdcount_b > rdtemp_b){
				rdtemp_b = rdcount_b;
			}
		}
		rdcount_w = 0;
		rdcount_b = 0;
		gotoxy(45, 19);
		printf("%d %d", rdtemp_w, rdtemp_b); // ↙ 대각선 돌의 갯수
	}
	
}

void CountMax(int BackPlane[SIZE][SIZE])
{
	int Max_W = 0;
	int Max_B = 0;
	int temp_w = 0;
	int temp_b = 0;

	// 가로
	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
			if ( BackPlane[i][j] == 1){
				temp_w++;
				for (int k = 1; k < SIZE - j; ++k){
					if (BackPlane[i][j + k] == 1){
						temp_w++;
					}
					else if (BackPlane[i][j+k] == 0){
						// 한칸 떨어진것 계산햇을때
						if (BackPlane[i][j+k+1] == 1){
							temp_w++;
						}
						break;
					}
				}
			}
			else if ( BackPlane[i][j] == 2){
				//temp_b++;
				for (int k = 0; k < SIZE - j; ++k){
					if (BackPlane[i][j + k] == 2){
						temp_b++;
					}
					else if (BackPlane[i][j + k] == 1){
						// 한칸 떨어진것 계산햇을때
						if (BackPlane[i][j+k+1] == 2){
							temp_b++;
							break;
						}
						break;
					}
				}
			}
			if (Max_W < temp_w){
				Max_W = temp_w;
			}
			if (Max_B < temp_b){
				Max_B = temp_b;
			}
		}
		temp_w = 0;
		temp_b = 0;
		gotoxy(45, 15);
		printf("%d %d", Max_W, Max_B);
	}
	// 세로

	// 대각선

	// 역대각선
}

void Check_3(int BackPlane[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
			// 검은돌 ●●●
			if (BackPlane[i][j] == 1 && BackPlane[i][j + 1] == 1 && BackPlane[i][j+2] == 1){
				if (BackPlane[i][j+3] == 0 || BackPlane[i][j - 1] == 0){
					if (j == 0){
						BackPlane[i][j + 3] = 3;
					}
					else if (j == 16){
						BackPlane[i][j - 1] = 3;
					}
					else {
						BackPlane[i][j - 1] = 3;
						BackPlane[i][j + 3] = 3;
					}
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i+1][j] == 1 && BackPlane[i+2][j] == 1){
				if (BackPlane[i+3][j] == 0 || BackPlane[i - 1][j] == 0){
					if (j == 0){
						BackPlane[i + 3][j] = 3;
					}
					else if (j == 16){
						BackPlane[i - 1][j] = 3;
					}
					else {
						BackPlane[i - 1][j] = 3;
						BackPlane[i + 3][j] = 3;
					}
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j + 1] == 1 && BackPlane[i + 2][j + 2] == 1){
				if (BackPlane[i+3][j+3] == 0 || BackPlane[i - 1][j - 1] == 0){
					if (j == 0){
						BackPlane[i + 3][j + 3] = 3;
					}
					else if (j == 16){
						BackPlane[i - 1][j - 1] = 3;
					}
					else {
						BackPlane[i - 1][j - 1] = 3;
						BackPlane[i + 3][j + 3] = 3;
					}
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 1][j - 1] == 1 && BackPlane[i + 2][j - 2] == 1){
				if (BackPlane[i+3][j-3] == 0 || BackPlane[i + 1][j - 1] == 0){
					if (j == 0){
						BackPlane[i + 3][j - 3] = 3;
					}
					else if (j == 18){
						BackPlane[i + 1][j - 1] = 3;
					}
					else {
						BackPlane[i + 1][j - 1] = 3;
						BackPlane[i + 3][j - 3] = 3;
					}
				}
			}
			// 한칸 떨어진 3개 ●● ●
			if (BackPlane[i][j] == 1 && BackPlane[i][j+1] == 1 && BackPlane[i][j+3] == 1){
				if (BackPlane[i][j+2] == 0){
					BackPlane[i][j+2] = 3;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i+1][j] == 1 && BackPlane[i+3][j] == 1){
				if (BackPlane[i+2][j] == 0){
					BackPlane[i+2][j] = 3;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i+1][j+1] == 1 && BackPlane[i+3][j+3] == 1){
				if (BackPlane[i+2][j+2] == 0){
					BackPlane[i+2][j+2] = 3;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i+1][j-1] == 1 && BackPlane[i+3][j-3] == 1){
				if (BackPlane[i+2][j-2] == 0){
					BackPlane[i+2][j-2] = 3;
				}
			}
			// 한칸 떨어진 3개 ● ●●
			if (BackPlane[i][j] == 1 && BackPlane[i][j + 2] == 1 && BackPlane[i][j + 3] == 1){
				if (BackPlane[i][j + 1] == 0){
					BackPlane[i][j + 1] = 3;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j] == 1 && BackPlane[i + 3][j] == 1){
				if (BackPlane[i + 1][j] == 0){
					BackPlane[i + 1][j] = 3;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j + 2] == 1 && BackPlane[i + 3][j + 3] == 1){
				if (BackPlane[i + 1][j + 1] == 0){
					BackPlane[i + 1][j + 1] = 3;
				}
			}
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j - 2] == 1 && BackPlane[i + 3][j - 3] == 1){
				if (BackPlane[i + 1][j - 1] == 0){
					BackPlane[i + 1][j - 1] = 3;
				}
			}
			// 흰돌 ○○○
			if (BackPlane[i][j] == 2 && BackPlane[i][j + 1] == 2 && BackPlane[i][j + 2] == 2){
				if (BackPlane[i][j-1] == 0 || BackPlane[i][j+3] == 0){
					if (j == 0){
						BackPlane[i][j + 3] = 4;
					}
					else if (j == 16){
						BackPlane[i][j - 1] = 4;
					}
					else {
						BackPlane[i][j - 1] = 4;
						BackPlane[i][j + 3] = 4;
					}
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j] == 2 && BackPlane[i + 2][j] == 2){
				if (BackPlane[i-1][j] == 0 || BackPlane[i+3][j] == 0){
					if (j == 0){
						BackPlane[i + 3][j] = 4;
					}
					else if (j == 16){
						BackPlane[i - 1][j] = 4;
					}
					else {
						BackPlane[i - 1][j] = 4;
						BackPlane[i + 3][j] = 4;
					}
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j + 1] == 2 && BackPlane[i + 2][j + 2] == 2){
				if (BackPlane[i+3][j+3] == 0 || BackPlane[i-1][j-1] == 0){
					if (j == 0){
						BackPlane[i + 3][j + 3] = 4;
					}
					else if (j == 16){
						BackPlane[i - 1][j - 1] = 4;
					}
					else {
						BackPlane[i - 1][j - 1] = 4;
						BackPlane[i + 3][j + 3] = 4;
					}
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j - 1] == 2 && BackPlane[i + 2][j - 2] == 2){
				if (BackPlane[i+3][j-3] == 0 || BackPlane[i+1][j-1] == 0){
					if (j == 0){
						BackPlane[i + 3][j - 3] = 4;
					}
					else if (j == 16){
						BackPlane[i + 1][j - 1] = 4;
					}
					else {
						BackPlane[i + 1][j - 1] = 4;
						BackPlane[i + 3][j - 3] = 4;
					}
				}
			}
			// 한칸 떨어진 3개 ○○ ○
			if (BackPlane[i][j] == 2 && BackPlane[i][j + 1] == 2 && BackPlane[i][j + 3] == 2){
				if (BackPlane[i][j + 2] == 0){
					BackPlane[i][j + 2] = 4;
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j] == 2 && BackPlane[i + 3][j] == 2){
				if (BackPlane[i + 2][j] == 0){
					BackPlane[i + 2][j] = 4;
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j + 1] == 2 && BackPlane[i + 3][j + 3] == 2){
				if (BackPlane[i + 2][j + 2] == 0){
					BackPlane[i + 2][j + 2] = 4;
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j - 1] == 2 && BackPlane[i + 3][j - 3] == 2){
				if (BackPlane[i + 2][j - 2] == 0){
					BackPlane[i + 2][j - 2] = 4;
				}
			}
			// 한 칸 떨어진 3개 ○ ○○
			if (BackPlane[i][j] == 2 && BackPlane[i][j + 2] == 2 && BackPlane[i][j + 3] == 2){
				if (BackPlane[i][j + 1] == 0){
					BackPlane[i][j + 1] = 4;
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 2][j] == 2 && BackPlane[i + 3][j] == 2){
				if (BackPlane[i + 1][j] == 0){
					BackPlane[i + 1][j] = 4;
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 2][j + 2] == 2 && BackPlane[i + 3][j + 3] == 2){
				if (BackPlane[i + 1][j + 1] == 0){
					BackPlane[i + 1][j + 1] = 4;
				}
			}
			if (BackPlane[i][j] == 2 && BackPlane[i + 2][j - 2] == 2 && BackPlane[i + 3][j - 3] == 2){
				if (BackPlane[i + 1][j - 1] == 0){
					BackPlane[i + 1][j - 1] = 4;
				}
			}
		}
	}
}