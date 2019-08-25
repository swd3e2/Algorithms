#pragma once
#include <iostream>

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

DS::link linkedlist_insert_sort(DS::LinkedList* ls)
{
	using namespace DS;

	Item dummy(0);
	link current = &dummy;
	current = (current->next = ls->head);
	link next = nullptr;
	link head = nullptr;

	while (current != nullptr) {
		next = current->next;

		if (head == nullptr || current->val < head->val) {
			current->next = head;
			head = current;
		} else {
			link temp = head;
			while (temp->next != nullptr && temp->next->val < current->val) {
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}

		current = next;
	}

	return head;
}

