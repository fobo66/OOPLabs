#include "stdafx.h"

using namespace TDA;

/**
 * Allocates memory for the matrix
 */
void Matrix::newInstance()
{
	this->instance = new int*[this->Rows];
	for (int i = 0; i < this->Cols; ++i)
		this->instance[i] = new int[this->Cols];
};

/**
 * Fill matrix by another matrix
 */
void Matrix::fill(const Matrix& source)
{
	for (int i = 0; i < this->Rows; ++i)
		for (int j = 0; j < this->Cols; ++j)
			this->instance[i][j] = source.instance[i][j];
};

/**
 * Fill matrix by hands from keyboard
 */
void Matrix::fill()
{
	for (int i = 0; i < this->Rows; ++i)
		for (int j = 0; j < this->Cols; ++j)
			std::cin >> this->instance[i][j];
};

/**
 * Output matrix to stdout
 */
void Matrix::show()
{
	for (int i = 0; i < this->Rows; ++i)
	{
		for (int j = 0; j < this->Cols; ++j)
			std::cout << this->instance[i][j] << " ";
		std::cout << "\n";
	}
};

/**
* Getter
*/
int Matrix::getElement(int row, int col)
{
	return this->instance[row][col];
};

/**
* Setter
*/
void Matrix::setElement(int row, int col, int val)
{
	this->instance[row][col] = val;
};

/**
* (Overloaded) Multiply current matrix with another one @param multiplicant. Returns this on error
*/
Matrix Matrix::operator*(Matrix& multiplicant)
{
	if (this->Cols != multiplicant.Rows)
	{
		std::cerr << "Unable to multiply matrixes: different sizes\n";
		return *this;
	}
	else
	{
		Matrix result(this->Rows, multiplicant.Cols);
		int i = 0, j = 0, k = 0, elem = 0;
		for (i = 0; i < this->Rows; ++i)
			for (j = 0; j < this->Cols; ++j)
			{
				elem = 0;
				for (k = 0; k < this->Rows; ++k)
					elem += this->instance[i][k] * multiplicant.getElement(k, j);
				result.setElement(i, j, elem);
			}
		return result;
	}
};

/**
* (Overloaded) Multiply current matrix to the grade
*/
Matrix Matrix::operator*(int grade)
{
		Matrix result(this->Rows, this->Cols);
		int i = 0, j = 0, k = 0, elem = 0;
		for (i = 0; i < this->Rows; ++i)
			for (j = 0; j < this->Cols; ++j)
				result.setElement(i, j, this->instance[i][j] * grade);
		return result;
};

/**
* (Overloaded) Multiply current matrix to the grade vice versa
*/
Matrix TDA::operator*(int grade, const Matrix& matrix)
{
	Matrix result(matrix.Rows, matrix.Cols);
	int i = 0, j = 0, k = 0, elem = 0;
	for (i = 0; i < matrix.Rows; ++i)
		for (j = 0; j < matrix.Cols; ++j)
			result.setElement(i, j, matrix.instance[i][j] * grade);
	return result;
};

/**
 * Overloaded operator for consistent copying matrixes
 */
Matrix& Matrix::operator=(const Matrix& second) 
{
	if (this != &second)
	{
		delete[] instance;// this;
		this->Rows = second.Rows;
		this->Cols = second.Cols;
		this->newInstance();

		this->fill(second);
	}

	return *this;
};

/**
 * Overloaded operator for comparing matrixes. Used for checking result of multiplication
 */
bool Matrix::operator!=(const Matrix& second)
{
	if (this != &second)
		return this->Cols != second.Cols &&
			   this->Rows != second.Rows &&
			   this->instance != second.instance;
	return false;
};
