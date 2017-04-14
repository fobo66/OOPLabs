#pragma once
#include "Stationary.h"
namespace comp {
	class Monoblock :
		public Stationary
	{
	private:
		std::string ports[6];
	public:
		Monoblock() {};
		Monoblock(int year, std::string os, int display, std::string brand,
			std::string ports[])
			: Stationary(year, os, display, brand)
		{
			for (size_t i = 0; i < 6; i++)
			{
				this->ports[i] = ports[i];
			}
		};

		std::string* getPorts();
		std::string getPort(int);
		
		void setPorts(std::string[]);
		void setPort(int, std::string);

		bool operator>(const Monoblock &);
		bool operator<(const Monoblock &);
		bool operator>=(const Monoblock &);
		bool operator<=(const Monoblock &);
		bool operator==(const Monoblock &);
		bool operator!=(const Monoblock &);

		void show();
		void header();

		friend std::istream& operator>>(std::istream&, Monoblock&);

		~Monoblock() {};
	};
}
