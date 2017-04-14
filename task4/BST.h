#pragma once

namespace BST {

	template<class T>
	struct Node {
		Node *parent;
		T key;
		int id;
		Node *left;
		Node *right;
	};

	template<class T>
	class Tree
	{
	private:
		Node<T> * _root; // указатель на корневой узел

		// Удаление узла
		void deleteNode(Node<T>* p);

		// Вывод дерева на экран так, как надо
		void show(Node<T> * node, int level);

		// Вывод в файл
		void fshow(Node<T> * node, std::fstream & stream, int level);
	
		// Метод для нахождения правильного потомка для подстановки
		// вместо удаляемого узла
		Node<T> * findSuccessor(int id);

		//Поиск узла с заданным ключом
		Node<T> * findElem(int id, Node<T> * node);

		// Копирование дерева
		void copy(Node<T> *);

		// Разворачивание дерева в вектор 
		void prepare(Node<T> * node, std::vector<T> & temp) const;

		//Удаление всех узлов
		void cleanup(Node<T> * node);	
	public:
		// Конструктор
		Tree()
		{
			this->_root = nullptr;
		};

		Tree<T> operator=(const Tree<T> &);

		// Вставка узла в дерево
		void insert(T data);

		// Обёртка над приватной функцией, скрывающая от пользователей указатель на корневой узел
		void deleteNode(int id);

		// Обёртка над приватной функцией, скрывающая от пользователей указатель на корневой узел
		std::vector<T> prepare();

		//Перегрузка оператора вывода
		friend std::ostream& operator<<(std::ostream & stream, Tree & root)
		{
			if (root._root != nullptr)
				root.show(root._root, 0);
			else
				stream << "Tree is empty!" << std::endl;

			return stream;
		};

		friend std::fstream& operator<<(std::fstream & stream, Tree & root)
		{
			if (root._root != nullptr)
				root.fshow(root._root, stream, 0);

			return stream;
		};

		friend std::fstream& operator>>(std::fstream & stream, Tree & root)
		{
			T item;
			while (true)
			{
				if (stream.eof()) break;
				stream >> item;
				root.insert(item);
			}

			return stream;
		};

		// Обёртка над приватной функцией, скрывающая от пользователей указатель на корневой узел
		void cleanup();

		// Обёртка над приватной функцией, скрывающая от пользователей указатель на корневой узел
		Node<T> * findElem(int id);

		bool empty();

		// Деструктор
		~Tree()
		{
			cleanup();
		};
	};
}