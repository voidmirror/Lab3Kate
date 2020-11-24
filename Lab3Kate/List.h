#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    char* string;
} Node;

void push(Node* head, char* str);
void printAll(Node* head);

int len(Node* head);
Node* find(Node* head, int index);
void del(Node* head, int index);

void freeList(Node* head);