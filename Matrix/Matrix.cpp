#include "Matrix.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>

using namespace std;
////////////////// OPERATOR + OVERLOADING /////////////
vector<vector<int>> Matrix::operator + (Matrix m2) {
	vector<vector<int>> C;
	C.assign(this->getColumns(), vector<int>(this->getRows()));
	for (int i = 0; i < this->getColumns(); i++)
		for (int j = 0; j < this->getRows(); j++)
			C[i][j] = this->MATRX[i][j] + m2.MATRX[i][j];

	return C;
}

////////////////// OPERATOR - OVERLOADING /////////////
vector<vector<int>> Matrix::operator - (Matrix m2) {
	vector<vector<int>> C;
	C.assign(this->getColumns(), vector<int>(this->getRows()));
	for (int i = 0; i < this->getColumns(); i++)
		for (int j = 0; j < this->getRows(); j++)
			C[i][j] = this->MATRX[i][j] - m2.MATRX[i][j];

	return C;
}

////////////// OPERATOR * OVERLOADING ///////////////
vector<vector<int>> Matrix::operator * (Matrix m2) {
	vector<vector<int>> C;
	C.assign(this->getColumns(), vector<int>(m2.getRows()));
	for (int i = 0; i < this->getColumns(); i++)
	{
		for (int j = 0; j < m2.getRows(); j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < m2.getColumns(); k++)
				C[i][j] += this->MATRX[i][k] * m2.MATRX[k][j];
		}
	}
	return C;
}

/////// FIND MAX ////////////
void Matrix::FIND_MAX() {
	int TEMP_MAX = MATRX[0][0];
	for (size_t i = 0; i < MATRX.size(); i++) {
		for (size_t j = 0; j < MATRX[i].size(); j++) {
			if (TEMP_MAX < MATRX[i][j]) {
				TEMP_MAX = MATRX[i][j];
			}
		}
	}
	MAX = TEMP_MAX;
}

/////////// FIND MIN /////////////
void Matrix::FIND_MIN() {
	int TEMP_MIN = MATRX[0][0];
	for (size_t i = 0; i < MATRX.size(); i++) {
		for (size_t j = 0; j < MATRX[i].size(); j++) {
			if (TEMP_MIN > MATRX[i][j]) {
				TEMP_MIN = MATRX[i][j];
			}
		}
	}
	MIN = TEMP_MIN;
}

////// FIND MAX AND MIN IN ALL COLUMN //////////
void Matrix::FIND_MAX_AND_MIN_IN_ALL_COLUMN() {
	MAX_IN_COLUMN.assign(COLUMNS, 0);
	MIN_IN_COLUMN.assign(COLUMNS, 0);

	for (size_t i = 0; i < MATRX.size(); i++) {
		MAX_IN_COLUMN[i] = MATRX[i][0];
		MIN_IN_COLUMN[i] = MATRX[i][0];
		for (size_t j = 0; j < MATRX[i].size(); j++) {
			if (MAX_IN_COLUMN[i] < MATRX[i][j]) {
				MAX_IN_COLUMN[i] = MATRX[i][j];
			}
			if (MIN_IN_COLUMN[i] > MATRX[i][j]) {
				MIN_IN_COLUMN[i] = MATRX[i][j];
			}
		}
	}

}

////// FIND MAX AND MIN IN ALL ROW //////////
void Matrix::FIND_MAX_AND_MIN_IN_ALL_ROW() {
	MAX_IN_ROW.assign(ROWS, 0);
	MIN_IN_ROW.assign(ROWS, 0);

	for (int i = 0; i < ROWS; i++)
	{
		MAX_IN_ROW[i] = MATRX[0][i];
		MIN_IN_ROW[i] = MATRX[0][i];
		for (int j = 0; j < COLUMNS; j++) {
			if (MAX_IN_ROW[i] < MATRX[j][i]) {
				MAX_IN_ROW[i] = MATRX[j][i];
			}
			if (MIN_IN_ROW[i] > MATRX[j][i]) {
				MIN_IN_ROW[i] = MATRX[j][i];
			}
		}
	}
}

/////////////// FILL MATRIX WITH RANDOM NUMBERS //////////////
void Matrix::FILL_RANDOM_MATRIX(int a, int b) {
	srand((unsigned)time(NULL));
	if (a > b) {
		int tempB = b;
		b = a;
		a = tempB;
	}

	for (size_t i = 0; i < MATRX.size(); i++)
	{
		for (size_t j = 0; j < MATRX[i].size(); j++)
		{
			MATRX[i][j] = rand() % (b - a + 1) + a;
		}
	}
}

//////////////// FILL MATRIX /////////////////
void Matrix::FILL_MATRIX() {
	int num;
	for (int i = 0; i < getColumns(); i++)
	{
		for (int j = 0; j < getRows(); j++)
		{
			cout << "Enter [" << i + 1 << "][" << j + 1 << "] : ";
			cin >> num;
			MATRX[i][j] = num;
		}
	}
}

////////////// SHOW MATRIX //////////////////
void Matrix::SHOW_MATRX() {
	for (int i = 0; i < getColumns(); i++)
	{
		for (int j = 0; j < getRows(); j++)
		{
			cout << MATRX[i][j] << " ";
		}
		cout << endl;
	}
}

////////// SHOW MAX AND MIN ELEMENTS ///////////
void Matrix::SHOW_MAX_MIN() {
	for (size_t i = 0; i < MAX_IN_COLUMN.size(); i++) {
		cout << "\nMax in column " << i + 1 << " - " << MAX_IN_COLUMN[i];
		cout << "\nMin in column " << i + 1 << " - " << MIN_IN_COLUMN[i];

		cout << endl;
	}

	for (size_t i = 0; i < MAX_IN_ROW.size(); i++) {
		cout << "\nMax in row " << i + 1<< " - " << MAX_IN_ROW[i];
		cout << "\nMin in row " << i + 1<< " - " << MIN_IN_ROW[i];

		cout << endl;
	}
}