#include "stdafx.h"

#include "BST.h"

using namespace BST;

template <class T>
void Tree<T>::insert(T data)
{
	Node<T>* tmp = new Node<T>;
	tmp->key = data;
	tmp->id = tmp->key.getCode();
	tmp->left = nullptr;
	tmp->right = nullptr;

	if (this->empty())
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
			cElem = (tmp->id < cElem->id) ? cElem->left : cElem->right;
		}

		tmp->parent = parent;

		if (tmp->id < parent->id)
			parent->left = tmp;
		else
			parent->right = tmp;
	}
};

template <class T>
void Tree<T>::deleteNode(int id)
{
	if (!this->empty())
		this->deleteNode(this->findElem(id));
	else
		std::cout << "Tree is empty!" << std::endl;
};

template<class T>
std::vector<T> BST::Tree<T>::prepare()
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

template<class T>
Tree<T> BST::Tree<T>::operator=(const Tree<T>& root)
{
	if (this != &root)
		this->copy(root._root);
	return *this;
};

template <class T>
void Tree<T>::cleanup()
{
	if (!this->empty())
	{
		cleanup(this->_root);
		this->_root = nullptr;
		std::cout << "Cleared" << std::endl;
	}
};

template <class T>
Node<T> * Tree<T>::findElem(int id)
{
	if (!this->empty())
		return this->findElem(id, this->_root);
	else
	{
		std::cout << "Tree is empty!" << std::endl;
		return nullptr;
	}
}

template<class T>
bool BST::Tree<T>::empty()
{
	return this->_root == nullptr;
}

template <class T>
void Tree<T>::deleteNode(Node<T>* p)
{
	Node<T> *q = nullptr;
	Node<T> *r = nullptr;

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
};

template <class T>
void Tree<T>::show(Node<T> * node, int indent)
{
	if (node != nullptr)
	{
		if (node->right)
			show(node->right, indent + 4);

		std::cout << node->key << std::endl;

		if (node->left) 
			show(node->left, indent + 4);
	}
}
template<class T>
void BST::Tree<T>::fshow(Node<T>* node, std::fstream& stream, int indent)
{
	if (node != nullptr)
	{
		if (node->right)
			fshow(node->right, stream, indent + 4);

		stream << node->key;

		if (node->left) 
			fshow(node->left, stream, indent + 4);
	}
}
;

template <class T>
Node<T> * Tree<T>::findSuccessor(int id)
{
	Node<T>* startNode = this->findElem(id);
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
Node<T> * Tree<T>::findElem(int id, Node<T> * node)
{
	if (node != nullptr)
	{
		if (id == node->id)
			return node;

		if (id < node->id)
			return findElem(id, node->left);
		else
			return findElem(id, node->right);
	}
	else
		return nullptr;
};

template<class T>
void BST::Tree<T>::copy(Node<T> * node)
{
	if (node != nullptr)
	{
		if (node->left)
			this->copy(node->left);
		this->insert(node->key);

		if (node->right)
			this->copy(node->right);
	}
};

template<class T>
void BST::Tree<T>::prepare(Node<T>* node, std::vector<T>& temp) const
{
	if (node != nullptr)
	{
		if (node->left)
			prepare(node->left, temp);

		temp.push_back(std::move(node->key));

		if (node->right != nullptr)
			prepare(node->right, temp);
	}
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