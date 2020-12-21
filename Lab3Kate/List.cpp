#include <string.h>
#include "List.h"

void push(Node* head, char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->string = str;
    //Node* next = head->next;
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

//void add2list(Node** pphead, char* str)
//{
//    Node** pp = pphead, * pnew;
//    while (*pp)
//    {
//        if (/*val < (*pp)->value ||*/ strcmp(str, (*pp)->string) < 0)
//            break;
//        else
//            pp = &((*pp)->next);
//    }
//    pnew = (Node*)malloc(sizeof(Node));
//    pnew->string = str;
//    pnew->next = *pp;
//    *pp = pnew;
//}

void print2(Node* phead)
{
    Node* p = phead;
    while (p)
    {
        printf("%s\n", p->string);
        p = p->next;
    }
    printf("\n");
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
    int i = 0;
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
    // ищем предыдущий для delNode
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
        free(p->string);
        free(p);
    }
}


//
//void mergeSort(Node** head) {
//    Node* low = NULL;
//    Node* high = NULL;
//    if ((*head == NULL) || ((*head)->next == NULL)) {
//        return;
//    }
//    split(*head, &low, &high);
//    mergeSort(&low);
//    mergeSort(&high);
//    merge(low, high, head);
//}
//
//
//void split(Node* src, Node** low, Node** high) {
//    Node* fast = NULL;
//    Node* slow = NULL;
//
//    if (src == NULL || src->next == NULL) {
//        (*low) = src;
//        (*high) = NULL;
//        return;
//    }
//
//    slow = src;
//    fast = src->next;
//
//    while (fast != NULL) {
//        fast = fast->next;
//        if (fast != NULL) {
//            fast = fast->next;
//            slow = slow->next;
//        }
//    }
//
//    (*low) = src;
//    (*high) = slow->next;
//    slow->next = NULL;
//}
//
//void merge(Node* a, Node* b, Node** c) {
//    Node tmp;
//    *c = NULL;
//    if (a == NULL) {
//        *c = b;
//        return;
//    }
//    if (b == NULL) {
//        *c = a;
//        return;
//    }
//    if (/*a->value < b->value ||*/ strcmp(a->string, b->string) < 0) {
//        *c = a;
//        a = a->next;
//    }
//    else {
//        *c = b;
//        b = b->next;
//    }
//    tmp.next = *c;
//    while (a && b) {
//        if (/*a->value < b->value ||*/ strcmp(a->string, b->string) < 0) {
//            (*c)->next = a;
//            a = a->next;
//        }
//        else {
//            (*c)->next = b;
//            b = b->next;
//        }
//        (*c) = (*c)->next;
//    }
//    if (a) {
//        while (a) {
//            (*c)->next = a;
//            (*c) = (*c)->next;
//            a = a->next;
//        }
//    }
//    if (b) {
//        while (b) {
//            (*c)->next = b;
//            (*c) = (*c)->next;
//            b = b->next;
//        }
//    }
//    *c = tmp.next;
//}