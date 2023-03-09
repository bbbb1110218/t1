#include <stdio.h>
#include <stdlib.h>




struct BINTREE_NODE{
    unsigned char elem;						//属于元素
    struct BINTREE_NODE *ltree,*rtree;		// 左 右子树
};

struct BINTREE_NODE* create_tree();


int main(){
    struct BINTREE_NODE* first=create_tree();
    return 0;
    
}

struct BINTREE_NODE* create_tree(){
    unsigned char flag;				//标指位
    struct BINTREE_NODE* tree;			//
    tree=(struct BINTREE_NODE *) malloc(sizeof(struct BINTREE_NODE)); //分配内存空间
    
    printf("please input the elem:");
    while((tree->elem =getchar()) =='\n');							//填充元素
    
    printf("Do you want to insert ltree[左子树] for %c (Y?N)?\n",tree->elem);		//询问是否要左子树
    while((flag =getchar()) =='\n');
    if(flag=='y' || flag =='Y')
        tree->ltree=create_tree();							//开辟空间
    else
        tree->ltree=NULL;									//填充NULL值
    
    printf("Do you want to insert rtree[右子树] for %c (Y?N)?\n",tree->elem); //询问是否要右子树
    while((flag =getchar()) =='\n');
    if(flag=='y' || flag =='Y')
        tree->rtree=create_tree();
    else
        tree->rtree=NULL;
    
    return tree;
        
    
    
    
}


