// task5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "Laptop.h"
#include "Interface.cpp"

void customTerminate()
{
	std::cerr << "Cannot continue work, forced termination";
}

int main()
{
	std::set_terminate(customTerminate);
	comp::Laptop laptop;
    Interface<comp::Laptop>::work(laptop);

	return 0;
}
