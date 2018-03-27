#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define SIZE 200

struct Champ{
	char name[20];
	float HealthPoint;
	float MagicPoint;
	float Power;
};

void Find(Champ *Champion);
void Insert(Champ *Champion);
void Delete(Champ *Champion);
void PrintAll(Champ *Champion);
void FindMax_Health(Champ *Champion);

int i, j, k;

int main()
{
	Champ Champion[SIZE] = {{"피즈", 500, 240, 56},
							{"스웨인", 463, 290, 52},
							{"를루", 497, 255, 46.6},
							{"리 신", 513, 200, 59},
							{"애쉬", 474, 208, 49.2},
							{"다이애나", 528, 270, 51},
							{"가렌",551, 0, 55.5},
							{"그라가스", 523, 268, 59.2},
							{"나미", 439,348,51.1},
							{"누누", 533, 255, 54.5},
							{"라이즈", 500,305,55},
							{"럭스", 424,300,53.3},
							{"드레이븐", 502, 282, 50},
							{"리븐", 500, 0, 54},
							{"리산드라", 449, 270, 50.7},
							{"마스터이", 536,222,58},
							{"말파이트", 513, 255, 59.7},
							{"문도", 522,0,59.2},
							{"베인", 442, 208, 53.3},
							{"블리츠 크랭크", 518, 240, 59.2}};
	int num;
	int head;
	
	head = sizeof(Champion);

	for( i = head ; i < SIZE; ++i){
		strcpy(Champion[i].name , NULL);
		Champion[i].HealthPoint = 0;
		Champion[i].MagicPoint = 0;
		Champion[i].Power = 0;
	}
	while(1){
		printf("1. 검색 2. 추가 3. 삭제 4. 전체출력 5. FindMax_Health");
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
			Delete(Champion);
			break;
		case 4:
			PrintAll(Champion);
			break;
		case 5:
			FindMax_Health(Champion);
			break;
		default:
			break;
		}
	}
}

void Find(Champ *Champion)
{
	char InputChamp[20];

	printf("찾으려는 챔피언의 이름을 입력하세요\n");
	gets(InputChamp);

	for( i = 0; i < SIZE; ++i){
		if ( strcmp(InputChamp, Champion[i].name) == 0){
			printf("이  름: %s\n", Champion[i].name);
			printf("체  력: %.2f\n", Champion[i].HealthPoint);
			printf("마  력: %.2f\n", Champion[i].MagicPoint);
			printf("공격력: %.2f\n", Champion[i].Power);
		} else if ( i == SIZE)
			printf("찾으려는 챔피언이 없습니다.\n");
	}
}

void Insert(Champ *Champion)
{
	for( i = 0; i < SIZE; ++i){
		if ( Champion[i].HealthPoint == 0){
			printf("이  름:");
			gets(Champion[i].name);
			for(j = 0; j < i; ++j){
				if( strcmp(Champion[i].name, Champion[j].name) == 0 ){
					printf("이미 존재하는 챔피언입니다.\n");
					k = 1;
					break;
				}
			}
			if( k == 1 ){
				break;
				k = 0;
			}
			printf("체  력:");
			scanf("%f", &Champion[i].HealthPoint);
			fflush(stdin);
			printf("마  력:");
			scanf("%f", &Champion[i].MagicPoint);
			fflush(stdin);
			printf("공격력:");
			scanf("%f", &Champion[i].Power);
			fflush(stdin);
			break;
		}
	}
}

void Delete(Champ *Champion)
{
	char InputChamp[20];
	char Testarr[1];

	printf("삭제할 챔피언의 이름을 입력해 주세요:");
	gets(InputChamp);

	for( i = 0; i < SIZE; ++i){
		if( strcmp(InputChamp, Champion[i].name) == 0){
			for( j = i; j < 177; ++j){
				strcpy(Champion[i].name , Champion[j+1].name);
				Champion[i].HealthPoint = Champion[j+1].HealthPoint;
				Champion[i].MagicPoint = Champion[j+1].MagicPoint;
				Champion[i].Power = Champion[j+1].Power;
			}
		}
	}
}

void PrintAll(Champ *Champion)
{
	for( i = 0; Champion != 0; ++i){
		if( Champion[i].Power != 0 ){
		printf("이  름:%s\n", Champion[i].name);
		printf("체  력:%.2f\n", Champion[i].HealthPoint);
		printf("마  력:%.2f\n", Champion[i].MagicPoint);
		printf("공격력:%.2f\n", Champion[i].Power);
		}
	}
}

void FindMax_Health(Champ *Champion)
{
	float temp = Champion[0].HealthPoint;

	for( i = 0; i < SIZE; ++i){
		if( temp < Champion[i].HealthPoint){
			temp = Champion[i].HealthPoint;
		}
	}
	for ( i = 0; i < SIZE; ++j){
		if( temp == Champion[i].HealthPoint){
			printf("이 름:%s", Champion[j].name);
		}
	}
}