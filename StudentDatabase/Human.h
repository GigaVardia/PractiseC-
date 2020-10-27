#pragma once
#include <string>

class Human
{
protected:
	struct DateOfBirth {
		int Year, Month, Day;
	} Date;
	
	std::string Name;
	std::string Surname;

	std::string Nationality;
public:
	/// CONSTRUCTOR ///
	Human();

	/// SET BIRTHDAY ///
	void setYear(int);
	void setMonth(int);
	void setDay(int);

	/// GET BIRTHDAY
	int getYear();
	int getMonth();
	int getDay();

	//// GET & SET NAME ///
	void setName(std::string);
	std::string getName();
	
	//// GET & SET SURNAME ///
	void setSurName(std::string);
	std::string getSurName();

	///// GET & SET NATIONALITY //// 
	void setNationality(std::string);
	std::string getNationality();
};

