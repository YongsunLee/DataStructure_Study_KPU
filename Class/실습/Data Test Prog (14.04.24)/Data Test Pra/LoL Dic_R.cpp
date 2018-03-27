#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#pragma warning(disable:4996)

#define SIZE 200

struct Champ{
	char name[20];
	float HealthPoint;
	float MagicPoint;
	float Power;
};

int Find_R(int num, char name[50], Champ *Champion);
int Insert_R(int num, char name[50], Champ *Champion, Champ *CopyChampion);
int Delete_R(int num, char name[50], Champ *Champion, Champ *CopyChampion);
int PrintAll_R(int num, Champ *Champion);
int FindMax_Health_R(int num, float temp, Champ *Champion);
int FindMax_Health_Print_R(int num, float temp, Champ *Champion);
int SortByMax_Health_R(int num, Champ *Champion, Champ *temp, Champ *Copy);

int k;
int num_temp, num_copy;
static int size = 200;
float MaxHealth;

int main()
{
	int sel;
	int head;
	float Health_temp;
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
	
	for (int i = head; i < SIZE; ++i){
		strcpy(Champion[i].name, NULL);
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

	while (1)
	{
		printf("1. �˻� 2. �߰� 3. ���� 4. ��ü��� 5. FindMax_Health\n");
		scanf("%d", &sel);
		fflush(stdin);

		switch (sel)
		{
		case 1:
			printf("ã������ è�Ǿ��� �̸��� �Է��ϼ���\n");
			gets(input);
			Find_R(0, input, Champion);
			break;
		case 2:
			printf("��  ��:");
			gets(input);

			Insert_R(0, input, Champion, Copy);
			break;
		case 3:
			printf("��  ��:");
			gets(input);

			Delete_R(0, input, Champion, Copy);
			break;
		case 4:
			PrintAll_R(0, Champion);
			break;
		case 5:
			Health_temp = Champion[0].HealthPoint;
			FindMax_Health_R(1, Health_temp, Champion);
			FindMax_Health_Print_R(0, MaxHealth, Champion);
			break;
		case 6:
			SortByMax_Health_R(0, Champion, temp, Copy);
			break;
		default:
			break;
		}
	}
}

int Find_R(int num, char input[50], Champ *Champion)
{
	if ( strcmp(input, Champion[num].name) == 0){
		printf("��  ��: %s\n", Champion[num].name);
		printf("ü  ��: %.2f\n", Champion[num].HealthPoint);
		printf("��  ��: %.2f\n", Champion[num].MagicPoint);
		printf("���ݷ�: %.2f\n", Champion[num].Power);
		return 0;
	}
	else if (num == SIZE){
		printf("ã������ è�Ǿ��� �����ϴ�.\n");
		return 0;
	}
	else 
		return Find_R(num + 1, input, Champion);
}

int Insert_R(int num, char input[50], Champ *Champion, Champ *Copy)
{
	if ( strcmp(input, Champion[num].name) == 0){
		printf("�̹� �����ϴ� è�Ǿ� �Դϴ�.\n");
		return 0;
	}
	else if ( Champion[num].Power == 0){
		strcpy(Champion[num].name, input);
		printf("ü  ��:");
		scanf("%f", &Champion[num].HealthPoint);
		fflush(stdin);
		printf("��  ��:");
		scanf("%f", &Champion[num].MagicPoint);
		fflush(stdin);
		printf("���ݷ�:");
		scanf("%f", &Champion[num].Power);
		fflush(stdin);

		strcpy(Copy[num].name, Champion[num].name);
		Copy[num].HealthPoint = Champion[num].HealthPoint;
		Copy[num].MagicPoint = Champion[num].MagicPoint;
		Copy[num].Power = Champion[num].Power;
	}
	else if (num == SIZE){
		printf("�迭�� ���� ã���ϴ�.\n");
	}
	else
		return Insert_R(num + 1, input, Champion, Copy);
}

int Delete_R(int num, char input[50], Champ *Champion, Champ *Copy)
{
	if ( strcmp(input, Champion[num].name) == 0){
		// �ڿ� �ִ� �����͸� ��� ���� �ٵ� ���� �����Ͱ� ����
		strcpy(Champion[num].name, Champion[num + 1].name);
		Champion[num].HealthPoint = Champion[num + 1].HealthPoint;
		Champion[num].MagicPoint = Champion[num + 1].MagicPoint;
		Champion[num].Power = Champion[num + 1].Power;
		// ���ٴ� ���¿� k
		k = 1;
		return Delete_R(num + 1, input, Champion, Copy);
	}
	else if ( k == 1 && num < SIZE){
		// �ڿ��� ���� num < SIZE �϶� ����
		strcpy(Champion[num].name, Champion[num + 1].name);
		Champion[num].HealthPoint = Champion[num + 1].HealthPoint;
		Champion[num].MagicPoint = Champion[num + 1].MagicPoint;
		Champion[num].Power = Champion[num + 1].Power;
		return Delete_R(num +1, input, Champion, Copy);
	}
	else if ( k == 1 && num >= SIZE){
		// ���������� ���� 
		strcpy(Champion[num].name, Champion[num + 1].name);
		Champion[num].HealthPoint = Champion[num + 1].HealthPoint;
		Champion[num].MagicPoint = Champion[num + 1].MagicPoint;
		Champion[num].Power = Champion[num + 1].Power;
		
		// ���¸޼��� �ʱ�ȭ
		k = 0;
		return 0;
	}
	// �� è�Ǿ�
	else if (num >= SIZE){
		printf("������ è�Ǿ��� �����ϴ�.\n");
	}
	else
		// �⺻������ name �� Champion[num].name �� ���������� ���ƾ���
		return Delete_R(num +1, input, Champion, Copy);
}

int PrintAll_R(int num, Champ *Champion)
{
	if ( Champion[num].Power != 0){
		printf("��  ��:%s\n", Champion[num].name);
		printf("ü  ��:%.2f\n", Champion[num].HealthPoint);
		printf("��  ��:%.2f\n", Champion[num].MagicPoint);
		printf("���ݷ�:%.2f\n", Champion[num].Power);
		return PrintAll_R(num + 1, Champion);
	}
	else 
		return 0;
}

int FindMax_Health_R(int num, float temp, Champ *Champion)
{
	if (num < SIZE){
		if (temp < Champion[num].HealthPoint){
			temp = Champion[num].HealthPoint;
			num_temp = num;
		}
		return FindMax_Health_R(num + 1, temp, Champion);
	}
	else{
		MaxHealth = temp;
		num_copy = num_temp;
		temp = 0;
		num_temp = 0;
	}
}

int FindMax_Health_Print_R(int num, float MaxHealth, Champ *Champion)
{
	if ( num < SIZE){
		if (MaxHealth == Champion[num].HealthPoint){
			printf("�̸�:%s\n", Champion[num].name);
		}
		return FindMax_Health_Print_R(num + 1, MaxHealth, Champion);
	}
}

int SortByMax_Health_R(int num, Champ *Champion, Champ *temp, Champ *Copy)
{
	if (size > 0){
		FindMax_Health_R(0, MaxHealth, Champion);
		strcpy(temp[num].name, Copy[num_copy].name);
		temp[num].HealthPoint = Copy[num_copy].HealthPoint;
		temp[num].MagicPoint = Copy[num_copy].MagicPoint;
		temp[num].Power = Copy[num_copy].Power;

		Champion[num_copy].HealthPoint = 0;
		Champion[num_copy].MagicPoint = 0;
		Champion[num_copy].Power = 0;
		size -= 1;
		num_copy = 0;
		return SortByMax_Health_R(num + 1, Champion, temp, Copy);
	}
	else if (size <= 0 && num >= 0){
		strcpy(Champion[num].name, temp[num].name);
		Champion[num].HealthPoint = temp[num].HealthPoint;
		Champion[num].MagicPoint = temp[num].MagicPoint;
		Champion[num].Power = temp[num].Power;
		return SortByMax_Health_R(num - 1, Champion, temp, Copy);
	}
	return 0;
}