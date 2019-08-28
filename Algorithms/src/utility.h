#pragma once

const int bitsword = 32;
const int bitsbyte = 8;
constexpr int bytesword = bitsword / bitsbyte;
constexpr int R = 1 << bitsbyte;

inline int digit(long a, int b)
{
	return (a >> bitsbyte * (bytesword - b - 1) * (R - 1));
}

inline int digit(const char* a, const int b)
{
	return a[b];
}