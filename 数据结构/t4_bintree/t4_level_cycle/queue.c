
#include "queue.h"


/*

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <string.h>

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdio.h>




struct BINTREE_NODE{
    unsigned char elem;                        //属于元素
    struct BINTREE_NODE *ltree,*rtree;        // 左 右子树
};

#include "queue.h"



struct BINTREE_NODE* create_tree();
void pre_order(struct BINTREE_NODE * tree);
void mid_order(struct BINTREE_NODE * tree);
void pos_order(struct BINTREE_NODE * tree);
void ShowByQueue(struct BINTREE_NODE * tree);


#endif







void enqueue(struct BINTREE_NODE c);
struct BINTREE_NODE dequeue();
int isEmpty();
int isFull();






#endif


*/


typedef struct BINTREE_NODE Valuetype;
const int MAX=200;
Valuetype Queue[100];


int head=0;
int tail=0;

void enqueue(struct BINTREE_NODE c){       //判断条件放在外面
    Queue[tail]=c;          //先操作队列的值 再更新索引
    tail = (tail +1) % MAX;  //从后面进去
}

struct BINTREE_NODE dequeue(){
    Valuetype ch;
    ch=Queue[head];             //先更新值 再更新索引
    head=(head+1) % MAX;
    return ch;
}


int isEmpty(){
    return head==tail;
}


int isFull(){
    return (tail+1) % MAX == head;
}