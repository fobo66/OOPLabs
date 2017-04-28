#pragma once
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
		Tree<K, T> * collection;
	public:
		TreeIterator()
		{
			collection = new Tree<K, T>();
			cursor = nullptr;
		};
		TreeIterator(const Tree<K, T> & tree, int beginOrEnd = BEGIN_ITER)
		{
			collection = new Tree<K, T>();
			collection->copy(tree._root);
			if (beginOrEnd == BEGIN_ITER)
				cursor = tree.min(tree._root);
			else if (beginOrEnd == END_ITER)
				cursor = nullptr;
		};
		T operator*();
		bool operator==(TreeIterator&);
		bool operator!=(TreeIterator&);
		TreeIterator<K, T> operator++();
		TreeIterator<K, T> operator++(int);
		TreeIterator<K, T> operator--();
		TreeIterator<K, T> operator--(int);

		TreeIterator<K, T> begin();
		TreeIterator<K, T> end();

		~TreeIterator()
		{
			collection->cleanup();
			cursor = nullptr;
		};
	};

	template<class K, class T>
	class Tree
	{
	private:
		Node<K, T> * _root; // ��������� �� �������� ����
		// �������� ����
		void deleteNode(Node<K, T>* p);
		friend class TreeIterator<K, T>;
		// ����� ������ �� ����� ���, ��� ����
		void show(Node<K, T> * node);

		// ����� � ����
		void fshow(Node<K, T> * node, std::fstream & stream);
	
		// ����� ��� ���������� ����������� ������� ��� �����������
		// ������ ���������� ����
		Node<K, T> * findSuccessor(K id);

		//����� ���� � �������� ������
		Node<K, T> * findElem(K id, Node<K, T> * node);

		// ����������� ������
		void copy(Node<K, T> *);

		// �������������� ������ � ������ 
		void prepare(Node<K, T> * node, std::vector<T> & temp) const;

		//�������� ���� �����
		void cleanup(Node<K, T> * node);

		Node<K, T> * min(Node<K, T> *) const;
		Node<K, T> * max(Node<K, T> *) const;

	public:
		// �����������
		Tree()
		{
			this->_root = nullptr;
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

		// ������� ���� � ������
		void insert(K id, T data);

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		void deleteNode(K id);

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		std::vector<T> prepare();

		//���������� ��������� ������
		friend std::ostream& operator<<(std::ostream & stream, Tree & root)
		{
			if (root._root != nullptr)
				for (auto i = root.begin(); i != root.end(); ++i)
					stream << (*i) << std::endl;
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
			K key;
			while (true)
			{
				if (stream.eof()) break;
				stream >> key >> item;
				root.insert(key, item);
			}

			return stream;
		};

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		void cleanup();

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		Node<K, T> * findElem(K id);

		// ���������
		TreeIterator<K, T> begin() const;
		TreeIterator<K, T> end() const;

		bool empty();

		// ����������
		~Tree()
		{
			cleanup();
		};
	};
}