#include "list.h"

void push(Node* head, char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->string = str;

    Node* next = head->next;
    head->next = newNode;
    newNode->next = next;
}

void printAll(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->string);
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
    // ищем предыдущий для delNode
    while (tmp->next != delNode) {
        tmp = tmp->next;
    }
    tmp->next = delNode->next;
    free(delNode);
}

void freeList(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        Node* p = tmp;
        tmp = tmp->next;
        free(p);
    }
}