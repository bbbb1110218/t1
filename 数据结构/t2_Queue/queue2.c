#include <stdio.h>

const int MAX=5;
char Queue[MAX];
int head=0; 
int tail=0;

void enqueue(char c);
char dequeue();
int isEmpty();
int isFull();


int main(){
	char c='A';
	int i;
	for(int i=0;i<3;i++){
		if(!isFull()){			//判断条件放在外面
			enqueue(c);
			c++;
		}
	}

	printf("-----out\n");
	while(!isEmpty()){			//判断条件放在外面
		putchar(dequeue());
	}

	return 0;
}

void enqueue(char c){		//判断条件放在外面
	Queue[tail]=c;			//先操作队列的值 再更新索引
	tail = (tail +1) % MAX;  //从后面进去
}

char dequeue(){
	char ch;
	ch=Queue[head];				//先更新值 再更新索引
	head=(head+1) % MAX;
	return ch;
}


int isEmpty(){
	return head==tail;
}


int isFull(){
	return (tail+1) % MAX == head;
}
