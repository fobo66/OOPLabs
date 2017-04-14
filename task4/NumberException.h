#pragma once
#include "Exception.h"
class NumberException :
	public Exception
{
public:
	NumberException(std::string msg) : Exception(msg) {};
	~NumberException() {};
};

