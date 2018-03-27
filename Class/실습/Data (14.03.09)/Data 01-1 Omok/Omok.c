#include <stdio.h>
#include <Windows.h>

#define SIZE 19

void gotoxy( int x, int y );
void MakePlane();
void InputXY( int BackPlane[SIZE][SIZE], int x, int y );
void PutStone( int BackPlane[SIZE][SIZE] );
void PrintCont();
void Count();

int CheckStone = 0;
int WhiteStone = 0;
int BlackStone = 0;
int Count_W;
int Count_B;
int Temp_W;
int Temp_B;
int main()
{
	int BackPlane[SIZE][SIZE] = {0};
	int x = 0 , y =0;

	MakePlane();
	do{
		InputXY( BackPlane , x ,y);
		PutStone( BackPlane );
		PrintCont();
	}while(1);
	return 0;
}

void gotoxy( int x, int y )
{
	COORD pos = {x, y};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void MakePlane()
{
	int i, j;

	printf("��");
	for( i = 0; i < 17; ++i) {
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
	for( i = 0; i < 17; ++i) {
		printf("��");
	}
	printf("��\n");

}

void InputXY( int BackPlane[SIZE][SIZE], int x, int y )
{
	gotoxy(40,5);
	printf("x y ��ǥ�� �Է��ϼ���: ");
	scanf("%d %d", &x, &y);

	while( (x < 1 || x > 18) && (y < 1 || y > 18)){
		gotoxy(40,5);
		printf("x y ��ǥ�� �Է��ϼ���: ");
		scanf("%d %d", &x, &y);
	}

	if( BackPlane[y][x] == 0){
		if( CheckStone == 0 ){
			BackPlane[y][x] = 1;
			CheckStone = 1;
			++BlackStone;
		} else {
			BackPlane[y][x] = 2;
			CheckStone = 0;
			++WhiteStone;
		}
	} else {
		gotoxy(40,6);
		printf("���� �̹� ������ �ֽ��ϴ�.");
	}
}

void PutStone( int BackPlane[SIZE][SIZE] )
{
	int i, j;

	for(i = 0; i < 19; ++i){
		for(j = 0; j < 19; ++j){
			if( BackPlane[j][i] == 1){
				gotoxy(i*2,j);
				printf("��");
			} else if( BackPlane[j][i] == 2){
				gotoxy(i*2,j);
				printf("��");
			}
		}
	}
}

void PrintCont()
{
	gotoxy(40,3);
	printf("������: %d", BlackStone);
	gotoxy(40,4);
	printf("��  ��: %d", WhiteStone);
}