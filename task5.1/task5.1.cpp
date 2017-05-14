// task5.cpp: ���������� ����� ����� ��� ����������� ����������.
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
