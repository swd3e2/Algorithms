#pragma once

namespace SelectSort
{
	template<typename T>
	void selectSort(T* data, int size)
	{
		int min = 0;

		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				if (data[j] < data[min]) min = j;
			}
			int temp = data[min];
			data[min] = data[i];
			data[i] = temp;
			min = i + 1;
		}
	}
}