#include "stdafx.h"
#include "Tablet.h"

using namespace comp;

std::vector<std::string> comp::Tablet::getAppsInstalled()
{
	return this->appsInstalled;
}

std::string comp::Tablet::getApp(int index)
{
	return this->appsInstalled[index];
}

bool comp::Tablet::getUnlocked()
{
	return this->isUnlocked;
}

void comp::Tablet::setAppsInstalled(std::vector<std::string> apps)
{
	this->appsInstalled = apps;
}

void comp::Tablet::setApp(std::string& app)
{
	this->appsInstalled.push_back(app);
}

void comp::Tablet::setApp(int index, std::string & app)
{
	this->appsInstalled.at(index) = app;
}

void comp::Tablet::setUnlocked(bool unlocked)
{
	this->isUnlocked = unlocked;
}

bool comp::Tablet::operator>(const Tablet & another)
{
	return this->weight > another.weight;
}

bool comp::Tablet::operator<(const Tablet & another)
{
	return this->weight < another.weight;
}

bool comp::Tablet::operator<=(const Tablet & another)
{
	return this->weight <= another.weight;
}

bool comp::Tablet::operator>=(const Tablet & another)
{
	return this->weight >= another.weight;
}

bool comp::Tablet::operator==(const Tablet & another)
{
	return this->weight == another.weight;
}

bool comp::Tablet::operator!=(const Tablet & another)
{
	return this->weight != another.weight;
}

void Tablet::header()
{
	std::cout << std::setw(8) << "Year:" << " | "
		<< std::setw(8) << "Code:" << " | "
		<< std::setw(20) << "Operating system:" << " | "
		<< std::setw(10) << "Weight" << " | "
		<< std::setw(10) << "Touchable:" << " | "
		<< std::setw(10) << "Unlocked:" << " | "
		<< std::setw(20) << "Apps:" << " | "
		<< std::endl;
}

void Tablet::show()
{
	std::cout << std::setw(8) << this->manufactureYear << " | "
		<< std::setw(8) << this->compCode << " | "
		<< std::setw(20) << this->operatingSystem << " | "
		<< std::setw(10) << this->weight << " | "
		<< std::setw(10) << this->isTouchInterfaceAvailable << " | "
		<< std::setw(10) << this->isUnlocked << " | "
		<< std::setw(20) << this->appsInstalled[0] << " | "
		<< std::endl;

	for (size_t i = 1; i < this->appsInstalled.size(); i++)
		std::cout << std::setw(104) << this->appsInstalled[i] << " | "
		<< std::endl;
}

std::istream & comp::operator>>(std::istream & in, Tablet & item)
{
	std::string app;

	in >> dynamic_cast<Portative&>(item);

	item.validator.checkedNumericalInput(item.isUnlocked, "Is device unlocked? 0 - false, 1 - true: ");
	std::cout << "Input apps. Press Esc after input to stop editing: ";

	for (size_t i = 0; i < item.appsCount; i++)
	{
		app = item.validator.localizedCheck("One more app: ");
		item.appsInstalled.push_back(app);
	}

	return in;
}

std::fstream & comp::operator >> (std::fstream & in, Tablet & item)
{
	std::string app;

	in >> dynamic_cast<Portative&>(item);
	in >> item.isUnlocked;
	for (size_t i = 0; i < item.appsCount; i++)
	{
		std::getline(in, app, '*');
		item.appsInstalled.push_back(app);
	}
	return in;
}

std::fstream & comp::operator<<(std::fstream & file, Tablet & item)
{
	file << " " << item.manufactureYear << " "
		 << item.compCode << " "
		 << item.operatingSystem << "*"
		 << item.weight << "*"
		 << item.isTouchInterfaceAvailable << " "
		 << item.isUnlocked << " ";

	for (size_t i = 0; i < item.appsCount; i++)
		file << item.appsInstalled[i] << '*';

	return file;
}