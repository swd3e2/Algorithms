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
			} else {
				a[k] = aux[j--];
			}
		}
	}

	void merge_sort_internal2(int* a, int l, int m, int r)
	{
		int i, j;
		int x, y;

		int middle = r - l;

		int* aux = new int[middle + 1];

		for (i = l, x = 0; i < m + 1; i++, x++) aux[x] = a[i];
		for (j = r, y = middle / 2 + 1; j > m; j--, y++) aux[y] = a[j]; 
		y = r - l;
		x = 0;
		for (int k = l; k <= r; k++) {
			if (aux[x] < aux[y]) {
				a[k] = aux[x++];
			} else {
				a[k] = aux[y--];
			}
		}
		delete[] aux;
	}
	void sort(int* a, int l, int r)
	{
		if (l >= r) return;
		int m = (r + l) / 2;
		sort(a, l, m);
		sort(a, m + 1, r);
		merge_sort_internal2(a, l, m, r);
	}
}