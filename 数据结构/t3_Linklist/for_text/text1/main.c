#include <stdlib.h>
#include "myhead.h"


int main(){

    NodeP first;
    NodeP second;
    NodeP n1=NULL;
    NodeP n2=NULL;

    NodeAdd(32);
    NodeAdd(68);
    NodeAdd(77);


    first=head;
    head=NULL;

    NodeAdd(14);
    NodeAdd(56);
    NodeAdd(99);
   // NodeAdd(37);

    second=head;
    head=NULL;


    //showNode(first);
   // showNode(second);

    n1=first;
    n2=second;

    //tail=NULL;

    while(n1 && n2){

        if(n1->item <=n2->item){
            if(head==NULL)
                head=n1;
            else
                tail->next=n1;
            tail=n1;
            n1=n1->next;
        }else{
            if(head==NULL)
                head=n2;
            else
                tail->next=n2;
            tail=n2;
            n2=n2->next;
        }


    }

    tail->next=n1?n1:n2;
    //showNode(second);


    showNode(head);
    FreeALLNode(head);





   return 0;

}