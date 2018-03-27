#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)

#define SIZE 200

struct Champ{
	char name[50];
	float HealthPoint;
	float MagicPoint;
	float Power;
};

void Find(Champ Champion[SIZE], char input[50]);
void Insert(Champ Champion[SIZE], Champ Copy[SIZE]);
void Delete(Champ Champion[SIZE], char input[50], Champ Copy[SIZE]);
void PrintAll(Champ Champion[SIZE]);
void FindMax_Health(Champ Champion[SIZE], int MaxHealth);
void FindMax_Health_Print(Champ Champion[SIZE], int MaxHealth);
void SortByMax_Health(Champ Champion[SIZE], Champ temp[SIZE], Champ Copy[SIZE]);

int main()
{
	int sel;
	int head;
	int Health_temp;
	int MaxHealth = 0;
	char input[50];
	Champ temp[SIZE], Copy[SIZE];
	Champ Champion[SIZE] = { { "����", 500, 240, 56 },
							{ "������", 463, 290, 52 },
							{ "����", 497, 255, 46.6 },
							{ "�� ��", 513, 200, 59 },
							{ "�ֽ�", 474, 208, 49.2 },
							{ "���ֳ̾�", 528, 270, 51 },
							{ "����", 551, 0, 55.5 },
							{ "�׶󰡽�", 523, 268, 59.2 },
							{ "����", 439, 348, 51.1 },
							{ "����", 533, 255, 54.5 },
							{ "������", 500, 305, 55 },
							{ "����", 424, 300, 53.3 },
							{ "�巹�̺�", 502, 282, 50 },
							{ "����", 500, 0, 54 },
							{ "������", 449, 270, 50.7 },
							{ "��������", 536, 222, 58 },
							{ "������Ʈ", 513, 255, 59.7 },
							{ "����", 522, 0, 59.2 },
							{ "����", 442, 208, 53.3 },
							{ "���� ũ��ũ", 518, 240, 59.2 } };
	head = sizeof(Champion);
	
	// �迭 �ʱ�ȭ
	for (int i = head; i < SIZE; ++i){
		strcpy(Champion[i].name, "\0");
		Champion[i].HealthPoint = 0;
		Champion[i].MagicPoint = 0;
		Champion[i].Power = 0;
	}

	for (int i = 0; i < SIZE; ++i){
		strcpy(temp[i].name, "\0");
		temp[i].HealthPoint = 0;
		temp[i].MagicPoint = 0;
		temp[i].Power = 0;
	}

	for (int i = 0; i < SIZE; ++i){
		strcpy(Copy[i].name, Champion[i].name);
		Copy[i].HealthPoint = Champion[i].HealthPoint;
		Copy[i].MagicPoint = Champion[i].MagicPoint;
		Copy[i].Power = Champion[i].Power;
	}

	while (1){

		printf("1.Find, 2.Insert, 3.Delete, 4.Print All, 5.FindMax_Health, 6.SortBy_MaxHealth");
		scanf("%d", &sel);
		fflush(stdin);

		switch (sel)
		{
		case 1:
			printf("ã���� è�Ǿ��� �̸��� �Է��ϼ���.");
			gets(input);
			Find(Champion, input);
			break;
		case 2:
			Insert(Champion, Copy);
			break;
		case 3:
			printf("����� è�Ǿ��� �̸��� �Է��ϼ���.");
			gets(input);
			Delete(Champion, input, Copy);
			break;
		case 4:
			PrintAll(Champion);
			break;
		case 5:
			FindMax_Health(Champion, MaxHealth);
			Health_temp = MaxHealth;
			FindMax_Health_Print(Champion, Health_temp);
			break;
		case 6:
			SortByMax_Health(Champion, temp, Copy);
			break;
		default:
			break;
		}
	}
	return 0;
}

void Find(Champ Champion[SIZE], char input[50])
{
	for (int i = 0; Champion != 0; ++i){
		if (strcmp(input, Champion[i].name) == 0){
			printf("��  �� : %s\n", Champion[i].name);
			printf("ü  �� : %.2f\n", Champion[i].HealthPoint);
			printf("��  �� : %.2f\n", Champion[i].MagicPoint);
			printf("���ݷ� : %.2f\n", Champion[i].Power);
			break;
		}
		else if ( i == SIZE){
			printf("�ش� è�Ǿ��� �����ϴ�.\n");
			break;
		}
	}
}

void Insert(Champ Champion[SIZE], Champ Copy[SIZE])
{
	int b_roop = 0;

	for (int i = 0; i < SIZE; ++i){
		if (Champion[i].Power == 0){
			printf("��  ��:");
			gets(Champion[i].name);
			for (int j = 0; j < i; ++j){
				if (strcmp(Champion[i].name, Champion[j].name) == 0){
					printf("�̹� �����ϴ� è�Ǿ� �Դϴ�.");
					b_roop = 1;
					break;
				}
			}
			if (b_roop == 1){
				break;
				b_roop = 0;
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

			strcpy(Copy[i].name, Champion[i].name);
			Copy[i].HealthPoint = Champion[i].HealthPoint;
			Copy[i].MagicPoint = Champion[i].MagicPoint;
			Copy[i].Power = Champion[i].Power;
			break;
		}
	}
}

void Delete(Champ Champion[SIZE], char input[50], Champ Copy[SIZE])
{
	for (int i = 0; i < SIZE; ++i){
		if (strcmp(input, Champion[i].name) == 0){
			for (int j = i; j < SIZE; ++j){
				strcpy(Champion[j].name, Champion[i].name);
				Champion[j].HealthPoint = Champion[i].HealthPoint;
				Champion[j].MagicPoint = Champion[i].MagicPoint;
				Champion[j].Power = Champion[i].Power;
			}

			for (int j = i; j < SIZE; ++j){
				strcpy(Copy[j].name, Copy[i].name);
				Copy[j].HealthPoint = Copy[i].HealthPoint;
				Copy[j].MagicPoint = Copy[i].MagicPoint;
				Copy[j].Power = Copy[i].Power;
			}
		}
	}
}

void PrintAll(Champ Champion[SIZE])
{
	for (int i = 0; i < SIZE; ++i){
		if (Champion[i].Power != 0){
			printf("��  ��:%s\n", Champion[i].name);
			printf("ü  ��:%.2f\n", Champion[i].HealthPoint);
			printf("��  ��:%.2f\n", Champion[i].MagicPoint);
			printf("���ݷ�:%.2f\n", Champion[i].Power);
		}
	}
}

void FindMax_Health(Champ Champion[SIZE], int MaxHealth)
{
	int temp = Champion[0].HealthPoint;

	for (int i = 0; i < SIZE; ++i){
		if ( temp < Champion[i].HealthPoint){
			temp = Champion[i].HealthPoint;
		}
	}
	MaxHealth = temp;
}

void FindMax_Health_Print(Champ Champion[SIZE],int MaxHealth)
{
	for (int i = 0; i < SIZE; ++i){
		if (MaxHealth == Champion[i].HealthPoint){
			printf("�� ��:%s\n", Champion[i].name);
		}
	}
}

void SortByMax_Health(Champ Champion[SIZE], Champ temp[SIZE], Champ Copy[SIZE])
{
	//for (){

	//}
}