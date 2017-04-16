#pragma once

#include "BST.cpp"

namespace BST {
	template<class T>
	class TreeIterator
		: public std::iterator<
			std::bidirectional_iterator_tag,
			T,
			int,
			const T*,
			T&
		>
	{
	private:
		Node<T> cursor;
		Node<T> previous;
		Tree<T> collection;
		std::list<T> keys;
	public:
		TreeIterator(Tree<T> & tree)
		{
			collection = tree;
			previous = nullptr;
			position = 0;
			cursor = keys.front();
		};
		T& operator*();
		void postorder(Node<T> *);
		bool operator==(TreeIterator&);
		bool operator!=(TreeIterator&);
		TreeIterator<T> operator++();
		TreeIterator<T> operator++(int);
		TreeIterator<T> operator--();

		TreeIterator<T> begin();
		TreeIterator<T> end();
		TreeIterator<T> rbegin();
		TreeIterator<T> rend();

		~TreeIterator() {};
	};
}

