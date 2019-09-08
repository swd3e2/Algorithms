#pragma once
#include <memory>

template<typename T>
class BinomialQueue
{
private:
	struct Node
	{
		T value;
		Node* l;
		Node* r;
		Node(T t): value(t)
		{}
	};
private:
	int size;
	using link = Node*;
	link* bq;
	const int maxSize = 10;
private:
	static link pair(link p, link q)
	{
		link result;
		if (p->value < q->value) {
			p->r = q->l;
			q->l = p;
			result = q;
		} else {
			q->r = p->l;
			p->l = q;
			result = p;
		}

		return result;
	}

	static inline int test(int C, int B, int A)
	{
		return C << 2 | B << 1 | A;
	}

	void join(link* a, link* b)
	{
		link c = nullptr;
		for(int i = 0; i < maxSize; i++)
		{
			switch (test(c != nullptr, b[i] != nullptr, a[i] != nullptr))
			{
			case 2: a[i] = b[i]; break;
			case 3: c = pair(a[i], b[i]); a[i] = 0; break;
			case 4: a[i] = c, c = nullptr; break;
			case 5: c = pair(c, a[i]); a[i] = nullptr; break;
			case 6:
			case 7: c = pair(c, b[i]); break;
			}
		}
	}
public:
	using handle = Node*;

	/**
	 * \brief 
	 */
	BinomialQueue(): size(0)
	{
		bq = new link[maxSize];
		memset(bq, 0, sizeof(link) * maxSize);
	}

	/**
	 * \brief 
	 * \return int
	 */
	int empty() const
	{
		return size;
	}

	/**
	 * \brief 
	 * \param item 
	 * \return 
	 */
	handle insert(T item)
	{
		const link t = new Node(item);
		link c = t;

		for (int i = 0; i < maxSize; i++) {
			if (c == nullptr) break;
			if (bq[i] == nullptr) {
				bq[i] = c;
				break;
			}
			c = pair(c, bq[i]);
			bq[i] = nullptr;
		}
		return t;
	}

	T getMax()
	{
		int i, max;
		T val = 0;
		link* temp = new link[maxSize];
		memset(temp, 0, sizeof(link) * maxSize);

		for (i = 0, max = -1; i < maxSize; i++)
		{
			if (bq[i] != nullptr)
			{
				if ((max == -1) || (val < bq[i]->value))
				{
					max = i;
					val = bq[max]->value;
				}
			}
		}

		link x = bq[max]->l;
		for(i = max; i > 0; i--)
		{
			temp[i - 1] = x;
			x = x->r;
			temp[i - 1]->r = nullptr;
		}
		
		delete bq[max];
		bq[max] = nullptr;
		join(bq, temp);
		delete[] temp;
		
		return val;
	}

	void change(handle item)
	{

	}

	void remove(handle item)
	{

	}
	
	void join(const BinomialQueue& other)
	{
		join(bq, other.bq);
	}
};