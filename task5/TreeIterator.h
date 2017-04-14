#pragma once

#include "BST.cpp"

namespace BST {
	template<class T>
	class TreeIterator
	{
	private:
		Node<T> * cursor;
		std::stack<T> keys;
	public:
		TreeIterator() {};
		TreeIterator(Node<T> * node)
		{
			cursor = node;
			postorder(node);
		};
		T operator*();
		void postorder(Node<T> *);
		bool begin();
		bool end();
		bool operator==(TreeIterator&);
		bool operator!=(TreeIterator&);
		bool operator++(TreeIterator&);
		bool operator--(TreeIterator&);
		~TreeIterator()
		{
			delete cursor;
		};
	};
}

