#include <iostream>
#include "src/1.h"
#include "src/2.h"
#include "src/3.h"
#include "src/sort.h"
#include "src/4.h"
#include "src/bst.h"

namespace test {
	struct Item
	{
		int val;
		Item* l;
		Item* r;
	};
}

test::Item* doShit(int* vars, int left, int right)
{
	int m = (left + right) / 2;

	test::Item* node = new test::Item();
	if (left == right) {
		node->val = vars[m];
		return node;
	}

	node->l = doShit(vars, left, m);
	node->r = doShit(vars, m + 1, right);

	node->val = node->l->val > node->r->val ? node->l->val : node->r->val;

	return node;
}

void show(test::Item* node, int h)
{
	if (node == nullptr) return;
	for (int i = 0; i < h; i++) std::cout << "  ";
	std::cout << node->val << std::endl;
	show(node->l, h +1);
	show(node->r, h +1);
}

int main(int agrc, char** args)
{
	DS::LinkedList linkedList;
	for (int i = 10; i >= 0; i--) {
		linkedList.insert(i);
	}
	DS::link link = linkedlist_select_sort(&linkedList);
	std::cin.get();

	//shell_sort();

	/*
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

	radix_sort();

	int vars[] = { 5, 16, 7, 6, 4, 2, 9, 1, 10, 18, 13, 19, 14, 15, 3, 17 };
	int size = sizeof(vars) / sizeof(int);
	test::Item* root = doShit(vars, 0, size - 1);
	show(root, 0);
	*/

	std::cin.get();
}