#pragma once
#include <iostream>
#define SIZE 10

using namespace ::std;

void fast_find()
{
	int i, p, q, id[SIZE];
	for (i = 0; i < SIZE; i++) id[i] = i;

	while (cin >> p >> q)
	{
		if (id[p] == id[q]) continue;

		for (i = 0; i < SIZE; i++)
			if (id[i] == id[p]) id[i] = id[q];

		cout << "Added new pair " << p << " " << q << endl;
	}
}

void fast_union()
{
	int i, j, p, q, id[SIZE];
	for (i = 0; i < SIZE; i++) id[i] = i;

	while (cin >> p >> q)
	{
		for (i = p; i != id[i]; i = id[i]);
		for (j = q; j != id[j]; j = id[j]);
		if (i == j) continue;
		id[i] = j;
		cout << "Added new pair " << p << " " << q << endl;
	}
}

void weighed_fast_union()
{
	int i, j, p, q, id[SIZE], sz[SIZE];
	for (i = 0; i < SIZE; i++) { id[i] = i; sz[i] = 1; }

	while (cin >> p >> q)
	{
		for (i = p; i != id[i]; i = id[i]);
		for (j = q; j != id[j]; j = id[j]);

		if (i == j) continue;

		if (sz[i] < sz[j]) {
			id[i] = j; sz[i] += sz[j];
		} else {
			id[j] = i; sz[j] += sz[i];
		}
		cout << "Added new pair " << p << " " << q << endl;
	}
}

void weighed_fast_union_half()
{
	int i, j, p, q, id[SIZE], sz[SIZE];
	for (i = 0; i < SIZE; i++) { id[i] = i; sz[i] = 1; }

	while (cin >> p >> q)
	{
		for (i = p; i != id[i]; i = id[i])
			id[i] = id[id[i]];
		for (j = q; j != id[j]; j = id[j])
			id[j] = id[id[j]];

		if (i == j) continue;

		if (sz[i] < sz[j]) {
			id[i] = j; sz[i] += sz[j];
		} else {
			id[j] = i; sz[j] += sz[i];
		}
		cout << "Added new pair " << p << " " << q << endl;
	}
}