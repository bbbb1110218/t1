#include <stdio.h>


char Queue[512];
int head=0; 
int tail=0;


void enqueue(char c);
char dequeue();
int isEmpty();
int isFull();


int main(){

}






void enqueue(char c){
	Queue[tail++]=c;
}

char dequeue(){
	return Queue[head++];
}


int isEmpty(){
	return head==tail;
}


int isFull(){
	if(tail+1 == head)
		return 1;
	else 
		return 0;
}
