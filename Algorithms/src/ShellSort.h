#pragma once

namespace ShellSort
{
	template<typename T>
	void shell_sort(T* data, const int size)
	{
		int h;
		for (h = 1; h < size / 9; h = 3 * h + 1);

		for (; h > 0; h /= 3) {
			for (int i = h; i < size; i++) {
				int j = i;
				int v = data[i];
				while (j >= h && v < data[j - h]) {
					data[j] = a[j - h];
					j -= h;
				}
				data[j] = v;
			}
		}
	}
}