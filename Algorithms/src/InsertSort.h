#pragma once

namespace InsertSort
{
	template<typename T>
	void insertSort(T* data, int size)
	{
		for (int i = 0; i < 13; i++) {
			int c = i;
			while (data[c] > data[c + 1] && c > 0) {
				int temp = data[c];
				data[c] = data[c + 1];
				data[c + 1] = temp;
				c--;
			}
		}
	}

	template<typename T>
	void binaryInsertSort(T* data, const int size)
	{
		for (int i = 1; i < size; i++) {
			T tempVal = data[i];
			int right = i;
			int left = 0;

			while (left < right) {
				int middle = (right + left) / 2;
				if (tempVal > data[middle]) {
					left = middle + 1;
				}
				else {
					right = middle;
				}
			}

			for (int j = i; j > left; --j) {
				T temp = data[j - 1];
				data[j - 1] = a[j];
				data[j] = temp;
			}
		}
	}
}