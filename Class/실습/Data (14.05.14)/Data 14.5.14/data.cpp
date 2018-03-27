#include <stdio.h>
#include <Windows.h>
#include <time.h>

#pragma warning (disable : 4996)

struct Data {
	char Position[10];
	char ID[15];
	int HP;
	int MP;
	int Power;
};

struct _NODE{
	Data data;
	_NODE *prev;
	_NODE *next;
};

_NODE insert(_NODE *head, _NODE *new_node);
_NODE *create_node_list(Data data, _NODE *link);

void FindMax_HP(_NODE head);
void insert_new(_NODE head, char input_ID[15]);
void Print_All(_NODE head);

_NODE head;

int main()
{
	head.next = NULL;
	FILE *fp;
	Data data;
	_NODE *curr;
	int num;
	char input_ID[15];
	double start, finish;

	start = clock();

	if ( (fp = fopen("../../LOLDic.txt", "r")) == NULL){
		fprintf(stderr, "파일을 읽는데 실패했습니다.");
		exit(1);
	}
	
	curr = head.next;
	while ( !feof(fp) ){
		fscanf(fp, "%s %s %d %d %d", &data.Position, &data.ID, &data.HP, &data.MP, &data.Power);
		insert(&head, create_node_list( data, NULL));
	}

	while (1){
		printf("1. 추가 2. FindMax_HP 3. Print_ALL");
		scanf("%d", &num);
		fflush(stdin);

		switch (num)
		{
		case 1:
			printf("추가할 ID를 입력하세요.\n");
			gets_s(input_ID);
			fflush(stdin);

			insert_new(head, input_ID);
			break;
		case 2:
			FindMax_HP(head);
			break;
		case 3:
			Print_All(head);
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}

		finish = clock();
		printf("time : %.3f\n", ((finish - start)/ CLK_TCK)/1000);
	}

	fclose(fp);
}

_NODE *create_node_list(Data data, _NODE *link)
{
	_NODE *new_node = new _NODE;

	new_node->data = data;
	new_node->next = link;

	return new_node;
}

_NODE insert(_NODE *head, _NODE *new_node)
{
	if (head->next == NULL){
		new_node->prev = head;
		new_node->next = head->next;
		head->next = new_node;
	}
	else {
		new_node->prev = head;
		new_node->next = head->next;
		head->next = new_node;
	}
	return *new_node;
}

// DL
void insert_new(_NODE head, char input_ID[15])
{
	_NODE *curr, *prev;
	_NODE *new_node = new _NODE;

	prev = &head;
	curr = prev->next;

	while ( curr->next != NULL ){
		if ( strcmp(input_ID, curr->data.ID) == 0){
			printf("이미 존재하는 ID값 입니다.");
			break;
		}
		prev = curr;
		curr = curr->next;
	}

	printf("ID:%s\n", input_ID);
	strcpy(new_node->data.ID, input_ID);
	printf("Position:\n");
	gets_s(new_node->data.Position);
	printf("HP:\n");
	scanf("%d", &new_node->data.HP);
	fflush(stdin);
	printf("MP:\n");
	scanf("%d", &new_node->data.MP);
	fflush(stdin);
	printf("Power:");
	scanf("%d", &new_node->data.Power);
	fflush(stdin);

	new_node->prev = prev;
	new_node->next = curr;
	prev->next = new_node;
}

// DL
void FindMax_HP(_NODE head)
{
	_NODE *curr, *prev;
	int temp = 0;

	prev = &head;
	curr = head.next;
	while ( curr->next != NULL ){
		if ( curr->data.HP > temp){
			temp = curr->data.HP;
		}
		prev = curr;
		curr = curr->next;
	}

	prev = &head;
	curr = prev->next;
	while (curr->next != NULL){
		if (curr->data.HP == temp){
			printf("I  D:%s\n", curr->data.ID);
		}
		prev = curr;
		curr = curr->next;
	}
}

void Print_All(_NODE head)
{
	_NODE *curr;

	curr = &head;
	if (head.next == NULL) return;

	while ( curr->next != NULL ){
		//printf("ID:%s\n", curr->data.ID);
		curr = curr->next;
	}
}

void SortByName()
{

}