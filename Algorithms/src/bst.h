#pragma once
#include <iostream>
#include <algorithm>

struct Node {
	int val;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int val) : val(val) {}
};

class BST
{
private:
	Node** A;
public:
	Node* rootNode;

	int counter = 0;
public:
	BST(int size)
	{
		A = new Node *[size];
		rootNode = nullptr;
	}

	int height(Node* n)
	{
		if (n == nullptr) {
			return 0;
		} else {
			return max(height(n->right), height(n->left)) + 1;
		}
	}
	
	bool isBalanced(Node* n)
	{
		return abs(height(n->left) - height(n->right)) < 2;
	}

	Node* leftRotate(Node* n)
	{
		Node* t = n->left;
		n->left = t->right;
		t->right = n;
		return t;
	}

	Node* rightRotate(Node* n)
	{
		Node* t = n->right;
		n->right = t->left;
		t->left = n;
		return t;
	}

	Node* doubleRightRotate(Node* n)
	{
		n->right = leftRotate(n->right);
		return rightRotate(n);
	}

	Node* doubleLeftRotate(Node* n)
	{
		n->left = rightRotate(n->left);
		return leftRotate(n);
	}

	Node* insert(int val)
	{
		if (rootNode == nullptr) {
			rootNode = A[counter++] = new Node(val);
			return rootNode;
		} else {
			return insertInternal(val, rootNode);
		}
	}

	Node* insertInternal(int val, Node* node)
	{
		Node* temp = nullptr;

		if (node->right == nullptr && val >= node->val) {
			node->right = new Node(val);
		} else if (node->left == nullptr && val <= node->val) {
			node->left = new Node(val);
		} else if (val >= node->val) {
			temp = insertInternal(val, node->right);
			if (temp != nullptr) {
				node->right = temp;
				temp = nullptr;
			}
			if (!isBalanced(node)) {
				if (val > node->right->val) {
					temp = rightRotate(node);
				} else {
					temp = doubleRightRotate(node);
				}
			}
		} else if (val <= node->val) {
			temp = insertInternal(val, node->left);
			if (temp != nullptr) {
				node->left = temp;
				temp = nullptr;
			}
			if (!isBalanced(node)) {
				if (val < node->left->val) {
					temp = leftRotate(node);
				} else {
					temp = doubleLeftRotate(node);
				}
			}
		}
		return temp;
	}
};