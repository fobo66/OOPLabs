#include "stdafx.h"
#include "Laptop.h"

using namespace comp;

std::string comp::Laptop::getVendor() const noexcept
{
	return this->vendor;
}

std::string comp::Laptop::getModel() const noexcept
{
	return this->model;
}

void comp::Laptop::setVendor(std::string vendor) noexcept
{
	this->vendor = vendor;
}

void comp::Laptop::setModel(std::string model) noexcept
{
	this->model = model;
}

bool comp::Laptop::operator>(const Laptop & another)
{
	return this->manufactureYear > another.manufactureYear;
}

bool comp::Laptop::operator<(const Laptop & another)
{
	return this->manufactureYear < another.manufactureYear;
}

bool comp::Laptop::operator>=(const Laptop & another)
{
	return this->manufactureYear >= another.manufactureYear;
}

bool comp::Laptop::operator<=(const Laptop & another)
{
	return this->manufactureYear <= another.manufactureYear;
}

bool comp::Laptop::operator==(const Laptop & another)
{
	return this->manufactureYear == another.manufactureYear;
}

bool comp::Laptop::operator!=(const Laptop & another)
{
	return this->manufactureYear != another.manufactureYear;
}

void comp::Laptop::header()
{
	std::cout << std::setw(8) << "Year:" << " | "
		<< std::setw(8) << "Code:" << " | "
		<< std::setw(20) << "Operating system:" << " | "
		<< std::setw(10) << "Weight" << " | "
		<< std::setw(10) << "Touchable:" << " | "
		<< std::setw(20) << "Vendor:" << " | "
		<< std::setw(20) << "Model:" << " | "
		<< std::endl;
}

void comp::Laptop::show()
{
	std::cout << std::setw(8) << this->manufactureYear << " | "
		<< std::setw(8) << this->compCode << " | "
		<< std::setw(20) << this->operatingSystem << " | "
		<< std::setw(10) << this->weight << " | "
		<< std::setw(10) << this->isTouchInterfaceAvailable << " | "
		<< std::setw(20) << this->vendor << " | "
		<< std::setw(20) << this->model << " | "
		<< std::endl;
}

std::fstream & comp::operator<< (std::fstream & file, Laptop & item)
{
	file << " " << item.manufactureYear << " "
		<< item.compCode << " "
		<< item.operatingSystem << "*"
		<< item.weight << " "
		<< item.isTouchInterfaceAvailable << " "
		<< item.vendor << "*"
		<< item.model;
	return file;
}

std::fstream & comp::operator >> (std::fstream & in, Laptop & item)
{
	in >> dynamic_cast<Portative&>(item);
	std::getline(in, item.vendor, '*');
	std::getline(in, item.model, '*');
	return in;
}

std::istream& comp::operator >> (std::istream& in, Laptop& item)
{
	in >> dynamic_cast<Portative&>(item);

	item.vendor = item.validator.checkedInput("Input vendor: ");
	item.model = item.validator.checkedInput("Input model: ");

	return in;
}