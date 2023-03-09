#include <stdio.h>
#include <stdlib.h>




const char * format = " %lf ->";

struct BINTREE_NODE{
    double elem;                        //属于元素
    struct BINTREE_NODE *ltree,*rtree;        // 左 右子树
};

struct BINTREE_NODE* create_tree();
void pre_order(struct BINTREE_NODE * tree);
void mid_order(struct BINTREE_NODE * tree);
void pos_order(struct BINTREE_NODE * tree);


int main(){
    struct BINTREE_NODE* mytree;
    printf("填充数字\n");
    printf("Please enter the number step by blank 0 for NULL:\n");
    mytree=create_tree();
    
    printf("先序列遍历:\n");
    pre_order(mytree);
    printf("\n");
    
    printf("中序列遍历:\n");
    mid_order(mytree);
    printf("\n");
    
    printf("后序列遍历:\n");
    pos_order(mytree);
    printf("\n");
    return 0;
    
}

struct BINTREE_NODE* create_tree(){
    struct BINTREE_NODE* node;

    double ch;
    scanf("%lf",&ch);

    if(ch == 0 ){
        node =NULL;
    }else{
        node=(struct BINTREE_NODE *)malloc(sizeof(struct BINTREE_NODE));
        node->elem =ch;
        node->ltree=create_tree();
        node->rtree=create_tree();
    }
    return node;
}





//先序遍历
void pre_order(struct BINTREE_NODE * tree){
  if(tree){
        printf(format,tree->elem);    //先访问数据
        pre_order(tree->ltree);        //先序遍历左子树 递归自己
        pre_order(tree->rtree);        //先序遍历右子树 递归自己
  }
}

//中序遍历
void mid_order(struct BINTREE_NODE * tree){
  if(tree){
        mid_order(tree->ltree);        //先序遍历左子树 递归自己
        printf(format,tree->elem);    //先访问数据
        mid_order(tree->rtree);        //先序遍历右子树 递归自己
  }
}


//后序遍历
void pos_order(struct BINTREE_NODE * tree){
  if(tree){
        
        pos_order(tree->ltree);        //遍历左子树 递归自己
        pos_order(tree->rtree);        //遍历右子树 递归自己
        printf(format,tree->elem);    //访问数据
  }
}


