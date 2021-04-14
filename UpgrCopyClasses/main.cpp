#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "School.h"
//#include "Info.h"

int main(int argc, char* argv[]) {
	Info* info = new Info();
	info->fillInfo(info);
	cout << info->toString() << endl;

	School* school = new School();
	school->addClass(info);
	school->printAllClasses();
	char* tmp = (char*)malloc(sizeof(char) * 30);
	cout << "to remove:";
	cin >> tmp;
	school->removeClass(tmp);
	school->printAllClasses();

}