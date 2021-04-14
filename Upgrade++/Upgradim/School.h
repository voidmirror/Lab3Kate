#pragma once
//#include <string>
//#include <vector>
#include "Info.h"

using namespace std;

//class School {
//private:
//	/*
//		for (Info i : school) {
//			cout << i.getClasss();
//		}
//	*/
//	list<Info> *school;
//
//public:
//	School();
//	list<Info> *getSchool();
//	void addClass();
//	void removeClass();
//	void searchClass();
//	void changeClass();
//	void printAllClasses();
//
//	void initFromFile();
//	void saveToFile();
//};

class School {
private:
	/*
		for (Info i : school) {
			cout << i.getClasss();
		}
	*/
	//vector<Info*> school;
	Node* head;

public:
	School();
	//vector<Info*> getSchool();
	void addClass();
	void removeClass();
	void searchClass();
	void changeClass();
	void printAllClasses();

	void initFromFile();
	void saveToFile();


	//Node* addNewAssignment(Node* head);
	//bool isClassExisted(Node* head, char* isClass);
	//Node* findByClass(Node* head, char* classs);



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