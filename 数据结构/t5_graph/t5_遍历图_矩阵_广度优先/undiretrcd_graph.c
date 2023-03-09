#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"


#define MAX 100
// extern int qsize;
//extern int *Queue;


//临接矩阵
struct AMG_graph{
    int vex_num;
    int edge_num;         //顶点个数和 边的个数
    char Vex[MAX];                //顶点的数组
    int Edge[MAX][MAX];        //边的关系 用二维矩阵

};

struct AMG_graph * Create_AMG_Graph(void);//
void ShowGraph(struct AMG_graph * graph);//显示
int seach_vex(struct AMG_graph * gp,char ch);//找索引

void BFS_AMG(struct AMG_graph * g);

int main(){
    struct AMG_graph *MyGraph;

    MyGraph=Create_AMG_Graph();
    ShowGraph(MyGraph); 
    // for(int i=0;i<QMAX;i++){
    //     printf("%d->",Queue[i]);
    // }

    printf("用广度优先遍历:");
    BFS_AMG(MyGraph);


    return 0;
}



struct AMG_graph *Create_AMG_Graph(){
    int i,j;
    char u,v;
    struct AMG_graph *graph;
    int ev;
    graph=(struct AMG_graph *)malloc(sizeof(struct AMG_graph));
    printf("please enter the number of vex:"); //顶点个数
    scanf("%d",&graph->vex_num);
    printf("please enter the number of edge:"); //顶点个数
    scanf("%d",&graph->edge_num);
    ev=graph->edge_num;
    
    while(getchar() !='\n');
    printf("enter the vex value:\n");
    
    for(i=0;i<graph->vex_num;i++){  //填充顶点
        graph->Vex[i]=getchar();
        while(getchar() !='\n');
    }
    
    for(i=0;i<graph->vex_num;i++)       //清空二维数组
        for(j=0;j<graph->vex_num;j++)
            graph->Edge[i][j]=0;
    
    while(ev--){
        printf("please enter the vex that connect each other:\n");
        u=getchar();
        while(getchar()!='\n');
        printf("please enter the anther:\n");
        v=getchar();
        while(getchar()!='\n');
        i=seach_vex(graph,u);
        j=seach_vex(graph, v);
        assert(i>-1);
        assert(j>-1);
        graph->Edge[i][j]=1;        //有向图 两个都设置为1  
        //graph->Edge[j][i]=1;        //如果该表是有向图，去掉这一个就行了
    }

    
    return graph;

}

void ShowGraph(struct AMG_graph * graph){
    int i,j;
    printf("Show info:------\n");
    printf("Vec : %d ,Graph:%d \n",graph->vex_num,graph->edge_num);
    printf("The vec:------\n");
    for(i=0;i<graph->vex_num;i++){
        printf("%c\t",graph->Vex[i]);
    }
    printf("\n");
    //printf("The Edge:------\n");
    for(i=0;i<graph->vex_num;i++){
        for(j=0;j<graph->vex_num;j++){
                printf("[%d]\t",graph->Edge[i][j]);
        }
        printf("\n");
        
    }

    
    printf("\n");
          
    
}

int seach_vex(struct AMG_graph * gp,char ch){
    int i;
    for(i=0;i<gp->vex_num;i++){
        if(ch==gp->Vex[i])
            return i;
    }
    return -1;
}

void BFS_AMG(struct AMG_graph * g){
    int flag[MAX]={0};
    int n=g->vex_num;
    int ni;
    enqueue(0);  //第一个元素进队列
    printf("%c ->",g->Vex[0]);
    flag[0]=1;

    while(!isEmpty()){
        ni=dequeue();
        for(int i=0;i<n;i++){
            if(g->Edge[ni][i]==1 && flag[i]==0)
            {
                flag[i]=1;
                printf("%c ->",g->Vex[i]);
                enqueue(i);
            }

        }

    }




}

