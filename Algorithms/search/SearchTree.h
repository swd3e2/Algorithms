#pragma once
#include <iostream>

namespace SearchTree
{
	template<class Item, class Key>
	class SearchTree
	{
	private:
		struct node
		{
			Item item;
			node* l;
			node* r;
			node(Item val) :
				item(val), l(nullptr), r(nullptr)
			{}
		};
	private:
		using link = node *;
		Item nullItem;
		link head;
	private:
		Item searchR(link h, Key v)
		{
			if (h == nullptr) return nullItem;

			Key t = h->item.key();
			if (v == t) return h->item;
			if (v < t) {
				return searchR(h->l, v);
			} else {
				return searchR(h->r, v);
			}
		}

		void insertR(link& h, Item x)
		{
			if (h == nullptr) {
				h = new node(x);
				return;
			}

			if (x.key() < h->item.key()) {
				insertR(h->l, x);
			} else {
				insertR(h->r, x);
			}
		}

		void insertT(link& h, Item x)
		{
			if (h == nullptr) {
				h = new node(x);
				return;
			}

			if (x.key() < h->item.key()) {
				insertT(h->l, x);
				rotR(h);
			} else {
				insertT(h->r, x);
				rotL(h);
			}
		}

		void showR(link h, std::ostream& os)
		{
			if (h == nullptr) return;
			showR(h->l, os);
			h->item.show(os);
			showR(h->r, os);
		}

		void rotR(link& h)
		{
			link temp = h->l;
			h->l = h->l->r;
			temp->r = h;
			h = temp;
		}

		void rotL(link& h)
		{
			link temp = h->r;
			h->r = h->r->l;
			temp->l = h;
			h = temp;
		}

		Item selectR(link h, int k)
		{
			if (h == nullptr) return nullItem;
			int t = height(h->l);
			if (t > k) return selectR(h->l, k);
			if (t < k) return selectR(h->r, k - t - 1);
			return h->item;
		}

		void partR(link& h, int k)
		{
			if (h == nullptr) return;
			int t = height(h->l);
			if (t > k) {
				partR(h->l, k);
				rotR(h);
			} 
			if (t < k) {
				partR(h->r, k - t - 1);
				rotL(h);
			}
		}

		link joinLR(link a, link b)
		{
			if (b == nullptr) return a;
			partR(b, 0);
			b->l = a;
			return b;
		}

		void removeR(link& h, Key v)
		{
			if (h == nullptr) return;
			Key w = h->item.key();
			if (v < w) removeR(h->l, v);
			if (v > w) removeR(h->r, v);
			if (v == w) {
				link t = h;
				h = joinLR(h->l, h->r);
				delete t;
			}
		}

		void joinR(link a, link b)
		{
			if (a == nullptr) return b;
			if (b == nullptr) return a;
			insertT(b, a->item);
			b->l = joinR(a->l, b->l);
			b->r = joinR(a->r, b->r);
			delete a;
			return b;
		}

		int height(link node)
		{
			if (node == nullptr) return 0;
			return height(node->l) + height(node->r) + 1;
		}
	public:
		SearchTree() : 
			head(nullptr), nullItem(0)
		{}

		Item search(Key v)
		{
			return searchR(head, v);
		}

		void insert(Item x)
		{
			insertR(head, x);
		}

		void rootInsert(Item x)
		{
			insertT(head, x);
		}

		void show(std::ostream& os)
		{
			showR(head, os);
		}

		Item select(int k)
		{
			return selectR(head, k);
		}

		void part(int k)
		{
			partR(head, k);
		}

		void remove(Key k)
		{
			removeR(head, k);
		}

		void join(SearchTree<Item, Key>& other)
		{
			head = joinR(head, other.head);
		}
	};
}