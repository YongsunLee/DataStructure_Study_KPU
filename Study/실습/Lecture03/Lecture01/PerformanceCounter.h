#pragma once
#define WIN32_LEAN_AND_MEAN // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#include <windows.h>
#include <stdio.h>

typedef struct _PERFORMANCE_COUNTER
{
	long long	nLastPerformanceCounter;
	double		dTimeScale;
} PERFORMANCE_COUNTER;

static PERFORMANCE_COUNTER ___pc;

inline void PERFORMANCE_COUNT_INIT()
{
	static long long nPerformanceFrequencyPerSec = 0;

	// Frequency :: 초당 클럭이 몇번 지나갔는지 반환
	QueryPerformanceFrequency((LARGE_INTEGER *)&nPerformanceFrequencyPerSec);
	
	// 반한된 값을 역수로 치환해서 1000을 곱하면 ms 단위가 된다.
	___pc.dTimeScale = 1000.0 / (double)nPerformanceFrequencyPerSec;

	// 현재 클럭이 얼마나 지났는지를 알려주는 값
	// 즉, PC부팅 이후로 돌아간 클럭
	QueryPerformanceCounter((LARGE_INTEGER *)&___pc.nLastPerformanceCounter);
}

inline void PERFORMANCE_COUNT_START()
{
	QueryPerformanceCounter((LARGE_INTEGER *)&___pc.nLastPerformanceCounter);
}

inline void PERFORMANCE_COUNT_END(const char* target_name)
{
	static int			millisecond = 0;
	static long long	nCurrPerformanceCounter = 0;

	QueryPerformanceCounter((LARGE_INTEGER *)&nCurrPerformanceCounter);
	millisecond = (int)((double)(nCurrPerformanceCounter - ___pc.nLastPerformanceCounter) * ___pc.dTimeScale);
	printf("%s\n-[Process Time]: %d ms\n", target_name, millisecond);
}