#pragma once
class Exception
{
private:
	std::string message;
public:
	Exception(std::string message) 
	{
		this->message = message;
	};

	std::string getMessage() const;

	virtual ~Exception() {};
};

