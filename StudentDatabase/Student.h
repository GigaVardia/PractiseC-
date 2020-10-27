#pragma once
#include "Human.h"
#include <string>

class Student :
	public Human
{
protected:
	std::string Mail;

	int Course; /// FIRST YEAR, SECOND YEAR, THIRD YEAR, FOURTH YEAR
	int Semester; /// SEMESTER

	double AVGMark; /// AVERAGE
	char Mark; /// A, B, C, D, F;
public:
	//// CONSTRUCTOR ////
	Student();

	/// SET & GET MAIL ///
	void setMail(std::string);
	std::string getMail();

	//// SET & GET COURSE & SEMESTER ////
	void setCourse(int);
	int getCourse();

	void setSemester(int);
	int getSemester();

	//// SET & GET AVGMARK AND MARK ///
	void setAVG_Mark(double);
	double getAVG_Mark();

	void setMark(char);
	char getMark();
};

