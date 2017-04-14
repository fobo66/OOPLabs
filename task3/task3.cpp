// task3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Laptop.h"
#include "Monoblock.h"
#include "Tablet.h"



int main()
{
	int choice = 0, innerChoice = 0, innerInnerChoice = 0; //переменные для switch
	int portToEdit = 0, appToEdit = 0, objToEdit = 0;
	int moreApps = 0;
	comp::Monoblock pc_arr[3];
	comp::Laptop laptop_arr[3];
	comp::Tablet tablet_arr[3];

	int manufactureYear;
	std::string os;
	int displaySize;
	std::string brand;
	std::string app;
	std::vector<std::string> appsInstalled;
	bool isUnlocked;
	float weight;
	bool isTouch;
	std::string ports[6];
	std::string vendor;
	std::string model;

	comp::Monoblock pc;
	comp::Laptop laptop;
	comp::Tablet tablet;

	int pcIndex = 0, laptopIndex = 0, tabletIndex = 0;
	
	while (true)
	{
		std::cout << "Choose:\n" <<
			"\t1 - Create" <<
			"\t2 - Edit" <<
			"\t3 - View" <<
			"\t0 - Quit" <<
		std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 1:

			std::cout << "Choose which object to create:\n" <<
				"\t1 - Monoblock PC" <<
				"\t2 - Laptop" <<
				"\t3 - Tablet PC" <<
				"\t0 - Quit" <<
				std::endl;

			std::cin >> innerChoice;
			switch (innerChoice)
			{
			case 1:
				std::cout << "Creating Monoblock PC" << std::endl;
				std::cin >> pc;
				pc_arr[pcIndex] = pc;
				pcIndex++;
				break;
			case 2:
				std::cout << "Creating Laptop" << std::endl;
				std::cin >> laptop;

				laptop_arr[laptopIndex] = laptop;
				laptopIndex++;
				break;
			case 3:
				std::cout << "Creating Tablet PC" << std::endl;
				std::cin >> tablet;

				tablet_arr[tabletIndex] = tablet;
				tabletIndex++;
				break;
			case 0:
			default:
				break;
			}
			
			break;
		case 2:
			std::cout << "Choose which object to edit:\n" <<
				"\t1 - Monoblock PC" <<
				"\t2 - Laptop" <<
				"\t3 - Tablet PC" <<
				"\t0 - Quit" <<
				std::endl;

			std::cin >> innerChoice;
			switch (innerChoice)
			{
			case 1:
				std::cout << "Editing PC" << std::endl;
				std::cout << "Which PC to edit (0 - 3)";
				std::cin >> objToEdit;
				if (objToEdit > pcIndex)
					objToEdit = pcIndex;
				pc = pc_arr[objToEdit];
				std::cout << "Choose what to edit:\n" <<
					"\t1 - Manufacture year" <<
					"\t2 - OS" <<
					"\t3 - Display size" <<
					"\t4 - Brand" <<
					"\t5 - Ports" <<
					"\t0 - Quit" <<
					std::endl;

				std::cin >> innerInnerChoice;
				switch (innerInnerChoice)
				{
					case 1:
						std::cout << "Input manufacture year: ";
						std::cin >> manufactureYear;
						pc.setManufactureYear(manufactureYear);
						break;
					case 2:
						std::cout << "Input OS: ";
						std::cin >> os;
						pc.setOperatingSystem(os);
						break;
					case 3:
						std::cout << "Input display size: ";
						std::cin >> displaySize;
						pc.setDisplaySize(displaySize);
						break;
					case 4:
						std::cout << "Input brand: ";
						std::cin >> brand;
						pc.setBrand(brand);
						break;
					case 5:
						std::cout << "Which port to edit? -1 - all: ";
						std::cin >> portToEdit;
						if (portToEdit == -1)
						{
							for (size_t i = 0; i < 6; i++)
								std::cin >> ports[i];
							pc.setPorts(ports);
						}
						else if (portToEdit >= 0 && portToEdit < 6)
						{
							std::cin >> ports[portToEdit];
							pc.setPort(portToEdit, ports[portToEdit]);
						}
						break;
					case 0:
					default:
						break;
					}
				pc_arr[objToEdit] = pc;
				break;
			case 2:
				std::cout << "Editing Laptop" << std::endl;
				std::cout << "Which Laptop to edit (0 - 3)";
				std::cin >> objToEdit;
				if (objToEdit > laptopIndex)
					objToEdit = laptopIndex;
				laptop = laptop_arr[objToEdit];
				std::cout << "Choose what to edit:\n" <<
					"\t1 - Manufacture year" <<
					"\t2 - OS" <<
					"\t3 - Weight" <<
					"\t4 - Touch" <<
					"\t5 - Vendor" <<
					"\t6 - Model" << 
					"\t0 - Quit" <<
					std::endl;

				std::cin >> innerInnerChoice;
				switch (innerInnerChoice)
				{
				case 1:
					std::cout << "Input manufacture year: ";
					std::cin >> manufactureYear;
					laptop.setManufactureYear(manufactureYear);
					break;
				case 2:
					std::cout << "Input OS: ";
					std::cin >> os;
					laptop.setOperatingSystem(os);
					break;
				case 3:
					std::cout << "Input weight: ";
					std::cin >> weight;
					laptop.setWeight(weight);
					break;
				case 4:
					std::cout << "Input touchability. 0 - false, 1 - true: ";
					std::cin >> isTouch;
					laptop.setTouchInterfaceAvailable(isTouch);
					break;
				case 5:
					std::cout << "Input vendor: ";
					std::cin >> vendor;
					laptop.setVendor(vendor);
					break;
				case 6:
					std::cout << "Input model: ";
					std::cin >> model;
					laptop.setModel(model);
					break;
				case 0:
				default:
					break;
				}
				laptop_arr[objToEdit] = laptop;
				break;
			case 3:
				std::cout << "Editing Tablet" << std::endl;
				std::cout << "Which Tablet to edit (0 - 3)";
				std::cin >> objToEdit;
				if (objToEdit > tabletIndex)
					objToEdit = tabletIndex;
				tablet = tablet_arr[objToEdit];
				std::cout << "Choose what to edit:\n" <<
					"\t1 - Manufacture year" <<
					"\t2 - OS" <<
					"\t3 - Weight" <<
					"\t4 - Touch" <<
					"\t5 - Apps" <<
					"\t6 - Unlocked" <<
					"\t0 - Quit" <<
					std::endl;

				std::cin >> innerInnerChoice;
				switch (innerInnerChoice)
				{
				case 1:
					std::cout << "Input manufacture year: ";
					std::cin >> manufactureYear;
					tablet.setManufactureYear(manufactureYear);
					break;
				case 2:
					std::cout << "Input OS: ";
					std::cin >> os;
					tablet.setOperatingSystem(os);
					break;
				case 3:
					std::cout << "Input weight: ";
					std::cin >> weight;
					tablet.setWeight(weight);
					break;
				case 4:
					std::cout << "Input touchability. 0 - false, 1 - true: ";
					std::cin >> isTouch;
					tablet.setTouchInterfaceAvailable(isTouch);
					break;
				case 5:
					std::cout << "Which app to edit? -1 - all: ";
					std::cin >> appToEdit;
					if (appToEdit == -1)
					{
						std::cout << "Input apps. Press Esc after input to stop editing: " << std::endl;
						while (moreApps != 27) // пока не нажали кнопку esc, вводим приложения
						{
							std::cin >> app;
							appsInstalled.push_back(app);
							moreApps = _getch();
						}
						tablet.setAppsInstalled(appsInstalled);
					}
					else
					{
						std::cout << "Input app: ";
						std::cin >> app;
						tablet.setApp(appToEdit, app);
					}
					break;
				case 6:
					std::cout << "Input lock state. 0 - false, 1 - true: ";
					std::cin >> isUnlocked;
					tablet.setUnlocked(isUnlocked);
					break;
				case 0:
				default:
					break;
				}
			tablet_arr[tabletIndex] = tablet;
			break;
			case 0:
			default:
				break;
			}
			break;
		case 3:
			std::cout << "Choose which object to show:\n" <<
				"\t1 - Monoblock PC" <<
				"\t2 - Laptop" <<
				"\t3 - Tablet PC" <<
				"\t0 - Quit" <<
				std::endl;

			std::cin >> innerChoice;
			switch (innerChoice)
			{
			case 1:
				std::cout << "Showing all the PCs:" << std::endl;
				pc_arr[0].header();
				for (size_t i = 0; i < pcIndex; i++)
				{
					pc_arr[i].show();
				}
				break;
			case 2:
				std::cout << "Showing all the Laptops:" << std::endl;
				laptop_arr[0].header();
				for (size_t i = 0; i < laptopIndex; i++)
				{
					laptop_arr[i].show();
				}
				break;
			case 3:
				std::cout << "Showing all the Tablets:" << std::endl;
				tablet_arr[0].header();
				for (size_t i = 0; i < tabletIndex; i++)
				{
					tablet_arr[i].show();
				}
				break;
			case 0:
			default:
				break;
			}
			break;
		case 0:
			return 0;
		}
	}
}