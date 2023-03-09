
#include <stdlib.h>
#include "binary_tree.h"



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
	

}


