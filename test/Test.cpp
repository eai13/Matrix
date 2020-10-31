#include <iostream>
#include "../include/MatrixLib.h"

using namespace std;

int main(){
	Matrix M(3, 3);
	Matrix M1(3, 2);
	cin >> M;
	cout << "M" << endl << M;
	cout << "M1" << endl << M1;
	cout << (M1 == M) << endl;
	M *= 0.5;
	cout << M;
	//M *= M1;
	return 0;
}