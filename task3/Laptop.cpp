#include "stdafx.h"
#include "Laptop.h"

using namespace comp;

std::string comp::Laptop::getVendor()
{
	return this->vendor;
}

std::string comp::Laptop::getModel()
{
	return this->model;
}

void comp::Laptop::setVendor(std::string vendor)
{
	this->vendor = vendor;
}

void comp::Laptop::setModel(std::string model)
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
		<< std::setw(20) << this->operatingSystem << " | "
		<< std::setw(10) << this->weight << " | "
		<< std::setw(10) << this->isTouchInterfaceAvailable << " | "
		<< std::setw(20) << this->vendor << " | "
		<< std::setw(20) << this->model << " | "
		<< std::endl;
}

std::istream& comp::operator >> (std::istream& in, Laptop& item)
{
	std::cout << "Input manufacture year: ";
	in >> item.manufactureYear;
	std::cout << "Input OS: ";
	in >> item.operatingSystem;
	std::cout << "Input weight: ";
	in >> item.weight;
	std::cout << "Is it touchable device? 0 - false, 1 - true: ";
	in >> item.isTouchInterfaceAvailable;
	std::cout << "Input vendor: ";
	in >> item.vendor;
	std::cout << "Input model: ";
	in >> item.model;

	return in;
}