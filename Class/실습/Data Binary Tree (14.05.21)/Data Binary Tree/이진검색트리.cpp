#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#pragma warning (disable : 4996)

typedef struct treeNode{
	int key;
	char data[10];
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode *search(treeNode *root, int key)
{
	if (root->key == key)
	{
		printf("%d\n", root->key);
		return root;
	}
	else if (root->key>key) return search(root->left, key);
	else if (root->key, key) return search(root->right, key);
	return root;
}
treeNode *insert(treeNode *root, int key, char data[10])
{
	treeNode *newNode;

	if (root == NULL)
	{
		newNode = (treeNode*)malloc(sizeof(treeNode));
		strcpy(root->data, data);
		newNode->key = key;
		newNode->right = NULL;
		newNode->left = NULL;
		return newNode;
	}
	if (root->key>key) root->left = insert(root->left, key, data);
	if (root->key<key) root->right = insert(root->right, key, data);
	else NULL;
	return root;
}
void SortName(treeNode *root)
{
	if (root)
	{
		SortName(root->left);
		printf("%d %s\n", root->key, root->data);
		SortName(root->right);
	}
}
treeNode *FindMaxName(treeNode *root)
{
	if (root->right == NULL) printf("%d\n", root->key);
	else return FindMaxName(root->right);
	return root;
}
void Printall(treeNode *root)
{
	printf("%d %s\n", root->key, root->data);
	if (root->left) Printall(root->left);
	if (root->right) Printall(root->right);
}
void Delete(treeNode *root, int key)
{
	static treeNode *p, *parent, *sp, *s, *child;
	p = root;
	while (p != NULL)
	{
		if (root->key == key)
			break;
		parent = p;
		if (p->key>key) p = p->left;
		else p = p->right;
	}
	if (p == NULL)
	{
		printf("없넹\n");
		free(p);
		return;
	}
	if (p->left == NULL && p->right == NULL)	//차수 0 (지 만있을때)
	{
		if (parent->left == p) parent->left = NULL;
		else parent->right = NULL;
	}
	else if (p->left == NULL || p->right == NULL)	//차수 1 (자식하나있을때)
	{
		if (p->left != NULL) child = p->left;
		else child = p->right;
		if (parent->left == p) parent->left = child;
		else parent->right = child;
	}
	else					//차수 2 (자식둘다있을때)
	{
		sp = p;
		s = p->right;		//결론 => 오른쪽, 가장 작은 값
		while (s->left != NULL)
		{
			sp = s;
			s = s->left;
		}
		if (sp->left == s) sp->left = s->right;
		else sp->right = s->right;
		strcpy(p->data, s->data);
		p->key = s->key;
		p = s;
		free(p);
	}
}
void main()
{
	int key;
	char data[10];
	treeNode *root = NULL;

	printf("root key : ");
	scanf("%d", &key);
	printf("data : ");
	scanf("%s", &data);
	root = insert(root, key, data);
	while (1)
	{
		printf("1.search 2.insert 3.Delete 4.Printall 5.FindMaxKey 6.Sort\n");
		printf("번호를 선택해 주세요 : ");
		scanf("%d", &key);
		if (key == 1)
		{
			printf("찾는 key : ");
			scanf("%d", &key);
			search(root, key);
		}
		else if (key == 2)
		{
			printf("root key : ");
			scanf("%d", &key);
			printf("data : ");
			scanf("%s", &data);
			insert(root, key, data);
		}
		else if (key == 3)
			Delete(root, key);
		else if (key == 4)
			Printall(root);
		else if (key == 5)
			FindMaxName(root);
		else if (key == 6)
			SortName(root);
	}
}