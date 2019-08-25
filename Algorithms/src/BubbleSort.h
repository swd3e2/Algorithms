#pragma once

namespace BubbleSort
{
	template<typename T>
	void bubbleSort(T* data, const int size)
	{
		for (int i = 0; i < size; i++) {
			for (int j = size - 1; j > i; j--) {
				if (data[j - 1] > data[j]) {
					int temp = data[j - 1];
					data[j - 1] = data[j];
					data[j] = temp;
				}
			}
		}
	}
}
