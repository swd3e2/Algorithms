#pragma once
#include <memory>
#include <stdlib.h>

namespace SkipList
{
	template<class Item, class Key>
	class SkipList
	{
	private:
		struct Node
		{
			Node** next;
			int size;
			Item item;
			Node(Item x, int k) :
				item(x), size(k)
			{
				next = new Node*[k];
				for (int i = 0; i < k; i++)
					next[i] = 0;
			}
		};
	private:
		using link = Node *;
		link head;
		Item nullItem;
		int lgN;

		const static int lgNMax = 5;
	public:
		SkipList() :
			lgN(0), nullItem(INT_MIN), head(new Node(nullItem, lgNMax))
		{
		}

		void insert(Item v)
		{
			insertR(head, new Node(v, randX()), lgN);
		}
	private:
		int randX()
		{
			int i, j, t = rand();
			for (i = 1, j = 2; i < lgNMax; i++, j += j) {
				if (t > RAND_MAX / j) 
					break;
			}
			if (i > lgN) lgN = 1;
			return i;
		}

		void insertR(link t, link x, int k)
		{
			const Key& v = x->item.key();
			link tk = t->next[k];

			if ((tk == nullptr) || (v < tk->item.key())) {
				if (k < x->size) {
					x->next[k] = tk;
					t->next[k] = x;
				}
				if (k == 0) {
					return;
				}
				insertR(t, x, k - 1);
				return;
			}
			insertR(tk, x, k);
		}
	};
}