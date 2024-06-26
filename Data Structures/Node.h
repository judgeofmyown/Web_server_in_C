#ifndef Node_h
#define Node_h

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

enum Datatypes 
{
    Special,
    Int,
    Long,
    Float,
    Double,
    Char,
    Bool
};

struct Node {
    void * data;
    int data_type;
    int size;
    struct Node* next;
};

struct Node node_constructor(void *data, int data_type, int size);
void node_destructor(struct Node *node);

#endif