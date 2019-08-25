#pragma once

namespace QuickSort
{
	template<typename T>
	int partition(T* a, int l, int r)
	{
		int i = l - 1;
		int j = r;
		int v = a[r];

		for (;;) {
			while (a[++i] < v);
			while (v < a[--j]) if (j == l) break;
			if (i >= j) break;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

		int temp = a[i];
		a[i] = a[r];
		a[r] = temp;

		return i;
	}

	template<typename T>
	void quickSort(T* a, int l, int r)
	{
		if (l >= r) {
			return;
		}
		int i = partition(a, l, r);
		quickSort(a, l, i - 1);
		quickSort(a, i + 1, r);
	}
}
