#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Functions.h"
#include "List.h"



int main() {
	Node *node = (Node*) malloc(sizeof(Node));
	char misc[] = "11A:Sviridova:4.16:Frolova A.M.:27\0";	//		\0 needed ?
	node->string = (char*)malloc(sizeof(char) * strlen(misc) + 10);
	node->string = misc;
	node->next = NULL;
	/*SplittedInfo* info = splitIntoStructure(&node);

	puts(info->classhead);
	puts(info->teacher);

	printf("\n\n");

	puts(formStringFromSplitted(info));
	
	printf("\n\n");*/

	//char kol[] = "11B:bhnjm:333:dfg:32\0";
	////push(node, kol);
	//add2list(node, kol);
	//char step[] = "7C:srf:2:srgvse:1\0";
	////push(node, step);
	//add2list(node, step);
	//char gap[] = "7A:svkp:78:mknkjaw:32\0";
	////push(node, gap);
	//add2list(node, gap);

	//print2(node);
	//printf("\n\n");
	//mergeSort(&node);
	//print2(node);

	for (int i = 0; i < 2; i++) {
		addNewAssignment(node);
	}
	puts("----------------------------");
	puts("----------------------------");
	puts("----------------------------");
	printAll(node);
	/*puts("----------------------------");
	puts("----------------------------");
	puts("----------------------------");
	printf("\n\n");
	puts("What to find?");
	char* tmp = (char*)malloc(sizeof(char) * 50);
	gets_s(tmp, 5);*/
	
	
	//printSplittedInfo(splitIntoStructure(findByClass(node, tmp)));

	changeData(node);


	printf("\n=================\n");
	printAll(node);
	freeList(node);
	return 0;
}