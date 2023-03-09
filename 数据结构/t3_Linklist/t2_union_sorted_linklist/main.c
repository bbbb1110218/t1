#include <stdio.h>
#include "head.h"


/*
使用head 要引入外部变量
extern struct Node * head;


两个有序列表

list1 =[1,4,6,7]
list2 =[2,5,8,11,12]

list3 =[1,2,4,5,6,7,8,11,12]; 

list3 不是新分配的空间 
list3=NULL;
用 p 指向 list1的首个元素
用 q 指向 list2的首个元素

当list3 为空的时候
list3先指向 p 或者 q 结构体中 value 值比较小的
tail = list3;

然后一次比较 p.value 和 q.value;
如果 p.value 小 tail 的指针域 指向p   tail =p 更新p p=p->next
如果 q.value 小 tail 的指针域 指向q   tail =q 更新q q=q->next

p 或者q 总有一个先为NULL


tail 指向不为NULL的



*/


int main(){

	struct Node *head1=NULL;
	struct Node *head2=NULL;

	struct Node *p=NULL;
	struct Node *q =NULL;
	

	MakeNode(1);		//全部加入外部节点head
	MakeNode(9);
	MakeNode(13);
	MakeNode(27);
	head1=head;			//让head1 指向head 
	ShowNode(head1);

	head=NULL;			//head 指向空

	MakeNode(3);		//节点重写加入head
	MakeNode(5);
	MakeNode(15);
	MakeNode(81);
	MakeNode(88);
	MakeNode(95);
	MakeNode(99);
	head2=head;				//head2 指向head 
	ShowNode(head2);

	head=NULL;				// head 再次为空
	p=head1;				// 临时节点p 指向 head1
	q=head2;				// 临时节点q 指向 head2


	while(p !=NULL && q !=NULL){		//条件 p 或者 q 为空的时候，停止循环
		if(p->value <=q->value){			//如果p 节点里面的数据域比较小
			if(head==NULL)
				head=p;						//先让head 指向一个比较小的
			else
				tail->next=p;				// 外部节点 tail的指针域 指向 数据域比较小的p
			tail=p;							// 更新 tail 
			p=p->next;						//	更新 p节点  更新比较小的节点
		}else{
			if(head==NULL)
				head=p;
			else
				tail->next=q;
			tail=q;
			q=q->next;
		}

	}								//两个节点总有一个会先被完
									//tail ->next 会 指向空
									// 用tail->next 重写指向不为空的节点

	tail->next= p ? p : q;  		// 等效于下面 巧妙

	// if(p==NULL)
	// 	tail->next=q;
	// if(q==NULL)
	// 	tail->next=p;



	ShowNode(head);
	ShowNode(head1);
	ShowNode(head2);









	return 0;
}