#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Functions.h"
#include "List.h"

void saveToFile(Node* head, char* fileName) {
	FILE* f = fopen(fileName, "w");
	Node* tmp = head;
	while (tmp) {
		fputs(tmp->string, f);
		fputs("\n", f);
		tmp = tmp->next;
	}

	fclose(f);
}

Node* initFromFile(Node* head, char* fileName) {
	FILE* f = fopen(fileName, "r");

	if (f == NULL) {
		return NULL;
	}
	
	char* mystring = (char*)malloc(sizeof(char) * 80);
	Node* tmp = head;
	while (fgets(mystring, 100, f) != NULL) {
		char* tmpchr = strchr(mystring, '\n');
		*tmpchr = '\0';

		if (head == NULL) {
			char* newstr = (char*)malloc(sizeof(char) * 80);
			strcpy(newstr, mystring);
			head = (Node*)malloc(sizeof(Node));
			head->string = newstr;
			head->next = NULL;
		}
		else {
			char* newstr = (char*)malloc(sizeof(char) * 80);
			strcpy(newstr, mystring);
			add2list(head, newstr);
		}
	}
	free(mystring);
	fclose(f);
	return head;
}

bool isClassExisted(Node* head, char* isClass) {
	if (findByClass(head, isClass) == NULL) {
		return false;
	}
	else {
		return true;
	}
}

Node* addNewAssignment(Node* head) {
	SplittedInfo* info = createNewSplittedInfo();
	printf("Enter the Class: ");
	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->string = (char*)malloc(sizeof(char) * 80);
		head->next = NULL;
		
		scanf("%s", info->classs);
		printf("Enter lastname of Head of the class: ");
		scanf("%s", info->classhead);
		printf("Enter Average Mark of students: ");
		scanf("%s", info->averageMark);
		printf("Enter teachers' lastname and initials: ");
		scanf("%s", info->teacher);
		printf("Enter Students number: ");
		scanf("%s", info->studentsNumber);

		head->string = formStringFromSplitted(info);

	}
	else {
		scanf("%s", info->classs);
		if (!isClassExisted(head, info->classs)) {
			printf("Enter lastname of Head of the class: ");
			scanf("%s", info->classhead);
			printf("Enter Average Mark of students: ");
			scanf("%s", info->averageMark);
			printf("Enter teachers' lastname: ");
			scanf("%s", info->teacher);
			printf("Enter Students number: ");
			scanf("%s", info->studentsNumber);

			add2list(head, formStringFromSplitted(info));
		}
		else {
			printf("This class is already existed in DataBase. Try to Change Data.\n\n");
			freeInfo(info);
			return NULL;
		}
	}
	

	printf("\n");
	printSplittedInfo(info);
	printf("\n");
	freeInfo(info);
	return head;
}

Node* deleteByClass(Node* head) {
	printf("Enter the class to delete: ");
	char* delClass = (char*)malloc(sizeof(char) * 80);
	scanf("%s", delClass);
	Node* toDel = findByClass(head, delClass);
	if (toDel == NULL) {
		printf("There is no class %s\n", delClass);
	}
	else {
		head = delNode(head, toDel);
	}
	free(delClass);
	return head;
}

SplittedInfo* createNewSplittedInfo() {
	SplittedInfo* info = (SplittedInfo*)malloc(sizeof(SplittedInfo));
	info->classs = (char*)malloc(sizeof(char) * 5);
	info->classhead = (char*)malloc(sizeof(char) * 20);
	info->averageMark = (char*)malloc(sizeof(char) * 5);
	info->teacher = (char*)malloc(sizeof(char) * 20);
	info->studentsNumber = (char*)malloc(sizeof(char) * 5);
	info->classs[0] = '\0';
	info->classhead[0] = '\0';
	info->averageMark[0] = '\0';
	info->teacher[0] = '\0';
	info->studentsNumber[0] = '\0';
	return info;
}

SplittedInfo* splitIntoStructure(Node* node) {
	char* tmp = (char*)malloc(sizeof(char) * strlen(node->string) * 2);
	tmp[0] = '\0';
	strcpy(tmp, node->string);
	char misc[5][20];
	char* lex = strtok(tmp, ":");
	SplittedInfo *info = createNewSplittedInfo();
	
	int i = 0;
	while (lex != NULL)
	{
		strcpy(misc[i], lex);
		i++;
		lex = strtok(NULL, ":");
	}
	
	strcpy(info->classs, misc[0]);
	strcpy(info->classhead, misc[1]);
	strcpy(info->averageMark, misc[2]);
	strcpy(info->teacher, misc[3]);
	strcpy(info->studentsNumber, misc[4]);

	return info;
}

char* formStringFromSplitted(SplittedInfo* info) {
	char* misc = (char*)malloc(sizeof(char) * (80));
	misc[0] = '\0';
	strcat(misc, info->classs);
	strcat(misc, ":");
	strcat(misc, info->classhead);
	strcat(misc, ":");
	strcat(misc, info->averageMark);
	strcat(misc, ":");
	strcat(misc, info->teacher);
	strcat(misc, ":");
	strcat(misc, info->studentsNumber);

	return misc;
}

void freeInfo(SplittedInfo* info) {
	free(info->classs);
	free(info->classhead);
	free(info->averageMark);
	free(info->teacher);
	free(info->studentsNumber);
	free(info);
}

Node* findByClass(Node* head, char* classs) {
	Node* tmp = head;
	while (tmp != NULL) {
		char* tmppp = splitIntoStructure(tmp)->classs;
		if (strcmp(tmppp, classs) == 0) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

Node* findByClasshead(Node* head, char* classhead) {
	Node* tmp = head;
	while (tmp != NULL) {
		char* tmppp = splitIntoStructure(tmp)->classhead;
		if (strcmp(tmppp, classhead) == 0) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

Node* findByTeacher(Node* head, char* teacher) {
	Node* tmp = head;
	while (tmp != NULL) {
		char* tmppp = splitIntoStructure(tmp)->teacher;
		if (strcmp(tmppp, teacher) == 0) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void printSplittedInfo(SplittedInfo* info) {
	printf("Class: %s\n", info->classs);
	printf("Head of class: %s\n", info->classhead);
	printf("Average mark: %s\n", info->averageMark);
	printf("Teacher: %s\n", info->teacher);
	printf("Students number: %s\n", info->studentsNumber);
}

void copySplittedInfo(SplittedInfo* dest, SplittedInfo* old) {
	strcpy(dest->classs, old->classs);
	strcpy(dest->classhead, old->classhead);
	strcpy(dest->averageMark, old->averageMark);
	strcpy(dest->teacher, old->teacher);
	strcpy(dest->studentsNumber, old->studentsNumber);
}

void printMenu() {
	printf("\n=====================================================\n\n");
	printf("Please, choose your action:\n");
	printf("1) Add new assignment to database\n");
	printf("2) Find information by Class\n");
	printf("3) Find information by Classhead's lastname\n");
	printf("4) Find information by Teacher's lastname\n");
	printf("5) Print raw info from Database file\n\n");
	printf("Dangerous zone!!\n");
	printf("6) Change data about Class\n");
	printf("7) Delete information about Class\n\n");
	printf("0) Any other input will close this app\n");
}

void changeData(Node* head) {
	SplittedInfo* info = createNewSplittedInfo();
	puts("Enter the class to change information about: ");
	char* buf = (char*)malloc(sizeof(char) * 5);
	scanf("%s", buf);
	if (!isClassExisted(head, buf)) {
		printf("This class is not existed now\n");
		return;
	}
	SplittedInfo* oldInfo = splitIntoStructure(findByClass(head, buf));
	printSplittedInfo(oldInfo);
	copySplittedInfo(info, oldInfo);
	puts("Please, enter cipher, what data you want to change:");
	puts("1. Class\n2. Head of the class\n3. Average mark of class\n4. Teacher\n5. Number of students in class\n6. Cancel all changes\n0) Any other input will save data\n");
	while (true) {
		printf("What to change? Enter: ");
		char* choice = (char*)malloc(sizeof(char) * 10);
		scanf("%s", choice);
		
		switch(atoi(choice)) {
			case 1:
				printf("Enter new Class: ");
				scanf("%s", info->classs);
				printf("Class changed\n\n");
				break;
			case 2:
				printf("Enter new Head of class: ");
				scanf("%s", info->classhead);
				printf("Classhead changed\n\n");
				break;
			case 3:
				printf("Enter new Average Mark: ");
				scanf("%s", info->averageMark);
				printf("Average mark changed\n\n");
				break;
			case 4:
				printf("Enter new Teacher: ");
				scanf("%s", info->teacher);
				printf("Teacher changed\n\n");
				break;
			case 5:
				printf("Enter new Students Number: ");
				scanf("%s", info->studentsNumber);
				printf("Students number changed\n\n");
				break;
			case 6:
				free(buf);
				freeInfo(info);
				printf("All changes canceled\n");
				return;
				info = createNewSplittedInfo();
				break;
			default:
				puts("Saving data and exit");
				puts("New data:");
				printSplittedInfo(info);
				findByClass(head, buf)->string = formStringFromSplitted(info);
				free(buf);
				freeInfo(info);
				return;
		}
	}
}
