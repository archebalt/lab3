#include "heap.h"
#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	BinaryHeap tree;
	for (int i = 1; i <= 10; i++)
	{
		tree.insert(i);
	}
	
	Iterator* iter1 = tree.create_bft_iterator();
	cout << "Обход в ширину: " << endl;
	while (iter1->has_next()) cout << iter1->next() << " ";
	cout << endl;
	cout << "Обход в глубину: " << endl;
	Iterator* iter2 = tree.create_dft_iterator();
	while (iter2->has_next()) cout << iter2->next() << " ";
	return 0;
}