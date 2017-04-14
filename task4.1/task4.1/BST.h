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
		Node<T> * _root; // ��������� �� �������� ����

		// �������� ����
		void deleteNode(Node<T>* p);

		// ����� ������ �� ����� ���, ��� ����
		void show(Node<T> * node, int level);
	
		// ����� ��� ���������� ����������� ������� ��� �����������
		// ������ ���������� ����
		Node<T> * findSuccessor(T val);

		//����� ���� � �������� ������
		Node<T> * findElem(T val, Node<T> * node);

		//�������� ���� �����
		void cleanup(Node<T> * node);	
	public:
		// �����������
		Tree()
		{
			this->_root = nullptr;
		};

		// ������� ���� � ������
		void insert(T data);

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		void deleteNode(T val);

		//���������� ��������� ������
		template<class T>
		friend std::ostream& operator<<(std::ostream & stream, Tree & root)
		{
			if (root._root != nullptr)
				root.show(root._root, 0);
			else
				stream << "Tree is empty!" << std::endl;

			return stream;
		};

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		void cleanup();

		// ������ ��� ��������� ��������, ���������� �� ������������� ��������� �� �������� ����
		Node<T> * findElem(T val);

		// ����������
		~Tree()
		{
			cleanup();
		};
	};
}