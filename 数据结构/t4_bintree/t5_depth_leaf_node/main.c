#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>





int main(){
    struct BINTREE_NODE* mytree=create_tree();

    unsigned int deep=depth(mytree);

    printf("\nthe tree deep:%d",deep);
    printf("\nthe tree depth:%d",leafCount(mytree));
    printf("\nthe tree NodeCount:%d",NodeCount(mytree));

    return 0;
    
}

