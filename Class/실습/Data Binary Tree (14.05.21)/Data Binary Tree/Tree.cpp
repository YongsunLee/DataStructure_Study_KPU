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

_NODE *create_node_list(Data data);
_NODE insert_list(_NODE *root, _NODE *new_node);
_NODE *insert(_NODE *root, Data data);

int main()
{
	FILE *fp;
	Data data;
	_NODE *root = NULL;
	int check = 1;

	if ((fp = fopen("../../LOLDic.txt", "r")) == NULL){
		fprintf(stderr, "파일을 읽는데 실패했습니다.");
		exit(1);
	}

	while (!feof(fp)){
		fscanf(fp, "%s %s %d %d %d", &data.Position, &data.ID, &data.HP, &data.MP, &data.Power);
		if (check == 1){
			root = insert(root, data);
			check = 0;
		}
		else
			insert(root, data);
	}

	printf("OK");
}

_NODE *create_node_list(Data data)
{
	_NODE *new_node = new _NODE;

	new_node->Left = NULL;
	new_node->Right = NULL;
	new_node->data = data;
	
	return new_node;
}

_NODE insert_list(_NODE *root, _NODE *new_node)
{
	if ( root->data.ID < new_node->data.ID){
		if ( root->Right == NULL){
			root->Right = new_node;
		}
		else 
			insert_list(root->Right, new_node);
	}
	else if ( root->data.ID > new_node->data.ID){
		if ( root->Left == NULL ){
			root->Left = new_node;
		}
		else
			insert_list(root->Left, new_node);
	}
	return *new_node;
}

_NODE *insert(_NODE *root, Data data)
{
	_NODE *new_node = new _NODE;

	if ( root == NULL ){
		new_node->data = data;
		new_node->Right = NULL;
		new_node->Left = NULL;
		return new_node;
	}
	if (root->data.ID < data.ID) root->Right = insert(root->Right , data);
	if (root->data.ID > data.ID) root->Left = insert(root->Left, data);
	else NULL;
	return root;
}