#include "stdafx.h"

#include "Interface.h"
#include "TextFile.cpp"
#include "BinaryFile.cpp"
#include "BST.cpp"
#include "MenuItem.h"

const std::string DEFAULT_FILE_NAME = "tree.txt";

template<class T>
void Interface<T>::work(T & param)
{
	BST::Tree<T> tree;
	Validator validator;
	std::string filename = typeid(T).name();
	filename = filename.substr(12, filename.length() - 12);
	file::TextFile<BST::Tree<T>> file(filename + ".txt");
	file::BinaryFile<std::vector<T>> binfile(filename + ".bin");
	int choice;
	int key;

	std::string choiceString = "Choose: \n1 - Add \n2 - Find \n3 - View \n4 - Delete \n5 - Clear \n6 - Backup \n7 - Restore \n8 - Archivate \n9 - Unarchivate \n0 - Quit\n";

	while (true)
	{
		validator.checkedNumericalInput(choice, choiceString);
		switch ((MenuItem) choice)
		{
		case MenuItem::ADD:
			std::cin >> param;
			tree.insert(param);
			break;
		case MenuItem::FIND:
			std::cout << "Input key to find - computer's code:  " << std::endl;
			std::cin >> key;
			if (tree.findElem(key) != nullptr)
				std::cout << "Found!" << std::endl;
			else
				std::cout << "Not found!" << std::endl;
			break;
		case MenuItem::VIEW:
			if (!tree.empty())
				param.header();
			std::cout << tree << std::endl;
			break;
		case MenuItem::DELETE:
			std::cout << "Input key to delete - computer's code" << std::endl;
			std::cin >> key;
			if (tree.findElem(key) != nullptr)
			{
				tree.deleteNode(key);
				std::cout << "Deleted!" << std::endl;
			}
			else
				std::cout << "Not found!" << std::endl;
			break;
		case MenuItem::CLEAR:
			tree.cleanup();
			break;
		case MenuItem::BACKUP:
			if (!tree.empty())
				file.write(tree);
			else
				std::cout << "Nothing to backup!" << std::endl;
			break;
		case MenuItem::RESTORE:
			if (file.exists() && !file.empty())
				file.read(tree);
			else
				std::cout << "No backup yet!" << std::endl;
			break;
		case MenuItem::BACKUP_BIN:
			if (!tree.empty())
				binfile.write(tree.prepare());
			else
				std::cout << "Nothing to archivate!" << std::endl;
			break;
		case MenuItem::RESTORE_BIN:
			if (binfile.exists() && !binfile.empty())
			{
				std::vector<T> vine;
				binfile.read(vine);
				for (auto i = vine.begin(); i != vine.end(); i++)
					tree.insert(*i);
			}
			else
				std::cout << "No archive yet!" << std::endl;
			break;
		case MenuItem::EXIT:
			return;
		}
	}
}