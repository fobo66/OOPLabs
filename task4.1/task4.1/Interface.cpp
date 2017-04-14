#include "stdafx.h"

#include "Interface.h"
#include "BST.cpp"

template<class T>
void Interface<T>::work(T & param)
{
	BST::Tree<T> tree;
	int choice;

	while (true)
	{
		std::cout << "Choose:\n" <<
			"\t1 - Add" <<
			"\t2 - Find" <<
			"\t3 - View" <<
			"\t4 - Delete" <<
			"\t5 - Clear" <<
			"\t0 - Quit" <<
			std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			std::cout << "Input some key:  " << std::endl;
			std::cin >> param;
			tree.insert(param);
			break;
		case 2:
			std::cout << "Input key to find:  " << std::endl;
			std::cin >> param;
			if (tree.findElem(param) != nullptr)
				std::cout << "Found!" << std::endl;
			else
				std::cout << "Not found!" << std::endl;
			break;
		case 3:
			std::cout << tree << std::endl;
			break;
		case 4:
			std::cout << "Input key to delete:  " << std::endl;
			std::cin >> param;
			if (tree.findElem(param) != nullptr)
			{
				tree.deleteNode(param);
				std::cout << "Deleted!" << std::endl;
			}
			else
				std::cout << "Not found!" << std::endl;
			break;
		case 5:
			tree.cleanup();
			std::cout << "Cleared" << std::endl;
			break;
		case 0:
			return;
		}
	}
}