#include <stdio.h>

#define MAX 20

typedef int TYPE;

TYPE QUEUE[MAX];

int head=0;
int tail=0;


void enqueue(TYPE it);

TYPE dequeue();

int isEmpty();

int isFull();


int main(){

	int a=666;
	for(int i=0;i<30;i++){
		if(!isFull()){
			enqueue(a++);
		}
	}

	printf("-----\n");
	while(!isEmpty()){
		static int cc=0;
		printf("[%2.2d] %d\n",cc++,dequeue());
	}



	return 0;
}

void enqueue(TYPE it){
	QUEUE[tail]=it;
	tail=(tail+1) % MAX;
}

TYPE dequeue(){
	TYPE it;
	it=QUEUE[head];
	head=(head+1) % MAX;
	return it;
}

int isEmpty(){
	return head==tail;
}

int isFull(){
	return (tail+1)%MAX==head;
}