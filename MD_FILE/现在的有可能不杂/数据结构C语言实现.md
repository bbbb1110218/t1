# 数据结构C语言实现

## 栈

### 初始化

>```c
>#include <stdio.h>
>
>char stack[512];
>int top=0;
>
>void push(char c);
>char pop();
>int isEmpty();
>
>int main(){
>    push('a');
>    push('b');
>    push('c');
>
>    while(!isEmpty()){
>        putchar(pop());
>    }
>    putchar('\n');
>
>    return 0;
>}
>
>
>
>void push(char c){
>    stack[top++]=c;
>
>}
>
>char pop(){
>    return stack[--top];
>}
>
>int isEmpty(){
>    return top==0;
>}
>```
>


### 栈 匹配括号
>
>```c
>#include <stdio.h>
>#include <string.h>
>
>
>char stack[512];
>int top=0;
>
>
>void push(int c);
>int pop();
>int isEmpty();
>
>int main(){
>    char str[100];
>    int len;
>    printf("Please enter your expression|输入表达式");
>    fgets(str,100,stdin);
>    len=strlen(str);
>
>    for(int i=0;i<len;i++){
>        if(str[i]=='(')
>            push(i);
>        else if(str[i] == ')')
>            printf("%d %d\n",pop(),i);
>    }
>
>
>    return 0;
>}
>
>
>
>void push(int c){
>    stack[top++]=c;
>
>}
>
>int pop(){
>    return stack[--top];
>}
>
>int isEmpty(){
>    return top==0;
>}
>```
>
>

### 栈 十进制转二进制

>
>
>```c
>
>/*
>十进制转二进制
>余数全部入栈
>最后全部出栈 高位排在前面
>*/
>
>#include <stdio.h>
>
>
>int stack[512];
>int top=0;
>
>
>void push(int c);
>int pop();
>int isEmpty();
>
>int main(){
>    int num;
>    printf("please enter an interager in decimal:");
>    scanf("%d",&num);
>
>    while(num){
>        push(num % 2);
>        num /=2;
>    }
>    while(!isEmpty()){
>        printf("%d",pop());
>    }
>    printf("\n");
>
>
>    return 0;
>}
>
>
>
>void push(int c){
>    stack[top++]=c;
>
>}
>
>int pop(){
>    return stack[--top];
>}
>
>int isEmpty(){
>    return top==0;
>}
>```
>
>

### 栈 回文

>Abcdcba
>
>```c
>//
>// Created by macbookpro on 2023/2/10.
>//
>#include <stdio.h>
>#include <string.h>
>
>
>char stack[512];
>int top=0;
>
>
>void push(char c);
>char pop();
>int isEmpty();
>
>int is_palindrom(char *str);
>
>int main(){
>    char str[100];
>    printf("Please enter string:");
>    gets(str);
>
>    if(is_palindrom(str))
>        printf("Is an is_palindrom|是回文\n");
>    else
>        printf("is not a palindrom｜不是回文\n");
>
>    return 0;
>}
>
>
>void push(char c){
>    stack[top++]=c;
>
>}
>
>char pop(){
>    return stack[--top];
>}
>
>int isEmpty(){
>    return top==0;
>}
>
>int is_palindrom(char *str){
>    int len=strlen(str);
>    int i;
>    for(i=0;i<len/2;i++){
>        push(str[i]);
>    }
>    
>    if(len % 2 ==1)
>        i++;
>
>    while(!isEmpty()){
>        char temp=pop();
>        if(str[i++] !=temp)
>            return 0;
>    }
>    return 1;
>}
>```
>
>





## 队列 

>先进先出 first in first out
>
>**顺序队列**：在内存中是是连续的
>
>**链条队列**：用指针
>
>队列头，队列尾 ｜
>
>```
>一个数组里面有10个元素 ,队列头和队列尾都指向第一个元素，入队列 tail +1 出队列head+1  
>当head ==10的时候，这个时候出现假溢出,这个时候尾队列重写指向队列第0个元素，只要不和头队列相等 就可以了
>这样更节约内存空间
>相当于把一个线性空间 整成圆形了
>```
>
>为了避免假溢出，一般使用循环队列
>
>一个不大于MAX的数 与 MAX 取余运算，结果仍然等于该数本身
>
>

### 顺序队列

>
>
>```c
>#include <stdio.h>
>
>char Queue[512];
>int head=0; 
>int tail=0;
>
>void enqueue(char c);
>char dequeue();
>int isEmpty();
>int isFull();
>
>int main(){
>
>}
>
>void enqueue(char c){
>	Queue[tail++]=c;
>}
>
>char dequeue(){
>	return Queue[head++];
>}
>
>int isEmpty(){
>	return head==tail;
>}
>
>int isFull(){
>	if(tail+1 == head)
>		return 1;
>	else 
>		return 0;
>}
>
>```
>
>

### 循环队列

>**一个不大于MAX的数 与 MAX 取余运算，结果仍然等于该数本身**
>
>```c
>#include <stdio.h>
>
>const int MAX=5;
>char Queue[MAX];
>int head=0; 
>int tail=0;
>
>void enqueue(char c);
>char dequeue();
>int isEmpty();
>int isFull();
>
>
>int main(){
>	char c='A';
>	int i;
>	for(int i=0;i<3;i++){
>		if(!isFull()){			//判断条件放在外面
>			enqueue(c);
>			c++;
>		}
>	}
>
>	printf("-----out\n");
>	while(!isEmpty()){			//判断条件放在外面
>		putchar(dequeue());
>	}
>
>	return 0;
>}
>
>void enqueue(char c){		//判断条件放在外面
>	Queue[tail]=c;			//先操作队列的值 再更新索引
>	tail = (tail +1) % MAX;  //从后面进去
>}
>
>char dequeue(){
>	char ch;
>	ch=Queue[head];				//先更新值 再更新索引
>	head=(head+1) % MAX;
>	return ch;
>}
>
>
>int isEmpty(){
>	return head==tail;
>}
>
>
>int isFull(){
>	return (tail+1) % MAX == head;
>}
>
>```
>
>

### 队列解码

>
>
>从一个队列取出一个值，再取一个值放到队列的后面,循环 取 ，知道队列为空
>
>```c++
>#include <stdio.h>
>#include <string.h>
>
>const int MAX=200;
>char Queue[MAX];
>int head=0; 
>int tail=0;
>
>void enqueue(char c);
>char dequeue();
>int isEmpty();
>int isFull();
>
>
>int main(){
>	char code[MAX+1];
>	int n;
>	int index=0;
>	char num;
>	printf("Please enter a code:");
>	gets(code);
>	for(n=0;n<strlen(code);n++){
>		if(!isFull())
>			enqueue(code[n]);
>		else
>			printf("Queue is full ,charator [%c] not enqueu",code[n]);
>	}
>
>	while(!isEmpty()){
>		code[index++]=dequeue();  //存入到一个数组里面
>		if(!isEmpty()){ 
>			num=dequeue();
>			if(!isFull()){
>				enqueue(num);
>			}
>		}
>	}
>	code[index]='\0';
>	printf("%s\n",code);
>
>	return 0;
>}
>
>void enqueue(char c){		//判断条件放在外面
>	Queue[tail]=c;			//先操作队列的值 再更新索引
>	tail = (tail +1) % MAX;  //从后面进去
>}
>
>char dequeue(){
>	char ch;
>	ch=Queue[head];				//先更新值 再更新索引
>	head=(head+1) % MAX;
>	return ch;
>}
>
>
>int isEmpty(){
>	return head==tail;
>}
>
> 
>int isFull(){
>	return (tail+1) % MAX == head;
>}
>
>```
>
>

### 双端循环队列

>
>
>双端循环队列是一种head 和 tail都可以进出队列的表现形式 形成一个圆环
>
>
>
>```c
>size 为队列长度
>双端队列
>head端 入队列
>			head = (head - 1 + size ) % size;
>				queue[head]=value;
>head端 出队列
>			value=queue[head];
>				head = (head+1) % size;
>tail端 进队列 
>		tail=(tail - 1 + size) % size;
>				value=quque[tail];
>tail端	出队列
>		queue[tail]=c;
>				tail=(tail +1) % size
>队列是否为空
>   head == tail
>队列是否为满
>  	tail=(tail +1)% size;
>
>
>```
>
>



## 链表

>栈 和队列在内存中都是连续的
>**链表在内存中不是 连续存储的**
>
>节点里面有数据和指针，指针指向下个节点，不支持随机访问
>
>需要有首位 和 tail 位置
>
>高效的排列，插入数据
>
>#### 链表基本操作
>
>```c
>创建链表
>创建节点（分配内存，填充数据域和指针域（null））
>节点连接在一起
>
>```
>
>



### 基本链表


>#### 链表头文件
>
>```c
>#ifndef __LINKLIST_H__
>#define __LINKLIST_H__
>
>#include<stdio.h>
>
>
>struct node{
>	unsigned char elem;
>	struct node *next;
>};
>
>void create_list(unsigned char c);
>void insert_node(int pos,unsigned char elem1 );
>void delete_node(int pos);
>void print_linklist(void);
>int search(unsigned char find);
>
>#endif
>
>```
>
>#### 链表实现文件
>
>```c
>#include "linklist.h"
>#include <stdlib.h>  //包含 malloc()
>
>
>
>struct node * head=NULL;
>
>struct node * tail=NULL;
>
>
>void create_list(unsigned char c){
>	struct node *p	=(struct node *)malloc(sizeof(struct node));//malloc 函数返回 void * 指针 需要 转换一下类型
>	p->elem =c;
>	p->next =NULL;
>
>	if(head ==NULL)
>		head=p;			//头节点永远指向第一个节点
>	else 
>		tail->next=p;
>	tail=p;		//当头节点为空的时候，tail也等于p节点
>				//否则tail等于 tail->next  也就是NULL
>}
>
>
>void insert_node(int pos,unsigned char elem1 ){  //需要考虑插入头节点
>	//插入
>	struct node *pre;
>	pre=head;
>	int i=0;
>
>	struct node*p=(struct node *)malloc(sizeof(struct node)); //开辟的新空间
>			//新空间存上值
>
>	if(pos ==0){		//考虑头节点的情况下
>		p->elem =elem1;
>		p->next=head;
>		head=p;
>
>
>	}
>	else{
>		while(i < pos -1){
>			pre=pre->next;
>			i++;
>		}
>		p->elem=elem1;	
>		p->next=pre->next;			// new->node = pre->next;
>		pre->next=p;					//pre->next= new ->node
>
>		if(p->next==NULL)				//考虑插入的节点在最后 更新尾指针
>			tail=p;
>
>	}
>
>}
>
>
>//函数有个DEbug pos 应该在节点个数之内
>void delete_node(int pos){		//删除节点也需要照出前区点,用钱去点的next 指向 找出NOde节点的下一个节点 free掉找出来的节点
>	struct node *pre;
>	struct node *p ;			//要删除的位置
>	pre=head;
>
>	int i=0;
>
>	if(pos==0){					//考虑要删除的节点为头节点
>		head=head->next;
>		free(pre);
>
>	}else{
>			while(i < pos -1){
>			pre=pre->next;
>			i++;
>			}
>			p=pre->next;			// p 为要删除的节点 
>			pre->next=p->next;			//前驱点的next 等于 要删除节点的next;
>			if(p->next==NULL)			//考虑删除的节点是最后一个节点，更新tail 指针的位置
>				tail=pre;
>			free(p);				//释放 要删除节点的内存空间，从内存中抹掉
>	}
>}
>
>
>void print_linklist(void){		//打印所有元素
>	struct node* p=head;
>
>	while(p !=NULL){
>		printf("%c ->",p->elem);
>		p=p->next;
>	}
>	printf("\n");
>}
>
>
>int search(unsigned char find){		//找节点
>	struct node * p =head;
>	while(p !=NULL){
>		if(p->elem ==find)
>			return 1;
>		p=p->next;
>	}
>	return 0;
>}
>
>void free_link_list(){			//free 所有节点
>	struct node *pre=head;
>	struct node *del;
>	while(pre !=NULL){
>		del=pre;
>		pre=pre->next;
>		free(del);
>	} 
>	printf("All node delete\n");
>
>}
>
>```
>
>#### Main 入口
>
>```c
>#include "linklist.h"
>#include <stdio.h>
>
>int main(){
>unsigned char temp='a';
>for(int a=10;a;a--)
>create_list(temp++);
>print_linklist();
>insert_node(0,'z');
>print_linklist();
>free_link_list();
>	return 0;
>}
>```
>   
>

### 合并两个已经排序链表

>**两个已经排序好的链表，不在分配新的内存空间对他们进行排序**
>
>**而是 新的链表 先指向他们中数据与中最小,通过只修改他们中的指针域 指向下一个两个链表中比较小的节点**
>
> 
>
> 
>
>#### main入口
>
>```c
>#include <stdio.h>
>#include "head.h"
>
>
>/*
>使用head 要引入外部变量
>extern struct Node * head;
>
>
>两个有序列表
>
>list1 =[1,4,6,7]
>list2 =[2,5,8,11,12]
>
>list3 =[1,2,4,5,6,7,8,11,12]; 
>
>list3 不是新分配的空间 
>list3=NULL;
>用 p 指向 list1的首个元素
>用 q 指向 list2的首个元素
>
>当list3 为空的时候
>list3先指向 p 或者 q 结构体中 value 值比较小的
>tail = list3;
>
>然后一次比较 p.value 和 q.value;
>如果 p.value 小 tail 的指针域 指向p   tail =p 更新p p=p->next
>如果 q.value 小 tail 的指针域 指向q   tail =q 更新q q=q->next
>
>p 或者q 总有一个先为NULL
>
>
>tail 指向不为NULL的
>
>
>
>*/
>
>
>int main(){
>
>	struct Node *head1=NULL;
>	struct Node *head2=NULL;
>
>	struct Node *p=NULL;
>	struct Node *q =NULL;
>	
>
>	MakeNode(1);		//全部加入外部节点head
>	MakeNode(9);
>	MakeNode(13);
>	MakeNode(27);
>	head1=head;			//让head1 指向head 
>	ShowNode(head1);
>
>	head=NULL;			//head 指向空
>
>	MakeNode(3);		//节点重写加入head
>	MakeNode(5);
>	MakeNode(15);
>	MakeNode(81);
>	MakeNode(88);
>	MakeNode(95);
>	MakeNode(99);
>	head2=head;				//head2 指向head 
>	ShowNode(head2);
>
>	head=NULL;				// head 再次为空
>	p=head1;				// 临时节点p 指向 head1
>	q=head2;				// 临时节点q 指向 head2
>
>
>	while(p !=NULL && q !=NULL){		//条件 p 或者 q 为空的时候，停止循环
>		if(p->value <=q->value){			//如果p 节点里面的数据域比较小
>			if(head==NULL)
>				head=p;						//先让head 指向一个比较小的
>			else
>				tail->next=p;				// 外部节点 tail的指针域 指向 数据域比较小的p
>			tail=p;							// 更新 tail 
>			p=p->next;						//	更新 p节点  更新比较小的节点
>		}else{
>			if(head==NULL)
>				head=p;
>			else
>				tail->next=q;
>			tail=q;
>			q=q->next;
>		}
>
>	}								//两个节点总有一个会先被完
>									//tail ->next 会 指向空
>									// 用tail->next 重写指向不为空的节点
>
>	tail->next= p ? p : q;  		// 等效于下面 巧妙
>
>	// if(p==NULL)
>	// 	tail->next=q;
>	// if(q==NULL)
>	// 	tail->next=p;
>
>
>
>	ShowNode(head);
>	ShowNode(head1);
>	ShowNode(head2);
>
>
>
>
>	return 0;
>}
>```
>
>
>
>#### myhead.h
>
>```c
>#ifndef __MYHEAD_C__
>#define __MYHEAD_C__
>#include <stdio.h>
>
>typedef int ValueType;
>
>struct Node{
>	ValueType value;
>	struct Node* next;
>};
>
>
>void MakeNode(ValueType vt);
>void ShowNode(struct Node * Node_head);
>void InsertNode(int pos,ValueType vt);
>void DeleteNode(int pos);
>
>int
>NodeCount();
>
>void
>FreeAllNode();
>
>extern struct Node *head;  // mian 函数文件会包含头文件  main 函数引入外部变量
>extern struct Node *tail;
>
>#endif
>```
>
> 
>
>#### myhead.c
>
>```c
>#include "head.h"
>#include <stdlib.h>
>
>
>struct Node *head=NULL;
>struct Node *tail=NULL;
>
>
>void
>MakeNode(ValueType vt){
>	struct Node *p=(struct Node*)malloc(sizeof(struct Node));
>	p->value=vt;
>
>	if(head==NULL)
>		head=p;
>	else
>		tail->next=p;
>	tail=p;
>}
>
>
>
>void 
>ShowNode(struct Node * Node_head){
>
>	struct Node *p=Node_head;
>	while(p !=NULL)
>	{
>		printf("%d ->",p->value);
>		p=p->next;
>	}
>	printf("\n");
>
>}
>
>
>void InsertNode(int pos,ValueType vt){
>	int n=0;
>	struct Node *p=(struct Node*)malloc(sizeof(struct Node));
>	struct Node *pre=NULL;
>	p->value=vt;
>	if(pos==0){
>		p->next=head;
>		head=p;
>	}else if(pos > NodeCount()){
>		printf("Warnning:  value %d append to the last\n",vt);
>		p->next=NULL;
>		tail->next=p;
>		tail=p;
>	}else{
>		pre=head;
>		for(n=0;n<pos-1;n++){
>			pre=pre->next;
>		}
>		p->next=pre->next;
>		pre->next=p;
>	}
>
>
>}
>
>void DeleteNode(int pos){
>	struct Node * pre=NULL;
>	struct Node * del=NULL;
>	int n=0;
>	if(pos == 0){
>		pre=head;
>		head=head->next;
>		free(pre);
>	}else if(pos >= NodeCount()){
>		printf("Invalid argument,Out of Range\n");
>		return;
>	}else{
>		pre=head;
>		for(n=0;n<pos-1;n++){
>			pre=pre->next;
>		}
>		del=pre->next;
>		pre->next=del->next;
>
>		if(pre->next ==NULL){
>			tail=pre;
>		}
>
>		free(del);
>
>	}
>}
>
>
>int
>NodeCount(){
>	int n=0;
>	struct Node *p=head;
>	while(p !=NULL){
>		p=p->next;
>		n++;}
>	return n;
>}
>
>
>
>void
>FreeAllNode(){
>	struct Node *p=head;
>	struct Node * temp;
>	int n=0;
>	while(p !=NULL){
>		temp=p;
>		p=p->next;
>		free(temp);
>		n++;
>	}
>
>	printf("all data [%d] freedom\n",n);
>
>
>}
>```
>
>



### 删除重复的数量

> 
>
>借助辅助数组, 链表节点的值 
>
> 数组[链表节点的值] =1   标记该值为1 为出现过
>
>判断条件为 节点的下一个节点
>
>如果下一个节点 在数组下标 那啥就那啥 优点难表达 
>
>```c
>void DeleteRepect(struct Node * Nodefirst){
>  int flag[100];											//100是节点数据域的取值范围 
>  for(int i=0;i<100;i++) flag[i]=0; 	//初始化数组全部为0；
>  
>  struct Node * move =Nodefirst;							// 移动指针指向第一个
>  struct Node * del = NULL;										//要删除的链表节点
>  flag[move->item]=1;									//链表里面的第一个元素 一定没有出现过 直接把该标志为设置为1
>  
>  while(move->next !=NULL){						//判断条件为 move 的下一个节点不为NULL
>   	if(flag[move->next->item] == 0){  //该数据域没有在数组里面出现过 取下标
>       flag[move->next->item]=1;				//更新数组下标，改元素已经出现过了,这个要放在前面
>      	move=move->next;								//这个要放在上一条语句的后面,要不然这条语句直接更新move，会出现下一条语句 下标标错误
>    }else{														//进入已经出现过的元素
>      del =	move->next; 							//标记要删除的节点
>      move->next =del->next;						//更新下一个while循环的判断条件，记住不是以P为条件,是p的下一个节点
>      free(del);											//删除重复出现的元素 节点
>      
>    }
>  }
>  
>}
>```
>
>

### 找到链表中间的值

>
>
>链表长度未知 用两个指针去便利
>
>快指针每次走两步 fast=fast->next->next;
>
>慢指针每次走一步 slow=slow-next;
>
>```c
>ValueType FindMid(struct Node * NodeFirst){
>struct Node *first=NodeFirst;
>struct Node *slow=NodeFirst;
>
>while(first !=NULL && first->next !=NULL){	 		//or first->next !=NULL && first->next->next !=NULL		偶数取较小的
>   first=first->next->next;                    //快指针每次移动两步
>   slow =slow->next;                           //满指针每次移动一步
>}
>
>return slow->item;
>}
>
>```
>
>   
>
> 
>
> 

### 找到链表中尾巴元素

> 
>
>有两根指针 
>
>快指针先走N步
>
>然后快慢指针 同时走，快指针为NULL了 ,慢指针里面的数据就是要找的数据了
>
>```c
>ValueType FindLastElement(Node *NodeFirst,int pos){
>    struct Node *first=NodeFirst;
>    struct Node *find =NodeFirst;
>    for(int i=0;i<pos;i++){
>        first=first->next;
>    }
>
>    while(first !=NULL){
>        first=first->next;
>        find=find->next;
>    }
>    return find->item;
>}
>
>
>
>```
>
>

### 倒置链表

>
>
> 作用域没搞懂
>
>```c
>void ResevedNode(struct Node * NodeFirst){
>    struct Node *p,*n;  //定义两根指针
>    p=NodeFirst->next;  //初始化前驱动   指向当前节点的下一个节点
>    n=NULL;                 //结构里面的next
>
>    while(p->next !=NULL){      //前驱指针结构里面的next为NULL的时候，为链表的最后一个节点
>        NodeFirst->next=n;      //当前节点的next 指向上一个节点的地址，循环的第一次的时候应该等于NULL
>        n=NodeFirst;            //当前节点的地址 保存一下，给下一个节点的next里面
>        NodeFirst=p;            //移动当前的指针 指向下一个
>        p=NodeFirst->next;      //移动前去节点 指向下一个    
>    }
>
>    NodeFirst=p;          //NodeFirst 为倒数第二个节点，p为倒数第一个
>                            //让NodeFirst为最后一个节点
>    NodeFirst->next=n;     //NodeFirst的节点指向上一个节点
>    ShowNode(NodeFirst);
>
>}
>
>```
>
>



### 循环链表 

> 
>
>循环链表的尾节点 不在指向NULL 而是指向链表头,可以循环
>
>插入和删除节点的时候，都要考虑头节点和尾节点，需要更新
>
>打印都最好使用Do while 循环，先更新节点 再判断移动节点是否为头节点，do while 循环可以是循环最少执行一次
>
>moveptr=head；终止条件也应该是 movepte ！=head 使用普通循环，一次也不遍历
>
>
>```c
>#include "linklist.h"
>#include <stdlib.h>  //包含 malloc()
>
>
>
>struct node * head=NULL;
>
>struct node * tail=NULL;
>
>
>void create_list(int c){
>	struct node *p	=(struct node *)malloc(sizeof(struct node));
>	p->elem =c;
>	p->next =NULL;
>
>	if(head ==NULL)
>		head=p;			
>	else 
>		tail->next=p;
>	tail=p;
>	tail->next=head;	//尾部的节点不再指向null 而是指向链表头	
>}
>
>
>void insert_node(int pos,int elem1 ){  //需要考虑插入头节点
>	//插入
>	struct node *pre;
>	pre=head;
>	int i=0;
>
>	struct node*p=(struct node *)malloc(sizeof(struct node)); //开辟的新空间
>			//新空间存上值
>
>	if(pos ==0){		//考虑头节点的情况下
>		p->elem =elem1;
>		p->next=head;
>		head=p;
>		tail->next=head;
>
>
>	}
>	else{
>		while(i < pos -1){
>			pre=pre->next;
>			i++;
>		}
>		p->elem=elem1;	
>		p->next=pre->next;			
>		pre->next=p;					
>
>		if(p->next==head)  //尾指针 指向 头 说明p是尾节点 需要更新tail的位置				
>			tail=p;
>
>	}
>
>}
>
>
>
>void delete_node(int pos){		//删除节点也需要照出前区点,用钱去点的next 指向 找出NOde节点的下一个节点 free掉找出来的节点
>	struct node *pre;
>	struct node *p ;			//要删除的位置
>	pre=head;
>
>	int i=0;
>
>	if(pos==0){					//考虑要删除的节点为头节点
>		head=head->next;
>		free(pre);
>		tail->next=head;		//更新尾节点
>
>	}else{
>			while(i < pos -1){
>			pre=pre->next;
>			i++;
>			}
>
>			p=pre->next;			// p 为要删除的节点 
>
>			pre->next=p->next;			//前驱点的next 等于 要删除节点的next;
>			
>			if(p->next==head)			//考虑删除的节点是最后一个节点，更新tail 指针的位置
>				tail=pre;
>
>			free(p);				//释放 要删除节点的内存空间，从内存中抹掉
>
>	}
>
>}
>
>
>void print_linklist(void){		//打印所有元素
>	struct node* p=head;
>
>	do{							//do while 循环
>		printf("%d ->",p->elem);
>		p=p->next;
>	}while(p !=head);
>	printf("\n");
>}
>
>
>int search(int find){			//找节点
>	struct node * p =head;
>
>	do{							//do while 循环
>		if(p->elem ==find)
>			return 1;
>		p=p->next;
>
>	}while(p !=head);
>	return 0;
>}
>
>
>
>
>```
>
>```c
>#ifndef __LINKLIST_H__
>#define __LINKLIST_H__
>
>#include<stdio.h>
>
>
>
>struct node{
>	int elem;
>	struct node *next;
>};
>
>void create_list(int c);
>void insert_node(int pos,int elem1 );
>void delete_node(int pos);
>void print_linklist(void);
>int search(int find);
>
>
>
>#endif
>
>```
>
>```c
>#include "linklist.h"
>#include <stdio.h>
>
>
>int main(){
>    
>   int a=1;
>   while(a !=9){
>        create_list(a);
>        a++;
>   }
>
>    print_linklist();
>    insert_node(0,a++);
>    print_linklist();
>    insert_node(9,a++);
>    print_linklist();
>    delete_node(6);
>    print_linklist();
>    delete_node(0);
>    print_linklist();
>    delete_node(7);
>    print_linklist();
>
>
>	return 0;
>}
>```



### 循环链表的应用

>
>
>n个人围坐在一张圆桌，从编号为k的人从1 开始报数，数到M的人出列，她的下一个人从1开始报数，数到M出列，依次重复下去，直刀所有人全部出列
>
>```c
>//用以上代码
>//main函数改成
>  
>#include "linklist.h"
>#include <stdio.h>
>#include <stdlib.h>
>
>
>int main(){
>   struct node *p,*q;   
>    int n,k,m;
>    int i;
>
>    printf("please enter the number of the person:");
>    scanf("%d",&n);
>
>    for(i=1;i<=n;i++){
>        create_list(i);
>    }
>
>
>    printf("Please enter the start number:");
>
>    scanf("%d",&k);
>    p=head;
>
>    for(i=0;i<k-1;i++){
>         p=p->next;
>    }
>
>  
>
>   printf("please enter the m:");
>   scanf("%d",&m);
>
>   
>   if(m==1){
>            for(int i=0;i<n;i++){
>               printf("move Element:%d\n",p->elem);
>               p=p->next;
>            }
>
>    }else{
>         while(n--)
>         {
>            for(i=0;i<m-1;i++){
>               p = p->next;}
>            q=p->next;
>            printf("move Element:%d\n",q->elem);
>            p->next=q->next;
>            free(q);
>
>
>         }
>
>
>    }
>   printf("\n");
>
>   return 0;
>}
>
>
>
>```
>
>



### 双向链表

> 
>
> 
>
> **双向链表**
>
>双链链表有两个指针域，分别指向前一个节点和后一个节点
>
>双向链表 头指针的pre指针指向NULL 尾指针的tail指向NULL
>
>插入数据的时候，应该注意更新前一个指针和后一个指针的指针域
>
>![](http://c.biancheng.net/uploads/allimg/190426/1H11B048-0.gif)
>
>
>
>#### 双向链表的实现
>
>```c
>// headfile
>#ifndef __LINKLIST_H__
>#define __LINKLIST_H__
>
>#include<stdio.h>
>
>typedef int ValueType;
>
>struct node{
>	ValueType elem;
>	struct node *pre;	//向前的指针
>	struct node *next;	//向后的指针
>};
>
>void create_list(ValueType c);
>void insert_node(int pos,ValueType elem1 );
>void delete_node(int pos);
>void print_linklist(void);
>int search(ValueType find);
>
>void print_linklist_reseved(void);
>
>
>
>#endif
>
>```
>
>```c
>#include "linklist.h"
>#include <stdlib.h>  //包含 malloc()
>
>
>
>struct node * head=NULL;
>
>struct node * tail=NULL;
>
>
>void create_list(ValueType c){
>	struct node *p	=(struct node *)malloc(sizeof(struct node));//malloc 函数返回 void * 指针 需要 转换一下类型
>	p->elem =c;
>	p->pre =NULL;	//前驱点也初始化
>	p->next =NULL;	//后去点
>
>	if(head ==NULL)
>		head=p;			//头节点永远指向第一个节点  //前驱 后驱点都是null
>	else{
>		tail->next=p;
>		p->pre=tail;			//新加入的节点的前驱点等于上一个tail
>	}
>
>	tail=p;		//更新更新尾巴节点
>}
>
>
>void insert_node(int pos,ValueType elem1 ){  //需要考虑插入头节点
>	//插入
>	struct node *prew;
>	prew=head;
>	int i=0;
>
>	struct node*p=(struct node *)malloc(sizeof(struct node)); //开辟的新空间
>			
>
>	if(pos ==0){			//考虑头节点的情况下
>		head->pre=p;		//老head前驱动点等于 新节点
>
>		p->elem =elem1;		//赋值给新的节点
>		p->next=head;		//新节点的下一个等于老head
>		p->pre=NULL;		//新节点的前驱点等于NULL
>
>		head=p;				//更新head
>
>
>	}
>	else{
>		while(i < pos -1){
>			prew=prew->next;
>			i++;
>		} 
>
>		p->elem=elem1;	//填数据
>		p->pre =prew ;	//  填新节点的前驱点
>		p->next=prew->next;	//填新节点的后驱点
>
>		prew->next=p;	//更新上一个节点的后驱点				
> 
>		if(p->next==NULL)		//p->next 为前驱点赋值的，如果为null 说明 prew是之前最后一个节点	
>			tail=p;				//需要更新一个最后一个节点是新加入的节点
>		else						//不为空的话说明，之前的节点不是最后一节点
>			p->next->pre =p;		//要给后面的节点添加前驱点
>									//p->next 是后面的节点  p->next->pre是最后节点的前驱点
>	}
>
>}
>
>
>
>void delete_node(int pos){		//删除节点也需要照出前区点,用钱去点的next 指向 找出NOde节点的下一个节点 free掉找出来的节点
>	struct node *prew;
>	struct node *p ;			//要删除的位置
>	prew=head;
>
>	int i=0;
>
>	if(pos==0){					//考虑要删除的节点为头节点
>		head=head->next;		//头节点指向下一个
>		head->pre=NULL;			//新头节点的前驱点等于NULL 
>		free(prew);
>
>	}else{
>			while(i < pos -1){
>				prew=prew->next;
>				i++;
>			}
>							//代码写到这里了
>			p=prew->next;			// p 为要删除的节点 
>
>			prew->next=p->next;			//前驱点的next 等于 要删除节点的next;
>			
>			if(p->next==NULL)			//考虑删除的节点是最后一个节点，更新tail 指针的位置
>				tail=prew;				//更新全局的尾节点
>			else
>				prew->next->pre=prew;	//更新后驱点里面的前驱点
>
>			free(p);				//释放 要删除节点的内存空间，从内存中抹掉
>
>	}
>
>}
>
>
>void print_linklist(void){		//打印所有元素
>	struct node* p=head;
>
>	while(p !=NULL){
>		printf("%d ->",p->elem);
>		p=p->next;
>	}
>	printf("\n");
>}
>
>void print_linklist_reseved(void){  //倒叙打印
>	struct node* p=tail;		//初始节点等于最后一个节点
>
>	while(p !=NULL){
>		printf("%d ->",p->elem);
>		p=p->pre;
>	}
>	printf("\n");
>
>}
>
>
>int search(ValueType find){		//找节点
>	struct node * p =head;
>	while(p !=NULL){
>		if(p->elem ==find)
>			return 1;
>		p=p->next;
>	}
>	return 0;
>}
>
>void free_link_list(){			//free 所有节点
>	struct node *pre=head;
>	struct node *del;
>	while(pre !=NULL){
>		del=pre;
>		pre=pre->next;
>		free(del);
>	} 
>	printf("All node delete\n");
>
>}
>
>
>
>```
>
>



## 二叉树

树是一对多的线性关系

处理二叉树 一般都使用递归思想



### 创建二叉树

>
>
>```c
>#include <stdio.h>
>#include <stdlib.h>
>
>
>struct BINTREE_NODE{
>    unsigned char elem;				//属于元素
>    struct BINTREE_NODE *ltree,*rtree;		// 左 右子树
>};
>
>struct BINTREE_NODE* create_tree();
>
>
>int main(){
>    struct BINTREE_NODE* first=create_tree();
>    return 0;
>    
>}
>
>struct BINTREE_NODE* create_tree(){
>    unsigned char flag;				//标指位
>    struct BINTREE_NODE* tree;			//
>    tree=(struct BINTREE_NODE *) malloc(sizeof(struct BINTREE_NODE)); //分配内存空间
>    
>    printf("please input the elem:");
>    while((tree->elem =getchar()) =='\n');							//填充元素
>    
>    printf("Do you want to insert ltree[左子树] for %c (Y?N)?\n",tree->elem);		//询问是否要左子树
>    while((flag =getchar()) =='\n');
>    if(flag=='y' || flag =='Y')
>        tree->ltree=create_tree();							//开辟空间
>    else
>        tree->ltree=NULL;									//填充NULL值
>    
>    printf("Do you want to insert rtree[右子树] for %c (Y?N)?\n",tree->elem); //询问是否要右子树
>    while((flag =getchar()) =='\n');
>    if(flag=='y' || flag =='Y')
>        tree->rtree=create_tree();
>    else
>        tree->rtree=NULL;    
>    return tree; 
>}
>
>```
>
>



### 遍历二叉树

>
>
>遍历二叉树的三种方式：按照根节点的访问顺序,根节点先访问就是先序遍历，根节点在中间就是中序遍历，根节点在后面就是后续遍历
>
>**先序遍历**：1先访问根节点，2 先序左子树，3 先序右子树 
>
>**中序遍历**：1 中序左子树 2根节点 3 中序右子树
>
>**后序遍历**：1后序遍历左子树 2后续遍历右边子树 3访问根节点
>
>```c
>//先序遍历
>void pre_order(struct BinTree_Node * tree){
>  if(tree){
>    	printf("%d",tree->elem);	//先访问数据
>    	pre_order(tree->ltree);		//先序遍历左子树 递归自己
>    	pre_order(tree->rtree);		//先序遍历右子树 递归自己
>  }
>}
>
>//中序遍历
>void mid_order(struct BinTree_Node * tree){
>  if(tree){
>    	mid_order(tree->ltree);		//先序遍历左子树 递归自己
>    	printf("%d",tree->elem);	//先访问数据
>    	mid_order(tree->rtree);		//先序遍历右子树 递归自己
>  }
>}
>
>
>//后序遍历
>void pos_order(struct BinTree_Node * tree){
>  if(tree){
>    	
>    	pos_order(tree->ltree);		//遍历左子树 递归自己
>    	pos_order(tree->rtree);		//遍历右子树 递归自己
>    	printf("%d",tree->elem);	//访问数据
>  }
>}
>```
>
>



### 按照层次遍历二叉树

>按照层级操作二叉树的数据
>
>```c
>如果二叉树的结构为
>  		 A
>  		/ \ 
>   	B   	 C
>  / \     / \
> D.  E.   F  G
>  
>按照队列先进 先出
>  
> 先把A 入队列
> while(队列不为空){
>   temp = 出队列;
>   printf(temp.data) //操作数据域
>   如果 temp ->ltree  !=NULL
>     	enqueue(*temp->ltree);
>    如果 temp ->rtree  !=NULL
>     	enqueue(*temp->rtree);
>   
> }
>```
>
> 
>
> 操作代码
>
>```c
>void ShowByQueue(struct BINTREE_NODE * tree){
>    enqueue(*tree);                              	//先把根节点 进队列
>    struct BINTREE_NODE temp;                       //临时节点存放信息，不是指针
>    while(!isEmpty()){                              //队列不为空 一直循环
>        temp=dequeue();                             //根节点 先出队列
>        printf("%c ->",temp.elem);                  //打印根节点信息
>        if(temp.ltree !=NULL){                      //如果左边节点不为空
>            enqueue(*temp.ltree);                  //左边节点进去队列  下一次循环先出
>        }
>        if(temp.rtree !=NULL){                           //如果左边节点不为空
>            enqueue(*temp.rtree);                     //左边节点进去队列  下一次循环先出
>        }
>    }
>}
>
>```
>
>

### 统计深度叶子数节点数

>
>
>用二叉树的时候，应该优先使用递归思想
>
>```c
>//用递归的思想 统计二叉树的深度
>unsigned int depth(struct BINTREE_NODE * tree){ 
>  unsigned int lcount;
>  unsigned int rcount;
>
>  if(tree==NULL)
>    return 0;
>  else{
>    lcount = depth(tree->ltree);
>    rcount =depth(tree->rtree);
>    return lcount > rcount ? lcount+1 :rcount +1;
>  }
>
>
>}
>
>//统计二叉树的有多少片叶子，叶子为左子树或者右子树 都为NULL
>//分三种情况 自身为空
>//左右子树为空
>//其他情况
>
>unsigned int leafCount(struct BINTREE_NODE * tree){
>  if(tree == NULL)
>    return 0;
>  else if((tree->ltree ==NULL) && (tree->rtree ==NULL))
>    return 1;
>  else
>    return leafCount(tree->ltree) + leafCount(tree->rtree);
>
>}
>
>//统计节点数量 还是应该使用递归的思想
>unsigned int NodeCount(struct BINTREE_NODE * tree){
>
>  if(tree==NULL)
>    return 0;
>  else
>    return 1+NodeCount(tree->ltree) +NodeCount(tree->rtree);
>}
>
>```
>
>

### 补空法创建二叉树

>
>
>用补空法创建二叉树 # 代表空节点 不分配内存，如果数据不为空 先填充数据，然后 左右节点再递归自己
>
>```c
>//定义结构题类型
>struct BINTREE_NODE{
>    unsigned char elem;                        //属于元素
>    struct BINTREE_NODE *ltree,*rtree;        // 左 右子树
>};
>
>
>
>struct BINTREE_NODE* create_tree(){
>    struct BINTREE_NODE* node;
>    char ch;
>    ch=getchar();
>
>    if(ch =='#'){
>        node =NULL;
>    }else{
>        node=(struct BINTREE_NODE *)malloc(sizeof(struct BINTREE_NODE));
>        node->elem =ch;
>        node->ltree=create_tree();
>        node->rtree=create_tree();
>    }
>    return node;
>}
>
>```
>
>填数字
>
>```c
>struct BINTREE_NODE{
>    unsigned int elem;                        //属于元素
>    struct BINTREE_NODE *ltree,*rtree;        // 左 右子树
>};
>
>
>struct BINTREE_NODE* create_tree(){
>    struct BINTREE_NODE* node;
>
>    int ch;
>    scanf("%d",&ch);
>
>    if(ch == 0 ){
>        node =NULL;
>    }else{
>        node=(struct BINTREE_NODE *)malloc(sizeof(struct BINTREE_NODE));
>        node->elem =ch;
>        node->ltree=create_tree();
>        node->rtree=create_tree();
>    }
>    return node;
>}
>```
>
>



### 线性化二叉树

>
>
>按照遍历方式（先序，中序，后序）等排列方式（用队列方式排序），找出二叉树的前驱点和后驱点，但是按照遍历方式
>
>如果用先序排序 右子树的上一个节点 是左子树的最后一个节点
>
>**中序排列** 线性化 （拍成一列）最容易找到节点的前驱和后继点
>
>有点难  TODO	：
>
>
>
>```c
>#include <stdio.h>
>#include <stdlib.h>
>
>
>//测试输入：ABDH##I##EJ##K##CFL##M##GN##O##
>//or；abd##e##cf#g###
>
>typedef char ValueType;
>
>struct BinTreeNode{
>    ValueType item;
>    struct BinTreeNode *ltree,*rtree;
>    int lflag,rflag;
>};
>
>struct BinTreeNode * pre=NULL;//全局的 最左边节点 随时会更新的
>                                //最后指向最后一个节点
>
>struct BinTreeNode *PreCreateNode();
>void PreShowNode(struct BinTreeNode * tree);
>void OrderNode(struct BinTreeNode * tree);                  //step 1:
>void FullOrderNode(struct BinTreeNode * trees);             //step 2:
>void traverse_INorder_thread(struct BinTreeNode * trees);   //step 3: //叶子节点不为NULL的时候判断
>
>
>int main(){
>    
>
>    printf("Please enter the Node value,step by blank,# for NULL:\n");
>    struct BinTreeNode *tree=PreCreateNode();
>    PreShowNode(tree);
>    printf("\n");
>    FullOrderNode(tree);
>    traverse_INorder_thread(tree);
>
>
>
>    return 0;
>}
>
>
>struct BinTreeNode *PreCreateNode(){  //前序遍历节点
>    ValueType value; //valuetype 暂时为char
>    struct BinTreeNode * tree;
>    value =getchar();
>    if(value == '#'){
>        tree = NULL;
>    }else{
>        tree=(struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
>        tree->item=value;
>        tree->ltree=PreCreateNode();
>        tree->rtree=PreCreateNode();
>    }
>
>    return tree;
>}
>
>void PreShowNode(struct BinTreeNode * tree){
>    if(tree){
>        printf("%c -> ",tree->item);
>        PreShowNode(tree->ltree);
>        PreShowNode(tree->rtree);
>
>    }
>}
>
>
>void OrderNode(struct BinTreeNode * tree){
>    if(tree){
>        OrderNode(tree->ltree);     //递归左边
>
>        if(tree->ltree ==NULL){
>            tree->ltree =pre;
>            tree->lflag = 1;
>
>        }else
>            tree->lflag = 0;
>        if(pre){
>            if(pre->rtree ==NULL){
>                pre->rflag=1;
>                pre->rtree= tree;
>            }else
>                pre->rflag=0;
>        }
>        pre=tree;
>
>        OrderNode(tree->rtree);         //递归右边
>        
>    }
>   
>}
>
>void FullOrderNode(struct BinTreeNode * trees){
>    if(trees){
>        OrderNode(trees);
>        pre->rtree=NULL;//设置最后一个节点的
>        pre->rflag=1;   //设置最后一个节点的
>
>    }
>}
>
>void traverse_INorder_thread(struct BinTreeNode * trees){
>    //思路先找到最左边的节点，然后打印上一个，然后再找到次要左边的节点，然后再上一个
>    //循环
>
>        while(trees){
>            
>            while(trees->lflag==0)
>                trees=trees->ltree;
>            
>            printf("[%c]->",trees->item);
>            while((trees->rflag == 1) && (trees->rtree)){
>                trees=trees->rtree;
>                printf("[%c]->",trees->item);
>            }
>            
>            trees=trees->rtree;
>            //ABDH##I##EJ##K##CFL##M##GN##O##
>        
>    }
>
>}
>
>
>```
>
>

### 找二叉树的前驱点和后驱点 

>
>
>找二叉树的前驱和后驱点必须先对二叉树线就是线性化(中序)
>
>最左边的叶子节点ltree为节点的前驱，rltree为该节点的后驱（需要有标志为 lflag 和 rflag可以设置为1，默认为0 说明该节点为非叶子节点）
>
>某一个节点 的前一个节点为 该节点左子树的最后节点
>
>某一个节点 的后一个节点为 该节点右子树的最左节点
>
>```c++
>typedef char ValueType;
>
>struct BinTreeNode{
>ValueType item;
>struct BinTreeNode *ltree,*rtree;
>int lflag,rflag;
>};
>//线性化之后
>//test input //ABDH##I##EJ##K##CFL##M##GN##O##
>
>
>
>struct BINARY_TREE *Find_Pre_Node(const struct BINARY_TREE * node)// 找到node的前驱点
>{	
>	struct BINARY_TREE *result;	//接收返回值 不能改变要查找的值
>
>	if(node->lflag ==1)		//之前的叶子节点
>		return node->ltree; 
>	else					//找左子树的最右下节点
>	{	
>
>		result=node->ltree;			//先等于左节点
>		while(result->rflag==0)		//普通节点 rflag=0
>			result=result->rtree;		
>									//跳出rflag=0，此时flag=1;为查找的节点的最右边节点
>		return result;
>	}
>}
>
>
>
>struct BINARY_TREE *Find_Post_Node(const struct BINARY_TREE * node){// 找到node的后驱点
>	struct BINARY_TREE *result;
>	if(node->rflag)					//如果node->rflag==1 ,说明右边是叶子节点
>		return node->rtree;
>	else{							//就是正常节点,后驱点是右子树的最左边节点
>		result=node->rtree;
>		while(result->lflag==0)			
>			result=result->ltree;
>		return result;				//此时的lfag=1
>
>	}
>
>}
>
>
>
>```
>
>完整代码
>
>```c
>
>/*
>
>text input: 	abd##e##cf#g###
>
>*/
>
>#include <stdio.h>
>#include <stdlib.h>
>
>typedef char ValueType;
>
>struct BINARY_TREE{
>	ValueType item;
>	int lflag;
>	int rflag;
>	struct BINARY_TREE *ltree;
>	struct BINARY_TREE *rtree;
>};
>
>struct BINARY_TREE *pre=NULL;//全局节点
>struct BINARY_TREE *create_tree();
>void ShowNode(struct BINARY_TREE * treeNode);		//显示单个节点
>void ShowTreePre(struct BINARY_TREE * treeStart); //先序查看
>void ShowTreeMid(struct BINARY_TREE * treeStart); //中序查看
>void ShowTreePost(struct BINARY_TREE * treeStart); //后序查看
>void SortTree(struct BINARY_TREE *treeStart);		//递归序列化二叉树
>void SortTreeAddEnd(struct BINARY_TREE *treeStart);//给序列化二叉树加个尾巴
>void ShowSortTreePre(struct BINARY_TREE *treeStart);// 显示序列化后的二叉树::TODO error
>void traverse_thread(struct BINARY_TREE *treeStart);// 显示序列化后的二叉树
>struct BINARY_TREE *Search_inorder_Thread(struct BINARY_TREE * treeStart,ValueType ch);//二叉树中找字符 返回所在的节点
>struct BINARY_TREE *Find_Pre_Node(const struct BINARY_TREE * node);// 找到node的前驱点
>struct BINARY_TREE *Find_Post_Node(const struct BINARY_TREE * node);// 找到node的后驱点
>
>
>
>
>
>
>int main(){
>	ValueType ch;
>	struct BINARY_TREE *current,*pre,*post;//要找到的节点，前驱点，后驱点
>	printf("Please enter the item for pre_顺序，# for null:\n");
>	struct BINARY_TREE * mytree=create_tree();
>	ShowTreePre(mytree);
>	printf("\n");
>	ShowTreeMid(mytree);
>	printf("\n");
>	ShowTreePost(mytree);
>	printf("\n");
>	SortTreeAddEnd(mytree);
>	
>	printf("\n");
>	printf("traverse_thread later; \n");
>	traverse_thread(mytree);
>	printf("\n");
>
>	
>	
>	printf("please enter your want to find the element:\n");
>
>
>	while(getchar()!='\n');
>
>	while((ch=getchar()) && (ch !='#')){
>
>		current=Search_inorder_Thread(mytree,ch); //找到的节点
>		printf("current:[%c]\n",current->item);
>		pre=Find_Pre_Node(current);					//当前节点的前驱点
>		if(pre)
>			printf("pre:[%c]\n",pre->item);
>		else
>			printf("pre data NONE\n");
>		post=Find_Post_Node(current);				//当前节点的后驱点
>		if(post)
>			printf("post:[%c]\n",post->item);
>		else
>			printf("post data NONE\n");
>		printf("please enter your want to find the element:\n");
>		while(getchar()!='\n');
>	}
>
>	return 0;
>}
>
>void ShowNode(struct BINARY_TREE * treeNode){
>	if(treeNode){
>		printf("-----------\n");
>
>		printf("item:%c\n",treeNode->item);
>		printf("lflag:%d\n",treeNode->lflag);
>		printf("rflag:%d\n",treeNode->lflag);
>		if(treeNode->ltree)
>			printf("ltree:%p\n",treeNode->ltree);
>		else
>			printf("ltree: NULL\n");
>
>		if(treeNode->rtree)
>			printf("rtree:%p\n",treeNode->rtree);
>		else
>			printf("ltree: NULL\n");
>
>		printf("-----------\n");
>	}else
>		printf("No data\n");
>}
>
>
>struct BINARY_TREE *create_tree(){
>	struct BINARY_TREE *ptree;
>	
>	ValueType ch;
>	ch=getchar();
>	
>	if(ch =='#'){
>		ptree=NULL;
>	}else{
>		ptree=(struct BINARY_TREE *)malloc(sizeof(struct BINARY_TREE));
>		ptree->item = ch;
>		ptree->ltree =ptree->rtree =0;
>		ptree->ltree=create_tree();
>		ptree->rtree=create_tree();
>	}
>	return ptree;
>}
>
>void ShowTreePre(struct BINARY_TREE * treeStart){
>	if(treeStart){
>		printf("%c -> ",treeStart->item);
>		ShowTreePre(treeStart->ltree);
>		ShowTreePre(treeStart->rtree);
>	}
>
>}
>
>void ShowTreeMid(struct BINARY_TREE * treeStart){
>	if(treeStart){
>		ShowTreeMid(treeStart->ltree);
>		printf("%c -> ",treeStart->item);
>		ShowTreeMid(treeStart->rtree);
>	}
>
>}
>
>void ShowTreePost(struct BINARY_TREE * treeStart){
>	if(treeStart){
>		ShowTreePost(treeStart->ltree);	
>		ShowTreePost(treeStart->rtree);
>		printf("%c -> ",treeStart->item);
>	}
>}
>
>void SortTree(struct BINARY_TREE *treeStart){
>	if(treeStart){
>		SortTree(treeStart->ltree);
>
>
>		if(treeStart->ltree ==NULL){ //判断是不是叶子节点 叶子节点 为NULL 
>			treeStart->lflag=1;		
>			treeStart->ltree=pre;
>		}else
>			treeStart->lflag=0;	
>
>
>		if(pre){		//操作上一个节点
>			if(pre->rtree ==NULL){
>				pre->rflag=1;			
>				pre->rtree=treeStart;
>			}else
>				pre->rflag=0;
>
>		}
>		pre=treeStart; //更新上一个节点
>
>		SortTree(treeStart->rtree);
>	}
>
>}
>void SortTreeAddEnd(struct BINARY_TREE *treeStart){
>	if(treeStart){
>		SortTree(treeStart);
>		pre->rflag=1;
>		pre->rtree=NULL;
>
>	}
>}
>
>void ShowSortTreePre(struct BINARY_TREE *treeStart){ //ERROR
>
>	if(treeStart){
>		if(treeStart->lflag ==0)
>			printf("%c -> ",treeStart->item);
>		ShowTreePre(treeStart->ltree);
>		if(treeStart->rflag ==0)
>			ShowTreePre(treeStart->rtree);
>	}
>}
>
>void traverse_thread(struct BINARY_TREE *treeStart){
>	while(treeStart){
>		while(treeStart->lflag ==0){
>			treeStart =treeStart->ltree;
>		}
>		printf("[%c]->",treeStart->item);
>
>		while((treeStart->rflag ==1) && treeStart->rtree){
>			treeStart =treeStart->rtree;
>			printf("[%c]->",treeStart->item);
>
>		}
>		treeStart =treeStart->rtree;
>	}
>
>}
>
>struct BINARY_TREE *Search_inorder_Thread(struct BINARY_TREE * treeStart,ValueType ch){
>	while(treeStart){
>		while(treeStart->lflag ==0){
>			treeStart =treeStart->ltree;
>		}
>		//printf("[%c]->",treeStart->item);
>		if(treeStart->item == ch)
>			return treeStart;
>
>		while((treeStart->rflag ==1) && treeStart->rtree){
>			treeStart =treeStart->rtree;
>			if(treeStart->item == ch)
>				return treeStart;
>
>		}
>		treeStart =treeStart->rtree;
>	}
>	return NULL; //没找到返回的结果
>
>}
>
>struct BINARY_TREE *Find_Pre_Node(const struct BINARY_TREE * node)// 找到node的前驱点
>{	
>	struct BINARY_TREE *result;	//接收返回值 不能改变要查找的值
>
>	if(node->lflag ==1)		//之前的叶子节点
>		return node->ltree; 
>	else					//找左子树的最右下节点
>	{	
>
>		result=node->ltree;			//先等于左节点
>		while(result->rflag==0)		//普通节点 rflag=0
>			result=result->rtree;		
>									//跳出rflag=0，此时flag=1;为查找的节点的最右边节点
>		return result;
>	}
>}
>
>
>
>struct BINARY_TREE *Find_Post_Node(const struct BINARY_TREE * node){// 找到node的后驱点
>	struct BINARY_TREE *result;
>	if(node->rflag)					//如果node->rflag==1 ,说明右边是叶子节点
>		return node->rtree;
>	else{							//就是正常节点,后驱点是右子树的最左边节点
>		result=node->rtree;
>		while(result->lflag==0)			
>			result=result->ltree;
>		return result;				//此时的lfag=1
>
>	}
>
>}
>
>
>
>
>```
>
>

### 还原二叉树

>
>
>```c
>//二叉树的结构如上
>
>//前序列排列根节点在第一个 //后续排列根节点为最后一个
>//找到根节点在中序排列的位置 如果位置为N个 那N前面的都是树的左子树及其分支，N后面的就是树的右子树和其分支
>//然后递归左子树和右子树 使其为根节点的左右子树
>
>
>//通过前序排列 和 中序 排列 还原一个二叉树
>struct BINARY_TREE *Pre_Mid_input_CreateTree(char *prestr,char *midstr,int len);
>
>//通过中序排列 和 后序 排列 还原一个二叉树
>struct BINARY_TREE *Mid_Post_input_CreateTree(char *midstr, char *poststr,int len);
>
>
>struct BINARY_TREE *Pre_Mid_input_CreateTree(char *prestr,char *midstr,int len){
>  if(len==0)
>    return NULL;  
>  struct BINARY_TREE * result;
>  char target=prestr[0];
>  int i=0;
>  while(midstr[i] !=target)
>  {
>    i++;
>    assert(i <= len);  // can't find  in Midstr, assert to stop the loop
>  }
>  result =(struct BINARY_TREE *)malloc(sizeof(struct BINARY_TREE));
>  result->item=target;
>  result->ltree=Pre_Mid_input_CreateTree(prestr+1,midstr,i);
>  result->rtree=Pre_Mid_input_CreateTree(prestr+1+i,midstr+1+i,len-i-1);
>  return result;
>
>
>}
>
>struct BINARY_TREE *Mid_Post_input_CreateTree(char *midstr, char *poststr,int len){
>  if(len==0)
>    return NULL;
>  struct BINARY_TREE * result;
>  char target=poststr[len-1]; 
>  int i=0;
>  while(midstr[i] !=target)
>  {
>    i++;
>    assert(i <= len);  // can't find  in Midstr, assert to stop the loop
>  }
>  result =(struct BINARY_TREE *)malloc(sizeof(struct BINARY_TREE));
>  result->item=target;
>  result->ltree=Mid_Post_input_CreateTree(midstr,poststr,i);
>  result->rtree=Mid_Post_input_CreateTree(midstr+i+1,poststr+i,len-i-1);
>  return result;
>
>}
>
>```
>
>





## 图

>
>
>**图**分为 V 顶点 和 边 E
>
>**图**可以再分为有向图 和 无向图
>
>**有向图**用<T1,T2>,代表 只能T1 -> t2
>
>**无向图**用(T1,T2), 代表 T1 可以到T2，T2 也能到T1 
>
>不能自己到自己，**自环图**
>
>不能通一条边出现多次 出现多次叫**多重图**
>
>任意两点都有边 叫做**完全图**
>
>定点 N个 无向完全图 有 N(N-1)/2 条边
>
>顶点N个 完全图 有N(N-1) 条边
>
>网：
>
>定点到顶点之间的值 叫**权值**，有可能是**权重值**
>
>带权值的图 叫做**网** 
>
>临接：顶点到顶点之间的关系 两个点相连叫临接点
>
>关联：边和顶点之间的关系，边关联 V1和V2 两个顶点
>
>**度：顶点的度**，与某个顶点相关联边的数量 度数是边的两倍
>
>有向图 叫 **入度** 和**出度**
>
>到某个点的边的条数量。叫**入度**
>
>离开某个点的边的条数 叫**出度**
>
>**连通图**，任意两个点都有路径的（一般无向图）
>
>**连通分量**：从某个图中取子图，并且该子图所有顶点都是联通的，拿掉了不连通的（最大连通子图）





### 图的存储结构

>
>
>顺序存储: 临接矩阵（需要两个数组 一个数组表示顶点，另外一个数组是二维度数组 表示边）
>
>链式存储：临接标，十字链表，临接多重标



### 链式存储

>链式存储是连续的内存空间
>
>```c
>#include <stdio.h>
>#include <stdlib.h>
>#include <assert.h>
>
>
>#define MAX 100
>
>//临接矩阵
>struct AMG_graph{
>    int vex_num;
>    int edge_num;         //顶点个数和 边的个数
>    char Vex[MAX];                //顶点的数组
>    int Edge[MAX][MAX];        //边的关系 用二维矩阵
>
>};
>
>struct AMG_graph * Create_AMG_Graph(void);//
>void ShowGraph(struct AMG_graph * graph);//显示
>int seach_vex(struct AMG_graph * gp,char ch);//找索引
>
>int main(){
>    struct AMG_graph *MyGraph;
>
>    MyGraph=Create_AMG_Graph();
>    ShowGraph(MyGraph);
>
>
>    return 0;
>}
>
>
>
>struct AMG_graph *Create_AMG_Graph(){
>    int i,j;
>    char u,v;
>    struct AMG_graph *graph;
>    graph=(struct AMG_graph *)malloc(sizeof(struct AMG_graph));
>    printf("please enter the number of vex:"); //顶点个数
>    scanf("%d",&graph->vex_num);
>    printf("please enter the number of edge:"); //顶点个数
>    scanf("%d",&graph->edge_num);
>    
>    while(getchar() !='\n');
>    printf("enter the vex value:\n");
>    
>    for(i=0;i<graph->vex_num;i++){  //填充顶点
>        graph->Vex[i]=getchar();
>        while(getchar() !='\n');
>    }
>    
>    for(i=0;i<graph->vex_num;i++)       //清空二维数组
>        for(j=0;j<graph->vex_num;j++)
>            graph->Edge[i][j]=0;
>    
>    while(graph->edge_num--){
>        printf("please enter the vex that connect each other:\n");
>        u=getchar();
>        while(getchar()!='\n');
>        printf("please enter the anther:\n");
>        v=getchar();
>        while(getchar()!='\n');
>        i=seach_vex(graph,u);
>        j=seach_vex(graph, v);
>        assert(i>-1);
>        assert(j>-1);
>        graph->Edge[i][j]=1;
>        graph->Edge[j][i]=1;
>    }
>
>    
>    return graph;
>
>}
>
>void ShowGraph(struct AMG_graph * graph){
>    int i,j;
>    printf("Show info:------\n");
>    printf("Vec : %d ,Graph:%d \n",graph->vex_num,graph->edge_num);
>    printf("The vec:------\n");
>    for(i=0;i<graph->vex_num;i++){
>        printf("%c\t",graph->Vex[i]);
>    }
>    printf("\n");
>    //printf("The Edge:------\n");
>    for(i=0;i<graph->vex_num;i++){
>        for(j=0;j<graph->vex_num;j++){
>                printf("[%d]\t",graph->Edge[i][j]);
>        }
>        printf("\n");
>        
>    }
>
>    
>    printf("\n");
>          
>    
>}
>
>int seach_vex(struct AMG_graph * gp,char ch){
>    int i;
>    for(i=0;i<gp->vex_num;i++){
>        if(ch==gp->Vex[i])
>            return i;
>    }
>    return -1;
>}
>
>```
>
>

### 临接表

>
>
>![](https://img-blog.csdn.net/20161212151905887)
>
>分为有向图和无向图
>
>顶点表是一个数组 数组里面是结构，顶点值和指针 指向的是和他临接的顶点(在顶点表中的索引 可以节约内存空间)



>```c
>#include <stdio.h>
>#include <stdlib.h>
>#include <assert.h>
>
>
>#define MAX 100
>
>
>struct AdjNode{  //临接表
>    int index;              //顶点数组里面的索引
>    struct AdjNode *next;
>};
>
>struct VexNode{     //顶点表
>    char node;
>    struct AdjNode *first;
>    
>};
>
>struct ALG_graph{
>    int vex_num;        //顶点个数
>    int edge_num;       //边的个数
>    struct VexNode Vex[MAX];    //顶点的数组 【顶点｜临接点第一个】
>};
>
>struct ALG_graph *CreateALGgraph();
>int search_vex(struct ALG_graph * grap,char ch);  //找索引
>void create_adj_node_list(struct ALG_graph *graph,int i,int j);//往节点表里面插入临节点
>void Show_ALG_graph(struct ALG_graph *graph);//显示节点表和临节点表
>
>int main(){
>    struct ALG_graph *ugraph=CreateALGgraph();
>    Show_ALG_graph(ugraph);
>    
>    return 0;
>}
>
>
>struct ALG_graph *CreateALGgraph(){
>    int i,j;
>    struct ALG_graph *graph;
>    char u,v;
>
>    graph =(struct ALG_graph *)malloc(sizeof(struct ALG_graph));
>    
>    printf("Please enter the number of vex|输入顶点个数:"); //顶点个数
>    scanf("%d",&graph->vex_num);
>    printf("Please enter the number of edge｜输入边的个数:"); //顶点个数
>    scanf("%d",&graph->edge_num);
>    
>    while(getchar() !='\n');
>    printf("Enter the vex value:\n");
>    
>    for(i=0;i<graph->vex_num;i++){  //填充顶点  //没有考虑输入重复的问题
>        
>        graph->Vex[i].node=getchar();
>        graph->Vex[i].first=NULL;
>       
>        while(getchar() !='\n');
>    }
>    while(graph->edge_num--){
>        printf("please enter the vex that connect each other|输入开始顶点:\n");
>        u=getchar();
>        while(getchar()!='\n');
>        printf("please enter the anther｜到达顶点:\n");
>        v=getchar();
>        while(getchar()!='\n');
>        i=search_vex(graph,u);
>        j=search_vex(graph,v);
>        if(i < 0 || j <0){ //没有考虑两次输入都是一样的问题
>            printf("输入错误，再重写输入一次\n");
>            graph->edge_num++;
>            continue;
>        }
>        else{
>            create_adj_node_list(graph,i,j);    //有向
>            create_adj_node_list(graph,j,i);    //相反加一条就成无向
>        }
>            
>  
>    }
>    
>    return graph;
>    
>}
>
>int search_vex(struct ALG_graph * grap,char ch){
>    int i;
>    for(i=0;i<grap->vex_num;i++){
>        if(grap->Vex[i].node==ch)
>            return i;
>    }
>    return -1;
>    
>}
>
>void create_adj_node_list(struct ALG_graph *graph,int i,int j){
>    struct AdjNode *NewNode=(struct AdjNode *)malloc(sizeof(struct AdjNode ));
>    NewNode->index=j;           //没有考虑两次节点都是一样的问题
>
>    NewNode->next=graph->Vex[i].first;  //新节点的下一个节点 first节点
>    graph->Vex[i].first=NewNode;        //first 等于新节点
>}
>
>void Show_ALG_graph(struct ALG_graph *graph){
>//    int n=graph->vex_num;
>    struct AdjNode *temp;
>    printf("SHOW ALG_GRAPH\nVec count:%d\n",graph->vex_num);
>    
>    for(int i=0;i<graph->vex_num;i++){
>        printf("VEC: %c ->",graph->Vex[i].node);
>        temp=graph->Vex[i].first;               //临时节点等于first节点
>        while(temp !=NULL){                     //当临时节点不等于空
>            printf("%d -> ",temp->index);       //打印 节点表的索引
>            temp=temp->next;                    //等于下一个节点
>        }
>        printf("\n");
>    }
>}
>
>
>```
>
>

### 十字链表

>如下图所示的一个有向图：
>
>![img](https://img-blog.csdn.net/20170505161450882)
>
>其对应的顶点以及弧结点如下所示。拿结点A说明，该结点对应两个链表（绿色和黄色标记的）。绿色链表表示以结点Ａ为弧头的弧组成的链表。黄色链表表示以结点Ａ为弧尾的弧组成的链表。
>
>![img](https://img-blog.csdn.net/20170505161543976)
>
>
>
>**临接表**  a 到 c 	  a的index ｜ c的index ｜ 到达a的指针｜a出发的指针 （有可能错，不知道咋表达）
>
>**顶点表**  元素的值 ｜可以到达该元素的索引｜ 从该索引出发
>
> 
>
> 
>
>十字链表的代码
>
>```c
>//
>//  main.c
>//  MyDataStruct
>//
>//  Created by macbookpro on 2023/2/24.
>//
>
>#include <stdio.h>
>#include <stdlib.h>
>#define SIZE 100
>
>typedef char ValueType; //定义顶点的基本数据类型
>
>struct node{
>    int outIndex;
>    int inIndex;
>    struct node *Pin; //开始节点指针
>    struct node *Pout;   //到达节点指针
>};
>
>struct asimple{             //单个顶点的值|到达这个顶点的值 的节点指针｜
>    ValueType value;
>    struct node *firstIn;
>    struct node *firstOut;
>};
>
>struct VecTable{
>    int VecNum;
>    int EdgeNum;
>    struct asimple arr[SIZE]; //数组默认100个 不要超出这个范围
>};
>
>
>struct VecTable *CreateVecTable(int vn,int en); //初始化结构 有默认值
>void Init(struct VecTable * p);//初始化结构呗
>
>int FindIndex(struct VecTable* p,ValueType ch);//找索引
>ValueType FindValue(struct VecTable* p,int index ); //找值
>
>void VecAddNode(struct VecTable* p,int out,int in); //添加边
>
>void DisplayInOut(struct VecTable* p,ValueType ch);//显示查询的值
>
>
>int main() {
>    ValueType vt = 'c';
>    struct VecTable *mygraph=CreateVecTable(5,7);
>    do{
>        DisplayInOut(mygraph,vt);
>        printf("please enter the check value｜输入要查询的元素(# to quit):");
>        vt=getchar();
>        while(getchar()!='\n');
>    }while(vt !='#');
>    
>    
>    
>
>    return 0;
>}
>
>struct VecTable *CreateVecTable(int vn,int en){
>    int i;
>    ValueType in,out;
>    int inIndex,outIndex;
>    struct VecTable *p=(struct VecTable *)malloc(sizeof(struct VecTable ));
>    Init(p);
>    p->VecNum=vn;
>    p->EdgeNum=en;
>    printf("Please enter the Vec element｜输入顶点元素:\n");
>    for(i=0;i<vn;i++){
>        p->arr[i].value=getchar();//
>        while(getchar() !='\n');
>    }
>    printf("Please enter the Edge｜开始输入边:\n");
>    for(i=0;i<en;i++){
>        printf("From item｜输入边的起点:");
>        out =getchar();
>        while(getchar() !='\n');
>        printf("arrivaled item｜输入边的重点:");
>        in =getchar();
>        while(getchar() !='\n');
>        outIndex=FindIndex(p,out);
>        inIndex=FindIndex(p,in);
>        printf("DEBUG: out:%d,in:%d\n",outIndex,inIndex);
>        if(outIndex != -1 && inIndex != -1 && outIndex != inIndex){
>            VecAddNode(p,outIndex,inIndex);
>        }else{
>            printf("Entered Edge Error,Please try again!｜输入错误，重写再输入一次\n ");
>            i--;
>        }
>        
>        
>    }
>    
>    
>    
>    
>    return p;
>}
>
>void Init(struct VecTable * p){
>    p->VecNum=p->EdgeNum=0;
>    for(int i=0;i<SIZE;i++){
>        p->arr[i].value=0;
>        p->arr[i].firstIn =NULL;
>        p->arr[i].firstOut =NULL;
>    }
>    
>}
>
>int FindIndex(struct VecTable* p,ValueType ch){
>    int i;
>    for(i=0;i<p->VecNum;i++){
>        if(p->arr[i].value ==ch)
>            return i;
>    }
>    return -1;
>}
>
>
>void VecAddNode(struct VecTable* p,int out,int in){
>    
>    struct node *pnode=(struct node *)malloc(sizeof(struct node));
>    pnode->outIndex = out;
>    pnode->inIndex = in;        //新建一个节点 开始｜到达｜开始指针｜到达指针
>    
>    pnode->Pout =p->arr[out].firstOut;
>    pnode->Pin =p->arr[in].firstIn;
>    
>    p->arr[out].firstOut=pnode;
>    p->arr[in].firstIn=pnode;
>  
>}
>
>
>ValueType FindValue(struct VecTable* p,int index ) //找值
>{
>    if(index < p->VecNum){
>        return p->arr[index].value;
>    }else
>        return '0';
>}
>
>
>
>
>void DisplayInOut(struct VecTable* p,ValueType ch){
>    int index=FindIndex(p,ch);
>    struct node *Pnode;
>    if(index != -1){
>        printf("Value: %c\n",ch);
>        Pnode = p->arr[index].firstIn;
>        printf("IN index :");
>        while(Pnode){
>            printf("%d[%c] - > ",Pnode->outIndex,FindValue(p, Pnode->outIndex));
>            Pnode=Pnode->Pin;
>        }
>        printf("\n");
>        Pnode = p->arr[index].firstOut;
>        printf("out index :");
>        while(Pnode){
>            printf("%d[%c] - > ",Pnode->inIndex,FindValue(p, Pnode->inIndex));
>            Pnode=Pnode->Pout;
>        }
>        printf("\n");
>        
>       
>    }
>    else{
>        printf("Find Error\n");
>    }
>    
>    
>}
>
>```
>
>

### 邻接多重表

>
>
>链接表
>
>a 链接b 
>
>a_index |
>
>```c
>
>#include <stdio.h>
>#include <stdlib.h>
>#define SIZE 100
>
>
>typedef char ValueType;
>
>struct node{
>    int index1;
>    struct node *sp1;
>    int index2;
>    struct node *sp2;
>};
>
>struct Simple{
>    ValueType Value;
>    struct node *first;
>};
>
>
>struct Grap{
>    int VecCount;
>    int EdgeCount;
>    struct Simple arr[SIZE];
>};
>
>
>struct temp{
>    int x;
>    int y;
>    struct temp * next;
>};
>
>
>struct Grap *CreateGrap(int vn,int en); //新建图
>int FindIndex(struct Grap *gp,ValueType ch);//通过元素找索引
>void GraphAddEdge(struct Grap *gp,int vv,int ev);//添加临接边,应该多一个检测，之前的之前的临接边没存在过
>void VecShowEdge(struct Grap *gp,ValueType ch); //显示无向图临接边；
>ValueType GetValue(struct Grap *gp,int n);
>
>
>int main(){
>    ValueType check;
>    struct Grap *p=CreateGrap(5,8);
>    
>    printf("please enter the element for check edge:");
>    
>    while((check = getchar()) !='#' ){
>        while(getchar() !='\n');
>        VecShowEdge(p, check);
>        printf("please enter the element for check edge:");
>        
>        
>    }
>    
>
>   
>    return 0;
>};
>
>
>struct Grap *CreateGrap(int vn,int en){
>    int i;
>    ValueType x,y;
>    int xi,yi;
>    
>    
>    struct Grap *p=(struct Grap*)malloc(sizeof(struct Grap));
>    
>    p->VecCount=vn;
>    p->EdgeCount=en;
>    printf("please enter the element|输入顶点:\n");
>    for(i=0;i<vn;i++){
>        p->arr[i].Value=getchar();
>        while(getchar() !='\n');
>        p->arr[i].first=NULL;
>    }
>    printf("Edge Count:%d\n",en);
>    
>    for(i=0;i<en;i++){
>        printf("start Edge|输入起始点:\n");
>        x=getchar();
>        while(getchar()!='\n');
>        printf("end Edge|输入起始点:\n");
>        y=getchar();
>        while(getchar()!='\n');
>        xi=FindIndex(p, x);
>        yi=FindIndex(p,y);
>        if(xi != -1 && yi != -1 && xi !=yi){
>            GraphAddEdge(p,xi,yi);
>            
>        }else{
>            printf("Input Error Please try again\n");
>            i--;
>        }
>       
>    }
>    
>    return p;
>}
>
>
>int FindIndex(struct Grap *gp,ValueType ch){
>    int i;
>    for(i=0;i<gp->VecCount;i++){
>        if(gp->arr[i].Value==ch)
>            return i;
>    }
>    return -1;
>}
>
>void GraphAddEdge(struct Grap *gp,int vv,int ev){
>    
>    struct node *movep;
>    struct node *p=(struct node *)malloc(sizeof(struct node));
>    p->index1=vv;
>    p->sp1=NULL;
>    p->index2=ev;
>    p->sp2=NULL;
>    
>    if(gp->arr[vv].first==NULL){
>        gp->arr[vv].first=p;
>    }else{
>        movep=gp->arr[vv].first;
>        while(movep->index1==vv ? (movep->sp1 !=NULL):(movep->sp2 !=NULL)){ //该行代码出错
>            movep = movep->index1==vv ? movep->sp1:movep->sp2;
>        }
>        if(movep->index1==vv)
>            movep->sp1=p;
>        else
>            movep->sp2=p;
>        
>
>    }
>    
>    if(gp->arr[ev].first==NULL){
>        gp->arr[ev].first=p;
>    }else{
>        movep=gp->arr[ev].first;{
>
>        }
>        while(movep->index1==ev ? (movep->sp1 !=NULL):(movep->sp2 !=NULL)){ //该行代码出错
>            movep = movep->index1==ev ? movep->sp1:movep->sp2;
>        }
>        if(movep->index1==ev)
>            movep->sp1=p;
>        else
>            movep->sp2=p;
>    
>    }
>  
>}
>
>void VecShowEdge(struct Grap *gp,ValueType ch){
>    struct node * movep;
>    ValueType chh;
>    int index=FindIndex(gp,ch);
>    if(index !=-1){
>        movep=gp->arr[index].first;
>        
>        if(movep){
>            printf("%c Edge value : ",ch);
>            //while(!(movep->sp1 ==NULL && movep->sp2 ==NULL))
>            while(movep){
>                chh=movep->index1==index ? GetValue(gp,movep->index2): GetValue(gp,movep->index1);
>                printf(" %c ->",chh);
>                movep = movep->index1==index ? movep->sp1:movep->sp2;
>            }
>            printf("\n");
>        }
>        else{
>            printf("%c 顶点 have no edge\n",ch);
>        }
>        
>    }
>    else{
>        printf("Input ValueType Error\n");
>    }
>    
>}
>
>ValueType GetValue(struct Grap *gp,int n){
>    return gp->arr[n].Value;
>}
>
>
>```
>
>



### 图的遍历

>遍历之前先定义一个数组，设置标志位，如果该标志位为0 说明没被访问过，访问过再标志为1  下次遍历到该索引就不会访问了
>
>**广度优先**：先被访问的节点，其邻接点也先被访问 ｜ 队列
>
>**深度优先**:一条道走到底｜使用栈 or 递归
>
>步骤
>
>|      | a    | b    | c    | d    | e    |
>| ---- | ---- | ---- | ---- | ---- | ---- |
>| a    | 0    | 1    | 1    | 0    | 1    |
>| b    |      |      |      |      |      |
>| c    |      |      |      |      |      |
>| d    |      |      |      |      |      |
>| e    |      |      |      |      |      |
>
>
>
>```
>该步骤基于二维矩阵 表
>1，创建数组，数组大小是元素的个数 arr[size] all 设置标志位（看是否访问过） //入队列的时候
>2.空队列（队列中存放的是顶点的编号)
>3,从图的起点a[0]出发 如果 a[0][1] 为真1入队列，检查arr[1]是否为0 如果为0 设置为1 并且入队列，说明访问过
>4,如果队列为空，继续访问，否则结束
>5，顶点出队列后，依次访问未被访问过的邻节点，标记并入队列
>```
>
>
>
>
>
>
>
>
>
>
>
>深度遍历 基于临接矩阵
>
>```c
>
>void DFS_AMG(struct AMG_graph * g){
>int i,x,y;
>int n=g->vex_num;
>int flag[n];
>for(i=0;i<n;i++)flag[i]=0;
>
>for(i=0;i<n;i++){   //防止漏掉没有边的节点
>   if(flag[i]==0){     //如果顶点没有被访问过
>       printf("%c->",g->Vex[i]);
>       flag[i]=1;
>       push(i);        //第一个先入展
>       while(!isEmpty()){
>           x=stack[top-1];//先等于栈顶元素
>           for(y=0;y<n;y++){
>               if(g->Edge[x][y]==1 && flag[y]==0){
>                   printf("%c->",g->Vex[y]);
>                   flag[y]=1;
>                   push(y);        
>                   break;          //找到一个节点了，断掉循环，下一次循环会等于改节点 
>               }
>           }
>           if(y==n)  //说明栈顶的元素没有边。应该栈了
>               pop();
>
>       }
>
>   }
>}}
>```
>
>深度遍历 基于临接表
>
>```c
>void DeepFirstTraverse(struct ALG_graph *graph){
>    //return;
>    int i;
>    int x,y;
>    int n=graph->vex_num;
>    int flag[n];
>    for(i=0;i<n;i++)
>        flag[i]=0;
>
>    struct AdjNode *pnode;
>
>
>    for(i=0;i<n;i++){  //防止没有边的节点
>        if(flag[i]==0){
>            flag[i]=1;  //设置标志位
>            push(i);		//该索引入栈
>            printf("%c ->",graph->Vex[i].node); //打印节点
>            while(!isEmpty()){				//栈不为空
>                x=stack[top-1];				//取出栈顶索引
>                pnode=graph->Vex[x].first; 	//到栈顶的那一行
>
>
>
>                while(pnode){				
>                    if(flag[pnode->index]==0){//如果不为空,第一个临接点就如栈 已经设置标志位的节点不算
>                        flag[pnode->index]=1;
>                        printf("%c ->",graph->Vex[pnode->index].node);//打印值
>                        push(pnode->index);
>                        break;
>
>                    }
>                    pnode=pnode->next;  //更新节点
>                }
>                if(pnode==NULL) //没有临接点，就出战 //轮到下一个栈顶了
>                    pop();
>
>            }
>
>        }
>    }
>
>
>
>
>}
>```
>
>

### 图的最短距离

>
>
>#### 寻找图中两个顶点的最短距离
>
>要计算两个在无向图或有向图中的顶点之间的最短路径，我们需要使用图形算法。最著名且常用于此任务的算法是Dijkstra和Floyd-Warshall算法。
>
>#### Dijkstra（迪杰斯特拉）算法
>
>Dijkstra算法是解决加权图中单源最短路径问题的典型算法（一个顶点到其他顶点的最短路径）。算法通过不断扩展最短路径来搜索其余的顶点。
>
>具体实现可以参考如下代码：
>
>CopyInsertNew
>
>```c
>#include<stdio.h>
>#include<limits.h>
>
>#define V 6
>
>//寻找未被确定的距离数组中距离source最小的下标
>int minDistance(int dist[], bool sptSet[]) {
>int min = INT_MAX, min_index;
>for(int v = 0; v < V; v++) 
>   if(sptSet[v] == false && dist[v] <= min)
>       min = dist[v], min_index = v;
>return min_index;
>}
>
>//打印所有的距离
>void printSolution(int dist[]) {
>printf("Vertex Distance from Source\n");
>for(int i = 0; i < V; i++)
>   printf("%d\t%d\n",i,dist[i]);
>}
>
>void dijkstra(int graph[V][V], int src) {
>int dist[V];
>bool sptSet[V];
>for(int i = 0; i < V; i++)
>   dist[i] = INT_MAX,sptSet[i]=false;
>dist[src] = 0;
>for(int count=0;count<V-1;count++){
>   int u = minDistance(dist,sptSet);
>   sptSet[u] = true;  
>   for(int v = 0 ; v < V ; v++)
>       if(!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
>           dist[v] = dist[u]+graph[u][v];
>
>}
>printSolution(dist);  
>}
>
>int main() {
>int graph[V][V]={{0,2,0,6,0,0},
>                {2,0,3,8,5,0},
>                {0,3,0,0,7,0},
>                {6,8,0,0,9,10},
>                {0,5,7,9,0,1},
>                {0,0,0,10,1,0}};
>dijkstra(graph, 0);
>return 0;
>}   
>```
>
>### 自己写的代码方便理解
>
>```c
>/* 最短路径 */
>#include <stdio.h>
>#include <stdbool.h>
>#include <limits.h>
>
>
>#define V 6
>
>enum choice{A,B,C,D,E,F};
>
>
>int graph[V][V]=    {{0,2,0,6,0,0},         //定点图
>                    {2,0,3,8,5,0},
>                    {0,3,0,0,7,0},
>                    {6,8,0,0,9,10},
>                    {0,5,7,9,0,1},
>                    {0,0,0,10,1,0}};
>
>
>int temp_arr[V];            //结果数组
>bool flag[V];               //标志为数组
>
>
>void Init(){                //初始化数组
>    for(int i=0;i<V;i++){
>        temp_arr[i]=INT_MAX;flag[i]=false;      //结果数组 全部更新为最大值，标志为全为false 代表未访问过
>    }
>        
>}
>
>void printRestult(){                            //打印结果值
>    for(int i=0;i<V;i++)
>        printf("%d\t%d\n",i,temp_arr[i]);
>    
>}
>
>int getMinIndex(){                              //只是得到未访问过而且是最小值 的索引
>    int min=INT_MAX;                            //用之前必须把第一个点 自己到自己的距离为0 从第一个开始找
>    int minIndex=V;
>    for(int i=0;i<V;i++){
>        if(!flag[i] && temp_arr[i] < min){
>            min=temp_arr[i];
>            minIndex = i;
>        }
>    }
>    return minIndex;
>}
>
>
>int main(){
>    int choice=1;                           //要寻找的最小值
>    int count=V;                              //便利用而已
>    Init();  //初始化两个数组
>    temp_arr[choice]=0;
>    while(count--){
>        int minindex=getMinIndex();
>        flag[minindex]=true;
>        for(int i=0;i<V;i++){
>            if(!flag[i] && graph[minindex][i] && graph[minindex][i]+temp_arr[minindex] < temp_arr[i])
>                temp_arr[i]=graph[minindex][i]+temp_arr[minindex];
>        } //如果为访问过的索引，而且从从索引开始不断的更新最小值，并且不标记,等下一次count开始便利的时候，找出这个最小值的索引
>            // 上一个最小索引是 minindex  minindex再次作为横坐标，去寻找一个点
>            //如果存在一个点 数组[minindex] + graph[minindex][y] < 数组[y] 会不断的更新 数组[y]的值，让其越来越小,并且作为下次 的最小索引
>        
>    }
>    printRestult();
>    
>};
>
>```
>
>
>
>#### Floyd-Warshall 算法
>
>Floyd-Warshall算法 是在给定负边缘的情况下计算带权图的所有最短路径的一种算法。该算法通常应用于跳板中转网络（Multihop Networks），因为它仅需所有节点对之间的边关系（path）即可。
>
>具体实现可以参考如下代码：
>
>CopyInsertNew
>
>```c
>#include<stdio.h> 
>
>#define V 4 
>#define INF 99999 
>
>void printSolution(int dist[][V]) {
>printf ("The following matrix shows the shortest distances"
>       " between every pair of vertices \n"); 
>for (int i = 0; i < V; i++) {
>   for (int j = 0; j < V; j++) {
>       if (dist[i][j] == INF) printf("%7s", "INF");
>       else printf ("%7d", dist[i][j]); 
>   }
>   printf("\n"); 
>}
>}
>
>void floydWarshall (int graph[][V]) { 
>int dist[V][V];//初始化结果矩阵
>for (int i = 0; i < V; i++) 
>   for (int j = 0; j < V; j++) 
>       dist[i][j] = graph[i][j]; 
>
>for (int k = 0; k < V; k++){ //逐渐增加路径长度进行更新
>   for (int i = 0; i < V; i++){ 
>       for (int j = 0; j < V; j++) {
>           // 如果k作为新路径比原路径更优，则更新值
>           if (dist[i][k] + dist[k][j] < dist[i][j]) 
>```







# 数据结构的查找





### 线性表的查找

> 
>
> 查找无序列链表
>
>```c
>//哨兵思想，现在最后添加想找的元素
>//在线性表里面查找如果 是查找的元素就返回  
>//如果返回结果是最后一个元素 则说明没找到
>int sqsearch(int *p,int n,int find){
>	p[n]=find;
>	int i=0;
>	while(p[i] !=find) i++;
>	return i;
>}
>```
>
>递归二分查找算法,只能对已经排序好的线性表进行操作
>
>```c
>//递归二分查找算法 应该提前设置好终止循环的条件
>int binary_search(int *p,int first,int last,int find){
>
>	if(first > last)
>		return -1;
>	int middle= (first+last)/2;
>
>	if(p[middle] == find)
>			return middle;
>	else if(p[middle] > find)
>			return binary_search(p,middle+1,last,find);
>	else
>			return binary_search(p,first,middle-1,find);
>
>
>}
>```
>
> 





