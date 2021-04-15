#include <iostream>
#include <fstream>
#include <cstring>

#include "School.h"

using namespace std;

School::School()
{
	head = NULL;
}

void School::addClass(Info* info) {
	if (head == NULL) {
		head = info;
	}
	else {
		Info* tmp = getLast();
		tmp->setNext(info);
	}
}

void School::removeClass(char* classs) {
	Info* toRemove = findByClass(classs);
	if (toRemove != NULL) {

		if (head == toRemove) {
			head = head->getNext();
			return;
		}
		
		Info* tmp = head;
		while (tmp->getNext() != toRemove) {
			tmp = tmp->getNext();
		}
		tmp->setNext(toRemove->getNext());
	}
	else {
		cout << "Class does not exist" << endl;
	}
}

Info* School::findByClass(char* classs) {
	Info* tmp = head;
	while (tmp != NULL) {
		if (strcmp(tmp->getClasss(), classs) == 0) {
			return tmp;
		}
		tmp = tmp->getNext();
	}
	return NULL;
}

Info* School::findByClasshead(char* classhead) {
	Info* tmp = head;
	while (tmp != NULL) {
		if (strcmp(tmp->getClasshead(), classhead) == 0) {
			return tmp;
		}
		tmp = tmp->getNext();
	}
	return NULL;
}

Info* School::findByTeacher(char* teacher) {
	Info* tmp = head;
	while (tmp != NULL) {
		if (strcmp(tmp->getTeacher(), teacher) == 0) {
			return tmp;
		}
		tmp = tmp->getNext();
	}
	return NULL;
}

void School::printAllClasses() {
	Info* tmp = head;
	while (tmp != NULL) {
		cout << tmp->toString() << endl;
		tmp = tmp->getNext();
	}
}

void School::changeClass(char* classs) {
	Info* toChange = findByClass(classs);
	if (toChange != NULL) {
		Info* dest = new Info();
		dest->clone(toChange);

		while (true) {
			cout << "What do you want to change?" << endl;
			cout << "1. Class" << endl;
			cout << "2. Head of class" << endl;
			cout << "3. Average mark" << endl;
			cout << "4. Teacher's lastname" << endl;
			cout << "5. Students number" << endl;
			cout << "6. Cancel all changes" << endl;
			cout << "0. Any other choice will save data" << endl << endl;

			int choice;
			cout << "Your choice: ";
			cin >> choice;
			char* toChange = (char*)malloc(sizeof(char) * 30);
			toChange[0] = '\0';

			switch (choice) {
			case 1:
				cout << "Enter new class num:";
				cin >> toChange;
				strcpy(dest->getClasss(), toChange);
				break;
			case 2:
				cout << "Enter new Head of class (lastname):";
				cin >> toChange;
				strcpy(dest->getClasss(), toChange);
			case 3:
				cout << "Enter new Average mark:";
				cin >> toChange;
				strcpy(dest->getClasss(), toChange);
				break;
			case 4:
				cout << "Enter new Teacher's lastname:";
				cin >> toChange;
				strcpy(dest->getClasss(), toChange);
				break;
			case 5:
				cout << "Enter new class num:";
				cin >> toChange;
				strcpy(dest->getClasss(), toChange);
				break;
			case 6:
				delete dest;
				dest = new Info();
				cout << "All changes cancelled" << endl;

			default:
				//saveToFile()
				break;
			}

			free(toChange);
		}

		
	}
	else {
		cout << "Class is not found" << endl;
	}
}

void School::initFromFile(char* file) {
	ifstream fin;
	fin.open(file, ios_base::in);		//ifstream::in
	if (!fin.is_open()) {
		cout << "# File does not exist" << endl;
		ofstream fout;
		fout.open(file, ios_base::out);
		cout << "# New database file created" << endl;
	}

	char* tmp = (char*)malloc(sizeof(char) * 200);
	while (fin.getline(tmp, 199)) {

		char misc[5][30];
		char* lex = strtok(tmp, ":");

		int i = 0;
		while (lex != NULL)
		{
			strcpy(misc[i], lex);
			i++;
			lex = strtok(NULL, ":");
		}

		Info* info = new Info();
		
		strcpy(info->getClasss(), misc[0]);
		strcpy(info->getClasshead(), misc[1]);
		strcpy(info->getAverageMark(), misc[2]);
		strcpy(info->getTeacher(), misc[3]);
		strcpy(info->getStudentsNumber(), misc[4]);

		addClass(info);

		free(tmp);
		tmp = (char*)malloc(sizeof(char) * 200);
	}

	fin.close();
	
}

void School::saveToFile(char* file) {
	char* tmp = (char*)malloc(sizeof(char) * 200);

	ofstream fout;
	fout.open(file, ios_base::out);
	Info* info = head;
	while (info != NULL) {
		fout << info->toSaveString();
		fout << '\n';
		info = info->getNext();
	}
	fout.close();
}

Info* School::getLast() {
	Info* tmp = head;
	while (tmp->getNext() != NULL) {
		tmp = tmp->getNext();
	}
	return tmp;
}
