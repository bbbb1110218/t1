#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<stdio.h>



typedef int ValueType;

struct node{
	ValueType elem;
	struct node *pre;	//向前的指针
	struct node *next;	//向后的指针
};

void create_list(ValueType c);
void insert_node(int pos,ValueType elem1 );
void delete_node(int pos);
void print_linklist(void);
int search(ValueType find);

void free_link_list();


void print_linklist_reseved(void);

void recursion_print(struct node* Nodefirst);

extern struct node * head;
extern struct node * tail;



#endif
