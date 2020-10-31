#include <iostream>
#include <stdlib.h>
#include "../include/MatrixLib.h"

// Constructor 1
// Creates a matrix of zeros of (rows X cols) size
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
	element = new double* [this->rows];
	element[0] = new double [this->rows * this->cols];
	for (int i = 1; i < this->rows; i++){
		element[i] = element[i - 1] + this->cols;
	}
	for (int i = 0; i < this->rows; i++){
		for (int j = 0; j < this->cols; j++){
			this->element[i][j] = 0;
		}
	}
}

// Constructor 2
// Creates a square matrix of zeros of (size X size) size
Matrix::Matrix(int size) : rows(size), cols(size){
	element = new double* [this->rows];
	element[0] = new double [this->rows * this->cols];
	for (int i = 1; i < this->rows; i++){
		element[i] = element[i - 1] + this->cols;
	}
	for (int i = 0; i < this->rows; i++){
		for (int j = 0; j < this->cols; j++){
			this->element[i][j] = (double)0;
		}
	}
}

// >>
// Hand-filling the matrix through the console
std::istream& operator >> (std::istream& in, Matrix const & matrix){
	for (int i = 0; i < matrix.rows; i++){
		for (int j = 0; j < matrix.cols; j++){
			std::cout << "[" << i + 1 << "][" << j + 1 << "]";
			in >> matrix.element[i][j];
		}
	}
	return in;
}

// <<
// Output the matrix into the console
std::ostream& operator << (std::ostream& out, Matrix const & matrix){
	for (int i = 0; i < matrix.rows; i++){
		if (i == 0){
			out << "/";
		}
		else if (i == matrix.rows - 1){
			out << "\\";
		}
		else{
			out << "|";
		}
		for (int j = 0; j < matrix.cols; j++){
			out << matrix.element[i][j];
			if (j < matrix.cols - 1){
				out << "\t";
			}
		}
		if (i == 0){
			out << "\\";
		}
		else if (i == matrix.rows - 1){
			out << "/";
		}
		else{
			out << "|";
		}
		out << std::endl;
	}
	return out;
}			

// +
// Matrix addition
Matrix const & operator + (Matrix const & mat1, Matrix const & mat2){
	if ((mat1.rows == mat2.rows) and (mat1.cols == mat2.cols)){
		Matrix* mat = new Matrix(mat1.rows, mat1.cols);
		for (int i = 0; i < mat->rows; i++){
			for (int j = 0; j < mat->cols; j++){
				mat->element[i][j] = mat1.element[i][j] + mat2.element[i][j];
			}
		}
		return *mat;
	}
	else{
		std::cout << "Wrong matrix sizes" << std::endl;
		return mat1;
	}
}

// +=
// Matrix addition (short)
Matrix const & Matrix::operator += (Matrix const & mat1){
	if ((this->rows == mat1.rows) and (this->cols == mat1.cols)){
		for (int i = 0; i < this->rows; i++){
			for (int j = 0; j < this->cols; j++){
				this->element[i][j] += mat1.element[i][j];
			}
		}
		return *this;
	}
	else{
		std::cout << "Wrong matrix sizes" << std::endl;
		return *this;
	}
}

// -
// Matrix subtract
Matrix const & operator - (Matrix const & mat1, Matrix const & mat2){
	if ((mat1.rows == mat2.rows) and (mat1.cols == mat2.cols)){
		Matrix* mat = new Matrix(mat1.rows, mat2.cols);
		for (int i = 0; i < mat->rows; i++){
			for (int j = 0; j < mat->cols; j++){
				mat->element[i][j] = mat1.element[i][j] - mat2.element[i][j];
			}
		}
		return *mat;
	}
	else{
		std::cout << "Wrong matrix sizes" << std::endl;
		return mat1;
	}
}

// -=
// Matrix subtract (short)
Matrix const & Matrix::operator -= (Matrix const & mat1){
	if ((this->rows == mat1.rows) and (this->cols == mat1.cols)){
		for (int i = 0; i < this->rows; i++){
			for (int j = 0; j < this->cols; j++){
				this->element[i][j] -= mat1.element[i][j];
			}
		}
		return *this;
	}
	else{
		std::cout << "Wrong matrix sizes" << std::endl;
		return *this;
	}
}

// =
// Matrix assignment
Matrix const & Matrix::operator = (Matrix const & mat1){
	delete [] this->element[0];
	delete [] this->element;
	this->rows = mat1.rows;
	this->cols = mat1.cols;
	this->element = new double* [this->rows];
	this->element[0] = new double [this->rows * this->cols];
	for (int i = 1; i < this->rows; i++){
		this->element[i] = this->element[i - 1] + this->cols;
	}
	for (int i = 0; i < this->rows; i++){
		for (int j = 0; j < this->cols; j++){
			this->element[i][j] = mat1.element[i][j];
		}
	}
	return *this;
}

// *
// Matrix multiplication
Matrix const & operator * (Matrix const & mat1, Matrix const & mat2){
	if (mat1.cols == mat2.rows){
		Matrix* mat = new Matrix(mat1.rows, mat2.cols);
		for (int i = 0; i < mat->rows; i++){
			for (int j = 0; j < mat->cols; j++){
				for (int k = 0; k < mat1.cols; k++){
					mat->element[i][j] += mat1.element[i][k] * mat2.element[j][k];
				}
			}
		}
		return *mat;
	}
	else{
		std::cout << "Wrong matrix sizes" << std::endl;
		return mat1;
	}
}

Matrix const & operator * (Matrix const & mat1, double num){
	for (int i = 0; i < mat1.rows; i++){
		for (int j = 0; j < mat1.cols; j++){
			mat1.element[i][j] *= num;
		}
	}
	return mat1;
}

Matrix const & operator * (double num, Matrix const & mat1){
	for (int i = 0; i < mat1.rows; i++){
		for (int j = 0; j < mat1.cols; j++){
			mat1.element[i][j] *= num;
		}
	}
	return mat1;
}

// *=
// Matrix Multiplication (short)
Matrix const & Matrix::operator *= (Matrix const & mat1){
	if (this->cols == mat1.rows){
		Matrix* mat = new Matrix(this->rows, mat1.cols);
		for (int i = 0; i < mat->rows; i++){
			for (int j = 0; j < mat->cols; j++){
				for (int k = 0; k < this->cols; k++){
					mat->element[i][j] += this->element[i][k] * mat1.element[j][k];
				}
			}
		}
		delete [] this->element[0];
		delete [] this->element;
		*this = *mat;
		return *this;
	}
	else{
		std::cout << "Wring matrix sizes" << std::endl;
		return *this;
	}
}

Matrix const & Matrix::operator *= (double num){
	for (int i = 0; i < this->rows; i++){
		for (int j = 0; j < this->cols; j++){
			this->element[i][j] *= num;
		}
	}
	return *this;
}

// ==
// Matrix equality
bool Matrix::operator == (Matrix const & mat1){
	if ((this->rows == mat1.rows) and (this->cols == mat1.cols)){
		for (std::size_t i = 0; i < this->cols; i++){
			for (std::size_t j = 0; j < this->rows; j++){
				if (this->element[i][j] != mat1.element[i][j]){
					return false;
				}
			}
		}
		return true;
	}
	else{
		return false;
	}
}

// Destructor
Matrix::~Matrix(){
	delete [] element[0];
	delete [] element;
}






































