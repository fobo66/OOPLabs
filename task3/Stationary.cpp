#include "stdafx.h"
#include "Stationary.h"

using namespace comp;

int Stationary::getDisplaySize()
{
	return this->displaySize;
}

std::string Stationary::getBrand()
{
	return this->brand;
}

void Stationary::setDisplaySize(int size)
{
	this->displaySize = size;
}

void Stationary::setBrand(std::string newBrand)
{
	this->brand = newBrand;
}
