#include "queue.h"



int Queue[QMAX];
int head=0; 
int tail=0;



void enqueue(int c){		//判断条件放在外面
	Queue[tail]=c;			//先操作队列的值 再更新索引
	tail = (tail +1) % QMAX;  //从后面进去
}

int dequeue(){
	int ch;
	ch=Queue[head];				//先更新值 再更新索引
	head=(head+1) % QMAX;
	return ch;
}


int isEmpty(){ 
	return head==tail;
}


int isFull(){
	return (tail+1) % QMAX == head;
}
