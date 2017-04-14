#include "stdafx.h"
#include "Monoblock.h"

using namespace comp;

std::string* comp::Monoblock::getPorts()
{
	return this->ports;
}

std::string comp::Monoblock::getPort(int index)
{
	return this->ports[index];
}

void comp::Monoblock::setPorts(std::string newPorts[])
{
	for (size_t i = 0; i < 6; i++)
	{
		this->ports[i] = newPorts[i];
	}
}

void comp::Monoblock::setPort(int index, std::string newPort)
{
	this->ports[index] = newPort;
}

bool comp::Monoblock::operator>(const Monoblock & another)
{
	return this->displaySize > another.displaySize;
}

bool comp::Monoblock::operator<(const Monoblock & another)
{
	return this->displaySize < another.displaySize;
}

bool comp::Monoblock::operator>=(const Monoblock & another)
{
	return this->displaySize >= another.displaySize;
}

bool comp::Monoblock::operator<=(const Monoblock & another)
{
	return this->displaySize <= another.displaySize;
}

bool comp::Monoblock::operator==(const Monoblock & another)
{
	return this->displaySize == another.displaySize;
}

bool comp::Monoblock::operator!=(const Monoblock & another)
{
	return this->displaySize != another.displaySize;
}

void Monoblock::header()
{
	std::cout << std::setw(8) << "Year:" << " | "
		<< std::setw(20) << "Operating system:" << " | "
		<< std::setw(20) << "Display size, inch:" << " | "
		<< std::setw(20) << "Brand:" << " | "
		<< std::setw(20) << "Ports:" << " | "
		<< std::endl;
}

void Monoblock::show()
{
	std::cout << std::setw(8) << this->manufactureYear << " | "
		<< std::setw(20) << this->operatingSystem << " | "
		<< std::setw(20) << this->displaySize << " | "
		<< std::setw(20) << this->brand << " \u007C "
		<< std::setw(20) << this->ports[0] << " \u007C "
		<< std::endl;

		for (size_t i = 1; i < 6; i++)
			std::cout << std::setw(100) << this->ports[i] << " | "
			<< std::endl;
}

std::istream & comp::operator>>(std::istream & in, Monoblock & item)
{
	std::cout << "Input manufacture year: ";
	in >> item.manufactureYear;
	std::cout << "Input OS: ";
	in >> item.operatingSystem;
	std::cout << "Input  display size in inches: ";
	in >> item.displaySize;
	std::cout << "Input brand: ";
	in >> item.brand;
	std::cout << "Input ports: ";

	for (size_t i = 0; i < 6; i++)
		std::cin >> item.ports[i];

	return in;
}
