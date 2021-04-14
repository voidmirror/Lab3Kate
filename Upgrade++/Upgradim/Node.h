#pragma once
#include "Info.h"
typedef struct Node {
    struct Node* next;
    Info* info;
} Node;