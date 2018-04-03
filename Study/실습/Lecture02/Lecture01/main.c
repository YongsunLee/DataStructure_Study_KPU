#include "PerformanceCounter.h"

typedef struct _MyData {
	int buf;
} MyData;

void call_by_value(MyData data) {
	// Scanf�� �ּҰ��� �޴´�. ��, �������� ���� ���ڴٴ� �ǹ�
	scnaf_s("%d", &data);
}

void call_by_reference(MyData* pData) {
	scnaf_s("%d", pData);
}

int main()
{
	MyData a;
	
	// init
	PERFORMANCE_COUNT_INIT();
	
	// call_by_value
	PERFORMANCE_COUNT_START();
	// Time Check

	PERFORMANCE_COUNT_END("call_by_value");
	
	// call_by_reference
	PERFORMANCE_COUNT_START();
	// Time Check

	PERFORMANCE_COUNT_END("call_by_reference");

	getchar();
	return 0;
}