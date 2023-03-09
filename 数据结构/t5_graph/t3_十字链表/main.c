//
//  main.c
//  MyDataStruct
//
//  Created by macbookpro on 2023/2/24.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef char ValueType;

struct node{//
//  main.c
//  MyDataStruct
//
//  Created by macbookpro on 2023/2/24.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef char ValueType; //定义顶点的基本数据类型

struct node{
int outIndex;
int inIndex;
struct node *Pin; //开始节点指针
struct node *Pout;   //到达节点指针
};

struct asimple{             //单个顶点的值|到达这个顶点的值 的节点指针｜
ValueType value;
struct node *firstIn;
struct node *firstOut;
};

struct VecTable{
int VecNum;
int EdgeNum;
struct asimple arr[SIZE]; //数组默认100个 不要超出这个范围
};


struct VecTable *CreateVecTable(int vn,int en); //初始化结构 有默认值
void Init(struct VecTable * p);//初始化结构呗

int FindIndex(struct VecTable* p,ValueType ch);//找索引
ValueType FindValue(struct VecTable* p,int index ); //找值

void VecAddNode(struct VecTable* p,int out,int in); //添加边

void DisplayInOut(struct VecTable* p,ValueType ch);//显示查询的值


int main() {
ValueType vt = 'c';
struct VecTable *mygraph=CreateVecTable(5,7);
do{
   DisplayInOut(mygraph,vt);
   printf("please enter the check value｜输入要查询的元素(# to quit):");
   vt=getchar();
   while(getchar()!='\n');
}while(vt !='#');




return 0;
}

struct VecTable *CreateVecTable(int vn,int en){
int i;
ValueType in,out;
int inIndex,outIndex;
struct VecTable *p=(struct VecTable *)malloc(sizeof(struct VecTable ));
Init(p);
p->VecNum=vn;
p->EdgeNum=en;
printf("Please enter the Vec element｜输入顶点元素:\n");
for(i=0;i<vn;i++){
   p->arr[i].value=getchar();//
   while(getchar() !='\n');
}
printf("Please enter the Edge｜开始输入边:\n");
for(i=0;i<en;i++){
   printf("From item｜输入边的起点:");
   out =getchar();
   while(getchar() !='\n');
   printf("arrivaled item｜输入边的重点:");
   in =getchar();
   while(getchar() !='\n');
   outIndex=FindIndex(p,out);
   inIndex=FindIndex(p,in);
   printf("DEBUG: out:%d,in:%d\n",outIndex,inIndex);
   if(outIndex != -1 && inIndex != -1 && outIndex != inIndex){
       VecAddNode(p,outIndex,inIndex);
   }else{
       printf("Entered Edge Error,Please try again!｜输入错误，重写再输入一次\n ");
       i--;
   }


}




return p;
}

void Init(struct VecTable * p){
p->VecNum=p->EdgeNum=0;
for(int i=0;i<SIZE;i++){
   p->arr[i].value=0;
   p->arr[i].firstIn =NULL;
   p->arr[i].firstOut =NULL;
}

}

int FindIndex(struct VecTable* p,ValueType ch){
int i;
for(i=0;i<p->VecNum;i++){
   if(p->arr[i].value ==ch)
       return i;
}
return -1;
}


void VecAddNode(struct VecTable* p,int out,int in){

struct node *pnode=(struct node *)malloc(sizeof(struct node));
pnode->outIndex = out;
pnode->inIndex = in;        //新建一个节点 开始｜到达｜开始指针｜到达指针

pnode->Pout =p->arr[out].firstOut;
pnode->Pin =p->arr[in].firstIn;

p->arr[out].firstOut=pnode;
p->arr[in].firstIn=pnode;

}


ValueType FindValue(struct VecTable* p,int index ) //找值
{
if(index < p->VecNum){
   return p->arr[index].value;
}else
   return '0';
}




void DisplayInOut(struct VecTable* p,ValueType ch){
int index=FindIndex(p,ch);
struct node *Pnode;
if(index != -1){
   printf("Value: %c\n",ch);
   Pnode = p->arr[index].firstIn;
   printf("IN index :");
   while(Pnode){
       printf("%d[%c] - > ",Pnode->outIndex,FindValue(p, Pnode->outIndex));
       Pnode=Pnode->Pin;
   }
   printf("\n");
   Pnode = p->arr[index].firstOut;
   printf("out index :");
   while(Pnode){
       printf("%d[%c] - > ",Pnode->inIndex,FindValue(p, Pnode->inIndex));
       Pnode=Pnode->Pout;
   }
   printf("\n");


}
else{
   printf("Find Error\n");
}


}

    int fIndex;
    int tIndex;
    struct node *Pfrom; //开始节点指针
    struct node *Pto;   //到达节点指针
};

struct asimple{
    ValueType value;
    struct node *firstIn;
    struct node *firstOut;
};

struct VecTable{
    int VecNum;
    int EdgeNum;
    struct asimple arr[SIZE];
};


struct VecTable *CreateVecTable(int vn,int en);
void Init(struct VecTable * p);


int main() {
    struct VecTable *mygraph=CreateVecTable(4,5);
    
    

    return 0;
}

struct VecTable *CreateVecTable(int vn,int en){
    int i;
    struct VecTable *p=(struct VecTable *)malloc(sizeof(struct VecTable ));
    Init(p);
    p->VecNum=vn;
    p->EdgeNum=en;
    for(i=0;i<vn;i++){
        p->arr[i].value=getchar();//
        while(getchar() !='\n');
    }
    
    
    return p;
}

void Init(struct VecTable * p){
    p->VecNum=p->EdgeNum=0;
    for(int i=0;i<SIZE;i++){
        p->arr[i].value=0;
        p->arr[i].firstIn =NULL;
        p->arr[i].firstOut =NULL;
    }
    
}
