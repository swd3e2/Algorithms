#pragma once
#include <iostream>
#include <math.h>

void insert_sort()
{
	int a[]{1,2,35,12,123,543,346,2,1,7,9,5,4,3};
	int temp;
	int c;

	for (int i = 0; i < 13; i++) {
		c = i;
		while (a[c] > a[c + 1] && c > 0) {
			temp = a[c];
			a[c] = a[c + 1];
			a[c + 1] = temp;
			c--;
		}
	}

	for (int i = 0; i < 14; i++) {
		std::cout << a[i] << " ";
	}
}

void binary_insert_sort()
{
	int a[] = { 1,2,35,12,123,543,346,2,1,7,9,5,4,3 };

	int temp;
	int tempVal;	

	int left = 0;
	int right = 0;

	for (int i = 1; i < sizeof(a) / sizeof(a[0]); i++) {
		tempVal = a[i];
		right = i;
		left = 0;

		while (left < right) {
			int middle = (right + left) / 2;
			if (tempVal > a[middle]) {
				left = middle + 1;
			} else {
				right = middle;
			}
		}
			
		for (int j = i; j > left; --j) {
			temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
		}
	}

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		std::cout << a[i] << " ";
	}
}

void merge_sort()
{
	int left[] = {20, 13, 7, 2 };
	int right[] = { 12, 11, 9, 1};
	int result[8];

	int leftPointer = 3;
	int rightPointer = 3;
	int curentPointer = 0;

	while (leftPointer != -1 || rightPointer != -1) {
		if (left[leftPointer] > right[rightPointer] && rightPointer >= 0) {
			result[curentPointer] = right[rightPointer--];
		} else if (leftPointer >= 0) {
			result[curentPointer] = left[leftPointer--];
		}
		curentPointer++;
	}

	for (int i = 0; i < sizeof(result) / sizeof(result[0]); i++) {
		std::cout << result[i] << " ";
	}
}

template<typename T>
void swap_val(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}

void heapify_max(int* A, int x, int size) {
	int val = x * 2;
	if (val == 0) val = 1;

	if (val > size) return;

	if (A[x] < A[val] || A[x] < A[val + 1]) {
		if (A[val] > A[val + 1]) {
			swap_val(A[x], A[val]);
		} else if (val + 1 < size){
			swap_val(A[x], A[val + 1]);
		}
	}
}

void heapify_max_recursive(int* A, int x, int size) {
	int val = x * 2;
	if (val == 0) val = 1;

	if (val < size) {
		heapify_max(A, x, size);
		heapify_max_recursive(A, val, size);
		if (val + 1 < size) heapify_max_recursive(A, val + 1, size);
	}
}

void heap_sort()
{
	int a[] = { 1,2,35,12,123,543,346,1,7,9,5,4,3 };
	int size = sizeof(a) / 4;
	int counter = size;

	for (int i = size / 2; i >= 0; i--) {
		heapify_max_recursive(a, i, counter);
	}

	for (int k = 0; k < size; k++) {
		heapify_max_recursive(a, 0, counter);
		swap_val(a[counter - 1], a[0]);
		counter--;
	}

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		std::cout << a[i] << " ";
	}
}

void radix_sort()
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

void bubble_sort()
{
	int a[] = { 1,2,35,12,123,543,346,2,1,7,9,5,4,3 };
	int size = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		std::cout << a[i] << " ";
	}
}

void select_sort()
{
	int a[] = { 1,2,35,12,123,543,346,2,1,7,9,5,4,3 };
	int size = sizeof(a) / sizeof(a[0]);
	int min = 0;

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (a[j] < a[min]) min = j;
		}
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
		min = i + 1;
	}

	for (int i = 0; i < size; i++) {
		std::cout << a[i] << " ";
	}
}

void shell_sort()
{
	int a[] = { 1,2,35,12,123,543,346,2,0,7,9,5,4,3, 16, 29, 31, 32 };
	int size = sizeof(a) / sizeof(a[0]);
	
	int h;
	for (h = 1; h < size / 9; h = 3 * h + 1);

	for (; h > 0; h /= 3) {
		for (int i = h; i < size; i++) {
			int j = i;
			int v = a[i];
			while (j >= h && v < a[j - h]) {
				a[j] = a[j - h]; 
				j -= h;
			}
			a[j] = v;
		}
	}

	for (int i = 0; i < size; i++) {
		std::cout << a[i] << " ";
	}
}

namespace DS
{
	struct Item {
		int val;
		Item* next;

		Item(int val = 0) :
			val(val), next(nullptr)
		{}
	};

	using link = Item*;

	struct LinkedList
	{
		link head;
		link currentHead;

		LinkedList() :
			head(nullptr), currentHead(nullptr)
		{}

		void insert(int val)
		{
			if (currentHead == nullptr) {
				head = currentHead = new Item(val);
			} else {
				currentHead = (currentHead->next = new Item(val));
			}
		}
	};
}

DS::link findmax(DS::link node) {
	DS::link max = node;
	DS::link temp = node->next;
	DS::link prev = node;

	while (temp != nullptr) {
		if (max->next->val < temp->val) {
			max = prev;
		}
		prev = temp;
		temp = temp->next;
	}

	return max;
}

DS::link linkedlist_select_sort(DS::LinkedList* ls)
{
	using namespace DS;

	Item dummy;
	link head = &dummy;
	link out = nullptr;
	head->next = ls->head;

	while (head->next != nullptr) {
		link max = findmax(head);
		link t = max->next;
		max->next = t->next;
		t->next = out;
		out = t;
	}
	return out;
}