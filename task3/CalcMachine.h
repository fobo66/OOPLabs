#pragma once

namespace comp {
	class CalcMachine
	{
	protected:
		int manufactureYear;
		std::string operatingSystem;
	public:
		CalcMachine() 
		{
			this->manufactureYear = 1970;
		};

		CalcMachine(int year, std::string os) 
		{
			this->manufactureYear = year;
			this->operatingSystem = os;
		};

		CalcMachine(const CalcMachine & machine)
		{
			this->manufactureYear = machine.manufactureYear;
			this->operatingSystem = machine.operatingSystem;
		};

		int getManufactureYear();
		std::string getOperatingSystem();

		void setManufactureYear(int);
		void setOperatingSystem(std::string&);

		virtual void show() = 0;
		virtual void header() = 0;

		friend std::ostream& operator<<(std::ostream&, CalcMachine&);
		
		virtual ~CalcMachine() {};
	};
}

