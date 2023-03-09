//
// Created by macbookpro on 2023/2/10.
//
#include <stdio.h>


char stack[512];
int top=0;


void push(char c);
char pop();
int isEmpty();

int main(){
    push('a');
    push('b');
    push('c');

    while(!isEmpty()){
        putchar(pop());
    }
    putchar('\n');

    return 0;
}



void push(char c){
    stack[top++]=c;

}

char pop(){
    return stack[--top];
}

int isEmpty(){
    return top==0;
}