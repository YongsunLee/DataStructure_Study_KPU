/*
14.4.4	13:41
Linked list Start
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

typedef struct Champ{
	char name[20];
	float HealthPoint;
	float MagicPoint;
	float Power;
}CHAMP;

typedef CHAMP champion;
typedef struct _NODE{
	champion data;
	struct _NODE *link;
}_NODE;

_NODE *create_node_insert(_NODE *link);
_NODE *create_node_list( champion data , _NODE *link);
_NODE *search(_NODE *head, char name[20]);
void insert_node(_NODE **phead, _NODE *new_node);
void insert_node_test(_NODE **phead, char input_Name[20]);
void delete_node(_NODE **phead, _NODE *p, char *name);
void display(_NODE *head);
float FindMax_Health(_NODE *head);
void FindMax_Health_Print(_NODE *head, float temp);
void SortBy_MaxHealth(_NODE *champion_list, _NODE *champion_copy_list);

int main()
{
	_NODE *champion_list = NULL;
	_NODE *champion_copy_list = NULL;
	_NODE *p;
	float Max_temp = 0;
	int select;
	char input_Name[20];
	champion data[21] = { {},
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

	for (int i = 0; i < 21; ++i){
		insert_node(&champion_list, create_node_list(data[i], NULL));
	}

	while (1)
	{
		printf("1. 검색, 2. 추가 3. 삭제 4. 모두보기 5. FIndMax_Health, 6. Sort_By_Max_Health\n");
		scanf("%d", &select);
		fflush(stdin);

		switch (select)
		{
		case 1:
			printf("챔피언 검색\n");
			printf("찾으실 챔피언의 이름을 입력하세요.");
			gets(input_Name);

			p = search(champion_list, input_Name);
			if ( p != NULL){
				printf("이름:%s\n체력:%.2f\n마력:%.2f\n공격력:%.2f\n", p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
			}
			break;
		case 2:
			printf("챔피언 추가\n");
			printf("추가하실 챔피언의 이름을 입력하세요.");
			gets(input_Name);

			insert_node_test(&champion_list, input_Name);
			break;
		case 3:
			printf("챔피언 삭제\n");
			printf("삭제하실 챔피언의 이름을 입력하세요.");
			gets(input_Name);

			delete_node(&champion_list, NULL, input_Name);
			break;
		case 4:
			display(champion_list);
			break;
		case 5:
			Max_temp = FindMax_Health(champion_list);
			FindMax_Health_Print(champion_list, Max_temp);
			break;
		case 6:
			SortBy_MaxHealth(champion_list, champion_copy_list);
			display(champion_copy_list);
			break;
		default:
			break;
		}
	}
	return 0;
}

_NODE *create_node_list(champion data, _NODE *link)
{
	_NODE *new_node;
	new_node = (_NODE *)malloc(sizeof(_NODE));
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}

_NODE *create_node_insert( _NODE *link)
{
	_NODE *new_node;
	
	new_node = (_NODE *)malloc(sizeof(_NODE));
	printf("이  름:");
	gets(new_node->data.name);
	printf("체  력:");
	scanf("%f", &new_node->data.HealthPoint);
	fflush(stdin);
	printf("마  력:");
	scanf("%f", &new_node->data.MagicPoint);
	fflush(stdin);
	printf("공격력:");
	scanf("%f", &new_node->data.Power);
	fflush(stdin);

	new_node->link = link;
	return (new_node);
}

void insert_node(_NODE **phead, _NODE *new_node)
{
	if (*phead == NULL){
		*phead = new_node;
		new_node->link = new_node;
	}
	else {
		new_node->link = (*phead)->link;
		(*phead)->link = new_node;
	}
}

void insert_node_test(_NODE **head, char input_Name[20])
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
		strcpy(plus_node->data.name, input_Name);
		printf("체  력:");
		scanf("%f", &plus_node->data.HealthPoint);
		fflush(stdin);
		printf("마  력:");
		scanf("%f", &plus_node->data.MagicPoint);
		fflush(stdin);
		printf("공격력:");
		scanf("%f", &plus_node->data.Power);
		fflush(stdin);

		plus_node->link = curr;
		prev->link = plus_node;
	}
}

void delete_node(_NODE **phead, _NODE *p, char *name)
{
	_NODE *curr, *prev;
	prev = *phead;
	curr = prev->link;
	while (1){
	if(curr->link == (*phead)->link){
		if (strcmp(name, curr->data.name) == 0){
			prev->link = curr->link;
			free(curr);
			break;
		}
	} else if( curr->link != (*phead)->link){
		if (strcmp(name, curr->data.name) == 0){
			prev->link = curr->link;
			free(curr);
			break;
		} 
	}
		prev = curr;
		curr = curr->link;
	}
}

void display(_NODE *head)
{
	_NODE *p;
	if (head == NULL) return;

	p = head;
	do {
		if (p->data.HealthPoint == NULL){
			p = p->link;
		}
		printf("이름:%s\n체력:%.2f\n마력:%.2f\n공격력:%.2f\n", p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
		p = p->link;
	} while (p != head);

	printf("\n");
}

_NODE *search(_NODE *head, char name[20])
{
	_NODE *p;
	
	p = head;
	while (strcmp(name, p->data.name) != 0){
		if (p->link == head){
			printf("찾으려는 챔피언이 없습니다.\n");
			return NULL;
		}
		else
			p = p->link;
	}
	return p;
}

float FindMax_Health(_NODE *head)
{
	_NODE *prev, *curr;
	float temp = 0;

	prev = head;
	curr = prev->link;
	while (curr->link != head->link){
		if ( curr->data.HealthPoint > temp){
			temp = curr->data.HealthPoint;
		}
		prev = curr;
		curr = curr->link;
	}
	return temp;
}

void FindMax_Health_Print( _NODE *head, float temp)
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

void SortBy_MaxHealth(_NODE *head, _NODE *copy)
{
	float Max_temp = 0;
	_NODE *prev, *curr;
	
	Max_temp = FindMax_Health(head);

	prev = head;
	curr = prev->link;
	while (curr->link != head->link){
		if (curr->data.HealthPoint == Max_temp){
			insert_node(&copy, curr);
			delete_node(&head, NULL, curr->data.name);
			break;
		}
		prev = curr;
		curr = curr->link;
	}
}