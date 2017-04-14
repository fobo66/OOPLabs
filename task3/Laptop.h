#pragma once
#include "Portative.h"
namespace comp {
	class Laptop :
		public Portative
	{
	private:
		std::string vendor;
		std::string model;
	public:
		Laptop() {};

		Laptop(int year, std::string os, float weight, bool touch, std::string vendor, std::string model)
			: Portative(year, os, weight, touch)
		{
			this->vendor = vendor;
			this->model = model;
		};

		std::string getVendor();
		std::string getModel();

		void setVendor(std::string);
		void setModel(std::string);

		bool operator>(const Laptop &);
		bool operator<(const Laptop &);
		bool operator>=(const Laptop &);
		bool operator<=(const Laptop &);
		bool operator==(const Laptop &);
		bool operator!=(const Laptop &);

		void header();
		void show();

		friend std::istream & operator>>(std::istream &, Laptop &);

		~Laptop() {};
	};
}
