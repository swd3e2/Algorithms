#pragma once

namespace RadixSort
{
	const int bitsword = 64;
	const int bitsbyte = 8;
	constexpr int bytesword = bitsword / bitsbyte;
	constexpr int R = 1 << bitsbyte;
	
	inline int digit(long a, int b)
	{
		return (a >> bitsbyte * (bytesword - b - 1) * (R - 1));
	}

	inline int digit(const char* a, const int b)
	{
		return a[b];
	}

	void radixSort()
	{
		int a[] = { 1,2,35,12,123,543,346,2,1,7,9,5,4,3 };
		int val = 0;
		int temp;
		int tempVal;

		for (int i = 1; i < 4; i++) {
			int numerator = pow(10, i);
			for (int j = 1; j < sizeof(a) / 4; j++) {
				val = a[j];
				temp = j - 1;
				while (val % numerator < a[temp] % numerator) {
					tempVal = a[temp + 1];
					a[temp + 1] = a[temp];
					a[temp] = tempVal;
					temp--;
				}

			}
		}

		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
			std::cout << a[i] << " ";
		}
	}
}