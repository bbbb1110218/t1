#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define MAX 100


struct AdjNode{  //临接表
    int index;              //顶点数组里面的索引
    struct AdjNode *next;
};

struct VexNode{     //顶点表
    char node;
    struct AdjNode *first;
    
};

struct ALG_graph{
    int vex_num;        //顶点个数
    int edge_num;       //边的个数
    struct VexNode Vex[MAX];    //顶点的数组 【顶点｜临接点第一个】
};

struct ALG_graph *CreateALGgraph();
int search_vex(struct ALG_graph * grap,char ch);  //找索引
void create_adj_node_list(struct ALG_graph *graph,int i,int j);//往节点表里面插入临节点
void Show_ALG_graph(struct ALG_graph *graph);//显示节点表和临节点表

int main(){
    struct ALG_graph *ugraph=CreateALGgraph();
    Show_ALG_graph(ugraph);
    
    return 0;
}


struct ALG_graph *CreateALGgraph(){
    int i,j;
    struct ALG_graph *graph;
    char u,v;

    graph =(struct ALG_graph *)malloc(sizeof(struct ALG_graph));
    
    printf("Please enter the number of vex|输入顶点个数:"); //顶点个数
    scanf("%d",&graph->vex_num);
    printf("Please enter the number of edge｜输入边的个数:"); //顶点个数
    scanf("%d",&graph->edge_num);
    
    while(getchar() !='\n');
    printf("Enter the vex value:\n");
    
    for(i=0;i<graph->vex_num;i++){  //填充顶点  //没有考虑输入重复的问题
        
        graph->Vex[i].node=getchar();
        graph->Vex[i].first=NULL;
       
        while(getchar() !='\n');
    }
    while(graph->edge_num--){
        printf("please enter the vex that connect each other|输入开始顶点:\n");
        u=getchar();
        while(getchar()!='\n');
        printf("please enter the anther｜到达顶点:\n");
        v=getchar();
        while(getchar()!='\n');
        i=search_vex(graph,u);
        j=search_vex(graph,v);
        if(i < 0 || j <0){ //没有考虑两次输入都是一样的问题
            printf("输入错误，再重写输入一次\n");
            graph->edge_num++;
            continue;
        }
        else{
            create_adj_node_list(graph,i,j);    //有向
            //create_adj_node_list(graph,j,i);    //相反加一条就成无向
        }
            
  
    }
    
    return graph;
    
}

int search_vex(struct ALG_graph * grap,char ch){
    int i;
    for(i=0;i<grap->vex_num;i++){
        if(grap->Vex[i].node==ch)
            return i;
    }
    return -1;
    
}

void create_adj_node_list(struct ALG_graph *graph,int i,int j){
    struct AdjNode *NewNode=(struct AdjNode *)malloc(sizeof(struct AdjNode ));
    NewNode->index=j;           //没有考虑两次节点都是一样的问题

    NewNode->next=graph->Vex[i].first;  //新节点的下一个节点 first节点
    graph->Vex[i].first=NewNode;        //first 等于新节点
}

void Show_ALG_graph(struct ALG_graph *graph){
//    int n=graph->vex_num;
    struct AdjNode *temp;
    printf("SHOW ALG_GRAPH\nVec count:%d\n",graph->vex_num);
    
    for(int i=0;i<graph->vex_num;i++){
        printf("VEC: %c ->",graph->Vex[i].node);
        temp=graph->Vex[i].first;               //临时节点等于first节点
        while(temp !=NULL){                     //当临时节点不等于空
            printf("%d -> ",temp->index);       //打印 节点表的索引
            temp=temp->next;                    //等于下一个节点
        }
        printf("\n");
    }
}

