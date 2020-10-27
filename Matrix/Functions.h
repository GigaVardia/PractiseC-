#pragma once
#include "Matrix.h"
#include "SQUARE_MATRIX.h"
#include <iostream>
#include <vector>
#include <memory>
#include <windows.h>

using namespace std;

////////// FOR CHANGING TEXT COLOR /////////////
void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

//////////// SHOW ALL MATRIX IN DATABASE ///////////
void SHOW_ALL_MATRIX(vector<shared_ptr<Matrix>>& matrx) {
	for (size_t i = 0; i < matrx.size(); i++)
	{
		cout << "N = " << i + 1 << ":" << endl;
		matrx[i]->SHOW_MATRX();
		cout << endl;
	}
}

////////////// SHOW MATRIX ////////
void showMatrix(vector<vector<int>> matrx) {
	for (size_t i = 0; i < matrx.size(); i++) {
		for (size_t j = 0; j < matrx[i].size(); j++) {
			cout << matrx[i][j] << " ";

		}
		cout << endl;
	}
}

////////////// MATRIX ADDITION FROM DATABASE ////////// 
void MATRIX_ADDITION_DB(vector<shared_ptr<Matrix>>& matrx, int mtrxNum) {
	int matrxIndexDB;  /// MATRIX INDEX FROM DATABASE
	vector<vector<int>> C;
	cout << "Enter which matrix add: ";
	SetColor(4, 0);
	cout << "\nTake into account - Matrix size must be same!!!\n";
	SetColor(7, 0);

	cin >> matrxIndexDB;
	matrxIndexDB -= 1;

	if ((matrx[mtrxNum]->getColumns() == matrx[matrxIndexDB]->getColumns()) && (matrx[mtrxNum]->getRows() == matrx[matrxIndexDB]->getRows())) {
		C = *(matrx[mtrxNum]) + *(matrx[matrxIndexDB]); ///// MATRIX ADDITION

		system("cls");
		matrx[mtrxNum]->SHOW_MATRX();
		cout << " + " << endl;
		matrx[matrxIndexDB]->SHOW_MATRX();
		cout << " = " << endl;;

		showMatrix(C);

		int pushBackC;
		cout << "\nEnter 1 to add result matrix in database: ";
		cout << "\nEnter 0 to exit: \n";
		cin >> pushBackC;

		int columnC = (int)C.size();
		int rowC = (int)C[0].size();
		if (pushBackC == 1 && (columnC == rowC)) { /// IF C IS SQUARE MATRIX
			matrx.push_back(make_shared<Matrix>(columnC));
			matrx[matrx.size() - 1]->MATRX = C;
		}
		else if (pushBackC == 1 && (int)C.size() != (int)C[0].size()) {
			matrx.push_back(make_shared<Matrix>(columnC, rowC));
			matrx[matrx.size() - 1]->MATRX = C;
		}
		else {
			system("cls");
			return;
		}
	}
	else {
		cout << "Matrix's size are not same!!!\n";
		return;
	}
}

////////////// MATRIX SUBTRACTION FROM DATABASE //////////
void MATRIX_SUBTRACTION_DB(vector<shared_ptr<Matrix>>& matrx, int mtrxNum) {
	int matrxIndexDB;  /// MATRIX INDEX FROM DATABASE
	vector<vector<int>> C;
	cout << "Enter which matrix substract: ";
	SetColor(4, 0);
	cout << "\nTake into account - Matrix size must be same!!!\n";
	SetColor(7, 0);

	cin >> matrxIndexDB;
	matrxIndexDB -= 1;

	if ((matrx[mtrxNum]->getColumns() == matrx[matrxIndexDB]->getColumns()) && (matrx[mtrxNum]->getRows() == matrx[matrxIndexDB]->getRows())) {
		C = *(matrx[mtrxNum]) - *(matrx[matrxIndexDB]);

		system("cls");
		matrx[mtrxNum]->SHOW_MATRX();
		cout << " - " << endl;
		matrx[matrxIndexDB]->SHOW_MATRX();
		cout << " = " << endl;;

		showMatrix(C);

		int pushBackC;
		cout << "\nEnter 1 to add result matrix in database: ";
		cout << "\nEnter 0 to exit: \n";
		cin >> pushBackC;

		int columnC = (int)C.size();
		int rowC = (int)C[0].size();
		if (pushBackC == 1 && (columnC == rowC)) { /// IF C IS SQUARE MATRIX
			matrx.push_back(make_shared<Matrix>(columnC));
			matrx[matrx.size() - 1]->MATRX = C;
		}
		else if (pushBackC == 1 && (int)C.size() != (int)C[0].size()) {
			matrx.push_back(make_shared<Matrix>(columnC, rowC));
			matrx[matrx.size() - 1]->MATRX = C;
		}
		else {
			return;
		}
	}
	else {
		cout << "Matrix's size are not same!!!\n";
		return;
	}
}

///////////////////// MATRIX MULTIPLICATION /////////////
void MATRIX_MULTIPLICATION_DB(vector<shared_ptr<Matrix>>& matrx, int mtrxNum) {
	vector<vector<int>> C;
	int colA = matrx[mtrxNum]->getColumns();
	int rowA = matrx[mtrxNum]->getRows();

	int UserMatrixIndex;
	cout << "Enter which matrix multiply: ";
	cin >> UserMatrixIndex;
	UserMatrixIndex -= 1;

	int colB = matrx[UserMatrixIndex]->getColumns();
	int rowB = matrx[UserMatrixIndex]->getRows();

	if (rowA != colB) {
		cout << "Can't multiply, A matrix column size must be same B matrix row size";
		return;
	}

	system("cls");

	////// SHOW MULTIPLICATION DETAILS ///////
	matrx[mtrxNum]->SHOW_MATRX();
	cout << " * \n";
	matrx[UserMatrixIndex]->SHOW_MATRX();
	cout << " = \n";

	///////// MULTIPLICATION
	C = *(matrx[mtrxNum]) * (*(matrx[UserMatrixIndex])); ////////// MATRIX MULTIPLICATION .. OVERLOADIING *

	showMatrix(C);

	int pushBackC;
	cout << "\nEnter 1 to add result matrix in database: ";
	cout << "\nEnter 0 to exit: \n";
	cin >> pushBackC;

	int columnC = (int)C.size();
	int rowC = (int)C[0].size();
	if (pushBackC == 1 && (columnC == rowC)) { /// IF C IS SQUARE MATRIX
		matrx.push_back(make_shared<Matrix>(columnC));
		matrx[matrx.size() - 1]->MATRX = C;
	}
	else if (pushBackC == 1 && (int)C.size() != (int)C[0].size()) {
		matrx.push_back(make_shared<Matrix>(columnC, rowC));
		matrx[matrx.size() - 1]->MATRX = C;
	}
	else {
		return;
	}
}

////////////// MATRIX SORT /////////////
void MATRIX_SORT(vector<shared_ptr<Matrix>>& matrx, int matrxIndex) {
	int choose;
	cout << "Enter 1 to sort high-low: ";
	cout << "\nEnter 2 to sort low-high: \n";
	cin >> choose;

	int c = matrx[matrxIndex]->getColumns();
	int r = matrx[matrxIndex]->getRows();

	if (choose == 1) {
		vector<int> temp;
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				temp.push_back(matrx[matrxIndex]->MATRX[i][j]);
			}
		}

		sort(temp.begin(), temp.end());

		int k = 0;
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				matrx[matrxIndex]->MATRX[i][j] = temp[k];
				++k;
			}
		}
	} if (choose == 2) {
		vector<int> temp;
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				temp.push_back(matrx[matrxIndex]->MATRX[i][j]);
			}
		}

		sort(temp.begin(), temp.end());
		reverse(temp.begin(), temp.end());

		int k = 0;
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				matrx[matrxIndex]->MATRX[i][j] = temp[k];
				++k;
			}
		}
	}

	matrx[matrxIndex]->SHOW_MATRX();
}

////////////// CREATE NEW MATRIX ////////////
void NEW_MATRIX(vector<shared_ptr<Matrix>>& matrx) {
	static int MATRIX_NUM = 0; // matricis raodenobis dasatvelelad
	int col, row;
	int a, b;
	int RANDOM_OR_MANUAL;

	//////////////// AXALI MATRICA //////////////
	cout << "Enter row size: ";
	cin >> col;

	while (col < 2) {
		cout << "\nEnter size more than 1: ";
		cin >> col;
	}

	//////// ENTER ROW ////////////
	cout << "Enter column size: ";
	cin >> row;

	while (row < 2) {
		cout << "\nEnter size more than 1: ";
		cin >> row;
	}

	if (col != row) matrx.push_back(make_shared<Matrix>(col, row));
	if (col == row) {
		matrx.push_back(make_shared<SQUARE_MATRIX>(col));
	}

	system("CLS");

	cout << "Enter 1 to fill matrix by user: ";
	cout << "\nEnter 0 to fill with random numbers: ";;

	cin >> RANDOM_OR_MANUAL;

	if (RANDOM_OR_MANUAL == 1) {
		matrx[MATRIX_NUM]->FILL_MATRIX();
		matrx[MATRIX_NUM]->SHOW_MATRX();
	}
	else if (RANDOM_OR_MANUAL == 0) {
		cout << "Enter range, a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;

		matrx[MATRIX_NUM]->FILL_RANDOM_MATRIX(a, b);

		matrx[MATRIX_NUM]->SHOW_MATRX();
	}
	else {
		cout << "ERROR!!!" << endl;
		return;
	}
	matrx[MATRIX_NUM]->FIND_MAX();
	matrx[MATRIX_NUM]->FIND_MIN();
	matrx[MATRIX_NUM]->FIND_MAX_AND_MIN_IN_ALL_COLUMN();
	matrx[MATRIX_NUM]->FIND_MAX_AND_MIN_IN_ALL_ROW();
	if (col == row) static_pointer_cast<SQUARE_MATRIX>(matrx[MATRIX_NUM])->FIND_MAX_MIN_DIAGONAL();
	++MATRIX_NUM;
}

//////////////// FUNCTIONS OF MATRIX ///////////
void functionMatrix(vector<shared_ptr<Matrix>>& matrx) {
	system("cls");
	int matrxNum;
	int menu;

	cout << "Enter matrix index: \n";
	SHOW_ALL_MATRIX(matrx);
	cin >> matrxNum;
	system("cls");

	if (matrxNum > (int)matrx.size()) {
		SetColor(4, 0);
		cout << "\nCan't find N" << matrxNum << " matrix!!!\n";
		SetColor(7, 0);
		return;
	}
	matrxNum -= 1;

	matrx[matrxNum]->SHOW_MATRX();

	cout << "Enter 0 to show info about max and min elements: ";
	cout << "\nEnter 1 to add matrix from database: ";
	SetColor(4, 0);
	cout << "\nTake into account matrix size must be same!!!\n";
	SetColor(7, 0);
	cout << "\nEnter 2 to substract matrix from database: ";
	SetColor(4, 0);
	cout << "\nTake into account matrix size must be same!!!\n";
	SetColor(7, 0);
	cout << "\nEnter 3 to multiply on matrix from database: ";
	cout << "\nEnter 4 to sort matrix: ";
	if (matrx[matrxNum]->getColumns() == matrx[matrxNum]->getRows()) {
		cout << "\nEnter 5 to make zero all number up or down of matrix diagonal: ";
	}

	cin >> menu;

	switch (menu)
	{
	case 0:
		system("cls");
		matrx[matrxNum]->SHOW_MATRX();
		cout << "\nMax element in Matrix: " << matrx[matrxNum]->getMax() << endl;
		cout << "Min element in Matrix: " << matrx[matrxNum]->getMin() << endl;
		matrx[matrxNum]->SHOW_MAX_MIN();
		if (matrx[matrxNum]->getColumns() == matrx[matrxNum]->getRows())static_pointer_cast<SQUARE_MATRIX>(matrx[matrxNum])->showMaxMinDG();
		break;
	case 1:
		system("cls");
		MATRIX_ADDITION_DB(matrx, matrxNum); ///// MATRIX ADDITION FUNCTION CALL //// 
		break;
	case 2:
		system("cls");
		MATRIX_SUBTRACTION_DB(matrx, matrxNum); ///// MATRIX SUBTRACTION FUNCTION CALL //// 
		break;
	case 3:
		system("cls");
		MATRIX_MULTIPLICATION_DB(matrx, matrxNum); ///// MATRIX MULTIPLICATION FUNCTION CALL /////
		break;
	case 4:
		system("cls");
		MATRIX_SORT(matrx, matrxNum);
		break;
	case 5:
		system("cls");
		static_pointer_cast<SQUARE_MATRIX>(matrx[matrxNum])->ZERO_MATRIX();
		break;
	default:
		return;
		break;
	}

}
