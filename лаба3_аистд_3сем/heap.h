#pragma once
#include "Iterator.h"
class BinaryHeap
{
private:
	int * heap;
	int heapsize;
public:
	BinaryHeap();
	~BinaryHeap();
	void SiftUp(int);
	bool contains(int); // поиск элемента в дереве по ключу
	void insert(int); // добавление элемента в дерево по ключу
	void remove(int);  // удаление элемента дерева по ключу
	Iterator *create_dft_iterator();// создание итератора, реализующего один из методов обхода в глубину (depth-first traverse)
	Iterator* create_bft_iterator(); // создание итератора, реализующего методы обхода в ширину (breadth-first traverse)
	class Stack
	{
	private:
		class node
		{
		public:
			int data; 
			node* next;
			node* prev;
		};
		node* top;
		int size;
	public:
		Stack();
		~Stack();
		void push(int); // добавление в конец списка
		void pop(); // удаление последнего элемент
		int GetTop();
		bool IsEmpty();
	};
	class bft_iterator : public Iterator
	{
	public:
		bft_iterator(int *heap, int heapSize)
		{
			Curheap = heap;
			HeapSize = heapSize;
			Current = 0;
			sup = 0;
		}
		int next() override;
		bool has_next() override;
	private:
		int Current;
		int HeapSize;
		int *Curheap;
		int sup;
	};
	class dft_iterator : public Iterator
	{
	public:
		dft_iterator(int* start, int  heapSize)
		{
			Curheap = start;
			Heapsize = heapSize;
			stack.push(0);
		};
		int next() override;
		bool has_next() override;
	private:
		Stack stack;
		int* Curheap;
		int Heapsize;
	};
};