
#include "linklist.h"
#include <stdio.h>


int main(){
    
   int a=1;
   while(a !=9){
        create_list(a);
        a++;
   }

    print_linklist();
    insert_node(0,a++);
    print_linklist();
    insert_node(9,a++);
    print_linklist();
    delete_node(6);
    print_linklist();
    delete_node(0);
    print_linklist();
    delete_node(7);
    print_linklist();


    return 0;
}