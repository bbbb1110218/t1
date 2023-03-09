#include "myhead.h"
#include <stdlib.h>


NodeP head=NULL;
NodeP tail=NULL;


void NodeAdd(ValueType nv){
    NodeP p=(NodeP) malloc(sizeof(struct Node));
    p->item=nv;
    p->next=NULL;
    if(head==NULL)
        head=p;
    else
        tail->next=p;
    tail=p;
}

unsigned int NodeCount(NodeP Nodefirst){
    int n=0;
    NodeP p=head;
    while(p){
        n++;
        p=p->next;
    }
    return n;
}

void InsertNode(int pos,ValueType nv){
    NodeP p=(NodeP)malloc(sizeof(struct Node));
    NodeP prev;
    //int n=0;
    p->item=nv;
    if(pos ==0){
        p->next=head;
        head=p;
    }else if(pos > NodeCount(head)){
        printf("Out of range\n");

    }else{
        prev=head;
        for(int i=0;i<pos-1;i++)
            prev=prev->next;
        p->next=prev->next;
        if(p->next ==NULL)
            tail=p;
        prev->next=p;

    }

}

void deleteNode(int pos){

    NodeP p=head;
    NodeP current;
    if(pos==0){
        head= head->next;
        free(p);
    }else if(pos >= NodeCount(head)){
        printf("Out of range\n");
    }else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        current=p->next;
        p->next=current->next;
        if(current->next==NULL){
            tail=p;
        }
        free(current);




    }

}

void showNode(NodeP Nodefirst){
    NodeP p=Nodefirst;
    while(p)
    {
        printf("%d -> ",p->item );
        p=p->next;
    }

    printf("\n");

}


void FreeALLNode(NodeP Nodefirst){
    NodeP temp=NULL;
    while(Nodefirst){
        temp=Nodefirst;
        Nodefirst =Nodefirst->next;
        free(temp);

    }
    printf("恭喜，闵睿全部答对\n");
}

