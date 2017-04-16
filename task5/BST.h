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
		Node<T> * _root; // ��������� �� �������� ����
		friend class TreeIterator;
		// �������� ����
		void deleteNode(Node<T>* p);

		// ����� ������ �� ����� ���, ��� ����
		void show(Node<T> * node, int level);

		// ����� � ����
		void fshow(Node<T> * node, std::fstream & stream, int level);
	
		// ����� ��� ���������� ����������� ������� ��� �����������
		// ������ ���������� ����
		Node<T> * findSuccessor(int id);

		//����� ���� � �������� ������
		Node<T> * findElem(int id, Node<T> * node);

		// ����������� ������
		void copy(Node<T> *);

		// �������������� ������ � ������ 
		void prepare(Node<T> * node, std::vector<T> & temp) const;		

		//�������� ���� �����
		void cleanup(Node<T> * node);	

		Node<T> * min(Node<T> *);
		Node<T> * max(Node<T> *);

		// ���������
		TreeIterator<T> begin();
		TreeIterator<T> end();
	public:
		// �����������
		Tree()
		{
			this->_root = nullptr;
		};

		Tree<T> operator=(const Tree<T> &);

		// ������� ���� � ������
		void insert(T data);

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		void deleteNode(int id);

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		std::vector<T> prepare();

		//���������� ��������� ������
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

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		void cleanup();

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		Node<T> * findElem(int id);

		bool empty();

		// ����������
		~Tree()
		{
			cleanup();
		};
	};

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
		Tree<T> collection;
		std::list<T> keys;
	public:
		TreeIterator(const Tree<T> & tree)
		{
			collection = tree;
			cursor = tree.min(tree._root);
		};
		T& operator*();
		void postorder(Node<T> *);
		bool operator==(TreeIterator&);
		bool operator!=(TreeIterator&);
		TreeIterator<T> operator++();
		TreeIterator<T> operator++(int);
		TreeIterator<T> operator--();
		TreeIterator<T> operator--(int);

		TreeIterator<T> begin();
		TreeIterator<T> end();

		~TreeIterator() {};
	};
}