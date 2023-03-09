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

    int a=FindLastElement(1);
    printf("the last n element is %d\n",a );

   return 0;

}