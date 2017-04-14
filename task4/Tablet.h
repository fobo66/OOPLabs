#pragma once
#include "Portative.h"
namespace comp {
	class Tablet :
		public Portative
	{
	private:
		friend class boost::serialization::access;
		std::vector<std::string> appsInstalled;
		bool isUnlocked;
		size_t appsCount = 5;

		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<Portative>(*this);
			ar & isUnlocked;
			ar & appsInstalled;
		}
	public:
		Tablet() {};

		Tablet(int year, int code, std::string os, float weight, bool touch, std::vector<std::string> apps, bool unlocked)
			: Portative(year, code, os, weight, touch)
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

		friend std::istream& operator >> (std::istream&, Tablet&);
		friend std::fstream& operator >> (std::fstream&, Tablet&);
		friend std::fstream& operator <<(std::fstream&, Tablet&);

		~Tablet() {};
	};
}
