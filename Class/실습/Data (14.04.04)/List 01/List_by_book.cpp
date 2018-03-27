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

typedef struct ListNode{  //단순연결리스트의 노드 구조 정의
	CHAMP data;
	struct ListNode *link;
} listNode;

typedef struct{   //리스트의 헤드 노드의 구조 정의
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
listNode *Find(linkedList_h*, char input_Name[20]);
void addLastNode(linkedList_h*, char input_Name[20]);
void deleteLastNode(linkedList_h*, char input_Name[20]);
void printList(linkedList_h*);

listNode *create_node_list(CHAMP data, listNode *link);
void insert_node_test(listNode **phead, char input_Name[20]);

listNode *create_node_list(CHAMP data, listNode *link)
{
	listNode *new_node;
	new_node = (listNode *)malloc(sizeof(listNode));
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}

void insert_node(listNode **phead, listNode *new_node)
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

void insert_node_test(listNode **head, char input_Name[20])
{
	listNode *plus_node;
	listNode *prev, *curr;

	prev = *head;
	curr = prev->link;
	plus_node = (ListNode*)malloc(sizeof(listNode));

	while (curr->link != (*head)->link){
		if (strcmp(input_Name, curr->data.name) == 0){
			printf("이미 존재하는 챔피언입니다.\n");
			break;
		}
		else if (curr->link == (*head)){
			if (strcmp(input_Name, curr->data.name) == 0){
				printf("이미 존재하는 챔피언입니다.\n");
				break;
			}
		}
		prev = curr;
		curr = curr->link;
	}
	//if (){
	printf("이름:%s\n", input_Name);
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
	//}

	plus_node->link = curr;
	prev->link = plus_node;
}


linkedList_h* createLinkedList_h(void){  //공백 연결리스트 생성 연산
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h)); //헤드 노드 할당
	L->head = NULL; //공백 리스트이므로 NULL 설정
	return L;
}

listNode *Find(linkedList_h *L, char input_Name[20])
{
	listNode *p;

	p = L->head;
	while (strcmp(input_Name, p->data.name) != 0){
		if (p->link == L->head){
			printf("찾으려는 챔피언이 없습니다.\n");
			return NULL;
		}
		else
			p = p->link;
	}
	return p;
}

void addNode(linkedList_h *L, char input_Name[20]){ //리스트의 마지막 노드 삽입 연산
	listNode *newNode;
	listNode *curr;
	listNode *prev;

	prev = L->head;
	curr = prev->link;

	// 중복검사
	while ( curr->link != L->head){
		if (strcmp(input_Name, curr->data.name) == 0){
			printf("이미 존재하는 챔피언입니다.");
			break;
		}
		prev = curr;
		curr = curr->link;
	}
	
	newNode = (listNode*)malloc(sizeof(listNode));
	printf("이름:");
	strcpy(newNode->data.name, input_Name);
	printf("체  력:");
	scanf("%f", &newNode->data.HealthPoint);
	fflush(stdin);
	printf("마  력:");
	scanf("%f", &newNode->data.MagicPoint);
	fflush(stdin);
	printf("공격력:");
	scanf("%f", &newNode->data.Power);
	fflush(stdin);
	newNode->link = curr;
	prev->link = newNode;
}

void deleteNode(linkedList_h * L, char input_Name[20]){
	listNode *curr, *prev;
	
	prev = L->head;
	curr = prev->link;
	while (curr->link != L->head->link){
		if (strcmp(input_Name, curr->data.name) == 0){
			prev->link = curr->link;
			free(curr);
			break;
		}
		if (curr->link == L->head->link){
			break;
		}
		prev = curr;
		curr = curr->link;
	}
}

void printList(linkedList_h* L){   //노드 순서대로 리스트를 출력하는 연산
	listNode *p;
	if (L->head == NULL) return;

	p = L->head;
	do {
		printf("이름:%s\n체력:%.2f\n마력:%.2f\n공격력:%.2f\n", p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
		p = p->link;
	} while (p != L->head);

	printf("\n");
}


int main(){
	linkedList_h* L;
	listNode *p;
	listNode *champion_list = NULL;
	char input_Name[20];
	int select;
	L = createLinkedList_h();
	
	insert_node(&champion_list, create_node_list({ "피즈", 500, 240, 56 }, NULL));
	insert_node(&champion_list, create_node_list({ "스웨인", 560, 360, 46 }, NULL));
	insert_node(&champion_list, create_node_list({ "크랭크", 600, 240, 66 }, NULL));

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

			p = Find(L, input_Name);
			if (p != NULL){
				printf("이름:%s\n체력:%.2f\n마력:%.2f\n공격력:%.2f\n", p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
			}
			else {
				printf("찾으려는 챔피언이 없습니다.\n");
			}
			break;
		case 2:
			printf("챔피언 추가\n");
			printf("추가하실 챔피언의 이름을 입력하세요.");
			gets(input_Name);
			
			addNode(L, input_Name);
			break;
		case 3:
			printf("챔피언 검색\n");
			printf("삭제하실 챔피언의 이름을 입력하세요.");
			gets(input_Name);

			deleteNode(L, input_Name);
			break;
		case 4:
			printList(L);
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}
	}
	return 0;
}
