#include <iostream>
#include "School.h"

using namespace std;

list<Info> School::getSchool() {
	return school;
}

void School::addClass() {

}

void School::removeClass() {

}

void School::searchClass() {

}

void School::changeClass() {

}

void School::printAllClasses() {
	for (Info i : school) {
		cout << i.toString();
	}
}

void School::initFromFile() {

}

void School::saveToFile() {

}