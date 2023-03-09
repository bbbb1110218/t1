#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdio.h>



struct BINTREE_NODE{
    unsigned char elem;                        //属于元素
    struct BINTREE_NODE *ltree,*rtree;        // 左 右子树
};

struct BINTREE_NODE* create_tree();
void pre_order(struct BINTREE_NODE * tree);
void mid_order(struct BINTREE_NODE * tree);
void pos_order(struct BINTREE_NODE * tree);


#endif