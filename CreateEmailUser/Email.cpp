#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

// emaili unda iyos 6 asoze meti da aucileblad unda mtavrdebodes @email.com - it
// ertnairi emailebi ar sheidzleba arsebobdes

// parolshi unda iyos 2 ze meti cifri
// parolshi ar unda iyos simboloebi
// parolshi unda iyos 6 ze meti aso 
// paroli ar unda iyos 20 ze didi
// paroli ar unda emtxveodes mails

using namespace std;

////////////////////////// USER CLASS ////////////////////////
class User {
private:
	string userName; // saxeli
	string userSurname; // gvardi
	struct date { // dabadebis tarigi
		int year;
		int month;
		int day;
	} Date;
	string userEmail; // email
	string userPassword; // password
public:
	User() {
		userName = "user";
		userSurname = "userSuname";
		userEmail = "user@email.com";
		userPassword = "useruser";
		Date.year = 0;
		Date.month = 0;
		Date.day = 0;
	}
	~User() {};
	void setName(string st) { userName = st; } 
	string getName() { return userName; }

	void setSurname(string st) { userSurname = st; }
	string getSurname() { return userSurname; }

	void setYear(int yr) { Date.year = yr; }
	int getYear() { return Date.year; }

	void setMonth(int mnth) { Date.month = mnth; }
	int getMonth() { return Date.month; }

	void setDay(int day) { Date.day = day; }
	int getDay() { return Date.day; }

	void setEmail(string st) { userEmail = st; }
	string getEmail() { return userEmail; }

	void setPassword(string st) { userPassword = st; }
	string getPassword() { return userPassword; }
};

void signUp(vector<User> &); // REGISTRACIIS FUNQCIA
void signIn(vector<User> &); // AKAUNTSHI SHESVLIS FUNQCIA
bool checkPassword(string&, string&); // AMOWMEBS MOXMAREBLIS MIER AXAL SHEYVANIL PAROLS, RATA AR SHEICAVDES SIMBOLOEBS DA A.SH.
bool checkEmail(string&, vector<User>); // IGIVE OGOND EMAILZE

///////////////////// MAIN FUNCTION ////////////////////////////

int main() {
	int choose;
	vector<User> user; // AQ INAXEBA YVELA AKAUNTI

	do {
		cout << "Enter 1 to Log In or Enter 0 to Create a New Account!(Enter 2 to exit)\n";

		cin >> choose; // 1 LOG IN ............ 0 SING UP ........... 2 EXIT
		if (choose == 2) break;

		while (cin.fail() || (choose != 1 && choose != 0)) {
			cout << "Error, Enter 0 or 1" << std::endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> choose;
		}

		if (choose) {
			cin.ignore();
			signIn(user);
		}
		else {
			signUp(user);
		}
	} while (true);

	return 0;
}

//////////////////////// parolis shemowmeba ///////////////////////////////////////

bool checkPassword(string &psw, string &eml) {
	// parolshi unda iyos 2 ze meti cifri
	// parolshi ar unda iyos simboloebi
	// parolshi unda iyos 6 ze meti aso
	// paroli ar unda iyos 20 ze didi
	// paroli ar unda emtxveodes mails
	string k = eml.erase((int)eml.size() - 10, (int)eml.size()); // emaili @email.com -is gareshe

	if (k == psw) return true; // PAROLI AR UNDA EMTXVEODES MAILS!!!!!!!!!!
	if ((int)psw.size() < 6) return true;  // PAROLI AR UNDA IYOS 6 ZE NAKLEBI
	if ((int)psw.size() > 20) return true; // !20 ZE METI
	int integer = 0; // cifrebis raodenobis dasatvlelad
	for (int i = 0; i < (int)psw.size(); i++) {
		if (isdigit(psw[i])) ++integer; // 2 CIFRI MAINC UNDA IYOS PAROLSHI
		if (ispunct(psw[i])) return true; // AR UNDA SHEICAVDES FIFQS TIRES DA A.SH.
	}

	if (integer > 1) return false; // TU CIFRI 2 ZE METIA

	return true;
}

///////////////// meilis shemowmeba /////////////////////
bool checkEmail(string& eml, vector<User> user) {
	if (eml.size() < 16) return true; // 16 radgan 10 simboloa @email.com
	for (int i = 0; i < (int)eml.size() - 10; i++) {
		if (!((isalpha(eml[i]) || isdigit(eml[i])) || (eml[i] == '.' || eml[i] == '_' || eml[i] == '-'))) return true; // ar unda iyos asos cifri da - , . _ garda araferi
	}
	
	for (int i = 0; i < (int)user.size(); i++) { // ertidaigive maili rom ar arsebobdes
		if (eml == user[i].getEmail()) return true;
	}


	if (eml.rfind("@email.com", eml.size()- 10) == string::npos) return true; // bolos unda mtavrebodes @email.com
	return false;
}


///////////////////// registracia ////////////////////////////////////////////

void signUp(vector<User> &user) {
	string usname; // saxeli
	string srname; // gvari
	string email; // email
	string password; // password
	string password2;
	bool alpha = true; // SAXELI AR UNDA SHEICAVDES CIFREBS DA SIMBOLOEBS
	int currentyear = 2020; // date
	int year, month, day;
	int x = 0;
	system("CLS");
	User* p_user; // MIMTIEBELI USER TIPZE
	p_user = new User; // AXALI OBIEQTI
	

	cin.ignore();
	do {
		alpha = true;
		if (x == 0) cout << "Hello, enter your name: "; // saxelis sheyvana
		if (x != 0) cout << "Hello, enter your name(only alphabet): ";
		getline(cin, usname);
		for (int i = 0; i < (int)usname.size(); i++) {
			if (!isalpha(usname[i])) {
				alpha = false;
				break;
			}
		}
		x++;
	} while (!alpha);
	p_user->setName(usname);

	x = 0;
	do {
		alpha = true;
		if (x == 0) cout << "Enter your surname: "; // gvaris sheyvana
		if (x != 0) cout << "Enter your surname(only alphabet): ";
		getline(cin, srname);
		for (int i = 0; i < (int)srname.size(); i++) {
			if (!isalpha(srname[i])) {
				alpha = false;
				break;
			}
		}
		x++;
	} while (!alpha);
	p_user->setSurname(srname);

	cout << "Enter your birthday--- "; // dabadebis dgis ricxvis sheyvana
	cout << "\nYear: ";

	do { // enter year
		cin >> year;
		cin.clear();
		cin.ignore(10000, '\n');
	} while (cin.fail() || (year < 1800 || year > currentyear));
	p_user->setYear(year);

	cout << "Month: ";

	do { // enter month
		cin >> month;
		cin.clear();
		cin.ignore(10000, '\n');
	} while (cin.fail() || (month < 1 || month > 12));
	p_user->setMonth(month);
	cout << "Day: ";

	do { // enter day
		cin >> day;
		cin.clear();
		cin.ignore(10000, '\n');
	} while (cin.fail() || (day < 1 || day > 31));
	p_user->setDay(day);

	// axali meilis sheqmna
	cout << "Create new email: ";
	cout << "\nFor example: ";
	cout << "\n" << p_user->getSurname() << "." << p_user->getName() << p_user->getYear() << "@email.com";
	cout << "\n" << p_user->getSurname() << "-" << p_user->getName() << p_user->getMonth() << p_user->getDay() << "@email.com";
	cout << "\n" << p_user->getName() << "." << p_user->getSurname() << p_user->getYear() << "@email.com";
	cout << "\n" << p_user->getSurname() << "_" << p_user->getName() << p_user->getDay() << p_user->getMonth() << "@email.com\n";

	// mailis sheyvana
	//cin.ignore();
	do {
		cout << "Enter new email(Number of letters must be more then 6): ";
		getline(cin, email);
	} while (checkEmail(email, user));
	p_user->setEmail(email);
	
	// parolis sheyvana
	pass: // to 0 sheiyavan tavidan sheiyvans axal parols
	cin.clear(); 
	do {
		cout << "Enter new password(Number of letters must be more then 6): ";
		getline(cin, password);
	} while (checkPassword(password, email));

	cout << "Repeat password: ";
	getline(cin, password2);
	if (password != password2) {
		do {
			cout << "ERROR- Repeat password (if you want change password enter 0): ";
			getline(cin, password2);
			if (password2 == "0") goto pass; // to 0 sheiyavan tavidan sheiyvans axal parols
		} while (password != password2);
	}
	p_user->setPassword(password);
	user.push_back(*p_user);

	system("CLS");

	cout << "Thank you! Now Sign in to your new account!\n";
	delete p_user;
}

/////////////////////// arsebul akauntshi shesvla /////////////////////////////////////////////////

void signIn(vector<User> &user) {
	bool findEmail = false;
	bool findPassword = false;
	string email;
	string password;
	int userIndex = 0;
	int k = 0, z = 0;
	system("CLS");

	while (true) {
		cin.clear();
		if (k == 0) cout << "Welcome Back! Enter your Email: ";
		if (k > 0) cout << "Incorrect Email, try again or enter 0 to exit: ";
		getline(cin, email);
		if (k > 0 && email == "0") return;

		for (userIndex = 0; userIndex < (int)user.size(); userIndex++) {
			if (user[userIndex].getEmail() == email) {
				findEmail = true;
				break;
			}
		}

		if (findEmail) break;
		++k;
	}

	
	while (true) {
		if (z < 1) cout << "Enter your password: ";
		if (z > 0) cout << "Incorrect password, try again or enter 0 to exit: ";
		
		getline(cin, password);
		if (z > 0 && password == "0") return;
		if (user[userIndex].getPassword() == password) findPassword = true;
		if (findPassword) break;
		++z;
	} 
	
	//////////////// TU PAROLI IQNA NAPOVNI
	if (findPassword) {
		int chs;
		system("CLS");
		cout << "Hello, " << user[userIndex].getSurname() << " " << user[userIndex].getName() << "!";
		cout << "\nEnter 1 to show your full information, or Enter 0 to exit: ";

		cin >> chs;

		while (cin.fail() || (chs != 1 && chs != 0)) {
			cout << "Error, Enter 0 or 1" << std::endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> chs;
		}

		if (chs == 1) {
			cout << "Name: " << user[userIndex].getName() << endl;
			cout << "Surname: " << user[userIndex].getSurname() << endl;
			cout << "Birthday: " << user[userIndex].getYear() << ":";
			if (user[userIndex].getMonth() < 10) cout << 0;
			cout << user[userIndex].getMonth() << ":";
			if (user[userIndex].getDay() < 10) cout << 0;
			cout << user[userIndex].getDay() << endl;
			cout << "Email: " << user[userIndex].getEmail() << endl;
		}
	}
	else {
		return;
	}
	
}
