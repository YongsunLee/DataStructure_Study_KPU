#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)

#define SIZE 20

struct PEOPLE{
	char name[20];
	int age;
	char ID[20];
	char sex[10];
	int x, y, z;
};

struct _NODE{
	PEOPLE data;
	struct _NODE *link;
};

void SearchByID_List(_NODE *head, int buf_age, int Max_age);
void Push(PEOPLE data);
void Pop();
void DeleteByMaxNumOfAge();
void PrintAll();

_NODE *create_node_list(PEOPLE People[SIZE], _NODE *link);
_NODE insert(_NODE *head, _NODE *new_node);

_NODE People_list;
_NODE S_head;

static int Count_age;

int main()
{
	People_list.link = NULL;
	S_head.link = NULL;
	_NODE *p;
	int buf_age = 0;
	int Max_age = 0;
	int sel;
	int input_x;
	PEOPLE People[SIZE] = { { "Lee JY", 17, "jylee", "male", 4, 9, 30 },
	{ "Yoon JH", 55, "wulong", "male", 7, 13, 0 },
	{ "Song IH", 18, "ihsong", "female", 1, 36, 29 },
	{ "Kong KS", 43, "kskon", "male", 16, 39, 14 },
	{ "Chang JW", 24, "duribaba", "male", 41, 94, 0 },
	{ "Lee HG", 44, "hgl", "male", 7, 13, 28 },
	{ "Lee YH", 42, "louis", "male", 5, 19, 32 },
	{ "Ko HJ", 47, "hjko", "male", 22, 5, 88 },
	{ "Kim JK", 42, "doublepar", "male", 16, 27, 18 },
	{ "Oh WS", 55, "oh", "male", 5, 7, 23 },
	{ "Lim CJ", 29, "scjlim", "male", 52, 48, 12 },
	{ "Kim YS", 55, "kimys", "female", 77, 53, 24 },
	{ "Kim YS", 52, "yskim", "male", 7, 13, 33 },
	{ "Lee DH", 46, "dustin", "male", 5, 7, 23 },
	{ "Jung NH", 42, "nhjung", "male", 3, 56, 21 },
	{ "Jin HS", 33, "hsjin", "male", 82, 13, 28 },
	{ "Kim KC", 17, "ken", "male", 27, 24, 13 },
	{ "Sung WJ", 22, "wjsung", "female", 32, 66, 28 },
	{ "Lee JY", 64, "jay", "male", 73, 92, 44 },
	{ "Kim YS", 55, "yes", "female", 66, 16, 20 } };

	for (int i = 0; i < SIZE; ++i){
		insert(&People_list, create_node_list(&People[i], NULL));
	}

	while (1){
		printf("1. ¹®Á¦ B¹ø, 2. PrintDeleteAll\n");
		scanf("%d", &sel);
		fflush(stdin);

		switch (sel)
		{
		case 1:
			SearchByID_List(&People_list, buf_age, Max_age);
			break;
		case 2:
			DeleteByMaxNumOfAge();
			break;
		case 3:
			PrintAll();
			break;
		default:
			break;
		}
	}

}

void SearchByID_List(_NODE *head, int buf_age, int Max_age)
{
	int buf;
	_NODE *curr, *prev;
	_NODE *p;

	prev = head;
	curr = prev->link;
	while (curr->link != head->link){
		for (p = head->link; p->link != head->link; p = p->link){
			if ( curr->data.age == p->data.age){
				buf_age++;
			}
			if ( buf_age > Max_age ){
				Max_age = buf_age;
				Count_age = curr->data.age;
			}
		}
		buf_age = 0;

		prev = curr;
		curr = curr->link;
	}

	prev = head;
	curr = prev->link;
	while (curr->link != head->link){
		if ( curr->data.age == Count_age ){
			Push(curr->data);

			prev->link = curr->link;
			prev = prev;
			curr = prev->link;
		}
		else {
			prev = curr;
			curr = curr->link;
		}
	}
}

void PrintAll()
{
	_NODE *p;

	p = &S_head;

	
	while (p->link != NULL){
		printf("Name :%s\n", p->data.name);
		printf(" age :%d\n", p->data.age);
		printf(" sex :%s\n", p->data.sex);
		printf(" Pos :(%d,%d,%d)\n", p->data.x, p->data.y, p->data.z);
		p = p->link;
	}
	
}

void DeleteByMaxNumOfAge()
{
	_NODE *p, *curr;

	p = &S_head;
	curr = p->link;

	while ( curr->link != NULL)
	{
		if ( curr->data.age == Count_age ){
			printf("Name :%s\n", curr->data.name);
			printf(" age :%d\n", curr->data.age);
			printf(" sex :%s\n", curr->data.sex);
			printf(" Pos :(%d,%d,%d)\n", curr->data.x, curr->data.y, curr->data.z);
			p->link = curr->link;
			delete curr;
			p = p;
			curr = p->link;
		}
		else {
			p = curr;
			curr = curr->link;
		}
	}

}

_NODE *create_node_list(PEOPLE People[SIZE], _NODE *link)
{
	_NODE *new_node = new _NODE;

	new_node->data = *People;
	new_node->link = link;

	return new_node;
}

_NODE insert(_NODE *head, _NODE *new_node)
{
	_NODE *curr;

	if (head->link == NULL){
		head->link = new_node;
		new_node->link = new_node;
	}
	else {
		curr = head->link;
		while (1){
			if (curr->link == head->link){
				break;
			}
			curr = curr->link;
		}
		new_node->link = head->link;
		head->link = new_node;
		curr->link = new_node;
	}
	return *new_node;
}

void Push(PEOPLE data)
{
	_NODE *new_node = new _NODE;

	new_node->data = data;
	new_node->link = S_head.link;
	S_head.link = new_node;
}