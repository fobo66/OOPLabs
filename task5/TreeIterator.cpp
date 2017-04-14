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
        
		this->keys.push(node->key);
	}
}

template<class T>
bool BST::TreeIterator<T>::operator==(TreeIterator & another) 
{
    return this->keys.pop() == another.keys.pop();
}

template<class T>
bool BST::TreeIterator<T>::operator!=(TreeIterator & another) 
{
    return !this->operator==();
}

template<class T>
T BST::TreeIterator<T>::operator*()
{
    return cursor->key;
}

template<class T>
TreeIterator<T> BST::TreeIterator<T>::begin()
{
    return cursor->key;
}