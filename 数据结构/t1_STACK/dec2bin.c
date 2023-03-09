//
// Created by macbookpro on 2023/2/10.
//
/*
十进制转二进制
余数全部入栈
最后全部出栈 高位排在前面
*/

#include <stdio.h>


int stack[512];
int top=0;


void push(int c);
int pop();
int isEmpty();

int main(){
    int num;
    printf("please enter an interager in decimal:");
    scanf("%d",&num);

    while(num){
        push(num % 2);
        num /=2;
    }
    while(!isEmpty()){
        printf("%d",pop());
    }
    printf("\n");


    return 0;
}



void push(int c){
    stack[top++]=c;

}

int pop(){
    printf("minliang");
    return stack[--top];
}

int isEmpty(){
    return top==0;
}