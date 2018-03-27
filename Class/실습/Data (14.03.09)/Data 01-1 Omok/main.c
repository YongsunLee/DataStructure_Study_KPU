/*	오목 만들기
	14.03.09
	1. 바둑판을 그린다.
		A. MakePlane
	2. 좌표를 입력받아 바둑판에 돌을 올려놓는다.
	3. 검은돌과 흰돌을 번갈아 사용한다.
	4. 검은돌의 갯수와 흰돌의 갯수를 출력한다.*/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int x, int y);
void MakePlane();
void InputPos( int BackPlane[][19], int x , int y );
void PutStoneDraw(int BackPlane[][19]);
void EraseStone( int x, int y);
void PrintCont();

int stone = 0;
int WhiteStone = 0;
int BlackStone = 0;

int main()
{
	int BackPlane[19][19] = {0};		// 0으로 초기화된 배열 (돌의 위치를 기억)
	int x = 0, y = 0;						// 커서를 0,0으로 옮기기 위한 초기화

	MakePlane();						// 바둑판을 그림
	do{
		EraseStone(x,y);
		InputPos( BackPlane, x, y);
		PutStoneDraw( BackPlane );
		PrintCont();
	}while(1);
	return 0;
}
void MakePlane()
{
	int i, j;

	printf("┌");
	for( i = 0; i < 17; ++i){
		printf("┬");
	}
	printf("┐\n");

	for( i = 0; i < 17; ++i){
		printf("├");
		for( j = 0; j < 17; ++j){
			printf("┼");
		}
		printf("┤\n");
	}

	printf("└");
	for( i = 0; i < 17; ++i){
		printf("┴");
	}
	printf("┘\n");
}
void gotoxy(int x, int y){
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
void InputPos( int BackPlane[][19], int x , int y )
{
	gotoxy(40,5);
	printf("x 좌표를 입력해 주세요 : ");
	scanf("%d", &x);
	while( x < 1 || x > 19 ){
		gotoxy(40,5);
		printf("x 좌표를 다시 입력하세요: ");
		scanf("%d", &x);
	}
	gotoxy(40,6);
	printf("y 좌표를 입력해 주세요 : ");
	scanf("%d", &y);
	while(y < 1 || y > 19){
		gotoxy(40,6);
		printf("y 좌표를 다시 입력하세요: ");
		scanf("%d", &y);
	}

	if( BackPlane[y][x] == 0){
		if( stone == 0 ){
			BackPlane[y][x] = 1;
			stone = 1;
			++BlackStone;
		} else{
			BackPlane[y][x] = 2;
			stone = 0;
			++WhiteStone;
		}
	} else {
		gotoxy(40,6);
		printf("이미 돌이 놓여져 있습니다. \n");
	}
}
void PutStoneDraw( int BackPlane[][19] )
{
	int i, j = 0;

	for ( i = 0; i < 19; ++i ){
		for( j = 0; j < 19; ++j ){
			if( BackPlane[j][i] == 1){
				gotoxy(i*2,j);
				printf("●");
			}
			else if(BackPlane[j][i] == 2){
				gotoxy(i*2, j);
				printf("○");
			}
		}
	}
}
void EraseStone( int x, int y )
{
	gotoxy(x,y);
	if( x == 0 && y == 0)
		printf("┌");
	else if( x == 36 && y == 0 )
		printf("┐");
	else if( x == 0 && y == 18 )
		printf("└");
	else if( x == 36 && y == 18 )
		printf("┘");
	else if( x == 0 )
		printf("├");
	else if( y == 0 )
		printf("┬");
	else if( x == 36 )
		printf("┤");
	else if( y == 18 )
		printf("┴");
	else
		printf("┼");
}
void PrintCont()
{
	int black;
	int white;
	white = WhiteStone;
	black = BlackStone;
	gotoxy(40,3);
	printf("검은 돌: %d", black);
	gotoxy(40,4);
	printf("흰 돌: %d", white);
}