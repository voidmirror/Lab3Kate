#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Functions.h"
#include "List.h"



int main() {
	Node node;
	char misc[] = "11A:Sviridova:4.16:Frolova A.M.:27";
	node.string = (char*)malloc(sizeof(char) * strlen(misc));
	node.string = misc;
	SplittedInfo* info = splitIntoStructure(&node);

	puts(info->classhead);
	puts(info->teacher);

	printf("\n\n");

	puts(formStringFromSplitted(info));
}