#include "stdafx.h"
#include "Validator.h"

std::string Validator::checkedInput(std::string message)
{
	bool flag;
	std::string input;
	do
	{
		try
		{
			flag = false;
			std::cout << message << std::endl;
			std::getline(std::cin, input);
			if (Validator::validateStringForEnglishLettersAndNumbersOnly(input))
				throw std::exception(
					"String contains incorrect symbols. You can type only latin letters, digits and space");
		}
		catch (const std::exception& ex)
		{
			flag = true;
			std::cin.clear();
			std::cerr << ex.what() << "\nTry again" << std::endl;
			std::cin.ignore(INT_MAX, '\n');
		}
		catch (...)
		{
			flag = true;
			std::cerr << "Something terrible happened, will stop...";
			std::terminate();
		}
	} while (flag);
	return input;
}

std::string Validator::localizedCheck(std::string message)
{
	bool flag;
	std::string input;
	do
	{
		try
		{
			flag = false;
			std::cout << message << std::endl;
			std::getline(std::cin, input);
			if (Validator::validateStringForEnglishOrRussianLetters(input))
				throw std::exception(
					"String contains incorrect symbols. You can type only English or Russian letters");
		}
		catch (const std::exception& ex)
		{
			flag = true;
			std::cin.clear();
			std::cerr << ex.what() << "\nTry again" << std::endl;
			std::cin.ignore(INT_MAX, '\n');
		}
		catch (...)
		{
			flag = true;
			std::cerr << "Something terrible happened, will stop...";
			std::terminate();
		}
	} while (flag);
	return input;
}

/**
 * Validate string for english letters and numbers only
 * Spaces included, because full name of e.g. OS or vendor
 * can contain 2 or more words
 */
bool Validator::validateStringForEnglishLettersAndNumbersOnly(std::string value)
{
	return !std::regex_match(value, std::regex("^[A-Za-z0-9\\s]+$"));
}

bool Validator::validateStringForEnglishOrRussianLetters(std::string value)
{
	return !std::regex_match(value, std::regex("^[A-Za-zР-пр-џ]+$"));
}