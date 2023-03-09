#ifndef __MYLINKLIST_H__
#define __MYLINKLIST_H__
#include <stdio.h>

typedef int MYTYPE;


struct Node{
	MYTYPE item;
	struct Node *next;
};

void Create_list(MYTYPE myt);

void ShowLinkList();
void InsertNode(int index,MYTYPE myt);
void FreeLinkList();
int FindNode(MYTYPE myt);

int NodeCount();

void DeleteNode(int index);


#endif
