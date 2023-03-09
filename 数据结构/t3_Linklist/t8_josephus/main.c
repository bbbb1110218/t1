#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
   struct node *p,*q;   
    int n,k,m;
    int i;

    printf("please enter the number of the person:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        create_list(i);
    }


    printf("Please enter the start number:");

    scanf("%d",&k);
    p=head;

    for(i=0;i<k-1;i++){
         p=p->next;
    }

  

   printf("please enter the m:");
   scanf("%d",&m);

   
   if(m==1){
            for(int i=0;i<n;i++){
               printf("move Element:%d\n",p->elem);
               p=p->next;
            }

    }else{
         while(n--)
         {
            for(i=0;i<m-1;i++){
               p = p->next;}
            q=p->next;
            printf("move Element:%d\n",q->elem);
            p->next=q->next;
            free(q);


         }


    }
   printf("\n");

   return 0;
}

