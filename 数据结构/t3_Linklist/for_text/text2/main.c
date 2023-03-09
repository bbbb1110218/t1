#include <stdlib.h>
#include "myhead.h"

/*
    删除节点里面的重复元素

*/

int main(){
    NodeAdd(1);
    NodeAdd(2);
    NodeAdd(1);
    NodeAdd(3);
    NodeAdd(4);
    NodeAdd(25);
    NodeAdd(3);
    NodeAdd(4);
    NodeAdd(5);

    
    ShowNode(head);
    DeleteRepert(head); //重点为该函数
    ShowNode(head);




   return 0;

}