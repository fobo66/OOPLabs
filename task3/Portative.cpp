#include "stdafx.h"
#include "Portative.h"

using namespace comp;

float Portative::getWeight()
{
	return this->weight;
}

bool Portative::getTouchInterfaceAvailable()
{
	return this->isTouchInterfaceAvailable;
}

void comp::Portative::setWeight(float newWeight)
{
	this->weight = newWeight;
}

void comp::Portative::setTouchInterfaceAvailable(bool touch)
{
	this->isTouchInterfaceAvailable = touch;
}

