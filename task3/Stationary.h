#pragma once
#include "CalcMachine.h"
namespace comp {
	class Stationary :
		public comp::CalcMachine
	{
	protected:
		int displaySize;  //size of display in inches
		std::string brand;
	public:
		Stationary() {};
		Stationary(int year, std::string os, int display, std::string brand)
			: CalcMachine(year, os)
		{
			this->brand = brand;
			this->displaySize = display;
		};

		int getDisplaySize();
		std::string getBrand();

		void setDisplaySize(int);
		void setBrand(std::string);

		~Stationary() {};
	};
}
