#include "heap.h"
#include<iostream>
using namespace std;

BinaryHeap::BinaryHeap()
{
	heapsize = 0;
	heap = new int[1];
}
BinaryHeap::~BinaryHeap()
{
	if (heapsize != 0)
	{
		delete[] heap;
	}
}
bool BinaryHeap::contains(int data)
{
	for (int i = 0; i < heapsize; i++)
	{
		if (heap[i] == data) return true;
	}
	return false;
}
void BinaryHeap::SiftUp(int i)
{
	int lSon, rSon;
	lSon = 2 * i + 1;
	rSon = 2 * i + 2;
	if ((heap[lSon] < heap[i]) && (lSon < heapsize))
	{
		swap(heap[lSon], heap[i]);
		SiftUp((i - 1) / 2);
	}
	if ((heap[rSon] < heap[i]) && (rSon < heapsize))
	{
		swap(heap[rSon], heap[i]);
		SiftUp((i - 1) / 2);
	}
}

void BinaryHeap::insert(int newData)
{
	int sup = heapsize + 1;
	int* sup_heap = new int[sup];
	for (int i = 0; i < heapsize; i++)
	{
		sup_heap[i] = heap[i];
	}
	delete[] heap;
	int parrent = (heapsize - 1) / 2;
	heapsize++;
	int support = heapsize - 1;
	sup_heap[support] = newData;
	heap = sup_heap;
	SiftUp(parrent);
}

void BinaryHeap::remove(int key)
{
	if (heapsize != 0)
	{
		int NewSize = heapsize - 1;
		swap(heap[key], heap[NewSize]);
		int* sup_heap = new int[NewSize];
		for (int i = 0; i < NewSize; i++)
		{
			sup_heap[i] = heap[i];
		}
		delete[]heap;
		heap = sup_heap;
		heapsize--;
		SiftUp(key);
	}
}

BinaryHeap::Stack::Stack()
{
	size = 0;
	top = 0;
}
BinaryHeap::Stack::~Stack()
{
	while (!IsEmpty())
	{
		pop();
	}
}
void BinaryHeap::Stack::push(int data)
{
	node* curr = new node;
	curr->data = data;

	curr->prev = top;
	top = curr;
	size++;
}

void BinaryHeap::Stack::pop()
{
	if (!IsEmpty())
	{
		node* prev = top->prev;
		delete top;
		top = prev;
		size--;
	}
	
}

bool BinaryHeap::Stack::IsEmpty()
{
	if (top == 0) return true;
	else return false;
}

int BinaryHeap::Stack::GetTop()
{
	if (!IsEmpty())
	{
		return top->data;
	}
}

Iterator* BinaryHeap::create_bft_iterator()
{
	return new bft_iterator(heap, heapsize);
}

bool BinaryHeap::bft_iterator::has_next()
{
	if (Current < HeapSize-1) return true;
	else return false;
}

int BinaryHeap::bft_iterator::next()
{
	if (has_next())
	{

		if (sup == 0)
		{
			sup = 1;
			return Curheap[Current];
		}
		else
		{
			Current++;
			return Curheap[Current];
		}
	}
}
Iterator* BinaryHeap::create_dft_iterator()
{
	return new dft_iterator(heap, heapsize);
}
int BinaryHeap::dft_iterator::next()
{
	int lastKey = stack.GetTop();
	stack.pop();
	if ((2 * lastKey + 2) < Heapsize)
	{
		int rSon = 2 * lastKey + 2;
		stack.push(rSon);
	}
	if ((2 * lastKey + 1) < Heapsize)
	{
		int lSon = 2 * lastKey + 1;
		stack.push(lSon);
	}
	return	Curheap[lastKey];
}
bool BinaryHeap::dft_iterator::has_next()
{
	return (stack.IsEmpty() == false);
}
