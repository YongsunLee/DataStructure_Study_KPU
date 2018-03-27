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
		printf("���ϴ� �޴��� �����ϼ���\n");
		printf("1. ����α�\n");
		printf("2. �����ϱ�\n");
		printf("3. �ҷ�����\n");
		printf("4. ������ �� ������\n");
		printf("5. �ǵ�����\n");
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
				printf("������ �� ���� x, y��ǥ�� �Է��Ͽ� �ֽʽÿ�. (-1�� �Է��Ͻø� �����մϴ�.)\n");
				if (turn == 0)
					printf("���� ������ �����Դϴ�.\n");
				else if (turn == 1)
					printf("���� �� �����Դϴ�.\n");
				scanf("%d %d", &x, &y);
				fflush(stdin);
				if (x == -1)
					break;
				else if (x > SIZE || y > SIZE) {
					printf("������ ������ϴ�.");
					Sleep(500);
				}
				else if (arr[x - 1][y - 1] != '+') {
					printf("�̹� ������ �ڸ��Դϴ�.");
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
				fprintf(stderr, "������ �� �� �����ϴ�.\n");
				exit(1);
			}
			current = head->next;
			while (current != NULL) {
				fprintf(fp, "%d %d %d\n", current->x, current->y, current->turn);
				current = current->next;
			}
			fclose(fp);
			printf("����Ǿ����ϴ�.");
			Sleep(500);
			break;
		case 3:
			head->next = NULL;
			for (i = 0; i < SIZE; i++) {
				for (j = 0; j < SIZE; j++)
					arr[i][j] = '+';
			}
			if ((fp = fopen("save.txt", "r")) == NULL) {
				fprintf(stderr, "������ �� �� �����ϴ�.\n");
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
			printf("�ҷ��Խ��ϴ�.");
			Sleep(500);
			break;
		case 4:
			current = head->next;
			if (current == NULL) {
				printf("���̻� ���� �� �����ϴ�.");
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
			printf("�����Ⱑ �Ϸ�Ǿ����ϴ�.");
			Sleep(500);
			break;
		case 5:
			current = head2->next;
			if (current == NULL) {
				printf("����� �� �����ϴ�.");
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
			printf("�����Ⱑ ��ҵǾ����ϴ�.");
			Sleep(500);
			break;
		default:
			break;
		}
	}
	return 0;
}