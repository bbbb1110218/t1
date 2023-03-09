//
// Created by macbookpro on 2023/2/10.
//
// 括号匹配   ()
//一整串 表达式 计算 对应的括号
// (1+2)*(2+3) 
#include <stdio.h>
#include <string.h>


char stack[512];
int top=0;


void push(int c);
int pop();
int isEmpty();

int main(){
    char str[100];
    int len;
    printf("Please enter your expression|输入表达式");
    fgets(str,100,stdin);
    len=strlen(str);

    for(int i=0;i<len;i++){
        if(str[i]=='(')
            push(i);
        else if(str[i] == ')')
            printf("%d %d\n",pop(),i);
    }


    return 0;
}



void push(int c){
    stack[top++]=c;

}

int pop(){
    return stack[--top];
}

int isEmpty(){
    return top==0;
}