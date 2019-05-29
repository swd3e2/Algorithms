#pragma once
#include <iostream>

struct node {
	node* next;
	int val;
	node(int val, node* next) : 
		val(val), next(next) 
	{}
};

/* Solution of flavian exercise with linked list */
void flav(int x,  int y)
{
	node* nod = new node(1, nullptr);
	nod->next = nod;
	node* last = nod;

	for (int i = 2; i <= x; i++) {
		last = (last->next = new node(i, nod));
	}

	while (last != last->next) {
		for (int i = 1; i < y; i++) {
			last = last->next;
		}
		last->next = last->next->next;
	}

	std::cout << last->val << std::endl;
}

/* Solution of flavian exercise with arrays */
void flavarr(int y)
{
	int arr1[9];
	int arr2[9];
	int last = 8;

	for (int i = 1; i <= 9; i++) {
		arr2[i-1] = i;
		arr1[i-1] = i;
	}
	arr1[8] = 0;

	while (arr1[last] != last) {
		for (int i = 1; i < y; i++) {
			last = arr1[last];
		}
		arr1[last] = arr1[arr1[last]];
	}

	std::cout << arr2[last] << std::endl;
}

/* Count nodes in circular linked list */
int count(node* nod)
{
	node* nextn = nod;
	int count = 1;

	while ((nextn = nextn->next) != nod) {
		count++;
	}

	return count;
}

/* Count nodes in circular linked list */
int count_between(node* first, node* second)
{
	node* nextn = first;
	int count = 0;

	while ((nextn = nextn->next) != second) {
		count++;
	}

	return count;
}

void merge_linked_lists(node* first, node* second)
{
	node* last = first;
	while (last->next != nullptr) { last = last->next; }

	last->next = second;
}


void reverse_linked_list(node* first)
{
	node* temp; 
	node* r = nullptr;
	node* y = first;

	while (y != nullptr) {
		temp = y->next;
		y->next = r;
		r = y;
		y = temp;
	}
}