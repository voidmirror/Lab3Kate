#pragma once
#include "Info.h"

class School {
private:
	Info* head;

public:
	School();
	//vector<Info*> getSchool();
	void addClass(Info* info);
	void removeClass(char* classs);
	void searchClass();
	void changeClass(char* classs);
	void printAllClasses();

	void initFromFile(char* file);
	void saveToFile(char* file);

	Info* getLast();


	//Node* addNewAssignment(Node* head);
	//bool isClassExisted(Node* head, char* isClass);
	//Node* findByClass(Node* head, char* classs);



	Info* findByClass(char* classs);
	Info* findByClasshead(char* classhead);
	Info* findByTeacher(char* teacher);
	/*Node* findByClasshead(Node* head, char* headFind);
	Node* findByTeacher(Node* head, char* teacher);
	bool isClassExisted(Node* head, char* isClass);
	Node* addNewAssignment(Node* head);
	void changeData(Node* head);
	void copySplittedInfo(Node* dest, Node* old);
	void saveToFile(Node* head, char* fileName);
	Node* initFromFile(Node* head, char* fileName);
	Node* deleteByClass(Node* head);*/
};