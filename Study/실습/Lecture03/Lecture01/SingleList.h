#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

#define SL_DATA_STRING_SIZE 16

typedef enum {
	SL_SORT_TYPE_INT_ASCENDING_ORDER,
	SL_SORT_TYPE_INT_DESENDING_ORDER,
	SL_SORT_TYPE_FLOAT_ASCENDING_ORDER,
	SL_SORT_TYPE_FLOAT_DESENDING_ORDER,
	SL_SORT_TYPE_STRING_ASCENDING_ORDER,
	SL_SORT_TYPE_STRING_DESENDING_ORDER
} SL_SORT_TYPE;

typedef struct _SL_Data
{
	int		integer;
	float	floating_point;
	char	string[SL_DATA_STRING_SIZE];
}SL_Data;

typedef struct _SL_NODE {
	SL_Data				data;
	struct _SL_NODE*	pNext;
} SL_NODE;

typedef struct _SINGLE_LIST {
	unsigned int	nDatas;
	SL_NODE			head, tail;
} SList;

// 생성자, 소멸자
void SL_Initailize(SList *pList);
void SL_Clear(SList *pList);

// 함수
void SL_InsertByScanf(SList *pList);
void SL_InsertByParameter(SList *pList, int i, float f, const char* str);

void SL_Delete(SList *pList, int keyvalue);
void SL_DeleteByFloat(SList *pList, float keyvalue);
void SL_DeleteByString(SList *pList, const char* pKeyvalue);
void SL_DeleteALL(SList *pList);

SL_Data* SL_Search(SList *pList, int keyvalue);
SL_Data* SL_Search(SList *pList, float keyvalue);
SL_Data* SL_Search(SList *pList, const char* pKeyvalue);

void SL_PrintData(const SL_Data* pData);
void SL_PrintALL(SList* pList);

void SL_QuickSort(SList *pList, SL_SORT_TYPE sort_type);
void SL_MergeSort(SList *pList, SL_SORT_TYPE sort_type);


