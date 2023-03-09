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

void ShowNode(NodeP Nodefirst){
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

void DeleteRepert(NodeP Nodefirst){

  int flag[100];                                            //100是节点数据域的取值范围 
  for(int i=0;i<100;i++) flag[i]=0;     //初始化数组全部为0；
  
  struct Node * move =Nodefirst;                            // 移动指针指向第一个
  struct Node * del = NULL;                                     //要删除的链表节点
  flag[move->item]=1;                                   //链表里面的第一个元素 一定没有出现过 直接把该标志为设置为1
  
  while(move->next !=NULL){                     //判断条件为 move 的下一个节点不为NULL
    if(flag[move->next->item] == 0){  //该数据域没有在数组里面出现过 取下标
       flag[move->next->item]=1;               //更新数组下标，改元素已经出现过了,这个要放在前面
        move=move->next;                                //这个要放在上一条语句的后面,要不然这条语句直接更新move，会出现下一条语句 下标标错误
    }else{                                                      //进入已经出现过的元素
      del = move->next;                             //标记要删除的节点
      move->next =del->next;                        //更新下一个while循环的判断条件，记住不是以P为条件,是p的下一个节点
      free(del);                                            //删除重复出现的元素 节点
      
    }
  }
  
}


ValueType FindLastElement(Node *NodeFirst,int pos){
    struct Node *first=NodeFirst;
    struct Node *find =NodeFirst;
    for(int i=0;i<pos;i++){
        first=first->next;
    }

    while(first !=NULL){
        first=first->next;
        find=find->next;
    }
    return find->item;
}














