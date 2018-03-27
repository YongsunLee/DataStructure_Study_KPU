#include <stdio.h>
#include <Windows.h>

#pragma warning (disable : 4996)

#define SIZE 15

typedef struct NODE{
	int x;
	int y;
	int turn;
	struct NODE *next;
}NODE;

NODE *head, *head2;

int main() {
	int select = 0, i, j, turn = 0, a, b, c;
	static int x, y;
	char arr[SIZE][SIZE];
	NODE *p, *current;
	FILE *fp;

	head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;

	head2 = (NODE*)malloc(sizeof(NODE));
	head2->next = NULL;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++)
			arr[i][j] = '+';
	}

	while (1) {
		system("cls");
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++)
				printf("%c ", arr[j][i]);
			printf("\n");
		}
		printf("==============================\n");
		printf("원하는 메뉴를 선택하세요\n");
		printf("1. 오목두기\n");
		printf("2. 저장하기\n");
		printf("3. 불러오기\n");
		printf("4. 마지막 수 무르기\n");
		printf("5. 되돌리기\n");
		scanf("%d", &select);
		fflush(stdin);

		switch (select) {
		case 1:
			while (1) {
				system("cls");
				for (i = 0; i < SIZE; i++) {
					for (j = 0; j < SIZE; j++)
						printf("%c ", arr[j][i]);
					printf("\n");
				}
				printf("==============================\n");
				printf("오목돌을 둘 곳의 x, y좌표를 입력하여 주십시오. (-1을 입력하시면 종료합니다.)\n");
				if (turn == 0)
					printf("현재 검은돌 차례입니다.\n");
				else if (turn == 1)
					printf("현재 흰돌 차례입니다.\n");
				scanf("%d %d", &x, &y);
				fflush(stdin);
				if (x == -1)
					break;
				else if (x > SIZE || y > SIZE) {
					printf("범위를 벗어났습니다.");
					Sleep(500);
				}
				else if (arr[x - 1][y - 1] != '+') {
					printf("이미 놓여진 자리입니다.");
					Sleep(500);
				}
				else if (turn == 0) {
					arr[x - 1][y - 1] = 'B';
					p = (NODE*)malloc(sizeof(NODE));
					p->x = (x - 1), p->y = (y - 1), p->turn = 0;
					p->next = head->next;
					head->next = p;
					turn = 1;
				}
				else if (turn == 1) {
					arr[x - 1][y - 1] = 'W';
					p = (NODE*)malloc(sizeof(NODE));
					p->x = (x - 1), p->y = (y - 1), p->turn = 1;
					p->next = head->next;
					head->next = p;
					turn = 0;
				}
			}
			break;
		case 2:
			if ((fp = fopen("save.txt", "w")) == NULL) {
				fprintf(stderr, "파일을 열 수 없습니다.\n");
				exit(1);
			}
			current = head->next;
			while (current != NULL) {
				fprintf(fp, "%d %d %d\n", current->x, current->y, current->turn);
				current = current->next;
			}
			fclose(fp);
			printf("저장되었습니다.");
			Sleep(500);
			break;
		case 3:
			head->next = NULL;
			for (i = 0; i < SIZE; i++) {
				for (j = 0; j < SIZE; j++)
					arr[i][j] = '+';
			}
			if ((fp = fopen("save.txt", "r")) == NULL) {
				fprintf(stderr, "파일을 열 수 없습니다.\n");
				exit(1);
			}
			while (!feof(fp)) {
				p = (NODE*)malloc(sizeof(NODE));
				fscanf(fp, "%d %d %d", &a, &b, &c);
				p->x = a, p->y = b, p->turn = c;
				if (c == 0)
					arr[a][b] = 'B';
				else if (c == 1)
					arr[a][b] = 'W';
				if (head->next == NULL)  {
					if (c == 0)
						turn = 1;
					else if (c == 1)
						turn = 0;
					p->next = head->next;
					head->next = p;
					current = p;
				}
				else {
					p->next = current->next;
					current->next = p;
					current = p;
				}
			}
			fclose(fp);
			printf("불러왔습니다.");
			Sleep(500);
			break;
		case 4:
			current = head->next;
			if (current == NULL) {
				printf("더이상 무를 수 없습니다.");
				Sleep(500);
				break;
			}
			arr[current->x][current->y] = '+';
			head->next = current->next;
			current->next = head2->next;
			head2->next = current;
			if (turn == 0)
				turn = 1;
			else if (turn == 1)
				turn = 0;
			printf("무르기가 완료되었습니다.");
			Sleep(500);
			break;
		case 5:
			current = head2->next;
			if (current == NULL) {
				printf("취소할 수 없습니다.");
				Sleep(500);
				break;
			}
			if (current->turn == 0)
				arr[current->x][current->y] = 'B';
			else if (current->turn == 1)
				arr[current->x][current->y] = 'W';
			head2->next = current->next;
			current->next = head->next;
			head->next = current;
			printf("무르기가 취소되었습니다.");
			Sleep(500);
			break;
		default:
			break;
		}
	}
	return 0;
}