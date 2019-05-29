#include <iostream>
#include "src/1.h"
#include "src/2.h"

int main()
{
	//flavarr(5);

	node* nod = new node(1, nullptr);
	node* last = nod;

	for (int i = 2; i <= 4; i++) {
		last = (last->next = new node(i, nullptr));
	}

	node* nod2 = new node(5, nullptr);
	last = nod2;

	for (int i = 2; i <= 4; i++) {
		last = (last->next = new node(i + 4, nullptr));
	}

	merge_linked_lists(nod, nod2);

	reverse_linked_list(nod);
}