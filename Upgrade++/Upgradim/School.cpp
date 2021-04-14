//#include <iostream>
//#include <string>
//#include "School.h"

using namespace std;

School::School() {
}

vector<Info*> School::getSchool() {
	return school;
}

void School::addClass() {
	Info tmp;
	cin >> tmp.getClasss();
	cin >> tmp.getClasshead();
	cin >> tmp.getAverageMark();
	cin >> tmp.getTeacher();
	cin >> tmp.getStudentsNumber();
	school.push_back(&tmp);
}

void School::removeClass() {
	char* s = (char*)malloc(sizeof(char) * 20);
	cin >> s;
	cout << s;
}

void School::searchClass() {

}

void School::changeClass() {

}

void School::printAllClasses() {
	cout << 
}

void School::initFromFile() {

}

void School::saveToFile() {

}

Node* School::addNewAssignment(Node* head) {
	Info *info = new Info();
	printf("Enter the Class: ");
	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		//head->string = (char*)malloc(sizeof(char) * 80);
		head->next = NULL;

		scanf("%s", info->getClasss());
		printf("Enter lastname of Head of the class: ");
		scanf("%s", info->getClasshead());
		printf("Enter Average Mark of students: ");
		scanf("%s", info->getAverageMark());
		printf("Enter teachers' lastname and initials: ");
		scanf("%s", info->getTeacher());
		printf("Enter Students number: ");
		scanf("%s", info->getStudentsNumber());

		// remove -> в ноде будет храниться сам класс
		//head->info = formStringFromSplitted(info);

		head->info = info;

	}
	else {
		scanf("%s", info->getClasss());
		if (!isClassExisted(head, info->getClasss())) {
			printf("Enter lastname of Head of the class: ");
			scanf("%s", info->getClasshead());
			printf("Enter Average Mark of students: ");
			scanf("%s", info->getAverageMark());
			printf("Enter teachers' lastname: ");
			scanf("%s", info->getTeacher());
			printf("Enter Students number: ");
			scanf("%s", info->getStudentsNumber());

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

bool isClassExisted(Node* head, char* isClass) {
	// TODO
	if (findByClass(head, isClass) == NULL) {
		return false;
	}
	else {
		return true;
	}
}

Node* findByClass(Node* head, char* classs) {
	Node* tmp = head;
	while (tmp != NULL) {
		//char* tmppp = splitIntoStructure(tmp)->classs;
		if (strcmp(head->info->getClasss(), classs) == 0) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}