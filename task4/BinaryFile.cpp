#include "stdafx.h"
#include "BinaryFile.h"

using namespace file;

template<class T>
void BinaryFile<T>::write(T& value)
{
	std::ofstream out(this->filename);
	if (out.good())
	{
		boost::archive::binary_oarchive oarch(out);
		oarch << value;
	}
}

template<class T>
void BinaryFile<T>::read(T& value)
{
	this->descriptor.open(this->filename, std::ios::in | std::ios::binary);
	if (this->exists())
	{
		boost::archive::binary_iarchive iarch(this->descriptor);
		iarch >> value;
	}
}