#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

struct CHAMP{
	char name[20];
	float HealthPoint;
	float MagicPoint;
	float Power;
};

struct _NODE{
	CHAMP data;
	struct _NODE *link;
};

_NODE *create_node_list(CHAMP data, _NODE *link);
_NODE *Find(_NODE *head, char input_Name[20]);
void insert(_NODE **head, _NODE *new_node);
void insert_node(_NODE **head, char input_Name[20]);
void delete_node(_NODE **head, char input_Name[20]);
void PrintAll(_NODE *head);
float FindMax_Health(_NODE *head);
void FindMax_Health_Print(_NODE *head, float temp);

int main()
{
	_NODE *champion_list = NULL;
	_NODE *p;
	int selection;
	char input_Name[20];
	float Max_temp = 0;
	int i;
	CHAMP data[21] = { {},
	{ "피즈", 500, 240, 56 },
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
	{ "블리츠 크랭크", 518, 240, 59.2 }, };

	for (i = 0; i < 21; ++i){
		insert(&champion_list, create_node_list(data[i], NULL));
	}

	while (1){
		printf("1. 검색, 2. 추가, 3. 삭제, 4. 모두보기, 5. FindMax_Health, 6.SortBy_Max_Health\n");
		scanf("%d", &selection);
		fflush(stdin);

		switch (selection)
		{
		case 1:
			printf("챔피언 검색\n");
			printf("검색하실 챔피언의 이름을 입력하세요.");
			gets(input_Name);

			p = Find(champion_list, input_Name);
			if ( p != NULL){
				printf("이  름:%s\n체  력:%.2f\n마  력:%.2f\n공격력:%.2f\n",
					p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
			}
			break;
		case 2:
			printf("챔피언 추가\n");
			printf("추가하실 챔피언의 이름을 입력하세요.");
			gets(input_Name);

			insert_node(&champion_list, input_Name);
			break;
		case 3:
			printf("챔피언 삭제\n");
			printf("삭제하실 챔피언의 이름을 입력하세요.");
			gets(input_Name);

			delete_node(&champion_list, input_Name);
			break;
		case 4:
			PrintAll(champion_list);
			break;
		case 5:
			Max_temp = FindMax_Health(champion_list);
			FindMax_Health_Print(champion_list, Max_temp);
			break;
		default:
			break;
		}
	}

}

_NODE *Find(_NODE *head, char input_Name[20])
{
	_NODE *curr;

	curr = head;
	while (strcmp(input_Name, curr->data.name) != 0){
		if (curr->link == head){
			printf("존재하지 않는 챔피언입니다.\n");
			return NULL;
		}
		else
			curr = curr->link;
	}
	return curr;
}

_NODE *create_node_list(CHAMP data, _NODE *link)
{
	_NODE *new_node;
	new_node = (_NODE*)malloc(sizeof(_NODE));
	new_node->data = data;
	new_node->link = link;
	return new_node;
}

void insert(_NODE **head, _NODE *new_node)
{
	if (*head == NULL){
		*head = new_node;
		new_node->link = new_node;
	}
	else {
		new_node->link = (*head)->link;
		(*head)->link = new_node;
	}
}

void PrintAll(_NODE *head)
{
	_NODE *curr;

	curr = head;
	do{
		if (curr->data.HealthPoint == 0){
			curr = curr->link;
		}
		printf("이  름:%s\n 체  력:%.2f\n 마  력:%.2f\n 공격력:%.2f\n",
			curr->data.name, curr->data.HealthPoint, curr->data.MagicPoint, curr->data.Power);
		curr = curr->link;
	} while (curr != head);

	printf("\n");
}

void insert_node(_NODE **head, char input_Name[20])
{
	_NODE *plus_node;
	_NODE *prev, *curr;
	bool check = true;

	prev = *head;
	curr = prev->link;
	plus_node = (_NODE*)malloc(sizeof(_NODE));

	while (curr->link != (*head)->link){
		if (strcmp(input_Name, curr->data.name) == 0){
			printf("이미 존재하는 챔피언입니다.\n");
			check = false;
			break;
		}
		prev = curr;
		curr = curr->link;
	}
	if (check == true){
		printf("이  름:%s\n", input_Name);
		strcpy(curr->data.name, input_Name);
		printf("체  력:");
		scanf("%f", &curr->data.HealthPoint);
		fflush(stdin);
		printf("마  력:");
		scanf("%f", &curr->data.MagicPoint);
		fflush(stdin);
		printf("공격력:");
		scanf("%f", &curr->data.Power);
		fflush(stdin);
		plus_node->link = prev->link;
		prev->link = plus_node;
	}
}

void delete_node(_NODE **head, char input_Name[20])
{
	_NODE *curr, *prev;

	prev = *head;
	curr = prev->link;

	while (curr->link != (*head)->link)
	{
		if (strcmp(input_Name, curr->data.name) == 0){
			prev->link = curr->link;
			free(curr);
			break;
		}
		prev = curr;
		curr = curr->link;
	}

}

float FindMax_Health(_NODE *head)
{
	_NODE *prev, *curr;
	float temp = 0;

	prev = head;
	curr = prev->link;
	while (curr->link != head->link){
		if (curr->data.HealthPoint > temp){
			temp = curr->data.HealthPoint;
		}
		prev = curr;
		curr = curr->link;
	}
	return temp;
}

void FindMax_Health_Print(_NODE *head, float temp)
{
	_NODE *prev, *curr;

	prev = head;
	curr = prev->link;
	while (curr->link != head->link){
		if (curr->data.HealthPoint == temp){
			printf("이  름:%s\n", curr->data.name);
		}
		prev = curr;
		curr = curr->link;
	}
}