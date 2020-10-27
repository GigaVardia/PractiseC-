#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "Human.h"
#include "Student.h"

using namespace std;

void newStudent(vector<Student>&);
void FindStudentInfo(vector<Student>&);
void showStudentInfo(vector<Student>&, int);
void showAllStudentsInfo(vector<Student>&);

int main() {
	vector<Student> Students;

	int Menu;

	do
	{
		system("cls");
		cout << "Enter 1 to show student information!" << endl;
		cout << "Enter 2 to add new student: " << endl;
		cout << "Enter 3 to show all student information: " << endl;
		cout << "Enter 0 to exit: " << endl;
		cin >> Menu;

		if (Menu == 1) {
			FindStudentInfo(Students);
		}
		else if (Menu == 2) {
			newStudent(Students);
		}
		else if (Menu == 3) {
			showAllStudentsInfo(Students);
		}
		else {
			break;
		}
	} while (true);

	return 0;
}

void newStudent(vector<Student>& student) {
	system("cls");
	Student* p_obj = new Student;

	string STemp;
	int intTemp;
	double dblTemp;
	char chrTemp;

	////// HUMAN CLASS INFORMATION INPUT /////
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, STemp);
	p_obj->setName(STemp);

	cout << "Enter surname: ";
	getline(cin, STemp);
	p_obj->setSurName(STemp);

	cout << "Enter year of birth: ";
	cin >> intTemp;
	p_obj->setYear(intTemp);

	cout << "Enter month of birth: ";
	cin >> intTemp;
	p_obj->setMonth(intTemp);

	cout << "Enter day of birth: ";
	cin >> intTemp;
	p_obj->setDay(intTemp);

	cout << "Enter nationality: ";
	cin.ignore();
	getline(cin, STemp);
	p_obj->setNationality(STemp);


	//// STUDENT CLASS INFORMATION INPUT ////

	cout << "\nEnter Email: ";
	getline(cin, STemp);
	p_obj->setMail(STemp);

	cout << "Enter Course: ";
	cin >> intTemp;
	p_obj->setCourse(intTemp);

	cout << "Enter semester: ";
	cin >> intTemp;
	p_obj->setSemester(intTemp);

	cout << "Enter average mark: ";
	cin >> dblTemp;
	while (dblTemp < 0 || dblTemp > 100) {
		cin >> dblTemp;
	}
	p_obj->setAVG_Mark(dblTemp);

	if (dblTemp > 0 && dblTemp < 51) {
		p_obj->setMark('F');
	}
	else if (dblTemp > 50 && dblTemp < 61) {
		p_obj->setMark('E');
	}
	else if (dblTemp > 60 && dblTemp < 71) {
		p_obj->setMark('D');
	}
	else if (dblTemp > 70 && dblTemp < 81) {
		p_obj->setMark('C');
	}
	else if (dblTemp > 80 && dblTemp < 91) {
		p_obj->setMark('B');
	}
	else if (dblTemp > 90 && dblTemp < 101) {
		p_obj->setMark('A');
	}

	student.push_back(*p_obj);

	cout << "New student has been add!!!";
	Sleep(4000);
}

void showStudentInfo(vector<Student>& student, int index) {
	cout << "Name: " << student[index].getName() << endl;
	cout << "Surname : " << student[index].getSurName() << endl;
	cout << "Date of birth: " << student[index].getDay() << "." << student[index].getMonth() << "." << student[index].getYear() << endl;
	cout << "Nationality: " << student[index].getNationality() << endl;
	
	cout << "Mail: " << student[index].getMail() << endl;
	cout << "Course: " << student[index].getCourse() << endl;
	cout << "Semester: " << student[index].getSemester() << endl;
	cout << "AVG MARK: " << student[index].getAVG_Mark() << endl;
	cout << "Mark: " << student[index].getMark() << endl;
}

void FindStudentInfo(vector<Student>& student) {
	system("cls");
	int mailORname;
	int studentIndex = 0;

	string nameTemp;
	string surnameTemp;
	string mailTemp;

	if (((int)student.size()) == 0) {
		cout << "Information not found!!!";
		Sleep(4000);
		return;
	}
	cout << "Enter 1 to search student by name and surname: ";
	cout << "\nEnter 2 to search student by email: ";
	cout << "\nEnter 0 to exit ";
	cin >> mailORname;

	if (mailORname == 1) {
		cout << "Enter student name: ";
		cin.ignore();
		getline(cin, nameTemp);
		cout << "Enter student surname: ";
		getline(cin, surnameTemp);

		for (int i = 0; i < (int)student.size(); i++) {
			if ((student[i].getName() == nameTemp) && (student[i].getSurName() == surnameTemp)) {
				studentIndex = i;
			}
			else if (i == ((int)student.size() - 1)) {
				cout << "Student not found, try again!!!";
				Sleep(4000);
				return;
			}
		}

		system("cls");
		showStudentInfo(student, studentIndex);
	}
	else if (mailORname == 2) {
		cout << "Enter student eMail: ";
		cin.ignore();
		getline(cin, mailTemp);

		for (int i = 0; i < (int)student.size(); i++) {
			if (student[i].getMail() == mailTemp) {
				studentIndex = i;
			}
			else if (i == ((int)student.size() - 1)) {
				cout << "Student not found, try again!!!";
				Sleep(4000);
				return;
			}
		}

		system("cls");
		showStudentInfo(student, studentIndex);
	}
	else return;

	cout << "\nPress any key...";
	while (!_kbhit()) {}
}

void showAllStudentsInfo(vector<Student>& student) {
	for (size_t i = 0; i < student.size(); i++) {
		cout << "N " << i + 1 << " student: " << endl;
		showStudentInfo(student, i);
		cout << endl;
	}

	cout << "\nPress any key...";
	while (!_kbhit()) {}
}