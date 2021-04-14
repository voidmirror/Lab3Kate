#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Info.h"

Info::Info() {
	classs = (char*)malloc(sizeof(char) * 30);
	classhead = (char*)malloc(sizeof(char) * 30);
	averageMark = (char*)malloc(sizeof(char) * 30);
	teacher = (char*)malloc(sizeof(char) * 30);
	studentsNumber = (char*)malloc(sizeof(char) * 30);
	this->classs[0] = '\0';
	this->classhead[0] = '\0';
	this->averageMark[0] = '\0';
	this->teacher[0] = '\0';
	this->studentsNumber[0] = '\0';
	pnext = NULL;
}

Info::~Info()
{
	free(classs);
	free(classhead);
	free(averageMark);
	free(teacher);
	free(studentsNumber);
}

Info::Info(char* classs, char* classhead, char* averageMark, char* teacher, char* studentsNumber) {
	this->classs = (char*)malloc(sizeof(char) * 30);
	this->classhead = (char*)malloc(sizeof(char) * 30);
	this->averageMark = (char*)malloc(sizeof(char) * 30);
	this->teacher = (char*)malloc(sizeof(char) * 30);
	this->studentsNumber = (char*)malloc(sizeof(char) * 30);
	this->classs[0] = '\0';
	this->classhead[0] = '\0';
	this->averageMark[0] = '\0';
	this->teacher[0] = '\0';
	this->studentsNumber[0] = '\0';
	pnext = NULL;
	strcpy(this->classs, classs);
	strcpy(this->classhead, classhead);
	strcpy(this->averageMark, averageMark);
	strcpy(this->teacher, teacher);
	strcpy(this->studentsNumber, studentsNumber);
}

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

Info* Info::getNext() {
	return pnext;
}

void Info::setNext(Info* info) {
	pnext = info;
}

char* Info::toString() {
	char* str = (char*)malloc(sizeof(char) * 200);
	str[0] = '\0';
	strcat(str, classs);
	strcat(str, " ");
	strcat(str, classhead);
	strcat(str, " ");
	strcat(str, averageMark);
	strcat(str, " ");
	strcat(str, teacher);
	strcat(str, " ");
	strcat(str, studentsNumber);
	return str;
}

char* Info::toSaveString() {
	char* str = (char*)malloc(sizeof(char) * 200);
	str[0] = '\0';
	strcat(str, classs);
	strcat(str, ":");
	strcat(str, classhead);
	strcat(str, ":");
	strcat(str, averageMark);
	strcat(str, ":");
	strcat(str, teacher);
	strcat(str, ":");
	strcat(str, studentsNumber);
	return str;
}

void Info::fillInfo() {
	cout << "Enter class num: ";
	cin >> this->getClasss();
	cout << "Enter Head of class (lastname): ";
	cin >> this->getClasshead();
	cout << "Enter average mark: ";
	cin >> this->getAverageMark();
	cout << "Enter Teacher's lastname: ";
	cin >> this->getTeacher();
	cout << "Enter Students number: ";
	cin >> this->getStudentsNumber();
}

void Info::clone(Info* source) {
	strcpy(this->classs, source->getClasss());
	strcpy(this->classhead, source->getClasshead());
	strcpy(this->averageMark, source->getAverageMark());
	strcpy(this->teacher, source->getTeacher());
	strcpy(this->studentsNumber, source->getStudentsNumber());
}