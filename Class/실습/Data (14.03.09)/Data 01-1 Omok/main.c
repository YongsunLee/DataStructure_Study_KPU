/*	���� �����
	14.03.09
	1. �ٵ����� �׸���.
		A. MakePlane
	2. ��ǥ�� �Է¹޾� �ٵ��ǿ� ���� �÷����´�.
	3. �������� ���� ������ ����Ѵ�.
	4. �������� ������ ���� ������ ����Ѵ�.*/
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
	int BackPlane[19][19] = {0};		// 0���� �ʱ�ȭ�� �迭 (���� ��ġ�� ���)
	int x = 0, y = 0;						// Ŀ���� 0,0���� �ű�� ���� �ʱ�ȭ

	MakePlane();						// �ٵ����� �׸�
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

	printf("��");
	for( i = 0; i < 17; ++i){
		printf("��");
	}
	printf("��\n");

	for( i = 0; i < 17; ++i){
		printf("��");
		for( j = 0; j < 17; ++j){
			printf("��");
		}
		printf("��\n");
	}

	printf("��");
	for( i = 0; i < 17; ++i){
		printf("��");
	}
	printf("��\n");
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
	printf("x ��ǥ�� �Է��� �ּ��� : ");
	scanf("%d", &x);
	while( x < 1 || x > 19 ){
		gotoxy(40,5);
		printf("x ��ǥ�� �ٽ� �Է��ϼ���: ");
		scanf("%d", &x);
	}
	gotoxy(40,6);
	printf("y ��ǥ�� �Է��� �ּ��� : ");
	scanf("%d", &y);
	while(y < 1 || y > 19){
		gotoxy(40,6);
		printf("y ��ǥ�� �ٽ� �Է��ϼ���: ");
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
		printf("�̹� ���� ������ �ֽ��ϴ�. \n");
	}
}
void PutStoneDraw( int BackPlane[][19] )
{
	int i, j = 0;

	for ( i = 0; i < 19; ++i ){
		for( j = 0; j < 19; ++j ){
			if( BackPlane[j][i] == 1){
				gotoxy(i*2,j);
				printf("��");
			}
			else if(BackPlane[j][i] == 2){
				gotoxy(i*2, j);
				printf("��");
			}
		}
	}
}
void EraseStone( int x, int y )
{
	gotoxy(x,y);
	if( x == 0 && y == 0)
		printf("��");
	else if( x == 36 && y == 0 )
		printf("��");
	else if( x == 0 && y == 18 )
		printf("��");
	else if( x == 36 && y == 18 )
		printf("��");
	else if( x == 0 )
		printf("��");
	else if( y == 0 )
		printf("��");
	else if( x == 36 )
		printf("��");
	else if( y == 18 )
		printf("��");
	else
		printf("��");
}
void PrintCont()
{
	int black;
	int white;
	white = WhiteStone;
	black = BlackStone;
	gotoxy(40,3);
	printf("���� ��: %d", black);
	gotoxy(40,4);
	printf("�� ��: %d", white);
}