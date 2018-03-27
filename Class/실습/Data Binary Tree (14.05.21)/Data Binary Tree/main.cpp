#include <stdio.h>
#include <Windows.h>

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
	_NODE *Left;
	_NODE *Right;
};

_NODE insert_list(_NODE *root, _NODE *new_node);
_NODE *create_node_list(Data data);

_NODE root;

int main()
{
	root.Left = NULL;
	root.Right = NULL;
	FILE *fp;
	Data data;
	int num, check = 1;

	if ((fp = fopen("../../LOLDic.txt", "r")) == NULL){
		fprintf(stderr, "파일을 읽는데 실패했습니다.");
		exit(1);
	}

	while ( !feof(fp) ){
		fscanf(fp, "%s %s %d %d %d", &data.Position, &data.ID, &data.HP, &data.MP, &data.Power);
		if ( check == 1 ){
			root = *create_node_list(data);
			check = 0;
		}else 
			insert_list(&root, create_node_list(data));
	}

	while (1){
		printf("1. 추가 ");
		scanf("%d", &num);
		fflush(stdin);

		switch (num)
		{
		case 1:
			printf("%s", root.Right->data.Position);
			break;
		}
	}

	fclose(fp);
}

_NODE *create_node_list(Data data)
{
	_NODE *new_node = new _NODE;

	new_node->Right = NULL;
	new_node->Left = NULL;
	new_node->data = data;

	return new_node;
}

_NODE insert_list(_NODE *root, _NODE *new_node)
{
	if (root->data.ID == NULL){
		root->data = new_node->data;
	}
	else {
		if ( root->data.ID < new_node->data.ID ){
			if ( root->Right == NULL){
				root->Right = new_node;
			}
			else 
				insert_list(root->Right, new_node);
		}

		if ( root->data.ID > new_node->data.ID ){
			if ( root->Left == NULL){
				root->Left = new_node;
			}
			else 
				insert_list(root->Left, new_node);
		}
	}
	return *new_node;
}