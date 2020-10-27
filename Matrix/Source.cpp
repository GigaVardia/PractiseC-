#include <iostream>
#include <vector>
#include <algorithm> 
#include <memory>
#include "Matrix.h"
#include "Functions.h"
#include "SQUARE_MATRIX.h"

using namespace std;

///////////////// MAIN FUNCTION //////////////
int main() {
	int NEW_MATRIX_OR_MENU;

	vector<shared_ptr<Matrix>> matrx; /////////// VECTOR OF POINTERS ON MATRIX OBJECT

	do {
		//////// CREATE NEW MATRIX OR RUN FUNCTIONS ///////////
		cout << "Enter 1 to create new matrix: ";
		cout << "\nEnter 0 to do some actions on matrix: ";
		cout << "\nEnter 2 to exit: ";
		cin >> NEW_MATRIX_OR_MENU;
		if (NEW_MATRIX_OR_MENU == 0 && matrx.empty())
		{
			cout << "Database is empty.";
			NEW_MATRIX_OR_MENU = -1;
		}

		////////// INPUT ONLY 0 1 OR 2 ////////
		while (NEW_MATRIX_OR_MENU != 0 && NEW_MATRIX_OR_MENU != 1 && NEW_MATRIX_OR_MENU != 2) {
			cout << "\nEnter 0 or 1(enter 2 to exit): ";
			cin >> NEW_MATRIX_OR_MENU;
			if (NEW_MATRIX_OR_MENU == 0 && matrx.empty())
			{
				cout << "Database is empty.";
				NEW_MATRIX_OR_MENU = -1;
			}
			else if (NEW_MATRIX_OR_MENU == 2) break;
		}

		if (NEW_MATRIX_OR_MENU == 2) break; 

		if (NEW_MATRIX_OR_MENU == 1) NEW_MATRIX(matrx); 
			else if (NEW_MATRIX_OR_MENU == 0) functionMatrix(matrx); 
	} while (true);

	return 0;
}

