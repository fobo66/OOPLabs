#pragma once
#include "CalcMachine.h"

namespace comp {
	class Portative :
		public CalcMachine
	{
	protected:
		float weight;
		bool isTouchInterfaceAvailable;
	public:
		Portative() {};

		Portative(int year, std::string os, float weight, bool touch)
			: CalcMachine(year, os)
		{
			this->weight = weight;
			this->isTouchInterfaceAvailable = touch;
		};

		float getWeight();
		bool getTouchInterfaceAvailable();

		void setWeight(float);
		void setTouchInterfaceAvailable(bool);
		~Portative() {};
	};
}

