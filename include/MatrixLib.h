#ifndef MATRIX_H
#define MATRIX_H

// Main matrix class
struct Matrix{
	public:
		// Constructor for (rows X cols) size of matrix initialization
		explicit Matrix(int rows, int cols);
		// Constructor for square matrix initialization
		explicit Matrix(int size);
		// Assignment
		Matrix const & operator = (Matrix const & mat1);
		// Matrix Fill
		friend std::istream & operator >> (std::istream& in, Matrix const & matrix);
		// Matrix Output
		friend std::ostream & operator << (std::ostream& out, Matrix const & matrix);
		// Matrix Addition
		friend Matrix const & operator + (Matrix const & mat1, Matrix const & mat2);
		Matrix const & operator += (Matrix const & mat1);
		// Matrix Subtraction
		friend Matrix const & operator - (Matrix const & mat1, Matrix const & mat2);
		Matrix const & operator -= (Matrix const & mat1);
		// Matrix Multiplication
		friend Matrix const & operator * (Matrix const & mat1, Matrix const & mat2);
		friend Matrix const & operator * (Matrix const & mat1, double num);
		friend Matrix const & operator * (double num, Matrix const & mat1);
		Matrix const & operator *= (Matrix const & mat1);
		Matrix const & operator *= (double num);
		// Matrix equality
		bool operator == (Matrix const & mat1);
		// Destructor
		~Matrix();
	private:
		// Matrix Elements
		double** element;
		// Matrix Rows amount
		int rows;
		// Matrix Cols amount
		int cols;
};

std::istream& operator >> (std::istream& in, const Matrix& matrix);
std::ostream& operator << (std::ostream& out, const Matrix& matrix);
Matrix const & operator + (Matrix const & mat1, Matrix const & mat2);
Matrix const & operator - (Matrix const & mat1, Matrix const & mat2);
Matrix const & operator * (Matrix const & mat1, Matrix const & mat2);
Matrix const & operator * (Matrix const & mat1, int num);
Matrix const & operator * (Matrix const & mat1, double num);
Matrix const & operator * (int num, Matrix const & mat1);
Matrix const & operator * (double num, Matrix const & mat1);

#endif