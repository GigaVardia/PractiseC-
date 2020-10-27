#include "Human.h"
#include <string>

/// CONSTRUCTOR ///
Human::Human() {
	Date.Year = 0;
	Date.Month = 0;
	Date.Day = 0;

	Name = "noname";
	Surname = "nosurname";

	Nationality = "nonationality";
}

//// SET BIRTHDAY //// 
void Human::setYear(int inputYear) {
	Date.Year = inputYear;
}

void Human::setMonth(int inputMonth) {
	Date.Month = inputMonth;
}

void Human::setDay(int inputDay) {
	Date.Day = inputDay;
}

///// GET BIRTHDAY ///
int Human::getYear() {
	return Date.Year;
}

int Human::getMonth() {
	return Date.Month;
}

int Human::getDay() {
	return Date.Day;
}

//// GET & SET NAME ///
void Human::setName(std::string inputName) {
	Name = inputName;
}
std::string Human::getName() {
	return Name;
}

//// GET & SET SURNAME ///
void Human::setSurName(std::string inputSurName) {
	Surname = inputSurName;
}
std::string Human::getSurName() {
	return Surname;
}

/// GET & SET NATIONALITY ///
void Human::setNationality(std::string inputNationality) {
	Nationality = inputNationality;
}

std::string Human::getNationality() {
	return Nationality;
}