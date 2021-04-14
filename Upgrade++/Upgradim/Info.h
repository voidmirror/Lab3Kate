#pragma once
//#include <string>
//#include "Node.h"
//#include "List.h"

using namespace std;

//class Info {
//private:
//	string* classs;
//	string* classhead;
//	string* averageMark;
//	string* teacher;
//	string* studentsNumber;
//
//public:
//	Info();
//	Info(string classs, string classhead, string averageMark, string teacher, string studentsNumber);
//	string* getClasss();
//	string* getClasshead();
//	string* getAverageMark();
//	string* getTeacher();
//	string* getStudentsNumber();
//	string toString();
//};

class Info {
private:
	char* classs;
	char* classhead;
	char* averageMark;
	char* teacher;
	char* studentsNumber;

public:
	Info();
	Info(string classs, string classhead, string averageMark, string teacher, string studentsNumber);
	char *toString();
	

	char* getClasss();
	char* getClasshead();
	char* getAverageMark();
	char* getTeacher();
	char* getStudentsNumber();

	Node* findByClass(Node* head, char* classs);
	Node* findByClasshead(Node* head, char* headFind);
	Node* findByTeacher(Node* head, char* teacher);
	bool isClassExisted(Node* head, char* isClass);
	Node* addNewAssignment(Node* head);
	void changeData(Node* head);
	void copySplittedInfo(Node* dest, Node* old);
	void saveToFile(Node* head, char* fileName);
	Node* initFromFile(Node* head, char* fileName);
	Node* deleteByClass(Node* head);
};