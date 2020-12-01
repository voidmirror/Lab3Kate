#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    char* string;
} Node;

void push(Node* head, char* str);
//void add2list(Node** pphead, char* str);
void initList(Node* head, char* str);
void add2list(Node* head, char* str);
void printAll(Node* head);
void print2(Node* phead);

int len(Node* head);
Node* find(Node* head, int index);
void del(Node* head, int index);
Node* delNode(Node* head, Node* toDelete);

void freeList(Node* head);

//void mergeSort(Node** head);
//void split(Node* src, Node** low, Node** high);
//void merge(Node* a, Node* b, Node** c);
Node* getLast(Node* head);