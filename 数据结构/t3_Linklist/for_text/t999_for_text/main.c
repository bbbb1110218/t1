#include "mylinklist.h"
#include <stdio.h>

int main(){

	int a=10;

	Create_list(a++);
	Create_list(a++);
    Create_list(a++);
    Create_list(a++);

//    DeleteNode(1);
//    DeleteNode(1);
//    DeleteNode(0);
//	Create_list(a++);
//	Create_list(a++);
//	InsertNode(1,100);
//	Create_list(a++);
//	//DeleteNode(2);
//
//
//	printf("the node Count: %d\n",NodeCount());
	ShowLinkList();
//	if(FindNode(10)){
//		printf("find the elemente\n");
//	}else
//		printf("Can not find the elemente\n");

	//FreeLinkList();
	return 0;
}