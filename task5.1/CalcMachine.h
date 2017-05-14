#include "Validator.h"

#pragma once

namespace comp {
	const int MIN_YEAR = 1950;
	const int MAX_YEAR = 2017;

	class CalcMachine
	{
	protected:
		int manufactureYear;         // ��� �������
		int compCode;                // ��� ���������� - ���������� ����
		std::string operatingSystem; // �����������
	public:
		CalcMachine() 
		{
			this->manufactureYear = MIN_YEAR;
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

		virtual void show() const = 0;
		virtual void header() = 0;

		friend std::ostream& operator <<(std::ostream&, const CalcMachine&);
		friend std::istream& operator >> (std::istream&, CalcMachine&);
		friend std::fstream& operator >> (std::fstream&, CalcMachine&);
		
		virtual ~CalcMachine() {};
	};
}

