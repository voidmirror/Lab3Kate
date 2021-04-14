#pragma once
//#include <iostream>
#include <cstdlib>
#include <string>
#include "Info.h"
#include "Node.h"

//class Info {
//private:
//	char* classs;
//	char* classhead;
//	char* averageMark;
//	char* teacher;
//	char* studentsNumber;
//
//public:
//	Info();
//	Info(string classs, string classhead, string averageMark, string teacher, string studentsNumber);
//	char* toString();
//
//
//	char* getClasss();
//	char* getClasshead();
//	char* getAverageMark();
//	char* getTeacher();
//	char* getStudentsNumber();
//
//	Node* findByClass(Node* head, char* classs);
//	Node* findByClasshead(Node* head, char* headFind);
//	Node* findByTeacher(Node* head, char* teacher);
//	bool isClassExisted(Node* head, char* isClass);		// _Bool
//	Node* addNewAssignment(Node* head);
//	void changeData(Node* head);
//	void copySplittedInfo(Node* dest, Node* old);
//	void saveToFile(Node* head, char* fileName);
//	Node* initFromFile(Node* head, char* fileName);
//	Node* deleteByClass(Node* head);
//};



void push(Node* head, char* str);
//void add2list(Node** pphead, char* str);
void initList(Node* head, char* str);
void add2list(Node* head, char* str);
void printAll(Node* head);
//void print2(Node* phead);

int len(Node* head);
Node* find(Node* head, int index);
void del(Node* head, int index);
Node* delNode(Node* head, Node* toDelete);

void freeList(Node* head);

//void mergeSort(Node** head);
//void split(Node* src, Node** low, Node** high);
//void merge(Node* a, Node* b, Node** c);
Node* getLast(Node* head);