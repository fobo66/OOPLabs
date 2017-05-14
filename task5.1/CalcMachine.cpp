#include "stdafx.h"
#include "CalcMachine.h"

using namespace comp;

int CalcMachine::getManufactureYear() const noexcept
{
	return this->manufactureYear;
}

int comp::CalcMachine::getCode() const noexcept
{
	return this->compCode;
}

std::string CalcMachine::getOperatingSystem() const noexcept
{
	return this->operatingSystem;
}

void comp::CalcMachine::setManufactureYear(int newYear) noexcept
{
	this->manufactureYear = newYear;
}

void comp::CalcMachine::setCode(int code) noexcept
{
	this->compCode = code;
}

void comp::CalcMachine::setOperatingSystem(std::string & os) noexcept
{
	this->operatingSystem = os;
}

std::ostream & comp::operator<<(std::ostream & out, const CalcMachine & item)
{
	item.show();

	return out;
}

std::istream & comp::operator >> (std::istream & in, CalcMachine & item)
{
	do
	{
		Validator::checkedNumericalInput(item.manufactureYear, "Input manufacture year: ");
	} while (item.manufactureYear < comp::MIN_YEAR || item.manufactureYear > comp::MAX_YEAR);

	do
	{
		Validator::checkedNumericalInput(item.compCode, "Input code: ");
	} while (item.compCode < 0);

	item.operatingSystem = Validator::checkedInput("Input OS: ");

	return in;
}

std::fstream & comp::operator >> (std::fstream & file, CalcMachine & item)
{
	file >> item.manufactureYear >> item.compCode;
	std::getline(file, item.operatingSystem, '*');
	return file;
}