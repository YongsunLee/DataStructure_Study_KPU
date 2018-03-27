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
	Champ Champion[SIZE] = { { "피즈", 500, 240, 56 },
							{ "스웨인", 463, 290, 52 },
							{ "를루", 497, 255, 46.6 },
							{ "리 신", 513, 200, 59 },
							{ "애쉬", 474, 208, 49.2 },
							{ "다이애나", 528, 270, 51 },
							{ "가렌", 551, 0, 55.5 },
							{ "그라가스", 523, 268, 59.2 },
							{ "나미", 439, 348, 51.1 },
							{ "누누", 533, 255, 54.5 },
							{ "라이즈", 500, 305, 55 },
							{ "럭스", 424, 300, 53.3 },
							{ "드레이븐", 502, 282, 50 },
							{ "리븐", 500, 0, 54 },
							{ "리산드라", 449, 270, 50.7 },
							{ "마스터이", 536, 222, 58 },
							{ "말파이트", 513, 255, 59.7 },
							{ "문도", 522, 0, 59.2 },
							{ "베인", 442, 208, 53.3 },
							{ "블리츠 크랭크", 518, 240, 59.2 } };
	head = sizeof(Champion);
	
	// 배열 초기화
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
			printf("찾으실 챔피언의 이름을 입력하세요.");
			gets(input);
			Find(Champion, input);
			break;
		case 2:
			Insert(Champion, Copy);
			break;
		case 3:
			printf("지우실 챔피언의 이름을 입력하세요.");
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
			printf("이  름 : %s\n", Champion[i].name);
			printf("체  력 : %.2f\n", Champion[i].HealthPoint);
			printf("마  력 : %.2f\n", Champion[i].MagicPoint);
			printf("공격력 : %.2f\n", Champion[i].Power);
			break;
		}
		else if ( i == SIZE){
			printf("해당 챔피언이 없습니다.\n");
			break;
		}
	}
}

void Insert(Champ Champion[SIZE], Champ Copy[SIZE])
{
	int b_roop = 0;

	for (int i = 0; i < SIZE; ++i){
		if (Champion[i].Power == 0){
			printf("이  름:");
			gets(Champion[i].name);
			for (int j = 0; j < i; ++j){
				if (strcmp(Champion[i].name, Champion[j].name) == 0){
					printf("이미 존재하는 챔피언 입니다.");
					b_roop = 1;
					break;
				}
			}
			if (b_roop == 1){
				break;
				b_roop = 0;
			}
			printf("체  력:");
			scanf("%f", &Champion[i].HealthPoint);
			fflush(stdin);
			printf("마  나:");
			scanf("%f", &Champion[i].MagicPoint);
			fflush(stdin);
			printf("공격력:");
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
			printf("이  름:%s\n", Champion[i].name);
			printf("체  력:%.2f\n", Champion[i].HealthPoint);
			printf("마  력:%.2f\n", Champion[i].MagicPoint);
			printf("공격력:%.2f\n", Champion[i].Power);
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
			printf("이 름:%s\n", Champion[i].name);
		}
	}
}

void SortByMax_Health(Champ Champion[SIZE], Champ temp[SIZE], Champ Copy[SIZE])
{
	//for (){

	//}
}