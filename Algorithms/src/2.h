#pragma once
#include <iostream>
#include <vector>

struct node {
	node* next;
	int val;
	node(int val, node* next) : 
		val(val), next(next) 
	{}
};

/* Solution of flavian exercise with linked list */
void flav(int x,  int y)
{
	node* nod = new node(1, nullptr);
	nod->next = nod;
	node* last = nod;

	for (int i = 2; i <= x; i++) {
		last = (last->next = new node(i, nod));
	}

	while (last != last->next) {
		for (int i = 1; i < y; i++) {
			last = last->next;
		}
		last->next = last->next->next;
	}

	std::cout << last->val << std::endl;
}

/* Solution of flavian exercise with arrays */
void flavarr(int y)
{
	int arr1[9];
	int arr2[9];
	int last = 8;

	for (int i = 1; i <= 9; i++) {
		arr2[i-1] = i;
		arr1[i-1] = i;
	}
	arr1[8] = 0;

	while (arr1[last] != last) {
		for (int i = 1; i < y; i++) {
			last = arr1[last];
		}
		arr1[last] = arr1[arr1[last]];
	}

	std::cout << arr2[last] << std::endl;
}

/* Count nodes in circular linked list */
int count(node* nod)
{
	node* nextn = nod;
	int count = 1;

	while ((nextn = nextn->next) != nod) {
		count++;
	}

	return count;
}

/* Count nodes in circular linked list */
int count_between(node* first, node* second)
{
	node* nextn = first;
	int count = 0;

	while ((nextn = nextn->next) != second) {
		count++;
	}

	return count;
}

void merge_linked_lists(node* first, node* second)
{
	node* last = first;
	while (last->next != nullptr) { last = last->next; }

	last->next = second;
}


void reverse_linked_list(node* first)
{
	node* temp; 
	node* r = nullptr;
	node* y = first;

	while (y != nullptr) {
		temp = y->next;
		y->next = r;
		r = y;
		y = temp;
	}
}

void sort()
{
	node heada(0, 0);
	node* a = &heada, *t = a;

	for (int i = 0; i < 10; i++)
		t = (t->next = new node(rand() % 1000, 0));

	node headb(0, 0);
	node *u, *x, *b = &headb;

	for (t = a; t != 0; t = u)
	{
		u = t->next;

		for (x = b; x->next != 0; x = x->next)
		{
			if (x->next->val > t->val) break;
		}

		t->next = x->next;
		x->next = t;
	}
}

void adjacent_graph_matrix()
{
	int i, j, adj[10][10];

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			adj[i][j] = 0;
	for (i = 0; i < 10; i++)
		adj[i][i] = 1;

	while (cin >> i >> j) {
		adj[i][j] = 1;
		adj[j][i] = 1;
	}
}

void adjacent_graph_linked_list()
{
	int i, j;
	node* adj[10];
	for (i = 0; i < 10; i++)
		adj[i] = 0;

	while (cin >> i >> j) {
		adj[i] = new node(j, adj[i]);
		adj[j] = new node(i, adj[j]);
	}
}

namespace Points {
	struct point { 
		float x; 
		float y; 
		point(float x, float y) :
			x(x), y(y)
		{}
	};
	float distance(point left, point right)
	{
		float dx = left.x - right.x;
		float dy = left.y - right.y;
		return sqrt(dx * dx + dy * dy);
	}

	struct node
	{
		point p;
		node* next;
		node(point p, node* next) :
			p(p), next(next)
		{}
	};

	using link = node *;
	static int G, cnt = 0;
	static link** grid;
	static float d;

	void gridinsert(float x, float y)
	{
		int X = x * G + 1;
		int Y = y * G + 1;
		
		point p(x, y);

		link s;
		link t = new node(p, grid[X][Y]);
		for (int i = X - 1; i <= X + 1; i++) {
			for (int j = Y - 1; j <= Y + 1; j++) {
				for (s = grid[X][Y]; s != nullptr; s = s->next) {
					if (distance(s->p, t->p) < d) {
						cnt++;
					}
				}
			}
		}
		grid[X][Y] = t;
	}

	link** malloc2d(int r, int c)
	{
		link** t = new link * [r];
		for (int i = 0; i < r; i++) {
			t[i] = new link[c];
		}
		return t;
	}

	void mainfunc()
	{
		int i;
		int N = 100;
		d = 0.1f;
		G = 1 / d;
		grid = malloc2d(G + 2, G + 2);

		for (i = 0; i < G + 2; i++) {
			for (int j = 0; j < G + 2; j++) {
				grid[i][j] = 0;
			}
		}

		for (i = 0; i < N; i++) {
			gridinsert(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX)), static_cast <float> (rand()) / (static_cast <float> (RAND_MAX)));
		}

		std::cout << cnt << std::endl;

		std::vector<int> kek;
	}
}
