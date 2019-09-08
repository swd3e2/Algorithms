#pragma once

template<typename T>
class rb
{
private:
	struct node
	{
		node* l;
		node* r;
		T value;
		bool red;

		node(T val) :
			value(val), l(nullptr), r(nullptr), red(true)
		{}
	};
public:
	node* head;
public:
	rb() :
		head(nullptr)
	{

	}

	void insert(T value)
	{
		insertR(head, value);
		head->red = false;
		/*if (!isBalanced(head)) {
			if (height(head->r) > height(head->l)) {
				rotateRight(head);
			} else {
				rotateLeft(head);
			}
		}*/
	}

	void rotateLeft(node*& n)
	{
		node* temp = n->r;
		n->r = n->r->l;
		temp->l = n;
		n = temp;
	}

	void rotateRight(node*& n)
	{
		node* temp = n->l;
		n->l = n->l->r;
		temp->r = n;
		n = temp;
	}

	const bool red(const node* const n) const noexcept
	{
		return n != nullptr ? n->red : false;
	}

	const int height(const node* const n) const noexcept
	{
		if (n == nullptr) return 0;
		return abs(height(n->r) - height(n->l)) + (n->red ? 0 : 1);
	}

	const bool isBalanced(const node* n) const  noexcept
	{
		if (n == nullptr) return 0;
		return height(n) < 2;
	}


	/**
	 * @param[in]	value		Value
	 * @param[in]	n			Node operating on
	 */
	void insertR(node*& n, T value)
	{
		if (n == nullptr) {
			n = new node(value);
			return;
		}

		if (value > n->value) {
			insertR(n->r, value);

			/**
						B				B
					  /   \			  /   \
					 B	   R		 B	   R
						  / \			  / \
							 R			 R
			  */
			if (((red(n->r) && red(n->r->r)) || (red(n->r) && red(n->r->l))) && !red(n->l)) {
				rotateLeft(n);
				n->l->red = true;
				n->r->red = true;
				n->red = false;
				/**
							B
						  /   \
						 R	   R
							  / \
								 R
				*/
			}
			else if (red(n->r) && red(n->r->r) && red(n->l)) {
				n->l->red = false;
				n->r->red = false;
				n->red = true;
			}
			/**
						 B
					   /   \
					  B	    R
						   / \
						  R
			  */
			if (red(n->r) && red(n->r->l) && !red(n->l)) {
				rotateRight(n->r);
				rotateLeft(n);
				n->red = false;
				n->l->red = true;
				n->r->red = true;
			}
		}
		else {
			insertR(n->l, value);
			/**
						B				B
					  /   \			  /   \
					 R	   B		 R	   B
					/ \				/ \
				   R				   R
			  */
			if ((red(n->l) && red(n->l->l) || red(n->l) && red(n->l->r)) && !red(n->r)) {
				rotateRight(n);
				n->l->red = true;
				n->r->red = true;
				n->red = false;
				/**
					B
				  /   \
				 R	   R
				/ \
			   R
		 */
			}
			else if (red(n->l) && red(n->l->l) && red(n->r)) {
				n->l->red = false;
				n->r->red = false;
				n->red = true;
			}
			/**
						 B
					   /   \
					  R	    B
					 / \
						R
			  */
			if (red(n->l) && red(n->l->r) && !red(n->r)) {
				rotateLeft(n->l);
				rotateRight(n);
				n->red = false;
				n->l->red = true;
				n->r->red = true;
			}
		}
	}
};