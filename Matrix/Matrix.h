#pragma once
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
///// CLASS MATRIX ////
class Matrix {
protected:
	int COLUMNS, ROWS;
	int MAX, MIN;

	vector<int> MAX_IN_COLUMN; // MAX ELEMENT IN ALL COLUMN
	vector<int> MIN_IN_COLUMN; // MIN ELEMENT IN ALL COLUMN

	vector<int> MAX_IN_ROW; // MAX ELEMENT IN ALL ROWS
	vector<int> MIN_IN_ROW; // MIN ELEMENT IN ALL ROWS

	vector<vector<int>> MATRX; // MATRIX
public:
	Matrix(int clm = 0, int row = 0) { // ANOTHER CONSTRUCTOR
		COLUMNS = clm;
		ROWS = row;

		MATRX.assign(clm, vector<int>(row));

		MAX = 0;
		MIN = 0;
	}

	virtual ~Matrix() = default;

	friend void MATRIX_ADDITION_DB(vector<shared_ptr<Matrix>>& matrx, int); /// ADDITON MATRIX FROM DATABASE
	friend void MATRIX_SUBTRACTION_DB(vector<shared_ptr<Matrix>>& matrx, int); /// SUBTRACTION MATRIX FROM DATABASE 
	friend void MATRIX_MULTIPLICATION_DB(vector<shared_ptr<Matrix>>& matrx, int); /// MULTIPLICATION MATRIX FROM DATABASE
	friend void MATRIX_SORT(vector<shared_ptr<Matrix>>& matrx, int); /// SORT MATRIX
	vector<vector<int>> operator + (Matrix m2); ////////////// OPERATOR + OVERLOADING
	vector<vector<int>> operator - (Matrix m2); ///////////// OPERATOR - OVERLOADING
	vector<vector<int>> operator * (Matrix m2); //////////// OPERATOR * OVERLOADING
	void FIND_MAX();
	void FIND_MIN();
	void FIND_MAX_AND_MIN_IN_ALL_COLUMN();
	void FIND_MAX_AND_MIN_IN_ALL_ROW();

	void FILL_RANDOM_MATRIX(int, int);
	void FILL_MATRIX();
	void SHOW_MATRX();
	void SHOW_MAX_MIN();

	//void setColumns(int clm) { COLUMNS = clm; } // SET COLUMNS
	int getColumns() { return COLUMNS; } // GET COLUMNS

	//void setRows(int rows) { ROWS = rows; } // SET ROWS
	int getRows() { return ROWS; } // GET ROWS
	int getMax() { return MAX; } // GET MAX
	int getMin() { return MIN; } // GET MIN*/
};
