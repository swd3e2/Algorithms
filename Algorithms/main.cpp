#include <iostream>
#include "src/1.h"
#include "src/2.h"
#include <math.h>
#include "src/3.h"
#include "src/sort.h"
#include "src/4.h"
#include "src/bst.h"

int main(int agrc, char** args)
{
	int a[] = { 3, 4, 5, 6, 7, 8, 9 };

	BST tree(100);

	tree.insert(41);
	tree.insert(20);
	tree.insert(65);
	tree.insert(50);
	tree.insert(11);
	tree.insert(29);
	tree.insert(26);
	tree.insert(23);
	tree.insert(55);

	std::cin.get();
}