#include "StringException.h"
#include "NumberException.h"
#include <regex>

#pragma once
class Validator
{
private:
	bool validateStringForEnglishLettersAndNumbersOnly(std::string);
	bool validateStringForEnglishOrRussianLetters(std::string);
public:
	Validator() {};
	std::string checkedInput(std::string); // функция для проверки введённых пользователями строк
	std::string localizedCheck(std::string);

	template <typename T> void checkedNumericalInput(T & param, std::string description)
	{       
		bool flag;
		do 
		{
			flag = false;
			try
			{
				std::cout << "\n" << description;
				std::cin >> param;
				if (std::cin.good())
					std::cin.ignore(INT_MAX, '\n');
				else
					throw NumberException("Incorrect number");
			}
			catch (NumberException ex) {
				flag = true;
				std::cin.clear();
				std::cerr << ex.getMessage() << "\nTry again" << std::endl;
				std::cin.ignore(INT_MAX, '\n');
			}
			catch (...)
			{
				flag = true;
				std::cin.clear();
				std::cerr << "Something terrible happened, will stop...";
				std::terminate();
			}
		} while (flag);

	};

	~Validator() {};
};

