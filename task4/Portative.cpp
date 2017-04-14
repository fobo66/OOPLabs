#include "stdafx.h"
#include "Portative.h"

using namespace comp;

float Portative::getWeight()
{
	return this->weight;
}

bool Portative::getTouchInterfaceAvailable()
{
	return this->isTouchInterfaceAvailable;
}

void comp::Portative::setWeight(float newWeight)
{
	this->weight = newWeight;
}

void comp::Portative::setTouchInterfaceAvailable(bool touch)
{
	this->isTouchInterfaceAvailable = touch;
}

std::istream & comp::operator >> (std::istream & in, Portative & item)
{
	in >> dynamic_cast<CalcMachine&>(item);

	do {
		item.validator.checkedNumericalInput(item.weight, "Input weight: ");
	} while (item.weight < 0);

	item.validator.checkedNumericalInput(item.isTouchInterfaceAvailable, "Is it touchable device? 0 - false, 1 - true: ");
	return in;
}

std::fstream & comp::operator >> (std::fstream & in, Portative & item)
{
	in >> dynamic_cast<CalcMachine&>(item);
	in >> item.weight >> item.isTouchInterfaceAvailable;
	return in;
}