#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<stdio.h>

extern struct node* head;
extern struct node* tail;



struct node{
	int elem;
	struct node *next;
};

void create_list(int c);
void insert_node(int pos,int elem1 );
void delete_node(int pos);
void print_linklist(void);
int search(int find);



#endif
