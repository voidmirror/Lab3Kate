#pragma once
#include <string>

using namespace std;

class Info {
private:
	string classs;
	string classhead;
	string averageMark;
	string teacher;
	string studentsNumber;

public:
	Info();
	Info(string classs, string classhead, string averageMark, string teacher, string studentsNumber);
	string getClasss();
	string getClasshead();
	string getAverageMark();
	string getTeacher();
	string getStudentsNumber();
	string toString();
};