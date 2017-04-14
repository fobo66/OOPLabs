#pragma once
#include "Portative.h"
namespace comp {
	class Tablet :
		public Portative
	{
	private:
		std::vector<std::string> appsInstalled;
		bool isUnlocked;
	public:
		Tablet() {};

		Tablet(int year, std::string os, float weight, bool touch, std::vector<std::string> apps, bool unlocked)
			: Portative(year, os, weight, touch)
		{
			this->appsInstalled = apps;
			this->isUnlocked = unlocked;
		};

		std::vector<std::string> getAppsInstalled();
		std::string getApp(int);
		bool getUnlocked();

		void setAppsInstalled(std::vector<std::string>);
		void setApp(std::string&);
		void setApp(int, std::string&);
		void setUnlocked(bool);

		bool operator>(const Tablet &);
		bool operator<(const Tablet &);
		bool operator>=(const Tablet &);
		bool operator<=(const Tablet &);
		bool operator==(const Tablet &);
		bool operator!=(const Tablet &);

		void header();
		void show();

		friend std::istream& operator>>(std::istream&, Tablet&);

		~Tablet() {};
	};
}
