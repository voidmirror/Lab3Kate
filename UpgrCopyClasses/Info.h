#pragma once
#pragma once

using namespace std;

class Info {
private:
	char* classs;
	char* classhead;
	char* averageMark;
	char* teacher;
	char* studentsNumber;

	Info* pnext;

public:
	Info();
	~Info();
	Info(char* classs, char* classhead, char* averageMark, char* teacher, char* studentsNumber);
	char* toString();


	char* getClasss();
	char* getClasshead();
	char* getAverageMark();
	char* getTeacher();
	char* getStudentsNumber();
	Info* getNext();
	void setNext(Info* info);
	void fillInfo(Info* info);
	void clone(Info* source);

	/*Node* findByClass(Node* head, char* classs);
	Node* findByClasshead(Node* head, char* headFind);
	Node* findByTeacher(Node* head, char* teacher);
	bool isClassExisted(Node* head, char* isClass);
	Node* addNewAssignment(Node* head);
	void changeData(Node* head);
	void copySplittedInfo(Node* dest, Node* old);
	void saveToFile(Node* head, char* fileName);
	Node* initFromFile(Node* head, char* fileName);
	Node* deleteByClass(Node* head);*/
};