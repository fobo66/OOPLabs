#include "stdafx.h"

#include "Type.h"
#include "Tablet.h"
#include "Laptop.h"
#include "Monoblock.h"
#include "Interface.cpp"

void customTerminate()
{
	std::cerr << "Cannot continue work, forced termination";
}

int main()
{
	std::set_terminate(customTerminate);
	DeviceType choice;
	int param;

	comp::Laptop laptop;
	comp::Tablet tablet;
	comp::Monoblock pc;

	std::string menu = "Which type of objects you want to work with?\n\t1 - Laptop\t2 - Monoblock\t3 - Tablet\t0 - Exit\n";
	do
		Validator::checkedNumericalInput(param, menu);
	while (param < 0 || param > 3);
	choice = (DeviceType) param;

	switch (choice)
	{
	case DeviceType::LAPTOP:
		Interface<comp::Laptop>::work(laptop);
		break;
	case DeviceType::MONOBLOCK:
		Interface<comp::Monoblock>::work(pc);
		break;
	case DeviceType::TABLET:
		Interface<comp::Tablet>::work(tablet);
		break;
	case DeviceType::EXIT:
		return 0;
	}

	return 0;
}
