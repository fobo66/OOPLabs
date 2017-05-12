#include "stdafx.h"

#include "BST.h"


using namespace BST;

template <class K, class T>
void Tree<K,T>::insert(K id, T data)
{
	Node<K, T>* tmp = new Node<K, T>;
	tmp->key = data;
	tmp->id = id;
	tmp->left = nullptr;
	tmp->right = nullptr;

	if (this->empty())
	{
		tmp->parent = nullptr;
		this->_root = tmp;
	}
	else {
		Node<K, T>* cElem = this->_root;
		Node<K, T>* parent = nullptr;

		while (cElem != nullptr)
		{
			parent = cElem;
			cElem = (tmp->id < cElem->id) ? cElem->left : cElem->right;
		}

		tmp->parent = parent;

		if (tmp->id < parent->id)
			parent->left = tmp;
		else
			parent->right = tmp;
	}
	_size++;
}
template<class K, class T>
size_t BST::Tree<K, T>::size() const
{
	return _size;
}
;

template <class K, class T>
void Tree<K, T>::deleteNode(K id)
{
	if (!this->empty())
		this->deleteNode(&(Algorithm::find(begin(), end(), id)));
	else
		std::cout << "Tree is empty!" << std::endl;
};

template<class K, class T>
std::vector<T> BST::Tree<K, T>::prepare()
{
	std::vector<T> temp;
	//разворачиваем дерево в вектор, чтобы сохранить данные в файл
	if (_root != nullptr)
	{
		prepare(_root, temp);
		return temp;
	}
	return std::vector<T>();
};

template<class K, class T>
Tree<K, T> BST::Tree<K, T>::operator=(const Tree<K, T>& root)
{
	if (this != &root)
	{
		this->_root = root._root;
		if (root._root->left != nullptr)
			this->copy(root._root->left);
		if (root._root->right != nullptr)
			this->copy(root._root->right);
	}
	return *this;
};

template <class K, class T>
void Tree<K, T>::cleanup()
{
	if (!this->empty())
	{
		cleanup(this->_root);
		this->_root = nullptr;
	}
};

template<class K, class T>
bool BST::Tree<K, T>::empty()
{
	return this->_root == nullptr;
}

template <class K, class T>
void Tree<K, T>::deleteNode(Node<K, T>* p)
{
	Node<K, T> *q = nullptr;
	Node<K, T> *r = nullptr;

	if (p->left == nullptr || p->right == nullptr)
		q = p;
	else
		q = this->findSuccessor(p->id);

	if (q->left != nullptr)
		r = q->left;
	else
		r = q->right;

	if (r != nullptr)
		r->parent = q->parent;

	if (q->parent == nullptr)
		this->_root = r;
	else if (q == q->parent->left)
		q->parent->left = r;
	else
		q->parent->right = r;

	if (q != p)
	{
		p->key = q->key;
		p->id = q->id;
	}

	_size--;
};

template <class K, class T>
void Tree<K, T>::show(Node<K, T> * node)
{
	if (node != nullptr)
	{
		if (node->right)
			show(node->right);

		std::cout << node->key << std::endl;

		if (node->left) 
			show(node->left);
	}
}
template<class K, class T>
void BST::Tree<K, T>::fileOutput(Node<K, T>* node, std::fstream& stream)
{
	if (node != nullptr)
	{
		if (node->right)
			fileOutput(node->right, stream);

		stream << node->id << node->key;

		if (node->left) 
			fileOutput(node->left, stream);
	}
}
;

template <class K, class T>
Node<K, T> * Tree<K, T>::findSuccessor(K id)
{
	Node<K, T>* startNode = &(Algorithm::find(begin(), end(), id));
	Node<K, T>* parent = startNode;

	startNode = startNode->right;
	while (startNode != nullptr && startNode->left != nullptr)
	{
		parent = startNode;
		startNode = startNode->left;
	}

	return startNode;
};

template<class K, class T>
void BST::Tree<K, T>::copy(Node<K, T> * node)
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
			this->copy(node->left);

		this->insert(node->id, node->key);

		if (node->right != nullptr)
			this->copy(node->right);
	}
};

template<class K, class T>
void BST::Tree<K, T>::prepare(Node<K, T>* node, std::vector<T>& temp) const
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
			prepare(node->left, temp);

		temp.push_back(std::move(node->key));

		if (node->right != nullptr)
			prepare(node->right, temp);
	}
};

template <class K, class T>
void Tree<K, T>::cleanup(Node<K, T> * node)
{
	if (node != nullptr)
	{
		cleanup(node->left);
		cleanup(node->right);
		delete node;
	}
};

template<class K, class T>
Node<K, T> * BST::Tree<K, T>::min(Node<K, T> * rootNode) const
{
	Node<K, T> * node = rootNode;
	if (node != nullptr)
		while (node->left != nullptr)
			node = node->left;

	return node;
};

template<class K, class T>
Node<K, T>* BST::Tree<K, T>::max(Node<K, T> *rootNode) const
{
	Node<K, T> *node = rootNode;
	if (node != nullptr)
		while (node->right != nullptr)
			node = node->right;

	return node;
};

template<class K, class T>
TreeIterator<K, T> BST::Tree<K, T>::begin() const
{
	return TreeIterator<K, T>(*this);
}
template<class K, class T>
TreeIterator<K, T> BST::Tree<K, T>::end() const
{
	return TreeIterator<K, T>(*this, END_ITER);
}
;
template<class K, class T>
bool BST::TreeIterator<K, T>::operator==(TreeIterator & another)
{
	if (cursor != nullptr && another.cursor != nullptr)
		return this->cursor->key == another.cursor->key;
	return this->cursor == another.cursor;
}

template<class K, class T>
bool BST::TreeIterator<K, T>::operator!=(TreeIterator & another)
{
	return !(this->operator==(another));
}

template<class K, class T>
BST::TreeIterator<K, T> BST::TreeIterator<K, T>::operator++()
{
	if (cursor == nullptr)
		;
	else if (cursor->right != nullptr)
	{
		cursor = cursor->right;
		while (cursor->left != nullptr)
			cursor = cursor->left;
	}
	else
	{
		Node<K, T> * tempNode = cursor->parent;
		while (tempNode != nullptr &&
			   cursor == tempNode->right)
		{
			cursor = tempNode;
			tempNode = tempNode->parent;
		}
		//if (cursor->right != tempNode)
			cursor = tempNode;
	}
	return *this;
}

template<class K, class T>
BST::TreeIterator<K, T> BST::TreeIterator<K, T>::operator++(int)
{
	TreeIterator<K, T> old = *this;
	++(*this);
	return old;
}

template<class K, class T>
TreeIterator<K, T> BST::TreeIterator<K, T>::operator+(int offset)
{
	int i = 0;
	while (i++ < offset)
		++(*this);
	return *this;
}

template<class K, class T>
BST::TreeIterator<K, T> BST::TreeIterator<K, T>::operator--()
{
	if (cursor == nullptr)
		cursor = collection->max(collection->_root);
	else if (cursor->left != nullptr)
		cursor = collection->max(cursor->left);
	else
	{
		Node<K, T> * tempNode;
		while ((tempNode = cursor->parent) != nullptr
			&& cursor == tempNode->left)
			cursor = tempNode;
		if (cursor == nullptr)
			;
		else
			cursor = tempNode;
	}

	return *this;
}

template<class K, class T>
BST::TreeIterator<K, T> BST::TreeIterator<K, T>::operator--(int)
{
	TreeIterator<K, T> old = *this;
	--(*this);
	return old;
}

template<class K, class T>
TreeIterator<K, T> BST::TreeIterator<K, T>::operator-(int offset)
{
	int i = 0;
	while (i++ < offset)
		--(*this);
	return *this;
}

template<class K, class T>
Node<K, T> * BST::TreeIterator<K, T>::operator&()
{
	return cursor;
}

template<class K, class T>
std::pair<K, T> BST::TreeIterator<K, T>::operator*()
{
	if (cursor != nullptr)
		return std::pair<K, T>(cursor->id, cursor->key);
	return std::pair<K, T>(0, T());
}