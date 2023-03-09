#include "linklist.h"
#include <stdio.h>


int main(){
    
    unsigned char temp='a';
    for(int a=10;a;a--)
        create_list(temp++);


    print_linklist();
    insert_node(0,'z');
    print_linklist();

    free_link_list();
	return 0;
}