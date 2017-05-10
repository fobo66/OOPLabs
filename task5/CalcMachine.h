#include "Validator.h"

#pragma once

namespace comp {
	const int MIN_YEAR = 1950;
	const int MAX_YEAR = 2017;

	class CalcMachine
	{
	private:
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & manufactureYear;
			ar & compCode;
			ar & operatingSystem;
		};
	protected:
		friend class boost::serialization::access;
		int manufactureYear;         // год выпуска
		int compCode;                // код компьютера - уникальное поле
		std::string operatingSystem; // операционка
	public:
		CalcMachine() 
		{
			this->manufactureYear = 1970;
		};

		CalcMachine(int year, int code, std::string os) 
		{
			this->manufactureYear = year;
			this->compCode = code;
			this->operatingSystem = os;
		};

		CalcMachine(const CalcMachine & machine)
		{
			this->manufactureYear = machine.manufactureYear;
			this->compCode = machine.compCode;
			this->operatingSystem = machine.operatingSystem;
		};

		int getManufactureYear() const noexcept;
		int getCode() const noexcept;
		std::string getOperatingSystem() const noexcept;

		void setManufactureYear(int) noexcept;
		void setCode(int) noexcept;
		void setOperatingSystem(std::string&) noexcept;

		virtual void show() = 0;
		virtual void header() = 0;

		friend std::ostream& operator <<(std::ostream&, CalcMachine&);
		friend std::istream& operator >> (std::istream&, CalcMachine&);
		friend std::fstream& operator >> (std::fstream&, CalcMachine&);
		
		virtual ~CalcMachine() {};
	};
}

