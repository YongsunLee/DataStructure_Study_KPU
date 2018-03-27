#include "PerformanceCounter.h"

typedef struct _MyData {
	// char 1byte
	// 원하는 만큼의 byte를 사용할 수 있으므로 buf 형식으로 이용한다.

	// chache 라인을 생각하면 4바이트 단위로 끊게 된다. (Packing 패킹)
	
	char buf[100000];
} MyData;

void call_by_value(MyData data) {
	// volatile :: 임베디드에서 입출력 장치에 사용
	// 컴파일러의 최적화를 막는 것
	volatile char a = data.buf[0];
}

void call_by_reference(MyData* pData) {
	volatile char a = pData->buf[0];
}

int main()
{
	MyData a;
	// 포인터의 크기를 재 봅시다.
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