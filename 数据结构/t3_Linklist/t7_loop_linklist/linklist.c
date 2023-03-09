#include "linklist.h"
#include <stdlib.h>  //包含 malloc()



struct node * head=NULL;

struct node * tail=NULL;


void create_list(int c){
	struct node *p	=(struct node *)malloc(sizeof(struct node));
	p->elem =c;
	p->next =NULL;

	if(head ==NULL)
		head=p;			
	else 
		tail->next=p;
	tail=p;
	tail->next=head;	//尾部的节点不再指向null 而是指向链表头	
}


void insert_node(int pos,int elem1 ){  //需要考虑插入头节点
	//插入
	struct node *pre;
	pre=head;
	int i=0;

	struct node*p=(struct node *)malloc(sizeof(struct node)); //开辟的新空间
			//新空间存上值

	if(pos ==0){		//考虑头节点的情况下
		p->elem =elem1;
		p->next=head;
		head=p;
		tail->next=head;


	}
	else{
		while(i < pos -1){
			pre=pre->next;
			i++;
		}
		p->elem=elem1;	
		p->next=pre->next;			
		pre->next=p;					

		if(p->next==head)  //尾指针 指向 头 说明p是尾节点 需要更新tail的位置				
			tail=p;

	}

}



void delete_node(int pos){		//删除节点也需要照出前区点,用钱去点的next 指向 找出NOde节点的下一个节点 free掉找出来的节点
	struct node *pre;
	struct node *p ;			//要删除的位置
	pre=head;

	int i=0;

	if(pos==0){					//考虑要删除的节点为头节点
		head=head->next;
		free(pre);
		tail->next=head;		//更新尾节点

	}else{
			while(i < pos -1){
			pre=pre->next;
			i++;
			}

			p=pre->next;			// p 为要删除的节点 

			pre->next=p->next;			//前驱点的next 等于 要删除节点的next;
			
			if(p->next==head)			//考虑删除的节点是最后一个节点，更新tail 指针的位置
				tail=pre;

			free(p);				//释放 要删除节点的内存空间，从内存中抹掉

	}

}


void print_linklist(void){		//打印所有元素
	struct node* p=head;

	do{							//do while 循环
		printf("%d ->",p->elem);
		p=p->next;
	}while(p !=head);
	printf("\n");
}


int search(int find){			//找节点
	struct node * p =head;

	do{							//do while 循环
		if(p->elem ==find)
			return 1;
		p=p->next;

	}while(p !=head);
	return 0;
}



