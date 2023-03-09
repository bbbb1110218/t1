#ifndef __MYHEAD_C__
#define __MYHEAD_C__
#include <stdio.h>

typedef int ValueType;

struct Node{
	ValueType value;
	struct Node* next;
};


void MakeNode(ValueType vt);

void ShowNode();

void InsertNode(int pos,ValueType vt);

void DeleteNode(int pos);

int
NodeCount();


void
FreeAllNode();






#endif