#include <iostream>
#include "src/RadixSort.h"
#include "src/utility.h"
#include "src/QuickSort.h"
#include "src/CountingSort.h"

int main(void)
{
	//int a[] = { 1,2,35,12,123,543,346,2,0,7,9,5,4,3, 16, 29, 31, 32 };
	int a[] = { 3,2,1,0,0,3,2 };
	const int size = sizeof(a) / 4;
	CountingSort::countingSort(a, 0, size - 1, 4);
	
	char temp[] = { 'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E','\0'};
	RadixSort::MSDRadixSort(a, 0, size - 1, 0);
	std::cin.get();
}