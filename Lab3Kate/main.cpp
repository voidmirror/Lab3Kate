#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Functions.h"
#include "List.h"



int main() {
	char* fileName = (char*)malloc(sizeof(char) * 80);
	printf("Enter database file name: ");
	//scanf("%s", fileName);
	gets_s(fileName, 80);
	Node* head = NULL;

	initFromFile(head, fileName);
	readFrom(fileName);

	printAll(head);


	//Node *node = (Node*) malloc(sizeof(Node));
	//char misc[] = "11A:Sviridova:4.16:Frolova A.M.:27\0";	//		\0 needed ?
	//node->string = (char*)malloc(sizeof(char) * strlen(misc) + 10);
	//node->string = misc;
	//node->next = NULL;
	

	//for (int i = 0; i < 2; i++) {
	//	addNewAssignment(head);
	//}
	//puts("----------------------------");
	//puts("----------------------------");
	//puts("----------------------------");
	//printAll(head);
	//

	////saveToFile(node, fileName);
	//


	//printf("\n=================\n");
	//printAll(head);
	//freeList(head);
	return 0;
}