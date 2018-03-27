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
	{ "����", 500, 240, 56 },
	{ "������", 463, 290, 52 },
	{ "����", 497, 255, 46.6 },
	{ "�� ��", 513, 200, 59 },
	{ "�ֽ�", 474, 208, 49.2 },
	{ "���ֳ̾�", 528, 270, 51 },
	{ "����", 551, 0, 55.5 },
	{ "�׶󰡽�", 523, 268, 59.2 },
	{ "����", 439, 348, 51.1 },
	{ "����", 533, 255, 54.5 },
	{ "������", 500, 305, 55 },
	{ "����", 424, 300, 53.3 },
	{ "�巹�̺�", 502, 282, 50 },
	{ "����", 500, 0, 54 },
	{ "������", 449, 270, 50.7 },
	{ "��������", 536, 222, 58 },
	{ "������Ʈ", 513, 255, 59.7 },
	{ "����", 522, 0, 59.2 },
	{ "����", 442, 208, 53.3 },
	{ "���� ũ��ũ", 518, 240, 59.2 }, };

	for (i = 0; i < 21; ++i){
		insert(&champion_list, create_node_list(data[i], NULL));
	}

	while (1){
		printf("1. �˻�, 2. �߰�, 3. ����, 4. ��κ���, 5. FindMax_Health, 6.SortBy_Max_Health\n");
		scanf("%d", &selection);
		fflush(stdin);

		switch (selection)
		{
		case 1:
			printf("è�Ǿ� �˻�\n");
			printf("�˻��Ͻ� è�Ǿ��� �̸��� �Է��ϼ���.");
			gets(input_Name);

			p = Find(champion_list, input_Name);
			if ( p != NULL){
				printf("��  ��:%s\nü  ��:%.2f\n��  ��:%.2f\n���ݷ�:%.2f\n",
					p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
			}
			break;
		case 2:
			printf("è�Ǿ� �߰�\n");
			printf("�߰��Ͻ� è�Ǿ��� �̸��� �Է��ϼ���.");
			gets(input_Name);

			insert_node(&champion_list, input_Name);
			break;
		case 3:
			printf("è�Ǿ� ����\n");
			printf("�����Ͻ� è�Ǿ��� �̸��� �Է��ϼ���.");
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
			printf("�������� �ʴ� è�Ǿ��Դϴ�.\n");
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
		printf("��  ��:%s\n ü  ��:%.2f\n ��  ��:%.2f\n ���ݷ�:%.2f\n",
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
			printf("�̹� �����ϴ� è�Ǿ��Դϴ�.\n");
			check = false;
			break;
		}
		prev = curr;
		curr = curr->link;
	}
	if (check == true){
		printf("��  ��:%s\n", input_Name);
		strcpy(curr->data.name, input_Name);
		printf("ü  ��:");
		scanf("%f", &curr->data.HealthPoint);
		fflush(stdin);
		printf("��  ��:");
		scanf("%f", &curr->data.MagicPoint);
		fflush(stdin);
		printf("���ݷ�:");
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
			printf("��  ��:%s\n", curr->data.name);
		}
		prev = curr;
		curr = curr->link;
	}
}