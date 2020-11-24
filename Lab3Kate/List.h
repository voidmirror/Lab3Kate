#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int number;//struct human student;
} Node;

void push(Node* head, int newNumber);
void printAll(Node* head);

int len(Node* head);
Node* find(Node* head, int index);
void del(Node* head, int index);

void freeList(Node* head);