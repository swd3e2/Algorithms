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

	namespace Pyramid
	{
		void exch(int* a, int l, int r)
		{
			int temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}

		void fixUp(int* a, int k, int size)
		{
			while (k / 2 >= 0) {
				int val = a[k];
				int j = k != 1 ? k / 2 : 0;
				if (val > a[j]) {
					exch(a, k, j);
				}
				if (k == 0) break;
				k = j;
			}
		}

		void fixDown(int* a, int k, int size)
		{
			while (k * 2 < size) {
				int val = a[k];
				int j = k * 2;
				if (a[j] < a[j + 1]) j = j + 1;
				if (val < a[j]) {
					exch(a, k, j);
				}
				k = j;
			}
		}
	}

	int test()
	{
		int a[] = { 1,2,35,12,123,543,346,2,0,7,9,5,4,3, 16, 29, 31, 32 };
		int size = sizeof(a) / 4;
		int arr[19];
		for (int i = 0; i < size; i++) {
			arr[i] = a[i];
		}

		for (int i = size / 2; i >= 0; i--) {
			Pyramid::fixDown(arr, i, size);
		}
		arr[18] = 800;
		Pyramid::fixUp(arr, 18, size);
		while (size > 0) {
			Pyramid::exch(arr, 0, size--);
			Pyramid::fixDown(arr, 0, size);
		}
		std::cin.get();
	}
}