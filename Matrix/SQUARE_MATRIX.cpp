#include "SQUARE_MATRIX.h"

///////////// SHOW MAX MIN IN DIAGONAL //////////
void SQUARE_MATRIX::showMaxMinDG() {
	cout << "\nMax in main diagonal: " << MAX_IN_MAIN_DG << endl;
	cout << "Min in main diagonal: " << MIN_IN_MAIN_DG << endl;

	cout << "\nMax in not main diagonal: " << MAX_IN_NMAIN_DG << endl;
	cout << "Min in not main diagonal: " << MIN_IN_NMAIN_DG << endl;
}

///////////////// FIND MAX & MIN IN SQUARE MATRIX DIAGONAL ////////////
void SQUARE_MATRIX::FIND_MAX_MIN_DIAGONAL() {
	MAX_IN_MAIN_DG = MATRX[0][0]; // MAX IN MAIN DIAGONAL
	MIN_IN_MAIN_DG = MATRX[0][0]; // MIN IN MAIN DIAGONAL

	MAX_IN_NMAIN_DG = MATRX[MATRX[0].size() - 1][MATRX[0].size() - 1]; // MAX IN NOT MAIN DIAGONAL
	MIN_IN_NMAIN_DG = MATRX[MATRX[0].size() - 1][MATRX[0].size() - 1]; // MIN IN NOT MAIN DIAGONAL

	int clm = MATRX.size();

	for (size_t i = 0; i < MATRX.size(); i++) {
		for (size_t j = 0; j < MATRX[i].size(); j++) {
			if (i == j) {
				if (MATRX[i][j] > MAX_IN_MAIN_DG) MAX_IN_MAIN_DG = MATRX[i][j];
				if (MATRX[i][j] < MIN_IN_MAIN_DG) MIN_IN_MAIN_DG = MATRX[i][j];
			}
			if (i + j + 1 == clm) {
				if (MATRX[i][j] > MAX_IN_NMAIN_DG) MAX_IN_NMAIN_DG = MATRX[i][j];
				if (MATRX[i][j] < MIN_IN_NMAIN_DG) MIN_IN_NMAIN_DG = MATRX[i][j];
			}
		}
	}
}

///////////// ZERO DIAGONAL UP AND DOWN //////////////
void SQUARE_MATRIX::ZERO_MATRIX() {
	int MAIN_OR_NOT;
	int choose;

	cout << "Enter 1 to make actions on main diagonal: ";
	cout << "\nEnter 1 to make actions on not main diagonal: ";
	cout << "\nEnter 0 to exit: " << endl;
	cin >> MAIN_OR_NOT;
	system("cls");
	cout << "Enter 1 to replace with zeros all number up of diagonal: ";
	cout << "\nEnter 2 to replace with zeros all number down of diagonal: ";
	cout << "\nEnter 3 to replace up and down zeros of diagonal: ";
	cout << "\nEnter 0 to exit: " << endl;

	cin >> choose;

	if (MAIN_OR_NOT == 1)
		if (choose == 1) {
			for (size_t i = 0; i < MATRX.size(); i++) {
				for (size_t j = 0; j < MATRX[i].size(); j++) {
					if (i < j) MATRX[i][j] = 0;
				}
			}
		}
		else if (choose == 2) {
			for (size_t i = 0; i < MATRX.size(); i++) {
				for (size_t j = 0; j < MATRX[i].size(); j++) {
					if (i > j) MATRX[i][j] = 0;
				}
			}
		}
		else if (choose == 3) {
			for (size_t i = 0; i < MATRX.size(); i++) {
				for (size_t j = 0; j < MATRX[i].size(); j++) {
					if (i > j || i < j) MATRX[i][j] = 0;
				}
			}
		}
		else {
			return;
		}
	else if (MAIN_OR_NOT == 2) {
		if (choose == 1) {
			for (size_t i = 0; i < MATRX.size(); i++) {
				for (size_t j = 0; j < MATRX[i].size(); j++) {
					if (i + j < MATRX.size() - 1) MATRX[i][j] = 0;
				}
			}
		}
		else if (choose == 2) {
			for (size_t i = 0; i < MATRX.size(); i++) {
				for (size_t j = 0; j < MATRX[i].size(); j++) {
					if (i + j > MATRX.size() - 1) MATRX[i][j] = 0;
				}
			}
		}
		else if (choose == 3) {
			for (size_t i = 0; i < MATRX.size(); i++) {
				for (size_t j = 0; j < MATRX[i].size(); j++) {
					if ((i + j < MATRX.size() - 1) || (i + j > MATRX.size() - 1)) MATRX[i][j] = 0;
				}
			}
		}
		else {
			return;
		}
	}
	else {
		return;
	}

	for (size_t i = 0; i < MATRX.size(); i++) {
		for (size_t j = 0; j < MATRX[i].size(); j++) {
			cout << MATRX[i][j] << " ";

		}
		cout << endl;
	} cout << endl;
}
