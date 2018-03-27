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

typedef struct ListNode{  //�ܼ����Ḯ��Ʈ�� ��� ���� ����
	CHAMP data;
	struct ListNode *link;
} listNode;

typedef struct{   //����Ʈ�� ��� ����� ���� ����
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
			printf("�̹� �����ϴ� è�Ǿ��Դϴ�.\n");
			break;
		}
		else if (curr->link == (*head)){
			if (strcmp(input_Name, curr->data.name) == 0){
				printf("�̹� �����ϴ� è�Ǿ��Դϴ�.\n");
				break;
			}
		}
		prev = curr;
		curr = curr->link;
	}
	//if (){
	printf("�̸�:%s\n", input_Name);
	strcpy(plus_node->data.name, input_Name);
	printf("ü  ��:");
	scanf("%f", &plus_node->data.HealthPoint);
	fflush(stdin);
	printf("��  ��:");
	scanf("%f", &plus_node->data.MagicPoint);
	fflush(stdin);
	printf("���ݷ�:");
	scanf("%f", &plus_node->data.Power);
	fflush(stdin);
	//}

	plus_node->link = curr;
	prev->link = plus_node;
}


linkedList_h* createLinkedList_h(void){  //���� ���Ḯ��Ʈ ���� ����
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h)); //��� ��� �Ҵ�
	L->head = NULL; //���� ����Ʈ�̹Ƿ� NULL ����
	return L;
}

listNode *Find(linkedList_h *L, char input_Name[20])
{
	listNode *p;

	p = L->head;
	while (strcmp(input_Name, p->data.name) != 0){
		if (p->link == L->head){
			printf("ã������ è�Ǿ��� �����ϴ�.\n");
			return NULL;
		}
		else
			p = p->link;
	}
	return p;
}

void addNode(linkedList_h *L, char input_Name[20]){ //����Ʈ�� ������ ��� ���� ����
	listNode *newNode;
	listNode *curr;
	listNode *prev;

	prev = L->head;
	curr = prev->link;

	// �ߺ��˻�
	while ( curr->link != L->head){
		if (strcmp(input_Name, curr->data.name) == 0){
			printf("�̹� �����ϴ� è�Ǿ��Դϴ�.");
			break;
		}
		prev = curr;
		curr = curr->link;
	}
	
	newNode = (listNode*)malloc(sizeof(listNode));
	printf("�̸�:");
	strcpy(newNode->data.name, input_Name);
	printf("ü  ��:");
	scanf("%f", &newNode->data.HealthPoint);
	fflush(stdin);
	printf("��  ��:");
	scanf("%f", &newNode->data.MagicPoint);
	fflush(stdin);
	printf("���ݷ�:");
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

void printList(linkedList_h* L){   //��� ������� ����Ʈ�� ����ϴ� ����
	listNode *p;
	if (L->head == NULL) return;

	p = L->head;
	do {
		printf("�̸�:%s\nü��:%.2f\n����:%.2f\n���ݷ�:%.2f\n", p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
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
	
	insert_node(&champion_list, create_node_list({ "����", 500, 240, 56 }, NULL));
	insert_node(&champion_list, create_node_list({ "������", 560, 360, 46 }, NULL));
	insert_node(&champion_list, create_node_list({ "ũ��ũ", 600, 240, 66 }, NULL));

	while (1)
	{
		printf("1. �˻�, 2. �߰� 3. ���� 4. ��κ��� 5. FIndMax_Health, 6. Sort_By_Max_Health\n");
		scanf("%d", &select);
		fflush(stdin);

		switch (select)
		{
		case 1:
			printf("è�Ǿ� �˻�\n");
			printf("ã���� è�Ǿ��� �̸��� �Է��ϼ���.");
			gets(input_Name);

			p = Find(L, input_Name);
			if (p != NULL){
				printf("�̸�:%s\nü��:%.2f\n����:%.2f\n���ݷ�:%.2f\n", p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
			}
			else {
				printf("ã������ è�Ǿ��� �����ϴ�.\n");
			}
			break;
		case 2:
			printf("è�Ǿ� �߰�\n");
			printf("�߰��Ͻ� è�Ǿ��� �̸��� �Է��ϼ���.");
			gets(input_Name);
			
			addNode(L, input_Name);
			break;
		case 3:
			printf("è�Ǿ� �˻�\n");
			printf("�����Ͻ� è�Ǿ��� �̸��� �Է��ϼ���.");
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
