#include "PerformanceCounter.h"

typedef struct _MyData {
	// char 1byte
	// ���ϴ� ��ŭ�� byte�� ����� �� �����Ƿ� buf �������� �̿��Ѵ�.

	// chache ������ �����ϸ� 4����Ʈ ������ ���� �ȴ�. (Packing ��ŷ)
	
	char buf[100000];
} MyData;

void call_by_value(MyData data) {
	// volatile :: �Ӻ���忡�� ����� ��ġ�� ���
	// �����Ϸ��� ����ȭ�� ���� ��
	volatile char a = data.buf[0];
}

void call_by_reference(MyData* pData) {
	volatile char a = pData->buf[0];
}

int main()
{
	MyData a;
	// �������� ũ�⸦ �� ���ô�.
	// x86 4byte
	// x64 8byte
	printf("size : %d\n", sizeof(MyData));

	// init
	PERFORMANCE_COUNT_INIT();
	
	// call_by_value
	PERFORMANCE_COUNT_START();
	// Time Check

	for (int i = 0; i < 1000000; ++i) {
		call_by_value(a);
	}

	PERFORMANCE_COUNT_END("call_by_value");
	
	// call_by_reference
	PERFORMANCE_COUNT_START();
	// Time Check
	
	for (int i = 0; i < 1000000; ++i) {
		call_by_reference(&a);
	}

	PERFORMANCE_COUNT_END("call_by_reference");

	getchar();
	return 0;
}