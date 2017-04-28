// task5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "BST.cpp"

int main()
{
	BST::Tree<int, std::string> tree;
	std::string value;
	int key;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "Key: ";
		std::cin >> key;
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Value: ";
		std::getline(std::cin, value);
		tree.insert(key, value);
	}
	std::cout << tree << std::endl;

	auto i = tree.begin();
	++i;
	std::cout << (*i) << std::endl;
	i--;
	std::cout << (*i) << std::endl;
    return 0;
}

