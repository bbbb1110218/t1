#ifndef __STACK_H__
#define __STACK_H__
#include <stdio.h>

#define SMAX 512



void push(int n);
int  pop(void);
int isEmpty(void);

extern int stack[SMAX];
extern int top;




#endif