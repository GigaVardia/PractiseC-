#include <iostream>

using namespace std;

void print(); // matricis ekranze gamoyvanis funqcia

const int mn = 10; // matricis zoma

int matrx[mn][mn]; // matrica mn zomit

int main() {
	int count = 1; // mtvleli
	int k = mn / 2; // spiraluri matricis funqciis shesrulebis raodenobis ganmsazgvreli
	if (mn % 2 != 0) k++;

	// pirobebi
	int down = 0;
	int left = 0;
	int up = mn - 1;
	int right = mn - 1;

	int f1_down = 0;
	int f1_left = mn - 2;
	int f1_up = mn - 2;
	int f1_right = 1;

	int f1_mnDown = 0;
	int f1_mnRight = 0;
	int f1_mnUp = 0;
	int f1_mnleft = 0;

	while (k > 0) {

		for (int i = f1_down; i < mn - f1_mnDown; i++) { // qvevit
			matrx[i][down] = count++;
		}

		for (int j = f1_right; j < mn - f1_mnRight; j++) { //marjvniv
			matrx[right][j] = count++;
		}

		for (int i = f1_up; i >= f1_mnUp; i--) { // zevit
			matrx[i][up] = count++;
		}

		for (int j = f1_left; j > f1_mnleft; j--) { // marcxniv
			matrx[left][j] = count++;
		}

		//pirobebis shecvla
		f1_down++;
		down++;
		f1_mnDown++;

		right--;
		f1_right++;
		f1_mnRight++;

		f1_up--;
		up--;
		f1_mnUp++;

		f1_mnleft++;
		f1_left--;
		left++;

		k--;
	}

	print();

	return 0;
}

void print() {
	for (int i = 0; i < mn; i++) {
		for (int j = 0; j < mn; j++) {
			cout << matrx[i][j] << " ";
		}
		cout << endl;
	}
}
