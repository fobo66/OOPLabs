#ifndef TDA_H	//чтобы заголовочник подключался только один раз
#define TDA_H

namespace TDA {	//хороший тон
	/**
	 *	Класс-обёртка для двумерного массива - матрицы
	 */
	class Matrix
	{
	private:
		int Rows;
		int Cols;
		int** instance;	//собственно, двумерный массив
	public:
		/**
		 * Default constructor
		 */
		Matrix(int rows, int cols)
		{
			this->Cols = cols;
			this->Rows = rows;
			this->newInstance();
		}

		/**
		 * Copy constructor
		 */
		Matrix(const Matrix& source)
		{
			this->Cols = source.Cols;
			this->Rows = source.Rows;
			this->newInstance();

			this->fill(source);
		}

		/**
		 * Allocates memory for the matrix
		 */
		void newInstance();

		/**
		 * Fill matrix by hands from keyboard
		 */
		void fill();

		/**
		* Fill matrix from another matrix
		*/
		void fill(const Matrix&);

		/**
		 * Output matrix to stdout
		 */
		void show();

		/**
		 * Get element at position ( @param row , @param col )
		 */
		int getElement(int row, int col);

		/**
		 * Set element at position ( @param row , @param col ) with @param val value
		 */
		void setElement(int row, int col, int val);

		/**
		* (Overloaded) Multiply current matrix with another one @param multiplicant. Returns this on error
		*/
		Matrix operator*(Matrix&);

		/**
		* (Overloaded) Multiply current matrix to the grade
		*/
		Matrix operator*(int);

		/**
		* (Overloaded) Multiply current matrix to the grade vice versa
		*/
		friend Matrix operator*(int grade, const Matrix& matrix);

		/**
		 * Overloaded operator for consistent copying matrixes
		 */
		Matrix& operator=(const Matrix&);

		/**
		* Overloaded operator for comparing matrixes. Used for checking result of multiplication
		*/
		bool operator!=(const Matrix&);

		/**
		 * Destroy object
		 */
		~Matrix()
		{
			for (int i = 0; i < this->Cols; ++i)
				delete[] this->instance[i];
			delete[] this->instance;
		}
	};
}
#endif