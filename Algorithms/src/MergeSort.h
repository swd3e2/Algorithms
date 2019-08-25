#pragma once

namespace MergeSort
{
	void merge_sort_internal(int* a, int l, int m, int r)
	{
		int i, j;
		static int aux[500];

		for (i = m + 1; i > l; i--) { aux[i - 1] = a[i - 1]; }
		for (j = m; j < r; j++) { aux[r + m - j] = a[j + 1]; }

		for (int k = l; k <= r; k++) {
			if (aux[i] < aux[j]) {
				a[k] = aux[i++];
			}
			else {
				a[k] = aux[j--];
			}
		}
	}

	void mergesort(int* a, int l, int r)
	{
		if (l >= r) return;
		int m = (r + l) / 2;
		mergesort(a, l, m);
		mergesort(a, m + 1, r);
		merge_sort_internal(a, l, m, r);
	}
}