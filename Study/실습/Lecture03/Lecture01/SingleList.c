#include "SingleList.h"

void SL_Initailize(SList * pList)
{
	pList->nDatas = 0;
	pList->head.pNext = &pList->tail;
	
	// zeromemory 따라가보면 memset이다.
	memset(&pList->head.data, 0, sizeof(pList->head.data));
}

void SL_Clear(SList * pList)
{
	SL_NODE *prev = NULL, *curr = NULL;

	prev = &pList->head;	// 더미
	curr = prev->pNext;		// 첫번째 데이터

	// 데이터가 없으면 헤더의 Next 값이 tail이므로
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

	// while 문의 결과로 prev 는 tail의 직전 curr 는 tail과 같다.
	
	curr = (SL_NODE*)malloc(sizeof(SL_NODE));	// 새로 만든 노드를 curr로 주고
	
	// 데이터 넣기
	curr->data.integer = i;
	curr->data.floating_point = f;
	strcpy_s(curr->data.string, strlen(str), str);

	prev->pNext = curr;			// 이전 노드의 Next는 curr 를 가리킨다.				
	curr->pNext = &pList->tail; // curr의 다음이 tail

	// 데이터 갯수 늘리기
	pList->nDatas++;
}

void SL_Delete(SList * pList, int keyvalue)
{
	SL_NODE *prev = NULL, *curr = NULL;

	prev = &pList->head;
	curr = prev->pNext;

	while (curr != &pList->tail) 
	{
		// 같은 경우
		if (curr->data.integer == keyvalue) 
		{
			// 지우기
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
		// 부동소수점은 오차가 있다.
		// float.h 에 있는 FLT_EPSILON을 이용한다. (가장 작은값)
		// 0. 까지 포함해서 16가지 float의 32bit
		// 이래서 float로는 비교문을 잘 사용하지 않는다.
		if (curr->data.floating_point > keyvalue - FLT_EPSILON
			&& curr->data.floating_point < keyvalue - FLT_EPSILON)
		{
			// 지우기
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
		// 비교할 것이기 때문에 const char* 이다.
		// strcmp 아스키 코드 값을 계산해 준다. (오름차순, 내림차순 정렬 가능 <, > 표현으로)
		if (strcmp(curr->data.string, pKeyvalue) == 0)
		{
			// 지우기
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

