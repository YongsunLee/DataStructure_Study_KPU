#pragma once
#define WIN32_LEAN_AND_MEAN // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
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

	// Frequency :: �ʴ� Ŭ���� ��� ���������� ��ȯ
	QueryPerformanceFrequency((LARGE_INTEGER *)&nPerformanceFrequencyPerSec);
	
	// ���ѵ� ���� ������ ġȯ�ؼ� 1000�� ���ϸ� ms ������ �ȴ�.
	___pc.dTimeScale = 1000.0 / (double)nPerformanceFrequencyPerSec;

	// ���� Ŭ���� �󸶳� ���������� �˷��ִ� ��
	// ��, PC���� ���ķ� ���ư� Ŭ��
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