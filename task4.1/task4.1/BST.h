#pragma once

namespace BST 
{

	template<class T>
	struct Node {
		Node *parent;
		T key;
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
	
		// Метод для нахождения правильного потомка для подстановки
		// вместо удаляемого узла
		Node<T> * findSuccessor(T val);

		//Поиск узла с заданным ключом
		Node<T> * findElem(T val, Node<T> * node);

		//Удаление всех узлов
		void cleanup(Node<T> * node);	
	public:
		// Конструктор
		Tree()
		{
			this->_root = nullptr;
		};

		// Вставка узла в дерево
		void insert(T data);

		// Обёртка над приватной функцией, скрывающая от пользователей указатель на корневой узел
		void deleteNode(T val);

		//Перегрузка оператора вывода
		template<class T>
		friend std::ostream& operator<<(std::ostream & stream, Tree & root)
		{
			if (root._root != nullptr)
				root.show(root._root, 0);
			else
				stream << "Tree is empty!" << std::endl;

			return stream;
		};

		// Обёртка над приватной функцией, скрывающая от пользователей указатель на корневой узел
		void cleanup();

		// Обёртка над приватной функцией, скрывающая от пользователей указатель на корневой узел
		Node<T> * findElem(T val);

		// Деструктор
		~Tree()
		{
			cleanup();
		};
	};
}