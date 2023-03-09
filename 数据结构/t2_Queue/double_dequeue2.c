//
// Created by macbookpro on 2023/2/11.
//



#include<stdio.h>
#include<stdbool.h>
#define SIZE 5


typedef int MYTYPE;     //

MYTYPE QUEUE[SIZE];
int head=0;
int tail=0;





void tail_enqueue(MYTYPE c);
MYTYPE tail_dequeue();
void head_enqueue(MYTYPE c);
MYTYPE head_dequeue();
bool isEmpty();
bool isFull();
int qCount();
void ShowQUEUE();
void showInfo();

int main(){

    for(int i=0;i<18;i++){
        if(!isFull()){
            tail_enqueue(i);
        }

    }

    showInfo();
    printf("now head_dequeue ->%d\n",head_dequeue());
    showInfo();
    printf("now head_dequeue ->%d\n",head_dequeue());
    showInfo();
    printf("now head_dequeue ->%d\n",tail_dequeue());
    showInfo();

    head_enqueue(20);
    showInfo();
    head_enqueue(210);
    showInfo();
    if(!isFull())
        head_enqueue(210);
    else
        printf("[Queue full]\n");
    showInfo();
    if(!isFull())
        head_enqueue(2110);
    else
        printf("[Queue full]\n");
    showInfo();

//    printf("now Queue count is [ %d ]\n",qCount());
//    printf("now head_dequeue ->%d\n",head_dequeue());
//    printf("now Queue count is [ %d ]\n",qCount());
//    printf("now head_dequeue ->%d\n",head_dequeue());
//    printf("now Queue count is [ %d ]\n",qCount());
//
//    tail_enqueue(20);
//    tail_enqueue(20);




    return 0;
}


void tail_enqueue(MYTYPE c){        //尾部入队列
    QUEUE[tail]=c;
    tail =(tail+1) % SIZE;          //循环队列,当假溢出的时候，再添加到头节点取，需要在外部判断下队列是否为满
}

MYTYPE tail_dequeue(){
    tail = (tail -1 +SIZE) % SIZE;      //尾部出队列 尾部先减1 小于0的时候  会到队列尾
    return QUEUE[tail];                 //返回尾巴，因为队列里面的元素并不会消失，只是指向的位置发生了变化
}

void head_enqueue(MYTYPE c){            //头部入队列 也得现在外面判断一下 是否为满
    head =(head-1+SIZE)%SIZE;           //先减去1 防止 索引为-1 所以加上 队列的个数 添加到队列尾巴
    QUEUE[head]=c;                       //赋值
}

MYTYPE head_dequeue(){                  //头部出队列 得在外面先判断一下队列 是不是为空
    MYTYPE temp=QUEUE[head];
    head=(head+1) %SIZE;                   //头节点加1 防止出现假溢出 % 队列个数
    return temp;
}

bool isEmpty(){
    return head==tail;                      //头节点等于尾节点的时候 队列为空
}

bool isFull(){                              //判断是否为满
    return (tail+1)%SIZE == head;
}

int qCount(){
    if(tail >= head){
        return tail - head;
    }else{
        return SIZE-head+tail;
    }
}

void ShowQUEUE(){
    for(int i=0;i<SIZE;i++){
        printf("%d -> " ,QUEUE[i]);
    }
    putchar(10);
}

void showInfo(){
    printf("count:[%d],head:[%d],tail:%[%d]    ",qCount(),head,tail);
    ShowQUEUE();
}

