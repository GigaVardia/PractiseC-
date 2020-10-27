#include <iostream>
#include <cstdlib>

using namespace std;

// Input AAAACCCCCBBXYZQQQQQQFFFFZZZBBBBBBBBBBBBBBB
// OUTPUT A4C5B2XYZQ6F4Z3B17

void addElement(char *&, char, int &); // masivis shevseba
void function(char *, int); // funqcia romelic asrulebs davalebas
void showArray(char *p, int size); // masivis ekranze gamotana

int main() {
	int size = 0; // masivsi tavdapirveli zoma
	char input = ' ';
	char *p_arr = new char[size];
	
	cout << "Enter letters:(Enter 0 to stop) ";
	
	while (cin >> input) { // shegvyavs asoebi
		if (input != '0') {
			addElement(p_arr, input, size);
		} else break;
	}
	
	showArray(p_arr, size); // masivis ekranze gamotana
	function(p_arr,size); // mocemuli davalebis shesruleba

	
	delete [] p_arr;
	
	return 0;
}

void addElement(char *&arr, char value, int &size) {
	char *newArray = new char[size+1]; // axali dinamiuri masivsi 
	
	for(int i = 0; i < size; i++)  // kopireba
	newArray[i]=arr[i];

	value = toupper(value);
	newArray[size]=value; // bolo indexze axali elementis chamateba
	
	size++;
	delete arr;
	arr = newArray;
}

void showArray(char *p, int size) { // masivis chveneba
	for (int i =0; i < size; i++) {
		cout << p[i];
	} cout << endl;
}
void function(char *p, int size) {
	int indx = 0; // aq inaxeba indexi imisa tu sanamde ganmeorda aso
	
	while (indx < size) {
		int repeat = 0; // aq inaxeba ramdenjer ganmeorda aso
		while (p[indx+1] == p[indx]) {
			repeat++;
			indx++;
		} 
		repeat++;
		indx++;
		cout << p[indx-1];
		if (repeat != 1) cout << repeat;
	}
	
}

