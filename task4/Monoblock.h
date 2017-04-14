#pragma once
#include "Stationary.h"
namespace comp {
	class Monoblock :
		public Stationary
	{
	private:
		friend class boost::serialization::access;
		std::string ports[6];

		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<Stationary>(*this);
			ar & ports;
		}
	public:
		Monoblock() {};
		Monoblock(int year, int code, std::string os, int display, std::string brand,
			std::string ports[])
			: Stationary(year, code, os, display, brand)
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

		friend std::istream& operator >> (std::istream&, Monoblock&);
		friend std::fstream& operator >> (std::fstream&, Monoblock&);
		friend std::fstream& operator << (std::fstream&, Monoblock&);

		~Monoblock() {};
	};
}
