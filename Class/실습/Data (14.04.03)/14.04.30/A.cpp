#include <stdio.h>
#include <stdlib.h>

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

void Sort_R(_NODE *prev);
void PrintAll(_NODE *head);

_NODE *create_node_list(PEOPLE People[SIZE], _NODE *link);
_NODE insert(_NODE *head, _NODE *new_node);

_NODE People_list;
_NODE S_head;

static int i = 20;

int main()
{
	People_list.link = NULL;
	S_head.link = NULL;
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
		printf("1. Sort, 2. printall Push \n");
		scanf("%d", &sel);
		fflush(stdin);

		switch (sel)
		{
		case 1:
			Sort_R(&People_list);
			break;
		case 2:
			PrintAll(&People_list);
			break;
		default:
			break;
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
	if (head->link == NULL){
		new_node->link = head->link;
		head->link = new_node;
	}
	else {
		new_node->link = head->link;
		head->link = new_node;
	}
	return *new_node;
}

void Sort_R(_NODE *prev)
{
	_NODE *curr;
	curr = prev->link;
	if (curr == NULL)
		return;

	if (prev->data.ID[0] > curr->data.ID[0]){
		_NODE *p_prev = &People_list;
		while (curr->data.ID[0] != p_prev->link->link->data.ID[0])
			p_prev = p_prev->link;
		prev->link = curr->link;
		curr->link = prev;
		p_prev->link = curr;
		return Sort_R(p_prev);
	}
	else if ( prev->data.ID[0] == curr->data.ID[0] ){
		if (prev->data.ID[1] > curr->data.ID[1]){
			_NODE *p_prev = &People_list;
			while (curr->data.ID[1] != p_prev->link->link->data.ID[1])
				p_prev = p_prev->link;
			prev->link = curr->link;
			curr->link = prev;
			p_prev->link = curr;
			return Sort_R(p_prev);
		}
	}
	else {
		prev = curr;
		return Sort_R(prev);
	}
}

void PrintAll(_NODE *head)
{
	_NODE *p;

	p = head->link;
	while ( p->link != NULL ){
		printf("Name :%s\n", p->data.name);
		printf("  ID :%s\n", p->data.ID);
		printf(" age :%d\n", p->data.age);
		printf(" sex :%s\n", p->data.sex);
		printf(" Pos :(%d,%d,%d)\n", p->data.x, p->data.y, p->data.z);
		p = p->link;
	}
}