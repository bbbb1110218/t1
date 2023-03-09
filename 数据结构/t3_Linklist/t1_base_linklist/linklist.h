#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<stdio.h>


struct node{
	unsigned char elem;
	struct node *next;
};

void create_list(unsigned char c);
void insert_node(int pos,unsigned char elem1 );
void delete_node(int pos);
void print_linklist(void);
int search(unsigned char find);

void free_link_list();

#endif
