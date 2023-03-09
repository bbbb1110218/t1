
#include "stack.h"


int stack[512];
int top=0;






void push(int c){
    stack[top++]=c;

}

int pop(){
    return stack[--top];
}

int isEmpty(){
    return top==0;
}