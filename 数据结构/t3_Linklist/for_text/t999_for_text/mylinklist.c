#include "mylinklist.h"
#include <stdlib.h>

struct Node *head=NULL;
struct Node *tail=NULL;


void Create_list(MYTYPE myt){

	struct Node* p=(struct Node *)malloc(sizeof(struct Node));
	p->item=myt;
	p->next=NULL;

	if(head ==NULL)
		head=p;
	else
		tail->next=p;
	tail=p;


}

void InsertNode(int index,MYTYPE myt){
	struct Node *pre=head;
	int n;


	struct Node *p=(struct Node *)malloc(sizeof(struct Node));
	p->item=myt;

	if(index ==0 ){
		p->next=head;
		head=p;

	}else if(index >= NodeCount()){  //超出索引
		p->next=NULL;
		tail->next=p;
		tail=p;
	}else{

		for(n=0;n<index-1;n++){
				pre=pre->next;

		}
		p->next=pre->next;
		pre->next=p;

		if(p->next ==NULL)
			tail=p;

	}

}


void ShowLinkList(){ //打印所有节点
	struct Node * temp=head;
	while(temp !=NULL){
		printf("%d ->", temp->item);
		temp=temp->next;
	}
		
	
	printf("\n");
}

void FreeLinkList(){		//释放所有节点
	struct Node * temp;
	while(head !=NULL){
		temp=head;
		head=head->next;
		free(temp);
	}
		
	
	printf("Delete Link List Done\n");

}

int NodeCount(){		//返回有多少个节点
    struct Node* temp=head;
    int n=0;
    while(temp !=NULL){
        n++;
        temp=temp->next;
    }

//	if(tail ==NULL)
//		return 0;
//	else
//		return tail-head +1;
    return n;
}

void DeleteNode(int index){
	struct Node* pre=NULL;
	struct Node *temp=NULL;
	int n=0;
	if(index > NodeCount()-1){
		printf("Out of Range\n");
	}else if(index == 0){
		temp=head;
		head=head->next;
		free(temp);
        return;

	}else{
		pre=head;
		for(n=0;n<index-1;n++)
			pre=pre->next;
		temp=pre->next;
		if(temp->next == NULL){
            tail=pre;
            pre->next=NULL;
            free(temp);
        }

		else{
			pre->next=temp->next;
            free(temp);
		}


	}

	
}

int FindNode(MYTYPE myt){
	
	struct Node *p=head;
	while(p !=NULL){
		if(p->item ==myt)
			return 1;

		p= p->next;
	}
	return 0;
}
