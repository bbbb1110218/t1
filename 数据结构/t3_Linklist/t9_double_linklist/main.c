#include "linklist.h"
#include <stdio.h>


int main(){ 
	struct node *temp;
	create_list(1);
	create_list(2);
	create_list(3);
	create_list(4);
	create_list(5);
	temp=head;
	recursion_print(temp);
	
	//print_linklist_reseved();
	// print_linklist();
	// insert_node(2,444);
	// print_linklist();
	// insert_node(3,1444);
	// print_linklist();
	// insert_node(0,1444);
	// print_linklist();
	// print_linklist_reseved();


    

	return 0;
}