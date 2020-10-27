#include "Student.h"
#include <string>

/// CONSTRUCTOR ///
Student::Student() {
	Mail = "noemail@agruni.edu.ge";

	Course = 0;
	Semester = 0;

	AVGMark = 0;
	Mark = '-';
}

/// SET & GET MAIL ///
void Student::setMail(std::string inputMail) {
	Mail = inputMail;
}

std::string Student::getMail() {
	return Mail;
}
	 
//// SET & GET COURSE & SEMESTER ////
void Student::setCourse(int inputCourse) {
	Course = inputCourse;
}

int Student::getCourse() {
	return Course;
}
	
void Student::setSemester(int inputSemester) {
	Semester = inputSemester;
}

int Student::getSemester() {
	return Semester;
}
	 
//// SET & GET AVGMARK AND MARK ///
void Student::setAVG_Mark(double inputAVG_MARK) {
	AVGMark = inputAVG_MARK;
}
double Student::getAVG_Mark() {
	return AVGMark;
}
	 
void Student::setMark(char inputMark) {
	Mark = inputMark;
}
char Student::getMark() {
	return Mark;
}
