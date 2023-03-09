#include <stdio.h>
#include "head.h"


int main(){
	int a=6;
	MakeNode(a++);
	MakeNode(a++);
	MakeNode(a++);
	MakeNode(a++);
	InsertNode(4,50);
	printf("Count:%d\n",NodeCount());
	ShowNode();
	//DeleteNode(8);
	DeleteNode(4);
	ShowNode();
	printf("Count:%d\n",NodeCount());
	FreeAllNode();

	return 0;
}