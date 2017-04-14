#include "stdafx.h"
#include "CalcMachine.h"

using namespace comp;

int CalcMachine::getManufactureYear()
{
	return this->manufactureYear;
}

std::string CalcMachine::getOperatingSystem()
{
	return this->operatingSystem;
}

void comp::CalcMachine::setManufactureYear(int newYear)
{
	this->manufactureYear = newYear;
}

void comp::CalcMachine::setOperatingSystem(std::string & os)
{
	this->operatingSystem = os;
}

std::ostream & comp::operator<<(std::ostream & out, CalcMachine & item)
{
	item.show();

	return out;
}
