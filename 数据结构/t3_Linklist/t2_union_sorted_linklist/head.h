#ifndef __MYHEAD_C__
#define __MYHEAD_C__
#include <stdio.h>

typedef int ValueType;

struct Node{
	ValueType value;
	struct Node* next;
};


void MakeNode(ValueType vt);

void ShowNode(struct Node * Node_head);

void InsertNode(int pos,ValueType vt);

void DeleteNode(int pos);

int
NodeCount();


void
FreeAllNode();

extern struct Node *head;  // mian 函数文件会包含头文件  main 函数引入外部变量
extern struct Node *tail;






#endif