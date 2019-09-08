#pragma once

namespace BSTTree
{
	template<typename T>
	class BSTTree
	{
	public:
		struct Node
		{
			Node* left;
			Node* right;
			T value;
			int N;
			Node(T val) : 
				value(val), left(nullptr), right(nullptr), N(0)
			{}
			Node() = default;
		};
	private:
		Node* head;
	public:
		BSTTree() : head(nullptr)
		{}

		void insert(T val)
		{
			if (head == nullptr) {
				head = new Node(val);
			} else {
				insertInternal(head, val);
			}
		}

		void remove(T key)
		{

		}

		Node* search(T key)
		{
			return searchInternal(head, key);
		}

		void rotateR(Node* node)
		{
			Node* temp = node->left;
			node->left = node->left->right;
			temp->right = node;
		}

		void rotateL(Node* node)
		{
			Node* temp = node->right;
			node->right = node->right->left;
			temp->left = node;
		}
	private:
		Node* searchInternal(Node* node, T key)
		{
			if (node == nullptr) return nullptr;

			if (node->value == key) {
				return node;
			} else {
				if (key < node->value) {
					return searchInternal(node->left, key);
				} else if (key > node->value) {
					return searchInternal(node->right, key);
				}
			}
			return nullptr;
		}

		void insertInternal(Node* node, T val)
		{
			if (node->value < val) {
				if (node->right != nullptr) {
					insertInternal(node->right, val);
				} else {
					node->right = new Node(val);
				}
			} else {
				if (node->left != nullptr) {
					insertInternal(node->left, val);
				} else {
					node->left = new Node(val);
				}
			}
			node->N++;
		}
	};
}
