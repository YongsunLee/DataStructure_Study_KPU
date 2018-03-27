#include <stdio.h>
#include <Windows.h>

#pragma warning (disable : 4996)

#define SIZE 19

struct _NODE {
	int x;
	int y;
	int turn;
	_NODE *link;
};

void gotoxy(int x, int y);
void MakePlane();
void Menu();
void InputXY(int BackPlane[SIZE][SIZE], int x, int y);
void PutStone(int BackPlane[SIZE][SIZE]);
void PrintCont();
void Count(int BackPlane[SIZE][SIZE]);
void Push(int x, int y, int turn);
void Pop(int BackPlane[SIZE][SIZE]);
void Push_c(int x, int y, int turn);

int CheckStone = 0;
int WhiteStone = 0;
int BlackStone = 0;
int Count_W = 0;
int Count_B = 0;
int Count_Max_W = 0;
int Count_Max_B = 0;
int Temp_W;
int Temp_B;
int P_x, P_y, P_CheckStone;
int Break_x;

_NODE head, head2;

int main()
{
	head.link = NULL;
	head2.link = NULL;
	int BackPlane[SIZE][SIZE] = { 0 };
	static int x = 0, y = 0;
	static int r_x, r_y, r_turn;
	int sel;
	FILE *fp;
	_NODE *curr, *read;

	MakePlane();
	while(1){
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
				PutStone(BackPlane);
				if (Break_x == -1){
					break;
				}
			}
			break;
		case 2:
			if ((fp = fopen("Test.txt", "w")) == NULL){
				fprintf(stderr, "파일을 읽는데 실패했습니다.");
				exit(1);
			}
			curr = head.link;
			while ( curr != NULL){
				fprintf(fp, "%d %d %d\n", curr->x, curr->y, curr->turn);
				curr = curr->link;
			}
			fclose(fp);
			gotoxy(45, 11);
			printf("저장되었습니다.");
			break;
		case 3:
			gotoxy(0,0);
			MakePlane();
			if ((fp = fopen("Test.txt", "r")) == NULL){
				fprintf(stderr, "파일을 읽는데 실패했습니다.");
				exit(1);
			}
			curr = head.link;
			while (!feof(fp)){
				fscanf(fp, "%d %d %d", &r_x, &r_y, &r_turn);
				curr->x = r_x; curr->y = r_y; curr->turn = r_turn;
				if (r_turn == 0){
					BackPlane[r_y][r_x] = 1;
				}
				else {
					BackPlane[r_y][r_x] = 2;
				}
			}
			fclose(fp);
			PutStone(BackPlane);
			break;
		case 4:
			Pop(BackPlane);
			gotoxy(0,0);
			MakePlane();
			PutStone(BackPlane);
			break;
		case 5:
			curr = head2.link;
			if (head2.link == NULL){
				gotoxy(45, 12);
				printf("취소할 값이 없습니다.");
				break;
			}
			if (curr->turn == 0){
				BackPlane[curr->y][curr->x] = 1;
				Push(curr->x, curr->y, curr->turn);
			}
			else {
				BackPlane[curr->y][curr->x] = 2;
				Push(curr->x, curr->y, curr->turn);
			}
			head2.link = curr->link;
			delete curr;
			PutStone(BackPlane);
			break;
		default:
			break;
		}
	}
	return 0;
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
		if (BackPlane[y][x] == 0){
			if (CheckStone == 0){
				BackPlane[y][x] = 1;
				Push(x, y, CheckStone);
				CheckStone = 1;
				++BlackStone;
			}
			else {
				BackPlane[y][x] = 2;
				Push(x, y, CheckStone);
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
		}
	}
}

void Push(int x, int y, int turn){
	_NODE *prev, *curr;

	prev = &head;
	curr = prev->link;

	_NODE *new_node = new _NODE;
	new_node->x = x;
	new_node->y = y;
	new_node->turn = turn;
	new_node->link = head.link;
	head.link = new_node;
}

void Pop(int BackPlane[SIZE][SIZE]){
	_NODE *prev, *curr;

	prev = &head;
	curr = prev->link;

	if (curr == NULL){
		gotoxy(45 , 10);
		printf("데이터가 없습니다.");
		return ;
	}
	else {
		Push_c(curr->x, curr->y, curr->turn);
		BackPlane[curr->y][curr->x] = 0;
		if (curr->turn == 0){
			CheckStone = 1;
		}
		else {
			CheckStone = 0;
		}
		prev->link = curr->link;
		delete curr;
	}
}

void Push_c(int x, int y, int turn)
{
	_NODE *prev, *curr;

	prev = &head2;
	curr = prev->link;

	_NODE *new_node = new _NODE;
	new_node->x = x;
	new_node->y = y;
	new_node->turn = turn;
	new_node->link = head2.link;
	head2.link = new_node;
}