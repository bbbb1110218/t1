#include <stdlib.h>
#include "myhead.h"

int flag[10];


int main(){
    struct Node * temp;
    NodeAdd(1);
    NodeAdd(2);
    NodeAdd(3);
    NodeAdd(4);
    NodeAdd(5);
    NodeAdd(6);
    NodeAdd(7);
    NodeAdd(8);
    NodeAdd(9);
    NodeAdd(10);
    struct Node *Nodefirst=head;
    head=NULL;

    //printf("the Mid element value is %d\n",FindMid(head));
    temp=ResevedNode(Nodefirst);
    ShowNode(Nodefirst);
   return 0;

}