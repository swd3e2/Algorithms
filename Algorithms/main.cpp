#include <iostream>
#include "src/RadixSort.h"
#include "src/utility.h"
#include "src/QuickSort.h"
#include "src/CountingSort.h"

int getMax(int* array, int size)
{
	int max = array[0];
	for (int i = 0; i < size; i++) {
		if (max < array[i]) max = array[i];
	}
	return max;
}

void countSort(int* array, int size) {
	int* output = new int[size + 1];
	int max = getMax(array, size);
	int* count = new int[max + 1];     //create count array (max+1 number of elements)
	for (int i = 0; i <= max; i++)
		count[i] = 0;     //initialize count array to all zero
	for (int i = 0; i <= size; i++)
		count[array[i] + 1]++;     //increase number count in count array.
	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];     //find cumulative frequency
	for (int i = size; i >= 0; i--)
		output[count[array[i]]++] = array[i];
	
	for (int i = 0; i <= size; i++) {
		array[i] = output[i]; //store output array to main array
	}
}

int getbit(int number, int digit)
{
	return (number >> digit) & 1;
}

int main(void)
{
	//int a[] = { 1,2,35,12,123,543,346,2,0,7,9,5,4,3, 16, 29, 31, 32 };
	//int a[] = { 6, 5, 6, 2, 3, 10, 3, 6, 7, 8 };
	int a[] = { 3,2,1,0,0,3,2 };
	const int size = sizeof(a) / 4;
	countSort(a, size - 1);
	CountingSort::sort(a, 0, size - 1, 4);
	int kek = 342342;
	

	std::cout << digit(kek, 6) << std::endl;
	//char temp[] = { 'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E','\0'};
	int temp[] = { 224, 61, 66, 221, 22, 62, 254, 26, 231, 230 };
	RadixSort::MSDSort(temp, 0, 10 - 1, 0);
	std::cin.get();
}