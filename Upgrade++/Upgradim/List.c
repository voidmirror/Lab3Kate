#include <iostream>
#include "List.h"

//using namespace std;

void push(Node* head, Info* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->string = str;
    head->next = newNode;
    newNode->next = NULL;
}

void add2list(Node* head, char* str) {
    push(getLast(head), str);
}

void initList(Node* head, char* str) {
    head = (Node*)malloc(sizeof(Node));
    head->string = str;
    head->next = NULL;
}

Node* getLast(Node* head) {
    Node* phead = head;
    if (phead == NULL) {
        return NULL;
    }
    while (phead->next) {
        phead = phead->next;
    }
    return phead;
}

void printAll(Node* head) {
    Node* tmp = head;
    int i = 1;
    while (tmp) {
        printf("%d ", i);
        i++;
        printf("%s\n", tmp->string);
        tmp = tmp->next;
    }
    printf("\n");
}

int len(Node* head) {
    int lenght = 0;
    Node* tmp = head;
    while (tmp != NULL) {
        lenght++;
        tmp = tmp->next;
    }
    return lenght;
}

Node* find(Node* head, int index) {
    int i = 0;
    Node* tmp = head;
    while (tmp != NULL) {
        if (i == index) {
            return tmp;
        }
        i++;
        tmp = tmp->next;
    }
    return NULL;
}

void del(Node* head, int index) {
    Node* delNode = find(head, index);
    Node* tmp = head;
    while (tmp->next != delNode) {
        tmp = tmp->next;
    }
    tmp->next = delNode->next;
    free(delNode);
}

Node* delNode(Node* head, Node* toDelete) {
    Node* tmp = head;
    if (tmp == toDelete) {
        head = toDelete->next;
    }
    else {
        while (tmp->next != toDelete) {
            tmp = tmp->next;
        }
    }
    tmp->next = toDelete->next;
    free(toDelete->string);
    free(toDelete);
    return head;
}

void freeList(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        Node* p = tmp;
        tmp = tmp->next;
        if (p->string != NULL) {
            free(p->string);
        }
        if (p != NULL) {
            free(p);
        }
    }
}
