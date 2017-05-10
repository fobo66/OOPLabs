#pragma once

#include "stdafx.h"
#include "File.h"
#include "FileException.h"

using namespace file;

template <class T>
File<T>::File(std::string name) 
{
	this->filename = name;
}

template<class T>
void File<T>::write(T& stuff)
{
	throw FileException("Stub!");
}

template<class T>
void File<T>::read(T& stuff)
{
	throw FileException("Stub!");
}

template <class T>
bool File<T>::exists()
{
	std::fstream tempFile(this->filename);
	return tempFile.good();
}
template<class T>
bool file::File<T>::empty()
{
	std::ifstream file(this->filename, std::ios::in);
	std::streamoff length;

	file.seekg(0, std::ios::end);
	length = file.tellg();

	return length == 0;
}
template <class T>
File<T>::~File()
{

}
