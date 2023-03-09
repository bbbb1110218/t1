#ifndef __MYHEAD_H__
#define __MYHEAD_H__

#include <stdio.h>

typedef int ValueType;

struct Node{
    ValueType item;
    struct Node *next;
};


typedef struct Node * NodeP;


void NodeAdd(ValueType nv);

unsigned int NodeCount(NodeP Nodefirst);

void InsertNode(int pos,ValueType nv);

void deleteNode(int pos);

void showNode(NodeP Nodefirst);

void FreeALLNode(NodeP Nodefirst);



extern NodeP head;
extern NodeP tail;










#endif