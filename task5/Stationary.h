#pragma once
#include "CalcMachine.h"
namespace comp {
	class Stationary :
		public comp::CalcMachine
	{
	private:
		friend class boost::serialization::access;

		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<CalcMachine>(*this);
			ar & displaySize;
			ar & brand;
		};
	protected:
		int displaySize;  //size of display in inches
		std::string brand;
	public:
		Stationary() {};
		Stationary(int year, int code, std::string os, int display, std::string brand)
			: CalcMachine(year, code, os)
		{
			this->brand = brand;
			this->displaySize = display;
		};

		int getDisplaySize();
		std::string getBrand();

		void setDisplaySize(int);
		void setBrand(std::string);

		friend std::istream& operator >> (std::istream&, Stationary&);
		friend std::fstream& operator >> (std::fstream&, Stationary&);

		virtual ~Stationary() {};
	};
}
