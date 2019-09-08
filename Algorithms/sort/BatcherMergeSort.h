#pragma once

namespace BatcherMergeSort
{
	const int maxN = 500;

	template<typename T>
	void compexch(T& l, T& r)
	{
		T temp = l;
		if (l < r) {
			l = r;
			r = temp;
		}
	}

	template<typename T>
	void shuffle(T* data, int l, int r)
	{
		int i, j, m = (l + r) / 2;
		static T aux[maxN];
		
		for (i = l, j = 0; i <= r; i += 2, j++)
		{
			aux[i] = a[i + j];
			aux[i + 1] = a[m + 1 + j];
		}
		for (i = l; i <= r; i++)
		{
			data[i] = aux[i];
		}
	}

	template<typename T>
	void unshuffle(T* data, int l, int r)
	{
		int i, j, m = (l + r) / 2;
		static T aux[maxN];

		for (i = l, j = 0; i <= r; i += 2, j++)
		{
			aux[l + j] = a[i];
			aux[m + 1 + j] = a[i + 1];
		}
		for (i = 1; i <= r; i++)
		{
			a[i] = aux[i];
		}
	}

	template<typename T>
	void sort(T* data, int l, int m, int r)
	{
		if (r == l + 1) compexch(data[l], data[r]);
		if (r < l + 2) return;
		unshuffle(data, l, r);
		sort(data, l, (l + m) / 2, r);
		sort(data, m + 1, (m + 1 + r) / 2, r);
		shuffle(a, l, r);
		for (int i = l + 1; i < r; i += 2)
			compexch(data[i], data[i + 1]);
	}
}