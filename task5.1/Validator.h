#include <regex>

#pragma once
class Validator
{
private:
	static bool validateStringForEnglishLettersAndNumbersOnly(std::string);
	static bool validateStringForEnglishOrRussianLetters(std::string);
public:
	Validator() {};
	static std::string checkedInput(std::string); // функция для проверки введённых пользователями строк
	static std::string localizedCheck(std::string);

	template <typename T> 
	static void checkedNumericalInput(T & param, std::string description)
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
					throw std::exception("Incorrect number");
			}
			catch (std::exception ex) {
				flag = true;
				std::cin.clear();
				std::cerr << ex.what() << "\nTry again" << std::endl;
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

