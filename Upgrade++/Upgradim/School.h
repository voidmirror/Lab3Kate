#pragma once
#include <string>
#include <list>
#include "Info.h"

using namespace std;

class School {
private:
	/*
		for (Info i : school) {
			cout << i.getClasss();
		}
	*/
	list<Info> school;

public:
	list<Info> getSchool();
	void addClass();
	void removeClass();
	void searchClass();
	void changeClass();
	void printAllClasses();

	void initFromFile();
	void saveToFile();
};