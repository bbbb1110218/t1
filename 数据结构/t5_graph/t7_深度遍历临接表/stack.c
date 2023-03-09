#include "stack.h"


int stack[SMAX];
int top=0;


void push(int n){
	stack[top++]=n;
}

int  pop(void){
	return stack[--top];

}
int isEmpty(void){
	return top==0 ? 1 : 0;
}


