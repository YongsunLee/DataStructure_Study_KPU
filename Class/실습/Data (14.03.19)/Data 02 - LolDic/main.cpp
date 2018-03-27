#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 118

struct Champ{
	char name[50];
	float HealthPoint;
	float MagicPoint;
	float Power;
}; struct Champ;

void Find(Champ *Champion);
void Insert(Champ *Champion);
void DeleteChamp(Champ *Champion);
void PrintAll(Champ *Champion);
void FindMax_Health(Champ *Champion);


int main()
{
	int i;
	int head;
	int num;
	Champ Champion[SIZE] = {{"����", 500, 240, 56},
							{"������", 463, 290, 52},
							{"����", 497, 255, 46.6},
							{"�� ��", 513, 200, 59},
							{"�ֽ�", 474, 208, 49.2},
							{"���ֳ̾�", 528, 270, 51},
							{"����",551, 0, 55.5},
							{"�׶󰡽�", 523, 268, 59.2},
							{"����", 439,348,51.1},
							{"����", 533, 255, 54.5},
							{"������", 500,305,55},
							{"����", 424,300,53.3},
							{"�巹�̺�", 502, 282, 50},
							{"����", 500, 0, 54},
							{"������", 449, 270, 50.7},
							{"��������", 536,222,58},
							{"������Ʈ", 513, 255, 59.7},
							{"����", 522,0,59.2},
							{"����", 442, 208, 53.3},
							{"���� ũ��ũ", 518, 240, 59.2}};
	head = sizeof(Champion);

	for( i = head; i <= SIZE; ++i){
		strcpy(Champion[i].name, "\0");
		Champion[i].HealthPoint = 0;
		Champion[i].MagicPoint = 0;
		Champion[i].Power = 0;
	}

	while(1){
		printf("������ �۾��� ������ �ּ���.\n");
		printf("1. �˻�, 2 �߰�, 3 ����, 4 ��ü ����, 5 FindMax_Health\n");
		scanf("%d", &num);
		fflush(stdin);
		switch (num)
		{
		case 1:
			Find(Champion);
			break;
		case 2:
			Insert(Champion);
			break;
		case 3:
			DeleteChamp(Champion);
			break;
		case 4:
			PrintAll(Champion);
			break;
		case 5:
			FindMax_Health(Champion);
			break;
		}
	}
	return 0;
}

void Find(Champ *Champion)
{
	int i;
	char FindChamp[20];

	printf("è�Ǿ� �˻�\n");
	printf("ã�� è�Ǿ��� �Է����ּ���.");
	gets(FindChamp);

	for( i = 0; Champion != 0; ++i){
		if(strcmp(FindChamp, Champion[i].name) == 0){
			printf("��  �� : %s\n", Champion[i].name);
			printf("ü  �� : %.2f\n", Champion[i].HealthPoint);
			printf("��  �� : %.2f\n", Champion[i].MagicPoint);
			printf("���ݷ� : %.2f\n", Champion[i].Power);
			break;
		} else if( i == SIZE ){
			printf("�ش� è�Ǿ��� �����ϴ�.\n");
			break;
		}
	}
}

void Insert(Champ *Champion)
{
	int i, j;
	int k = 0;

	for( i = 0; i < SIZE; ++i){
		if( Champion[i].Power == 0 ){
			printf("��  ��:");
			gets(Champion[i].name);
			for( j = 0; j < i; ++j){
				if( strcmp(Champion[i].name, Champion[j].name) == 0){
					printf("�̹� �����ϴ� è�Ǿ� �Դϴ�.\n");
					k = 1;
					break;
				}
			}
			if( k == 1){
				break;
				k = 0;
			}
			printf("ü  ��:");
			scanf("%f", &Champion[i].HealthPoint);
			fflush(stdin);
			printf("��  ��:");
			scanf("%f", &Champion[i].MagicPoint);
			fflush(stdin);
			printf("���ݷ�:");
			scanf("%f", &Champion[i].Power);
			fflush(stdin);
			break;
		}
	}
}

void DeleteChamp(Champ *Champion)
{
	int i, j = 0;
	char FindChamp[20];

	printf("è�Ǿ� ���� ����");
	printf("������ è�Ǿ��� �Է����ּ���.");
	gets(FindChamp);

	for(i = 0; i < SIZE; ++i){
		if( strcmp(FindChamp, Champion[i].name) == 0){
			for( j = i; j < 117; ++j){
				strcpy(Champion[j].name, Champion[j+1].name);
				Champion[j].HealthPoint = Champion[j+1].HealthPoint;
				Champion[j].MagicPoint = Champion[j+1].MagicPoint;
				Champion[j].Power = Champion[j+1].Power;
			}
		}
	}
}

void PrintAll(Champ *Champion)
{
	int i;

	for(i = 0; i < SIZE; ++i){
		if( Champion[i].Power != 0 ){
			printf("��  ��:%s\n", Champion[i].name);
			printf("ü  ��:%.2f\n", Champion[i].HealthPoint);
			printf("��  ��:%.2f\n", Champion[i].MagicPoint);
			printf("���ݷ�:%.2f\n", Champion[i].Power);
		}
	}
}

void FindMax_Health(Champ *Champion)
{
	int i;
	int temp = Champion[0].HealthPoint;

	for( i = 0; i < SIZE; ++i){
		if( temp < Champion[i].HealthPoint ){
			temp = Champion[i].HealthPoint;
		}
	}
	for( i = 0 ; i < SIZE ; ++i){
		if( temp == Champion[i].HealthPoint){
			printf("�� ��:%s\n", Champion[i].name);
		}
	}
}