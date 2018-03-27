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

void error(char *message);
_NODE *create_node(champion data, _NODE *link);
void insert_node(_NODE **phead, _NODE *new_node);
void delete_node(_NODE **phead, _NODE *delete_node);
void display(_NODE *head);
_NODE *search(_NODE *head, char name[20]);

int main()
{
	_NODE *list1 = NULL;
	_NODE *p;
	char input_name[20], name[20];
	float Health, Magic, Power;

	// list 1
	insert_node(&list1, create_node({"피즈", 500, 240, 56}, NULL));
	insert_node(&list1, create_node({"스웨인", 560, 360, 46 }, NULL));
	insert_node(&list1, create_node({"크랭크", 600, 240, 66 }, NULL));
	
	printf("챔피언 추가\n");
	printf("추가하실 챔피언의 이름을 입력하세요.");
	gets(input_name);
	printf("체  력:");
	scanf("%f", &Health);
	fflush(stdin);
	printf("마  력:");
	scanf("%f", &Magic);
	fflush(stdin);
	printf("공격력:");
	scanf("%f", &Power);
	fflush(stdin);
	insert_node(&list1, create_node({ , Health, Magic, Power }, NULL));
	display(list1);

	p = search(list1, "카사딘");
	printf("이름:%s\n체력:%.2f\n마력:%.2f\n공격력:%.2f\n", p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
	return 0;
}

_NODE *create_node(champion data, _NODE *link)
{
	_NODE *new_node;
	new_node = (_NODE *)malloc(sizeof(_NODE));
	if (new_node == NULL) error("메모리 할당 에러");
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}

void insert_node(_NODE **phead, _NODE *new_node)
{
	if ( *phead == NULL){
		*phead = new_node;
		new_node->link = new_node;
	}
	else {
		new_node->link = (*phead)->link;
		(*phead)->link = new_node;
	}
}

void delete_node(_NODE **phead, _NODE *p, _NODE *delete_node)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = delete_node->link;
	// 동적 메모리 할당 해제
	free(delete_node);
}

void display(_NODE *head)
{
	_NODE *p;
	if (head == NULL) return;

	p = head;
	do {
		printf("이름:%s\n체력:%.2f\n마력:%.2f\n공격력:%.2f\n", p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
		p = p->link;
	} while ( p != head);
	
	printf("\n");
}

_NODE *search(_NODE *head, char name[20])
{
	_NODE *p;
	//if (head == NULL) return;
	
	p = head;
	while ( strcmp(name, p->data.name) != 0){
		if ( p->link == head){
			printf("찾으려는 챔피언이 없습니다.\n");
			return NULL;
		} else
			p = p->link;
	}
	return p;
}

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}