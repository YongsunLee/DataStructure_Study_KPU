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

_NODE *create_node_list(champion data, _NODE *link);
_NODE *Find(_NODE *head, char input_Name[20]);
_NODE ArrayChampion(_NODE *champion_list);
void insert_node(_NODE *head, char input_Name[20]);

int main()
{
	_NODE *champion_list = NULL;
	_NODE *p;
	int select;
	char input_Name[20];

	champion_list = &ArrayChampion(champion_list);

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

			p = Find(champion_list, input_Name);
			if (p != NULL){
				printf("�̸�:%s\nü��:%.2f\n����:%.2f\n���ݷ�:%.2f\n", p->data.name, p->data.HealthPoint, p->data.MagicPoint, p->data.Power);
			}
			break;
		case 2:
			printf("è�Ǿ� �߰�\n");
			printf("�߰��Ͻ� è�Ǿ��� �̸��� �Է��ϼ���.");
			gets(input_Name);

			insert_node(champion_list, input_Name);
			break;
		case 3:
			break;
		case 4:
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

_NODE *create_node_list(champion data, _NODE *link)
{
	_NODE *new_node;
	new_node = (_NODE *)malloc(sizeof(_NODE));
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}

_NODE *Find(_NODE *head, char input_Name[20])
{
	_NODE *p;

	p = head;
	while (strcmp(input_Name, p->data.name) != 0){
		if (p->link == head){
			printf("ã������ è�Ǿ��� �����ϴ�.\n");
			return NULL;
		}
		else
			p = p->link;
	}
	return p;
}

_NODE ArrayChampion(_NODE *champion_list)
{
	champion data[20] = { { "����", 500, 240, 56 },
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
	
	int i;
	for (i = 0; i < 20; ++i){
		champion_list = create_node_list(data[i], NULL);
	}

	return *champion_list;
}

void insert_node(_NODE *head, char input_Name[20])
{
	_NODE *plus_node;
	_NODE *prev, *curr;

	prev = head;
	curr = prev->link;
	plus_node = (_NODE*)malloc(sizeof(_NODE));

	while (curr->link != head){
		if ( strcmp(input_Name, curr->data.name) == 0){
			printf("�̹� �����ϴ� è�Ǿ��Դϴ�.\n");
		}
		prev = curr;
		curr = curr->link;
	}
	printf("�̸�:");
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

	plus_node->link = curr;
	prev->link = plus_node;
}