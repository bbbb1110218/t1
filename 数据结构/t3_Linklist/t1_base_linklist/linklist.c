#include "linklist.h"
#include <stdlib.h>  //包含 malloc()



struct node * head=NULL;

struct node * tail=NULL;


void create_list(unsigned char c){
	struct node *p	=(struct node *)malloc(sizeof(struct node));//malloc 函数返回 void * 指针 需要 转换一下类型
	p->elem =c;
	p->next =NULL;

	if(head ==NULL)
		head=p;			//头节点永远指向第一个节点
	else 
		tail->next=p;
	tail=p;		//当头节点为空的时候，tail也等于p节点
				//否则tail等于 tail->next  也就是NULL
}


void insert_node(int pos,unsigned char elem1 ){  //需要考虑插入头节点
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


	}
	else{
		while(i < pos -1){
			pre=pre->next;
			i++;
		}
		p->elem=elem1;	
		p->next=pre->next;			// new->node = pre->next;
		pre->next=p;					//pre->next= new ->node

		if(p->next==NULL)				//考虑插入的节点在最后 更新尾指针
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

	}else{
			while(i < pos -1){
			pre=pre->next;
			i++;
			}

			p=pre->next;			// p 为要删除的节点 

			pre->next=p->next;			//前驱点的next 等于 要删除节点的next;
			
			if(p->next==NULL)			//考虑删除的节点是最后一个节点，更新tail 指针的位置
				tail=pre;

			free(p);				//释放 要删除节点的内存空间，从内存中抹掉

	}

}


void print_linklist(void){		//打印所有元素
	struct node* p=head;

	while(p !=NULL){
		printf("%c ->",p->elem);
		p=p->next;
	}
	printf("\n");
}


int search(unsigned char find){		//找节点
	struct node * p =head;
	while(p !=NULL){
		if(p->elem ==find)
			return 1;
		p=p->next;
	}
	return 0;
}

void free_link_list(){			//free 所有节点
	struct node *pre=head;
	struct node *del;
	while(pre !=NULL){
		del=pre;
		pre=pre->next;
		free(del);
	} 
	printf("All node delete\n");

}


