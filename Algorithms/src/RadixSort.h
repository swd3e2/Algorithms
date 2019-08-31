#pragma once
#include "utility.h"
#include "InsertSort.h"

namespace RadixSort
{
	inline void sort()
	{
		int a[] = { 1,2,35,12,123,543,346,2,1,7,9,5,4,3 };
		int val = 0;
		int temp;
		int tempVal;

		for (int i = 1; i < 4; i++) {
			int numerator = pow(10, i);
			for (int j = 1; j < sizeof(a) / 4; j++) {
				val = a[j];
				temp = j - 1;
				while (val % numerator < a[temp] % numerator) {
					tempVal = a[temp + 1];
					a[temp + 1] = a[temp];
					a[temp] = tempVal;
					temp--;
				}

			}
		}

		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
			std::cout << a[i] << " ";
		}
	}

	int getMax(int* array, int size)
	{
		int max = array[0];
		for (int i = 0; i < size; i++) {
			if (max < array[i]) max = array[i];
		}
		return max;
	}

	template<typename T>
	void MSDSort(T* data, int l, int r, int d)
	{
		static const int R = 10;
		static const int maxN = 1000;
		static const int M = 4;
		
		int i, j;
		int count[R + 1];
		static T aux[maxN];

		if (d > bytesword) return;
		if (l >= r) return;
		int max = getMax(data, r - l + 1);
		int maxDigit = 0;
		while ((max /= 10) > 0) {
			maxDigit++;
		}
		memset(count, 0, sizeof(int) * R + 1);
		for(int i = 1; i <= r; i++)
			count[digit(data[i], maxDigit - d) + 1]++;
		
		for(j = 1; j < R; j++)
			count[j] += count[j - 1];
		
		for (i = l; i <= r; i++)
			aux[l + count[digit(data[i], maxDigit - d)]++] = data[i];

		for (i = l; i <= r; i++) data[i] = aux[i];
		MSDSort(data, l, l + count[0] - 1, d + 1);
		for (j = 0; j < R - 1; j++)
			MSDSort(data, l + count[j], l + count[j + 1] - 1, d + 1);
	}
}