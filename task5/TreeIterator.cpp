#include "stdafx.h"
#include "TreeIterator.h"

template<class T>
void BST::TreeIterator<T>::postorder(Node<T>* node)
{
	if (node != nullptr)
	{
        if (node->left != nullptr)
		  postorder(node->left);
        if (node->right != nullptr)
		  postorder(node->right);
        
		this->keys.push_back(node->key);
	}
}

template<class T>
bool BST::TreeIterator<T>::operator==(TreeIterator & another) 
{
    return this->cursor == another.cursor;
}

template<class T>
bool BST::TreeIterator<T>::operator!=(TreeIterator & another) 
{
    return !(this->operator==());
}

template<class T>
BST::TreeIterator<T> BST::TreeIterator<T>::operator++()
{
	previous = cursor;
	position++;
	cursor = keys.begin();
	return *this;
}

template<class T>
BST::TreeIterator<T> BST::TreeIterator<T>::operator++(int)
{
	TreeIterator<T> old = *this;
	++(*this);
	return old;
}

template<class T>
BST::TreeIterator<T> BST::TreeIterator<T>::operator--()
{
	if (previous != nullptr && position > 0)
	{
		cursor = previous;
		keys.insert(position, previous);
		position--;
	}
}

template<class T>
std::list<T>::iterator BST::TreeIterator<T>::begin()
{
	return keys.begin();
}

template<class T>
T& BST::TreeIterator<T>::operator*()
{
    return cursor;
}