#include <iostream>
#include <string>
#include "Info.h"

using namespace std;

Info::Info() {
}

Info::Info(string classs, string classhead, string averageMark, string teacher, string studentsNumber) {
	this->classs = classs;
	this->classhead = classhead;
	this->averageMark = averageMark;
	this->teacher = teacher;
	this->studentsNumber = studentsNumber;					// maybe change to setClasss(string class) ...
}

string Info::getClasss() {
	return classs;
}

string Info::getClasshead() {
	return classhead;
}

string Info::getAverageMark() {
	return averageMark;
}

string Info::getTeacher() {
	return teacher;
}

string Info::getStudentsNumber() {
	return studentsNumber;
}

string Info::toString() {
	return classs + " " + classhead + " " + averageMark + " " + teacher + " " + studentsNumber;
}