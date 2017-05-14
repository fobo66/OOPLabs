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

		Laptop(int year, int code, std::string os, float weight, bool touch, std::string vendor, std::string model)
			: Portative(year, code, os, weight, touch)
		{
			this->vendor = vendor;
			this->model = model;
		};

		std::string getVendor() const noexcept;
		std::string getModel() const noexcept;

		void setVendor(std::string) noexcept;
		void setModel(std::string) noexcept;

		bool operator>(const Laptop &);
		bool operator<(const Laptop &);
		bool operator>=(const Laptop &);
		bool operator<=(const Laptop &);
		bool operator==(const Laptop &);
		bool operator!=(const Laptop &);
			
		void header();
		void show() const;

		friend std::istream & operator>>(std::istream &, Laptop &);
		friend std::fstream& operator<< (std::fstream&, Laptop&);
		friend std::fstream& operator>> (std::fstream&, Laptop&);

		~Laptop() {};
	};
}
