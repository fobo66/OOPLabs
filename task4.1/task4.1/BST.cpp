#include "stdafx.h"

#include "BST.h"

using namespace BST;

template <class T>
void Tree<T>::insert(T data)
{
	Node<T>* tmp = new Node<T>;
	tmp->key = data;
	tmp->left = nullptr;
	tmp->right = nullptr;

	if (this->_root == nullptr)
	{
		tmp->parent = nullptr;
		this->_root = tmp;
	}
	else {
		Node<T>* cElem = this->_root;
		Node<T>* parent = nullptr;

		while (cElem != nullptr)
		{
			parent = cElem;
			cElem = (data < cElem->key) ? cElem->left : cElem->right;
		}

		tmp->parent = parent;

		if (data < parent->key)
			parent->left = tmp;
		else
			parent->right = tmp;
	}
};

template <class T>
void Tree<T>::deleteNode(T val)
{
	this->deleteNode(this->findElem(val));
};

template <class T>
std::ostream& operator<<(std::ostream & stream, Tree<T> & root)
{
	if (root._root != nullptr)
		root.show(root._root, 0);
	else
		stream << "Tree is empty!" << std::endl;

	return stream;
};

template <class T>
void Tree<T>::cleanup()
{
	cleanup(this->_root);
	this->_root = nullptr;
};

template <class T>
Node<T> * Tree<T>::findElem(T val)
{
	return this->findElem(val, this->_root);
}

template <class T>
void Tree<T>::deleteNode(Node<T>* p)
{
	Node<T> *q = nullptr;
	Node<T> *r = nullptr;

	if (p->left == nullptr || p->right == nullptr)
		q = p;
	else
		q = this->findSuccessor(p->key);

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
		p->key = q->key;
};

template <class T>
void Tree<T>::show(Node<T> * node, int indent)
{
	if (node != nullptr)
	{
		if (node->right)
			show(node->right, indent + 4);

		if (indent)
			std::cout << std::setw(indent) << ' ';

		if (node->right) 
			std::cout << " /\n" << std::setw(indent) << ' ';

		std::cout << node->key << "\n ";

		if (node->left) 
		{
			std::cout << std::setw(indent) << ' ' << " \\\n";
			show(node->left, indent + 4);
		}
	}
};

template <class T>
Node<T> * Tree<T>::findSuccessor(T val)
{
	Node<T>* startNode = this->findElem(val);
	Node<T>* parent = startNode;

	startNode = startNode->right;
	while (startNode != nullptr && startNode->left != nullptr)
	{
		parent = startNode;
		startNode = startNode->left;
	}

	return startNode;
};

template <class T>
Node<T> * Tree<T>::findElem(T val, Node<T> * node)
{
	if (node != nullptr)
	{
		if (val == node->key)
			return node;

		if (val < node->key)
			return findElem(val, node->left);
		else
			return findElem(val, node->right);
	}
	else
		return nullptr;
};

template <class T>
void Tree<T>::cleanup(Node<T> * node)
{
	if (node != nullptr)
	{
		cleanup(node->left);
		cleanup(node->right);
		delete node;
	}
};
