
#include <stdlib.h>
#include "binary_tree.h"

/*

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdio.h>




struct BINTREE_NODE{
    unsigned char elem;                        //属于元素
    struct BINTREE_NODE *ltree,*rtree;        // 左 右子树
};

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <string.h>

#include "binary_tree.h" //需要结构类型







void enqueue(struct BINTREE_NODE c);
struct BINTREE_NODE dequeue();
int isEmpty();
int isFull();






#endif



struct BINTREE_NODE* create_tree();
void pre_order(struct BINTREE_NODE * tree);
void mid_order(struct BINTREE_NODE * tree);
void pos_order(struct BINTREE_NODE * tree);
void ShowByQueue(struct BINTREE_NODE * tree);


#endif
 */




struct BINTREE_NODE* create_tree(){
    unsigned char flag;                //标指位
    struct BINTREE_NODE* tree;            //
    tree=(struct BINTREE_NODE *) malloc(sizeof(struct BINTREE_NODE)); //分配内存空间
    
    printf("please input the elem:");
    while((tree->elem =getchar()) =='\n');                            //填充元素
    
    printf("Do you want to insert ltree[左子树] for %c (Y?N)?\n",tree->elem);        //询问是否要左子树
    while((flag =getchar()) =='\n');
    if(flag=='y' || flag =='Y')
        tree->ltree=create_tree();                            //开辟空间
    else
        tree->ltree=NULL;                                    //填充NULL值
    
    printf("Do you want to insert rtree[右子树] for %c (Y?N)?\n",tree->elem); //询问是否要右子树
    while((flag =getchar()) =='\n');
    if(flag=='y' || flag =='Y')
        tree->rtree=create_tree();
    else
        tree->rtree=NULL;
    
    return tree;
        
  
}

//先序遍历
void pre_order(struct BINTREE_NODE * tree){
  if(tree){
        printf(" %c ->",tree->elem);    //先访问数据
        pre_order(tree->ltree);        //先序遍历左子树 递归自己
        pre_order(tree->rtree);        //先序遍历右子树 递归自己
  }
}

//中序遍历
void mid_order(struct BINTREE_NODE * tree){
  if(tree){
        mid_order(tree->ltree);        //先序遍历左子树 递归自己
        printf(" %c ->",tree->elem);    //先访问数据
        mid_order(tree->rtree);        //先序遍历右子树 递归自己
  }
}


//后序遍历
void pos_order(struct BINTREE_NODE * tree){
  if(tree){
        
        pos_order(tree->ltree);        //遍历左子树 递归自己
        pos_order(tree->rtree);        //遍历右子树 递归自己
        printf(" %c ->",tree->elem);    //先访问数据
  }
}



void ShowByQueue(struct BINTREE_NODE * tree){
    enqueue(*tree);                              //先把根节点 进队列
    struct BINTREE_NODE temp;                       //临时节点存放信息，不是指针
    while(!isEmpty()){                              //队列不为空 一直循环
        temp=dequeue();                             //根节点 先出队列
        printf("%c ->",temp.elem);                  //打印根节点信息
        if(temp.ltree !=NULL){                      //如果左边节点不为空
            enqueue(*temp.ltree);                  //左边节点进去队列  下一次循环先出

        }
        if(temp.rtree !=NULL){                           //如果左边节点不为空
            enqueue(*temp.rtree);                     //左边节点进去队列  下一次循环先出
        }

    }

}




