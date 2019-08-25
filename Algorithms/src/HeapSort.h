#pragma once

namespace HeapSort
{
	template<typename T>
	void swap_val(T& left, T& right) {
		T temp = left;
		left = right;
		right = temp;
	}

	template<typename T>
	void heapify_max(T* A, int x, int size) {
		int val = x * 2;
		if (val == 0) val = 1;

		if (val > size) return;

		if (A[x] < A[val] || A[x] < A[val + 1]) {
			if (A[val] > A[val + 1]) {
				swap_val(A[x], A[val]);
			}
			else if (val + 1 < size) {
				swap_val(A[x], A[val + 1]);
			}
		}
	}

	template<typename T>
	void heapify_max_recursive(T* A, int x, int size) {
		int val = x * 2;
		if (val == 0) val = 1;

		if (val < size) {
			heapify_max(A, x, size);
			heapify_max_recursive(A, val, size);
			if (val + 1 < size) heapify_max_recursive(A, val + 1, size);
		}
	}

	template<typename T>
	void heapSort(T* data, int size)
	{
		int counter = size;

		for (int i = size / 2; i >= 0; i--) {
			heapify_max_recursive(data, i, counter);
		}

		for (int k = 0; k < size; k++) {
			heapify_max_recursive(data, 0, counter);
			swap_val(data[counter - 1], data[0]);
			counter--;
		}
	}
}