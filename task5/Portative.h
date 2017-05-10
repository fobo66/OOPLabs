#pragma once
#include "CalcMachine.h"

namespace comp {
	class Portative :
		public CalcMachine
	{
	private:
		friend class boost::serialization::access;

		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<CalcMachine>(*this);
			ar & weight;
			ar & isTouchInterfaceAvailable;
		}
	protected:
		float weight;
		bool isTouchInterfaceAvailable;
	public:
		Portative() {};

		Portative(int year, int code, std::string os, float weight, bool touch)
			: CalcMachine(year, code, os)
		{
			this->weight = weight;
			this->isTouchInterfaceAvailable = touch;
		};

		float getWeight();
		bool getTouchInterfaceAvailable();

		void setWeight(float);
		void setTouchInterfaceAvailable(bool);

		friend std::istream& operator >> (std::istream&, Portative&);
		friend std::fstream& operator >> (std::fstream&, Portative&);

		virtual ~Portative() {};
	};
}

