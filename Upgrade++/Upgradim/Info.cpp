//#include <iostream>
//#include <string>
//#include <fstream>
//#include "Info.h"
//#include "List.h"

using namespace std;

//Info::Info() {
//	this->classs = new string;
//	this->classhead = new string;
//	this->averageMark = new string;
//	this->teacher = new string;
//	this->studentsNumber = new string;
//}
//
//Info::Info(string classs, string classhead, string averageMark, string teacher, string studentsNumber) {
//
//	this->classs = new string(classs);
//	this->classhead = new string(classhead);
//	this->averageMark = new string(averageMark);
//	this->teacher = new string(teacher);
//	this->studentsNumber = new string(studentsNumber);
//
//	//this->classs = classs;
//	//this->classhead = classhead;
//	//this->averageMark = averageMark;
//	//this->teacher = teacher;
//	//this->studentsNumber = studentsNumber;					// maybe change to setClasss(string class) ...
//}

char* Info::getClasss() {
	return classs;
}

char* Info::getClasshead() {
	return classhead;
}

char* Info::getAverageMark() {
	return averageMark;
}

char* Info::getTeacher() {
	return teacher;
}

char* Info::getStudentsNumber() {
	return studentsNumber;
}
//
//string Info::toString() {
//	return *classs + " " + *classhead + " " + *averageMark + " " + *teacher + " " + *studentsNumber;
//}


char* Info::toString() {
	char* t = (char*)malloc(sizeof(char) * 5);
	cin >> t;
	//return *classs + " " + *classhead + " " + *averageMark + " " + *teacher + " " + *studentsNumber;
	return t;
}














//
//
//
//
//Node* Info::findByClass(Node* head, char* classs) {
//
//}
//
//Node* Info::findByClasshead(Node* head, char* headFind) {
//
//}
//
//Node* Info::findByTeacher(Node* head, char* teacher) {
//
//}
//
//bool Info::isClassExisted(Node* head, char* isClass) {
//
//}
//
//Node* Info::addNewAssignment(Node* head) {
//
//}
//
//void Info::changeData(Node* head) {
//
//}
//
//void Info::copySplittedInfo(Node* dest, Node* old) {
//
//}
//
//void Info::saveToFile(Node* head, char* fileName) {
//
//}
//
//Node* Info::initFromFile(Node* head, char* fileName) {
//
//}
//
//Node* Info::deleteByClass(Node* head) {
//
//}