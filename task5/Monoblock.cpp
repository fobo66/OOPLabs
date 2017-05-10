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
	std::cout
		<< std::setw(8)  << "Year:"               << " | "
		<< std::setw(8)  << "Code:"               << " | "
		<< std::setw(20) << "Operating system:"   << " | "
		<< std::setw(20) << "Display size, inch:" << " | "
		<< std::setw(20) << "Brand:"              << " | "
		<< std::setw(20) << "Ports:"              << " | "
		<< std::endl;
}

void Monoblock::show()
{
	std::cout << std::setw(8)  << this->manufactureYear << " | "
			  << std::setw(8)  << this->compCode        << " | "
			  << std::setw(20) << this->operatingSystem << " | "
			  << std::setw(20) << this->displaySize     << " | "
			  << std::setw(20) << this->brand           << " | "
			  << std::setw(20) << this->ports[0]        << " | "
			  << std::endl;

	for (size_t i = 1; i < 6; i++)
		std::cout << std::setw(111) << this->ports[i] << " | "
		<< std::endl;
}

std::fstream & comp::operator << (std::fstream & stream, Monoblock & item)
{
	stream << " " << item.manufactureYear << " "
		<< item.compCode << " "
		<< item.operatingSystem << "*"
		<< item.displaySize << " "
		<< item.brand << "*";
	for (size_t i = 0; i < 6; i++)
		stream << item.ports[i] << "*";

	return stream;
}

std::istream & comp::operator>>(std::istream & in, Monoblock & item)
{
	in >> dynamic_cast<Stationary&>(item);

	std::cout << "Input ports: ";

	for (size_t i = 0; i < 6; i++)
		item.ports[i] = Validator::localizedCheck("Input port: ");

	return in;
}

std::fstream & comp::operator >> (std::fstream & in, Monoblock & item)
{
	in >> dynamic_cast<Stationary&>(item);

	for (size_t i = 0; i < 6; i++)
		in >> item.ports[i];

	return in;
}