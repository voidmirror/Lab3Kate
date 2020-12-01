#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Functions.h"
#include "List.h"



int main() {
	printf("|----------------------------|\n");
	printf("| Perfect School Database TM |\n");
	printf("|----------------------------|\n\n");
	printf("Enter filename of your database: ");
	char* fileName = (char*)malloc(sizeof(char) * 80);
	gets_s(fileName, 80);
	Node* head = NULL;
	head = initFromFile(head, fileName);
	if (head == NULL) {
		printf("File does not exist or is empty. Database created\n");
	}

	char* choice = (char*)malloc(sizeof(char) * 10);
	bool working = true;
	
	//printAll(head);

	while (working) {
		printMenu();
		printf("\nYour action choice: ");
		gets_s(choice, 10);
		char* tmp = (char*)malloc(sizeof(char) * 20);
		Node* toFind;

		switch (atoi(choice)) {
		case 1:
			head = addNewAssignment(head);
			break;
		case 2:
			printf("Enter Class: ");
			gets_s(tmp, 10);
			toFind = findByClass(head, tmp);
			if (toFind == NULL) {
				printf("There is no Class %s\n", tmp);
			}
			else {
				printSplittedInfo(splitIntoStructure(toFind));
			}
			free(tmp);
			break;
		case 3:
			printf("Enter Classhead's lastname: ");
			gets_s(tmp, 20);
			toFind = findByClasshead(head, tmp);
			if (toFind == NULL) {
				printf("There is no Classhead %s\n", tmp);
			}
			else {
				printSplittedInfo(splitIntoStructure(toFind));
			}
			free(tmp);
			break;
		case 4:
			printf("Enter Teacher's lastame (Ex.: Voronina E.A.): ");
			gets_s(tmp, 20);
			toFind = findByTeacher(head, tmp);
			if (toFind == NULL) {
				printf("There is no Teacher %s\n", tmp);
			}
			else {
				printSplittedInfo(splitIntoStructure(toFind));
			}
			free(tmp);
			break;
		case 5:
			printf("\n");
			printAll(head);
			printf("\n");
			break;
		case 6:
			changeData(head);
			break;
		case 7:
			head = deleteByClass(head);
			break;
		default:
			saveToFile(head, fileName);
			working = false;
		}
	}




	//================================================================================
	//
	//                                  TESTING
	//
	//================================================================================

	//char* fileName = (char*)malloc(sizeof(char) * 80);
	//printf("Enter database file name: ");
	////scanf("%s", fileName);
	//gets_s(fileName, 80);
	//Node* head = NULL;

	//head = initFromFile(head, fileName);
	//if (head == NULL) {
	//	printf("File does not exist or is empty. Database created");
	//}
	////readFrom(fileName);

	//printAll(head);


	////Node *node = (Node*) malloc(sizeof(Node));
	////char misc[] = "11A:Sviridova:4.16:Frolova A.M.:27\0";	//		\0 needed ?
	////node->string = (char*)malloc(sizeof(char) * strlen(misc) + 10);
	////node->string = misc;
	////node->next = NULL;
	//

	//puts("----------------------------");
	//puts("----------------------------");
	//puts("----------------------------");

	//for (int i = 0; i < 2; i++) {
	//	head = addNewAssignment(head);
	//}
	//puts("----------------------------");
	//puts("----------------------------");
	//puts("----------------------------");
	//printAll(head);

	////head = deleteByClass(head);

	//puts("----------------------------");
	//puts("----------------------------");
	//puts("----------------------------");
	//printAll(head);
	//
	//

	//saveToFile(head, fileName);
	//


	//printf("\n=================\n");
	//printAll(head);

	//================================================================================
	//
	//                                  TESTING
	//
	//================================================================================

	// End of program ====================================================================
	freeList(head);
	return 0;
}