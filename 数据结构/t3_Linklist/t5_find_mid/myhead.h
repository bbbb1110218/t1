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

void ShowNode(NodeP Nodefirst);

void FreeALLNode(NodeP Nodefirst);
void DeleteRepert(NodeP Nodefirst);

ValueType FindMid(struct Node * Nodehead);

extern NodeP head;
extern NodeP tail;










#endif