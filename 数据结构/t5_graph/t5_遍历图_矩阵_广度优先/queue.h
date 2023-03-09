#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>

#define QMAX 512
extern int Queue[QMAX];

void enqueue(int c);
int dequeue();
int isEmpty();
int isFull();


#endif


