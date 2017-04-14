// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int main(int argc, _TCHAR* argv[])
{
	int n, m;
	char confirm;
	TDA::Matrix emptyMatrix(1, 1);
	do {
		confirm = 'y';
		std::cout << "Input rows: ";
		std::cin >> n;
		std::cout << "Input cols: ";
		std::cin >> m;

		TDA::Matrix* matrix = new TDA::Matrix(n, m);

		std::cout << "Fill matrix please: " << std::endl;
		matrix->fill();
		std::cout << "Matrix: " << std::endl;
		matrix->show();

		TDA::Matrix* secondMatrix = new TDA::Matrix(n, m);
		std::cout << "Fill another matrix for multiplication please: " << std::endl;
		secondMatrix->fill();

		TDA::Matrix resultMatrix = *matrix * *secondMatrix;
		TDA::Matrix resultMatrix2 =  10 * *matrix * 2;

		if (resultMatrix != emptyMatrix)
		{
			std::cout << "Multiplicated matrix: " << std::endl;
			resultMatrix.show();

			std::cout << "Multiplicated on digit matrix: " << std::endl;
			resultMatrix2.show();
		}
		std::cout << "Do you want to continue? y/n  ";
		std::cin >> confirm;

		delete matrix;
		delete secondMatrix;
	} while (tolower(confirm) != 'n');
	return 0;
}

