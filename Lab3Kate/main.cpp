#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>



int main() {
	char* mas = (char*)malloc(50 * sizeof(char));
	mas[0] = 'k';
	mas[2] = 'o';
	mas[1] = 't';
	gets_s(mas, 49);
	puts(mas);

	char* kal;
	gets_s(kal, 30);
	puts(kal);
}