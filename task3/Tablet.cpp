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
		<< std::setw(20) << this->operatingSystem << " | "
		<< std::setw(10) << this->weight << " | "
		<< std::setw(10) << this->isTouchInterfaceAvailable << " | "
		<< std::setw(10) << this->isUnlocked << " | "
		<< std::setw(20) << this->appsInstalled[0] << " | "
		<< std::endl;

	for (size_t i = 1; i < this->appsInstalled.size(); i++)
		std::cout << std::setw(93) << this->appsInstalled[i] << " | "
		<< std::endl;
}

std::istream & comp::operator>>(std::istream & in, Tablet & item)
{
	int moreApps = 0;
	std::string app;

	std::cout << "Input manufacture year: ";
	in >> item.manufactureYear;
	std::cout << "Input OS: ";
	in >> item.operatingSystem;
	std::cout << "Input weight: ";
	in >> item.weight;
	std::cout << "Is it touchable device? 0 - false, 1 - true: ";
	in >> item.isTouchInterfaceAvailable;
	std::cout << "Is device unlocked? 0 - false, 1 - true: ";
	in >> item.isUnlocked;
	std::cout << "Input apps. Press Esc after input to stop editing: ";

	while (moreApps != 27) // пока не нажали кнопку esc, вводим приложения
	{
		std::cin >> app;
		item.appsInstalled.push_back(app);
		moreApps = _getch();
	}

	return in;
}
