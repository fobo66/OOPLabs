#include "stdafx.h"
#include "String.h"

using namespace str;

String String::operator+(String & lvalue)
{
	size_t newlen = (strlen(this->instanse) + strlen(lvalue.instanse)) * 2;
	char* result = new char[newlen];
	ZeroMemory(result, newlen);
	strcpy_s(result, newlen, this->instanse);
	strcat_s(result, newlen, lvalue.instanse);
	return String(result);
}

String String::operator+(const char * source)
{
	size_t newlen = (strlen(this->instanse) + strlen(source)) * 2;
	char *result = new char[newlen];
	ZeroMemory(result, newlen);
	strcpy_s(result, newlen, this->instanse);
	strcat_s(result, newlen, source);
	return String(result);
}

String String::operator-(String & second)
{
	size_t newlen = strlen(this->instanse) * 2;
	char* result = new char[newlen];
	size_t i, j, k = 0;
	ZeroMemory(result, newlen);
	strcpy_s(result, newlen, this->instanse);
	for (i = 0; i < strlen(second.instanse); i++)
		for (j = 0; j < strlen(result); j++)
			if (second.instanse[i] == result[j])
			{
				for (k = j; k < strlen(result); k++)
					result[k] = result[k + 1];
				if (j > 0)
				{
					j--;
				}
			}
	return String(result);
}

String String::operator-(const char * second)
{
	size_t newlen = strlen(this->instanse) * 2;
	char* result = new char[newlen];
	size_t i, j, k = 0;
	ZeroMemory(result, newlen);
	strcpy_s(result, newlen, this->instanse);
	for (i = 0; i < strlen(second); i++)
		for (j = 0; j < strlen(result); j++) 
			if (second[i] == result[j]) 
			{
				for (k = j; k < strlen(result); k++)
					result[k] = result[k + 1];
				if (j > 0)
				{
					j--;
				}	
			}
	return String(result);
}

String String::operator=(const String& second)
{
	if (this != &second) 
	{
		delete[] (this->instanse);
		this->instanse = new char[DEFAULT_STRLEN];

		ZeroMemory(this->instanse, DEFAULT_STRLEN);
		strcpy_s(this->instanse, DEFAULT_STRLEN, second.instanse);
	}

	return *this;
}

String String::operator=(const char *str)
{
	if (strcmp(this->instanse, str) != 0)
	{
		delete[] (this->instanse);
		this->instanse = new char[DEFAULT_STRLEN];

		ZeroMemory(this->instanse, DEFAULT_STRLEN);
		strcpy_s(this->instanse, DEFAULT_STRLEN, str);
	}

	return *this;
}

void String::operator+=(String & second)
{
	*this = *this + second;
}

void String::operator+=(const char *second)
{
	*this = *this + second;
}

void String::operator-=(String & second)
{
	*this = *this - second;
}

void String::operator-=(const char *second)
{
	*this = *this - second;
}

bool String::operator<(const String & second)
{
	return strcmp(this->instanse, second.instanse) < 0;
}

bool String::operator>(const String & second)
{
	return strcmp(this->instanse, second.instanse) > 0;
}

bool str::String::operator==(const String &second)
{
	return strcmp(this->instanse, second.instanse) == 0;
}

char String::operator[](int index)
{
	return this->instanse[index];
}

String String::operator()(int a, int b)
{
	char* result = new char[b - a + 1];
	strncpy_s(result, sizeof(result), this->instanse + a, b);
	return String(result);
}

String String::operator()(int a)
{
	size_t newStringSize = strlen(this->instanse) - a + 1;
	char* result = new char[newStringSize];
	strncpy_s(result, newStringSize, this->instanse + a, newStringSize - 1);
	return String(result);
}

String String::operator++(int)
{
	for (size_t i = 0; i < strlen(this->instanse); i++)
		this->instanse[i]++;
	return *this;
}

String String::operator++()
{
	return ++(*this);
}

String String::operator--(int)
{
	for (size_t i = 0; i < strlen(this->instanse); i++)
		this->instanse[i]--;
	return *this;
}

String String::operator--()
{
	return --(*this);
}

String str::operator+(const char *left, String &right)
{
	size_t newlen = (strlen(left) + strlen(right.instanse)) * 2;
	char *result = new char[newlen];
	ZeroMemory(result, newlen);
	strcat_s(result, newlen, left);
	strcat_s(result, newlen, right.instanse);
	return String(result);
}

String str::operator-(const char *left , String & right)
{
	size_t newlen = strlen(left) * 2;
	char* result = new char[newlen];
	ZeroMemory(result, newlen);
	strcpy_s(result, newlen, left);
	for (size_t i = 0; i < strlen(right.instanse); i++)
		for (size_t j = 0; j < strlen(result); j++)
			if (right.instanse[i] == left[j]) {
				for (size_t k = j; k < strlen(result); k++)
					result[k] = result[k + 1];
				i--;
				j--;
			}
	return String(result);
}

std::ostream & str::operator<< (std::ostream & os, const String & str)
{
	os << str.instanse;
	return os;
}

std::istream & str::operator>> (std::istream & is, const String & str)
{
	is >> str.instanse;
	return is;
}
