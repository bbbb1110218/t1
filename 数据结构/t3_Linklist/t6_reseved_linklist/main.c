#include <stdlib.h>
#include "myhead.h"


void ShowNode(NodeP Nodefirst);

int main(){
    struct Node* NodeFirst;
    struct Node *p,*n;  //定义两根指针
    int a=77;
    int Count=30;
    while(Count--)
        NodeAdd(a++);
    NodeFirst=head;
    head=NULL;

    ResevedNode(NodeFirst);
    ShowNode(NodeFirst);

    // p=NodeFirst->next;  //初始化前驱动   指向当前节点的下一个节点
    // n=NULL;                 //结构里面的next


    // while(p->next !=NULL){      //前驱指针结构里面的next为NULL的时候，为链表的最后一个节点
    //     NodeFirst->next=n;      //当前节点的next 指向上一个节点的地址，循环的第一次的时候应该等于NULL
    //     n=NodeFirst;            //当前节点的地址 保存一下，给下一个节点的next里面
    //     NodeFirst=p;            //移动当前的指针 指向下一个
    //     p=NodeFirst->next;      //移动前去节点 指向下一个    
    // }

    // NodeFirst=p;          //NodeFirst 为倒数第二个节点，p为倒数第一个
    //                         //让NodeFirst为最后一个节点
    // NodeFirst->next=n;     //NodeFirst的节点指向上一个节点

    // while(NodeFirst !=NULL){
    //     printf("[%d] ->",NodeFirst->item);
    //     NodeFirst =NodeFirst->next;
    // }
   
   return 0;

}

void ShowNode(NodeP Nodefirst){
    NodeP p=Nodefirst;
    while(p)
    {
        printf("%d -> ",p->item );
        p=p->next;
    }

    printf("\n");

}