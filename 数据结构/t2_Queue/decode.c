#include <stdio.h>
#include <string.h>

const int MAX=200;
char Queue[MAX];
int head=0; 
int tail=0;

void enqueue(char c);
char dequeue();
int isEmpty();
int isFull();


int main(){
	char code[MAX+1];
	int n;
	int index=0;
	char num;
	printf("Please enter a code:");
	gets(code);
	for(n=0;n<strlen(code);n++){
		if(!isFull())
			enqueue(code[n]);
		else
			printf("Queue is full ,charator [%c] not enqueu",code[n]);
	}

	while(!isEmpty()){
		code[index++]=dequeue();  //存入到一个数组里面
		if(!isEmpty()){ 
			num=dequeue();
			if(!isFull()){
				enqueue(num);
			}
		}
	}
	code[index]='\0';
	printf("%s\n",code);

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
