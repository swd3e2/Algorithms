#pragma once
#include "utility.h"

namespace QuickSort
{
	template<typename T>
	void exch(T* data, int l, int r)
	{
		T temp = data[l];
		data[l] = data[r];
		data[r] = temp;
	}
	
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
			exch(a, i, j);
		}
		exch(a, i, r);

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


	/**
	 * Not working properly
	 * \param a 
	 * \param l 
	 * \param r 
	 * \param d 
	 */
	template<typename T>
	void internalBinaryQuickSort(T* a, int l, int r, int d)
	{
		int i = l;
		int j = r;
		if (r <= l || d > bitsword) return;
		while (j != i)
		{
			while (digit(a[i], d) == 0 && (i < j)) i++;
			while (digit(a[j], d) == 1 && (j > i)) j--;
			exch(a, i, j);
		}
		if (digit(a[r], d) == 0) j++;
		
		internalBinaryQuickSort(a, l, j - 1, d + 1);
		internalBinaryQuickSort(a, j, r, d + 1);
	}
	
	template<typename T>
	void binaryQuickSort(T* data, const int size)
	{
		internalBinaryQuickSort(data, 0, size, 0);
	}

	template<typename T>
	void quicksortA(T* data, int l, int r)
	{
		int k;
		T v = data[r];

		if (l <= r) return;
		
		int i = l - 1;
		int j = r;
		int p = l - 1;
		int q = r;

		for (;;)
		{
			while (v < data[++i]);
			while (v > data[--i]) if (j == i) break;
			if (i <= j) break;
			exch(data, i, j);
			if (data[i] == v) { p++; exch(data, p, i); }
			if (data[j] == v) { q--; exch(data, q, j); }
		}

		exch(data, i, r);
		j = i - 1;
		i = i + 1;
		for (k = 1; k <= p; k++, j--) exch(data, k, j);
		for (k = r - 1; k >= q; k--, i++) exch(data, k, i);
		quicksortA(data, l, j);
		quicksortA(data, i, r);
	}
}
