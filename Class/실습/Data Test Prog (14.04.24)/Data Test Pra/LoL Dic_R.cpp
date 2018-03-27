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
		printf("1. 검색 2. 추가 3. 삭제 4. 전체출력 5. FindMax_Health\n");
		scanf("%d", &sel);
		fflush(stdin);

		switch (sel)
		{
		case 1:
			printf("찾으려는 챔피언의 이름을 입력하세요\n");
			gets(input);
			Find_R(0, input, Champion);
			break;
		case 2:
			printf("이  름:");
			gets(input);

			Insert_R(0, input, Champion, Copy);
			break;
		case 3:
			printf("이  름:");
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
		printf("이  름: %s\n", Champion[num].name);
		printf("체  력: %.2f\n", Champion[num].HealthPoint);
		printf("마  력: %.2f\n", Champion[num].MagicPoint);
		printf("공격력: %.2f\n", Champion[num].Power);
		return 0;
	}
	else if (num == SIZE){
		printf("찾으려는 챔피언이 없습니다.\n");
		return 0;
	}
	else 
		return Find_R(num + 1, input, Champion);
}

int Insert_R(int num, char input[50], Champ *Champion, Champ *Copy)
{
	if ( strcmp(input, Champion[num].name) == 0){
		printf("이미 존재하는 챔피언 입니다.\n");
		return 0;
	}
	else if ( Champion[num].Power == 0){
		strcpy(Champion[num].name, input);
		printf("체  력:");
		scanf("%f", &Champion[num].HealthPoint);
		fflush(stdin);
		printf("마  력:");
		scanf("%f", &Champion[num].MagicPoint);
		fflush(stdin);
		printf("공격력:");
		scanf("%f", &Champion[num].Power);
		fflush(stdin);

		strcpy(Copy[num].name, Champion[num].name);
		Copy[num].HealthPoint = Champion[num].HealthPoint;
		Copy[num].MagicPoint = Champion[num].MagicPoint;
		Copy[num].Power = Champion[num].Power;
	}
	else if (num == SIZE){
		printf("배열이 가득 찾습니다.\n");
	}
	else
		return Insert_R(num + 1, input, Champion, Copy);
}

int Delete_R(int num, char input[50], Champ *Champion, Champ *Copy)
{
	if ( strcmp(input, Champion[num].name) == 0){
		// 뒤에 있는 데이터를 당김 아직 근데 같은 데이터가 남음
		strcpy(Champion[num].name, Champion[num + 1].name);
		Champion[num].HealthPoint = Champion[num + 1].HealthPoint;
		Champion[num].MagicPoint = Champion[num + 1].MagicPoint;
		Champion[num].Power = Champion[num + 1].Power;
		// 당겼다는 상태용 k
		k = 1;
		return Delete_R(num + 1, input, Champion, Copy);
	}
	else if ( k == 1 && num < SIZE){
		// 뒤에껄 땡김 num < SIZE 일때 까지
		strcpy(Champion[num].name, Champion[num + 1].name);
		Champion[num].HealthPoint = Champion[num + 1].HealthPoint;
		Champion[num].MagicPoint = Champion[num + 1].MagicPoint;
		Champion[num].Power = Champion[num + 1].Power;
		return Delete_R(num +1, input, Champion, Copy);
	}
	else if ( k == 1 && num >= SIZE){
		// 마지막으로 땡김 
		strcpy(Champion[num].name, Champion[num + 1].name);
		Champion[num].HealthPoint = Champion[num + 1].HealthPoint;
		Champion[num].MagicPoint = Champion[num + 1].MagicPoint;
		Champion[num].Power = Champion[num + 1].Power;
		
		// 상태메세지 초기화
		k = 0;
		return 0;
	}
	// 노 챔피언
	else if (num >= SIZE){
		printf("삭제할 챔피언이 없습니다.\n");
	}
	else
		// 기본적으로 name 과 Champion[num].name 이 같을때까지 돌아야함
		return Delete_R(num +1, input, Champion, Copy);
}

int PrintAll_R(int num, Champ *Champion)
{
	if ( Champion[num].Power != 0){
		printf("이  름:%s\n", Champion[num].name);
		printf("체  력:%.2f\n", Champion[num].HealthPoint);
		printf("마  력:%.2f\n", Champion[num].MagicPoint);
		printf("공격력:%.2f\n", Champion[num].Power);
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
			printf("이름:%s\n", Champion[num].name);
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