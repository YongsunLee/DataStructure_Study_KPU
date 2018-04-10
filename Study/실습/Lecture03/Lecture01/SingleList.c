#include "SingleList.h"

void SL_Initailize(SList * pList)
{
	pList->nDatas = 0;
	pList->head.pNext = &pList->tail;
	
	// zeromemory ���󰡺��� memset�̴�.
	memset(&pList->head.data, 0, sizeof(pList->head.data));
}

void SL_Clear(SList * pList)
{
	SL_NODE *prev = NULL, *curr = NULL;

	prev = &pList->head;	// ����
	curr = prev->pNext;		// ù��° ������

	// �����Ͱ� ������ ����� Next ���� tail�̹Ƿ�
	while (curr != &pList->tail) {
		prev->pNext = curr->pNext;
		free(curr);
		curr = prev->pNext;
	}

	pList->nDatas = 0;

}

void SL_InsertByScanf(SList * pList)
{

}

void SL_InsertByParameter(SList * pList, int i, float f, const char * str)
{
	SL_NODE *prev = NULL, *curr = NULL;

	prev = &pList->head;
	curr = prev->pNext;

	while (curr != &pList->tail) {
		prev = curr;
		curr = prev->pNext;
	}

	// while ���� ����� prev �� tail�� ���� curr �� tail�� ����.
	
	curr = (SL_NODE*)malloc(sizeof(SL_NODE));	// ���� ���� ��带 curr�� �ְ�
	
	// ������ �ֱ�
	curr->data.integer = i;
	curr->data.floating_point = f;
	strcpy_s(curr->data.string, strlen(str), str);

	prev->pNext = curr;			// ���� ����� Next�� curr �� ����Ų��.				
	curr->pNext = &pList->tail; // curr�� ������ tail

	// ������ ���� �ø���
	pList->nDatas++;
}

void SL_Delete(SList * pList, int keyvalue)
{
	SL_NODE *prev = NULL, *curr = NULL;

	prev = &pList->head;
	curr = prev->pNext;

	while (curr != &pList->tail) 
	{
		// ���� ���
		if (curr->data.integer == keyvalue) 
		{
			// �����
			prev->pNext = curr->pNext;
			free(curr);
			curr = prev->pNext;
			pList->nDatas--;
		}
		else 
		{
			prev = curr;
			curr = prev->pNext;
		}
	}
}

void SL_DeleteByFloat(SList * pList, float keyvalue)
{
	SL_NODE *prev = NULL, *curr = NULL;

	prev = &pList->head;
	curr = prev->pNext;

	while (curr != &pList->tail)
	{
		// �ε��Ҽ����� ������ �ִ�.
		// float.h �� �ִ� FLT_EPSILON�� �̿��Ѵ�. (���� ������)
		// 0. ���� �����ؼ� 16���� float�� 32bit
		// �̷��� float�δ� �񱳹��� �� ������� �ʴ´�.
		if (curr->data.floating_point > keyvalue - FLT_EPSILON
			&& curr->data.floating_point < keyvalue - FLT_EPSILON)
		{
			// �����
			prev->pNext = curr->pNext;
			free(curr);
			curr = prev->pNext;
			pList->nDatas--;
		}
		else
		{
			prev = curr;
			curr = prev->pNext;
		}
	}
}

void SL_DeleteByString(SList * pList, const char * pKeyvalue)
{
	SL_NODE *prev = NULL, *curr = NULL;

	prev = &pList->head;
	curr = prev->pNext;

	while (curr != &pList->tail)
	{
		// ���� ���̱� ������ const char* �̴�.
		// strcmp �ƽ�Ű �ڵ� ���� ����� �ش�. (��������, �������� ���� ���� <, > ǥ������)
		if (strcmp(curr->data.string, pKeyvalue) == 0)
		{
			// �����
			prev->pNext = curr->pNext;
			free(curr);
			curr = prev->pNext;
			pList->nDatas--;
		}
		else
		{
			prev = curr;
			curr = prev->pNext;
		}
	}
}

