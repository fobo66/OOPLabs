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

std::istream & comp::operator >> (std::istream & in, Stationary & item)
{
	in >> dynamic_cast<CalcMachine&>(item);

	do
		item.validator.checkedNumericalInput(item.displaySize,
			"Input  display size in inches: ");
    while (item.displaySize < 0 || item.displaySize > 100);
	item.brand = item.validator.localizedCheck("Input brand: ");

	return in;
}

std::fstream & comp::operator >> (std::fstream & in, Stationary & item)
{
	in >> dynamic_cast<CalcMachine&>(item);
	in >> item.displaySize;
	std::getline(in, item.brand, '*');
	return in;
}
