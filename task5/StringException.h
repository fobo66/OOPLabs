#pragma once
#include "Exception.h"
class StringKeyboardInputException :
	public Exception
{
public:
	StringKeyboardInputException(std::string message) : Exception(message) {};
	~StringKeyboardInputException() {};
};

