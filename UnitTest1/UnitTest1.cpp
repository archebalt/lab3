#include "pch.h"
#include "CppUnitTest.h"
#include "../лаба3_аистд_3сем/heap.h"
#include "../лаба3_аистд_3сем/heap.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		BinaryHeap tree;
		TEST_METHOD(insertAndBftOperator)
		{
			tree.insert(7);
			tree.insert(5);
			tree.insert(15);
			tree.insert(20);
			tree.insert(3);
			tree.insert(4);
			tree.insert(6);
			Iterator* iter = tree.create_bft_iterator();
			Assert::AreEqual(iter->next(), 3);
			Assert::AreEqual(iter->next(), 5);
			Assert::AreEqual(iter->next(), 4);
			Assert::AreEqual(iter->next(), 20);
			Assert::AreEqual(iter->next(), 7);
			Assert::AreEqual(iter->next(), 15);
			Assert::AreEqual(iter->next(), 6);
		}
		TEST_METHOD(insertAndDftOperator)
		{
			tree.insert(7);
			tree.insert(5);
			tree.insert(15);
			tree.insert(20);
			tree.insert(3);
			tree.insert(4);
			tree.insert(6);
			Iterator* iter = tree.create_dft_iterator();
			Assert::AreEqual(iter->next(), 3);
			Assert::AreEqual(iter->next(), 5);
			Assert::AreEqual(iter->next(), 20);
			Assert::AreEqual(iter->next(), 7);
			Assert::AreEqual(iter->next(), 4);
			Assert::AreEqual(iter->next(), 15);
			Assert::AreEqual(iter->next(), 6);
		}
		TEST_METHOD(insertAndRemove)
		{
			tree.insert(7);
			tree.insert(5);
			tree.insert(15);
			tree.insert(20);
			tree.insert(3);
			tree.insert(4);
			tree.insert(6);
			tree.remove(1);
			Iterator* iter = tree.create_bft_iterator();
			Assert::AreEqual(iter->next(), 3);
			Assert::AreEqual(iter->next(), 6);
			Assert::AreEqual(iter->next(), 4);
			Assert::AreEqual(iter->next(), 20);
			Assert::AreEqual(iter->next(), 7);
			Assert::AreEqual(iter->next(), 15);
		}
		TEST_METHOD(insertAndRemoveAgain)
		{
			tree.insert(13);
			tree.insert(17);
			tree.insert(5);
			tree.remove(0);
			tree.insert(6);
			tree.insert(1);
			Iterator* iter = tree.create_dft_iterator();
			Assert::AreEqual(iter->next(), 1);
			Assert::AreEqual(iter->next(), 6);
			Assert::AreEqual(iter->next(), 17);
			Assert::AreEqual(iter->next(), 13);
		}
		TEST_METHOD(insertAndContainsAndRemove)
		{
			tree.insert(2);
			tree.insert(5);
			tree.insert(8);
			tree.insert(6);
			tree.remove(2);
			tree.insert(10);
			tree.insert(4);
			Iterator* iter = tree.create_bft_iterator();
			Assert::AreEqual(iter->next(), 2);
			Assert::AreEqual(iter->next(), 4);
			Assert::AreEqual(iter->next(), 6);
			Assert::AreEqual(iter->next(), 10);
			Assert::AreEqual(iter->next(), 5);
			Assert::IsFalse(tree.contains(8));
		}
		TEST_METHOD(InsertAndRemvoe)
		{
			tree.insert(10);
			tree.insert(9);
			tree.insert(8);
			tree.insert(13);
			tree.insert(15);
			tree.remove(3);
			tree.remove(2);
			Iterator* iter = tree.create_dft_iterator();
			Assert::AreEqual(iter->next(), 8);
			Assert::AreEqual(iter->next(), 10);
			Assert::AreEqual(iter->next(), 15);
		}
	};
}
