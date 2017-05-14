#include "stdafx.h"

#include "Interface.h"
#include "MenuItem.h"

template<class T>
void Interface<T>::work(T & param)
{
	std::multimap<const int, T> tree;
	int choice;
	int key;

	std::string choiceString = 
		"Choose: \n1 - Add \n2 - Find \n3 - View \n4 - Delete \n5 - Clear \n0 - Quit\n";

	while (true)
	{
		Validator::checkedNumericalInput(choice, choiceString);
		switch ((MenuItem) choice)
		{
		case MenuItem::ADD:
			std::cin >> param;
			if (param.getCode() != 0)
				tree.insert(std::pair<const int, T>(param.getCode(), param));
			else
				std::cout << "Tree cannot contain keys equal to 0!" << std::endl;
			break;
		case MenuItem::FIND:
			Validator::checkedNumericalInput(key,
				"Input key to find");
			if (tree.count(key) != 0)
				std::cout << (*tree.find(key)).second << std::endl;
			else
				std::cout << "Not found!" << std::endl;
			break;
		case MenuItem::VIEW:
			if (!tree.empty())
				param.header();
			for (auto i = tree.cbegin(); i != tree.cend(); ++i)
				std::cout << (*i).second << std::endl;
			break;
		case MenuItem::DELETE:
			Validator::checkedNumericalInput(key, "Input key to delete - computer's code:  ");
			if (tree.count(key) != 0)
			{
				tree.erase(key);
				std::cout << "Deleted!" << std::endl;
			}
			else
				std::cout << "Not found!" << std::endl;
			break;
		case MenuItem::CLEAR:
			tree.clear();
			break;
		case MenuItem::EXIT:
			return;
		}
	}
}
