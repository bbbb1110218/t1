#include "head.h"
#include <stdlib.h>


struct Node *head=NULL;
struct Node *tail=NULL;


void
MakeNode(ValueType vt){
	struct Node *p=(struct Node*)malloc(sizeof(struct Node));
	p->value=vt;

	if(head==NULL)
		head=p;
	else
		tail->next=p;
	tail=p;
}



void 
ShowNode(){

	struct Node *p=head;
	while(p !=NULL)
	{
		printf("%d ->",p->value);
		p=p->next;
	}
	printf("\n");

}


void InsertNode(int pos,ValueType vt){
	int n=0;
	struct Node *p=(struct Node*)malloc(sizeof(struct Node));
	struct Node *pre=NULL;
	p->value=vt;
	if(pos==0){
		p->next=head;
		head=p;
	}else if(pos > NodeCount()){
		printf("Warnning:  value %d append to the last\n",vt);
		p->next=NULL;
		tail->next=p;
		tail=p;
	}else{
		pre=head;
		for(n=0;n<pos-1;n++){
			pre=pre->next;
		}
		p->next=pre->next;
		pre->next=p;
	}


}

void DeleteNode(int pos){
	struct Node * pre=NULL;
	struct Node * del=NULL;
	int n=0;
	if(pos == 0){
		pre=head;
		head=head->next;
		free(pre);
	}else if(pos >= NodeCount()){
		printf("Invalid argument,Out of Range\n");
		return;
	}else{
		pre=head;
		for(n=0;n<pos-1;n++){
			pre=pre->next;
		}
		del=pre->next;
		pre->next=del->next;

		if(pre->next ==NULL){
			tail=pre;
		}

		free(del);



		// if(del->next==NULL){
		// 	tail=pre;
		// 	free(del);
		// 	pre->next=NULL;  //容易错的地方
		// }else{
		// 	pre->next=del->next;
		// 	free(del);

		// }

	}
}





int
NodeCount(){
	int n=0;
	struct Node *p=head;
	while(p !=NULL){
		p=p->next;
		n++;}
	return n;
}



void
FreeAllNode(){
	struct Node *p=head;
	struct Node * temp;
	int n=0;
	while(p !=NULL){
		temp=p;
		p=p->next;
		free(temp);
		n++;
	}

	printf("all data [%d] freedom\n",n);


}