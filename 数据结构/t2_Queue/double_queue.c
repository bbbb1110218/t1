#include <stdio.h>
#include <string.h>
/*
双向都可以进出的队列
*/

const int MAX=512;
char Queue[MAX];
int head=0; 
int tail=0;

void tail_enqueue(char c); //尾端
char tail_dequeue();		//尾短出队列
void head_enqueue(char c);
char head_dequeue();
int isEmpty();
int isFull();


int main(){
	char *str="fuckyouoykcuf";
	int len=strlen(str);
	for(int i=0;i<len;i++){
		tail_enqueue(str[i]);
	}
	while(head < tail){
		if(head_dequeue() != tail_dequeue()){

			printf("%s is not 回文\n",str);
			return 0;
		}

	}
	printf("%s is  回文\n",str);


	return 0;

}

void tail_enqueue(char c){		//判断条件放在外面
	Queue[tail]=c;			//先操作队列的值 再更新索引
	tail = (tail +1) % MAX;  //从后面进去
}

char tail_dequeue(){
	tail=(tail -1 + MAX) % MAX;	//考虑到出现负数的问题
	return Queue[tail];
}

void head_enqueue(char c){		//头部入队列
	head=(head-1 +MAX) % MAX;
	Queue[head]=c;

}


char head_dequeue(){			//头部出队列
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
