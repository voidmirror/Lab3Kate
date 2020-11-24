#pragma once
#include "List.h"
typedef struct SplittedInfo {
	char* classs;
	char* classhead;
	char* averageMark;
	char* teacher;
	char* studentsNumber;
} SplittedInfo;

SplittedInfo* splitIntoStructure(Node* node);
char* formStringFromSplitted(SplittedInfo* info);
Node* findByClass(Node* head, char* classs);
Node* findByClasshead(Node* head, char* headFind);
Node* findByTeacher(Node* head, char* teacher);
void printSplittedInfo(SplittedInfo* info);