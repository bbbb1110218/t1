#include <stdio.h>
#include <stdlib.h>



typedef char ValueType;

struct BinTreeNode{
    ValueType item;
    struct BinTreeNode *ltree,*rtree;
    int lflag,rflag;
};

struct BinTreeNode * pre=NULL;//全局的 最左边节点 随时会更新的

struct BinTreeNode *PreCreateNode();
void PreShowNode(struct BinTreeNode * tree);
void OrderNode(struct BinTreeNode * tree);
void FullOrderNode(struct BinTreeNode * trees);
void sortShow(struct BinTreeNode * p);


int main(){

    printf("Please enter the Node value,step by blank,# for NULL:\n");
    struct BinTreeNode *tree=PreCreateNode();
    PreShowNode(tree);
    printf("\n");
    FullOrderNode(tree);


    printf("\nthe last:%c\n",pre->item);
    sortShow(tree);


    return 0;
}


struct BinTreeNode *PreCreateNode(){  //前序遍历节点
    ValueType value; //valuetype 暂时为char
    struct BinTreeNode * tree;
    value =getchar();
    if(value == '#'){
        tree = NULL;
    }else{
        tree=(struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
        tree->item=value;
        tree->ltree=PreCreateNode();
        tree->rtree=PreCreateNode();
    }

    return tree;
}

void PreShowNode(struct BinTreeNode * tree){
    if(tree){
        printf("%c -> ",tree->item);
        PreShowNode(tree->ltree);
        PreShowNode(tree->rtree);

    }
}


void OrderNode(struct BinTreeNode * tree){
    if(tree){
        OrderNode(tree->ltree);

        if(tree->ltree ==NULL){
            
            tree->ltree =pre;
            tree->lflag = 1;

        }else
            tree->lflag = 0;
        if(pre){
            if(pre->rtree ==NULL){
                
                pre->rflag=1;
                pre->rtree= tree;
               
            }else
                pre->rflag=0;
        }
        pre=tree;
            


        OrderNode(tree->rtree);
    }
}

void FullOrderNode(struct BinTreeNode * trees){
    if(trees){
        OrderNode(trees);
        pre->rtree=NULL;
        pre->rflag=1;

    }
}

void sortShow(struct BinTreeNode * p){
    while(p->lflag==0)
        p=p->ltree;
        printf("[%c]->",p->item);
    if(p->rtree !=NULL && p->rflag == 1)


        printf("[%c]->",p->item);
        p=p->rtree;
    
    
}
