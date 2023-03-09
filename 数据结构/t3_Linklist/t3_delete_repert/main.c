#include <stdlib.h>
#include "myhead.h"

int flag[10];


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
    DeleteRepert(head);
    ShowNode(head);


   return 0;

}