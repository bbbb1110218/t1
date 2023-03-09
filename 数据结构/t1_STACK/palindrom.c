//
// Created by macbookpro on 2023/2/10.
//
#include <stdio.h>
#include <string.h>


char stack[512];
int top=0;


void push(char c);
char pop();
int isEmpty();

int is_palindrom(char *str);

int main(){
    char str[100];
    printf("Please enter string:");
    gets(str);

    if(is_palindrom(str))
        printf("Is an is_palindrom|是回文\n");
    else
        printf("is not a palindrom｜不是回文\n");

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

int is_palindrom(char *str){
    int len=strlen(str);
    int i;
    for(i=0;i<len/2;i++){
        push(str[i]);
    }

    if(len % 2 ==1)
        i++;

    while(!isEmpty()){
        char temp=pop();
        if(str[i++] !=temp)
            return 0;
    }
    return 1;
}