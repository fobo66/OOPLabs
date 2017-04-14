// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int main()
{
	char plainString[DEFAULT_STRLEN], 
		 plainString2[DEFAULT_STRLEN],
		 confirm;
	do {
		confirm = 'y';
		std::cout << "Type some string:" << std::endl;
		std::cin >> plainString;

		std::cout << "Type another string:" << std::endl;
		std::cin >> plainString2;

		str::String strObject1(plainString),
					strObject,
					strObject2;

		strObject = plainString2;

		std::cout << "Type string object:" << std::endl;
		std::cin >> strObject2;

		str::String strObject3 = "Hello " + strObject1 + strObject2 + " world";
		std::cout << "strObject1 + strObject2 = : " << strObject3 << std::endl;

		strObject2 += strObject1;
		std::cout << "strObject2 += strObject1 : " << strObject2 << std::endl;

		strObject3++;
		std::cout << "strObject3++: " << strObject3 << std::endl;

		strObject3--;
		std::cout << "strObject3--: " << strObject3 << std::endl;

		std::cout << "strObject3[0]: " << strObject3[0] << std::endl;

		if (strObject3 > strObject1)
			std::cout << "strObject3 > strObject1" << std::endl;

		if (strObject2 < strObject1)
			std::cout << "strObject2 < strObject1" << std::endl;


		std::cout << "strObject3(1, 3): " << strObject3(1, 3) << std::endl;
		std::cout << "strObject3(3): " << strObject3(3) << std::endl;

		std::cout << "before Subtraction: " << strObject << std::endl;
		strObject -= "a";
		std::cout << "after Subtraction: " << strObject << std::endl;

		std::cout << "Do you want to continue? y/n  ";
		std::cin >> confirm;
	} while (tolower(confirm) != 'n');

    return 0;
}

