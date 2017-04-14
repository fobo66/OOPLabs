#pragma once
#include "Exception.h"
class FileException :
	public Exception
{
public:
	FileException(std::string reason): Exception(reason) {};
	~FileException() {};
};

