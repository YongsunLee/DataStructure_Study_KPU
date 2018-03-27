#include <stdio.h>
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

void Search();
void Insert();
void Delete();
void FindMax_Health();
void SortBy_MaxHealth();

int main()
{

}

void Search()
{

}