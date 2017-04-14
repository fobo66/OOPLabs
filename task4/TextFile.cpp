#include "stdafx.h"
#include "TextFile.h"

using namespace file;

template<class T>
void TextFile<T>::write(T& stuff)
{
	this->descriptor.open(this->filename, std::ios::out);
	if (this->exists())
	    this->descriptor << stuff;
	this->descriptor.close();
}

template<class T>
void TextFile<T>::read(T & stuff)
{
	this->descriptor.open(this->filename, std::ios::in);
	if (exists() && !empty())
		descriptor >> stuff;
	this->descriptor.close();
}