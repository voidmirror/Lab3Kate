#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Functions.h"
#include "List.h"

void addLine(char* fileName, char* string) {
	FILE* f = fopen(fileName, "a");
	if (f == NULL) {
		printf("File does not exist\n");
		//    return 0;
	}
	fwrite(string, sizeof(char), strlen(string), f);
	fclose(f);
}

bool isClassExisted(Node* head, char* isClass) {
	if (findByClass(head, isClass) == NULL) {
		return false;
	}
	else {
		return true;
	}
}

void addNewAssignment(Node* head) {
	SplittedInfo* info = createNewSplittedInfo();
	printf("Enter the Class: ");
	gets_s(info->classs, 5);
	if (!isClassExisted(head, info->classs)) {
		printf("Enter lastname of Head of the class: ");
		gets_s(info->classhead, 20);
		printf("Enter Average Mark of students: ");
		gets_s(info->averageMark, 5);
		printf("Enter teachers' lastname and initials: ");
		gets_s(info->teacher, 20);
		printf("Enter Students number: ");
		gets_s(info->studentsNumber, 5);

		add2list(head, formStringFromSplitted(info));
	}
	else {
		printf("This class is already existed in DataBase. Try to Change Data.\n\n");
		freeInfo(info);
		return;
	}


	//printf("Enter lastname of Head of the class: ");
	//gets_s(info->classhead, 20);
	//printf("Enter Average Mark of students: ");
	//gets_s(info->averageMark, 5);
	//printf("Enter teachers' lastname and initials: ");
	//gets_s(info->teacher, 20);
	//printf("Enter Students number: ");
	//gets_s(info->studentsNumber, 5);
	//add2list(head, formStringFromSplitted(info));


	printf("\n");
	printSplittedInfo(info);
	printf("\n");
	freeInfo(info);
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
	/*info->classs = (char*)malloc(sizeof(char) * 5);
	info->classhead = (char*)malloc(sizeof(char) * 20);
	info->averageMark = (char*)malloc(sizeof(char) * 5);
	info->teacher = (char*)malloc(sizeof(char) * 20);
	info->studentsNumber = (char*)malloc(sizeof(char) * 5);*/
	
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
	//return char*
	// 5 + 20 + 5 + 20 + 5 + 5 (symb)

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
	//int i = 0;
	Node* tmp = head;
	while (tmp != NULL) {
		char* tmppp = splitIntoStructure(tmp)->classs;
		if (strcmp(tmppp, classs) == 0) {
			return tmp;
		}
		//i++;
		tmp = tmp->next;
	}
	return NULL;
}

Node* findByClasshead(Node* head, char* classhead) {
	int i = 0;
	Node* tmp = head;
	while (tmp != NULL) {
		if (strcmp(splitIntoStructure(tmp)->classhead, classhead) == 0) {
			return tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return NULL;
}

Node* findByTeacher(Node* head, char* teacher) {
	int i = 0;
	Node* tmp = head;
	while (tmp != NULL) {
		if (strcmp(splitIntoStructure(tmp)->teacher, teacher) == 0) {
			return tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return NULL;
}

void printSplittedInfo(SplittedInfo* info) {
	printf("Class: %s\n", info->classs);
	printf("Heado of class: %s\n", info->classhead);
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

void changeData(Node* head) {
	SplittedInfo* info = createNewSplittedInfo();
	puts("Enter the class to change information about: ");
	char* buf = (char*)malloc(sizeof(char) * 5);
	gets_s(buf, 5);
	SplittedInfo* oldInfo = splitIntoStructure(findByClass(head, buf));
	printSplittedInfo(oldInfo);
	copySplittedInfo(info, oldInfo);
	puts("Please, enter cipher, what data you want to change");
	puts("1. Class\n2. Head of the class\n3. Average mark of class\n4. Teacher\n5. Number of students in class\n6. Cancel all changes\nAny other input will save data\n");
	while (true) {
		printf("Your choice: ");
		int choice;
		scanf("%d", &choice);

		//fflush(stdin);
		switch(choice) {
			case 1:
				printf("Enter new Class:");
				//gets_s(info->classs, 5);
				scanf("%s", info->classs);
				printf("Class changed\n\n");
				break;
			case 2:
				printf("Enter new Head of class: ");
				//gets_s(info->classhead, 20);
				scanf("%s", info->classs);
				printf("Classhead changed\n\n");
				break;
			case 3:
				printf("Enter new Average Mark: ");
				//gets_s(info->averageMark, 5);
				scanf("%s", info->classs);
				printf("Average mark changed\n\n");
				break;
			case 4:
				printf("Enter new Teacher: ");
				//gets_s(info->teacher, 20);
				scanf("%s", info->classs);
				printf("Teacher changed\n\n");
				break;
			case 5:
				printf("Enter new Students Number: ");
				//gets_s(info->studentsNumber, 5);
				scanf("%s", info->classs);
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
				//free(findByClass(head, buf)->string);		// works?
				findByClass(head, buf)->string = formStringFromSplitted(info);
				free(buf);
				freeInfo(info);
				return;
		}
	}
}