#include "linklist.h"
#include <stdlib.h>  //包含 malloc()



struct node * head=NULL;

struct node * tail=NULL;


void create_list(ValueType c){
	struct node *p	=(struct node *)malloc(sizeof(struct node));//malloc 函数返回 void * 指针 需要 转换一下类型
	p->elem =c;
	p->pre =NULL;	//前驱点也初始化
	p->next =NULL;	//后去点

	if(head ==NULL)
		head=p;			//头节点永远指向第一个节点  //前驱 后驱点都是null
	else{
		tail->next=p;
		p->pre=tail;			//新加入的节点的前驱点等于上一个tail
	}

	tail=p;		//更新更新尾巴节点
}


void insert_node(int pos,ValueType elem1 ){  //需要考虑插入头节点
	//插入
	struct node *prew;
	prew=head;
	int i=0;

	struct node*p=(struct node *)malloc(sizeof(struct node)); //开辟的新空间
			//新空间存上值

	if(pos ==0){			//考虑头节点的情况下
		head->pre=p;		//老head前驱动点等于 新节点

		p->elem =elem1;		//赋值给新的节点
		p->next=head;		//新节点的下一个等于老head
		p->pre=NULL;		//新节点的前驱点等于NULL

		head=p;				//更新head


	}
	else{
		while(i < pos -1){
			prew=prew->next;
			i++;
		} 

		p->elem=elem1;	//填数据
		p->pre =prew ;	//  填新节点的前驱点
		p->next=prew->next;	//填新节点的后驱点

		prew->next=p;	//更新上一个节点的后驱点				
 
		if(p->next==NULL)		//p->next 为前驱点赋值的，如果为null 说明 prew是之前最后一个节点	
			tail=p;				//需要更新一个最后一个节点是新加入的节点
		else						//不为空的话说明，之前的节点不是最后一节点
			p->next->pre =p;		//要给后面的节点添加前驱点
									//p->next 是后面的节点  p->next->pre是最后节点的前驱点
	}

}



void delete_node(int pos){		//删除节点也需要照出前区点,用钱去点的next 指向 找出NOde节点的下一个节点 free掉找出来的节点
	struct node *prew;
	struct node *p ;			//要删除的位置
	prew=head;

	int i=0;

	if(pos==0){					//考虑要删除的节点为头节点
		head=head->next;		//头节点指向下一个
		head->pre=NULL;			//新头节点的前驱点等于NULL 
		free(prew);

	}else{
			while(i < pos -1){
				prew=prew->next;
				i++;
			}
							//代码写到这里了
			p=prew->next;			// p 为要删除的节点 

			prew->next=p->next;			//前驱点的next 等于 要删除节点的next;
			
			if(p->next==NULL)			//考虑删除的节点是最后一个节点，更新tail 指针的位置
				tail=prew;				//更新全局的尾节点
			else
				prew->next->pre=prew;	//更新后驱点里面的前驱点

			free(p);				//释放 要删除节点的内存空间，从内存中抹掉

	}

}


void print_linklist(void){		//打印所有元素
	struct node* p=head;

	while(p !=NULL){
		printf("%d ->",p->elem);
		p=p->next;
	}
	printf("\n");
}

void print_linklist_reseved(void){  //倒叙打印
	struct node* p=tail;		//初始节点等于最后一个节点

	while(p !=NULL){
		printf("%d ->",p->elem);
		p=p->pre;
	}
	printf("\n");

}


int search(ValueType find){		//找节点
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

void recursion_print(struct node* Nodefirst){
    if(Nodefirst->next !=NULL){
        recursion_print(Nodefirst->next);
    }
    printf("%d ->\n",Nodefirst->elem);
}


