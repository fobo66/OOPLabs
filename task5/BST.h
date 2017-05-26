#pragma once

#include "BSTAlgorithm.h"

#define BEGIN_ITER 1
#define END_ITER 2
namespace BST {

	template<class K, class T>
	class Tree;

	template<class K, class T>
	struct Node {
		Node *parent;
		T key;
		K id;
		Node *left;
		Node *right;
	};

	template<class K, class T>
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
		Node<K, T> * cursor;
		Node<K, T> * rightMost;
		friend class Tree<K, T>;
		Node<K,T> * operator&();
	public:
		TreeIterator()
		{
			cursor = nullptr;
			rightMost = nullptr;
		};
		TreeIterator(const Tree<K, T> & tree, int beginOrEnd = BEGIN_ITER)
		{
			if (beginOrEnd == BEGIN_ITER)
			{
				cursor = tree.min(tree._root);
				rightMost = tree.max(tree._root);
			}
			else if (beginOrEnd == END_ITER)
			{
				cursor = nullptr;
				rightMost = nullptr;
			}
		};

		TreeIterator(const TreeIterator<K, T> &another)
		{
			this->cursor = another.cursor;
			this->rightMost = another.rightMost;
		}
		std::pair<K, T> operator*();
		bool operator==(TreeIterator&);
		bool operator!=(TreeIterator&);
		TreeIterator<K, T> operator=(const TreeIterator<K, T> &);
		TreeIterator<K, T> operator++();
		TreeIterator<K, T> operator++(int);
		TreeIterator<K, T> operator+(int);
		TreeIterator<K, T> operator--();
		TreeIterator<K, T> operator--(int);
		TreeIterator<K, T> operator-(int);

		~TreeIterator()
		{
			cursor = nullptr;
			rightMost = nullptr;
		};
	};

	template<class K, class T>
	class TreeReverseIterator {
	private:
		TreeIterator<K, T> iter;
	public:
		typedef TreeReverseIterator<K, T> self;
		TreeReverseIterator() {};
		TreeReverseIterator(const TreeIterator<K, T> & iter)
		{
			this->iter = iter;
		};

		std::pair<K, T> operator*();
		bool operator==(self&);
		bool operator!=(self&);
		self operator=(const self &);
		self operator++();
		self operator++(int);
		self operator--();
		self operator--(int);

		~TreeReverseIterator() {};
	};

	template<class K, class T>
	class Tree
	{
	private:
		Node<K, T> * _root; // указатель на корневой узел
		size_t _size;
		// Удаление узла
		void deleteNode(Node<K, T>* p);
		friend class TreeIterator<K, T>;
		// Вывод дерева на экран так, как надо
		void show(Node<K, T> * node);

		// Вывод в файл
		void fileOutput(Node<K, T> * node, std::fstream & stream);
	
		// Метод для нахождения правильного потомка для подстановки
		// вместо удаляемого узла
		Node<K, T> * findSuccessor(K id);

		// Копирование дерева
		void copy(Node<K, T> *);

		// Разворачивание дерева в вектор 
		void prepare(Node<K, T> * node, std::vector<T> & temp) const;

		//Удаление всех узлов
		void cleanup(Node<K, T> * node);

		Node<K, T> * min(Node<K, T> *) const;
		Node<K, T> * max(Node<K, T> *) const;

	public:
		// Конструктор
		Tree()
		{
			this->_root = nullptr;
			_size = 0;
		};

		Tree(const Tree<K, T> &another) 
		{
			this->_root = another._root;
			if (another._root->left != nullptr)
				this->copy(another._root->left);
			if (another._root->right != nullptr)
				this->copy(another._root->right);
		};

		Tree<K, T> operator=(const Tree<K, T> &);

		// Вставка узла в дерево
		void insert(K id, T data);
		
		// Получение размера дерева
		size_t size() const;

		// Обёртка над приватной функцией, скрывающая от пользователей указатель на корневой узел
		void deleteNode(K id);

		// Обёртка над приватной функцией, скрывающая от пользователей указатель на корневой узел
		std::vector<T> prepare();

		//Перегрузка оператора вывода
		friend std::ostream& operator<<(std::ostream & stream, Tree & root)
		{
			if (root._root != nullptr)
				for (auto i = root.begin(); i != root.end(); ++i)
					stream << (*i).second << std::endl;
			else
				stream << "Tree is empty!" << std::endl;

			return stream;
		};

		friend std::fstream& operator<<(std::fstream & stream, Tree & root)
		{
			if (root._root != nullptr)
				root.fileOutput(root._root, stream);

			return stream;
		};

		friend std::fstream& operator>>(std::fstream & stream, Tree & root)
		{
			T item;
			K key;
			while (true)
			{
				if (stream.eof()) break;
				stream >> key >> item;
				root.insert(key, item);
			}

			return stream;
		};

		// Обёртка над приватной функцией, скрывающая от пользователей указатель на корневой узел
		void cleanup();

		// Итераторы
		TreeIterator<K, T> begin() const;
		TreeIterator<K, T> end() const;
		TreeReverseIterator<K, T> rbegin() const;
		TreeReverseIterator<K, T> rend() const;

		bool empty();

		// Деструктор
		~Tree()
		{
			cleanup();
		};
	};
}