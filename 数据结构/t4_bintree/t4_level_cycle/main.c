#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>





int main(){
    struct BINTREE_NODE* mytree=create_tree();
    
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

