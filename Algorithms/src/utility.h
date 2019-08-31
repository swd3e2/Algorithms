#pragma once
#include <cmath>

const int bitsword = 32;
const int bitsbyte = 8;
constexpr int bytesword = bitsword / bitsbyte;
constexpr int R = 1 << bitsbyte;

inline int digit(long a, int b)
{
	int num = 0;
	for (int i = 0; i < b + 1; i++) {
		num = a % 10;
		a /= 10;
	}
	return num;
}

inline int digit(const char* a, const int b)
{
	return a[b];
}