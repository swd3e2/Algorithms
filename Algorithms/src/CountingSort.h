#pragma once
#include <memory>

namespace CountingSort
{
	void countingSort(int* data, int l, int r, size_t max)
	{
		int i, j;
		int* cnt = new int[max + 2];
		int* temp = new int[r - l];

		memset(cnt, 0, sizeof(int) * (max + 1));
		for (i = l; i <= r; i++)
		{
			cnt[data[i] + 1]++;
		}
		for (j = 1; j < max + 1; j++) {
			cnt[j] += cnt[j - 1];
		}
		for (i = l; i <= r; i++) 
		{
			temp[cnt[data[i]]++] = data[i];
		}
		for (i = l; i <= r; i++)
		{
			data[i] = temp[i];
		}
		
		delete[] cnt;
		delete[] temp;
	}
}