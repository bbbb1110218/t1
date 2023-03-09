#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"


#define MAX 100

struct AMG_graph{
    int vex_num;
    int edge_num;         //顶点个数和 边的个数
    char Vex[MAX];                //顶点的数组
    int Edge[MAX][MAX];        //边的关系 用二维矩阵

};

struct AMG_graph * Create_AMG_Graph(void);//
void ShowGraph(struct AMG_graph * graph);//显示
int seach_vex(struct AMG_graph * gp,char ch);//找索引

void DFS_AMG(struct AMG_graph * g);

int main(){
    struct AMG_graph *MyGraph;

    MyGraph=Create_AMG_Graph();
    // ShowGraph(MyGraph); 
    // // for(int i=0;i<QMAX;i++){
    // //     printf("%d->",Queue[i]);
    // // }

    printf("用广度优先遍历:\n");
    DFS_AMG(MyGraph);


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

/*
struct AMG_graph{
    int vex_num;
    int edge_num;         //顶点个数和 边的个数
    char Vex[MAX];                //顶点的数组
    int Edge[MAX][MAX];        //边的关系 用二维矩阵

};*/

void DFS_AMG(struct AMG_graph * g){
    int i,x,y;
    int n=g->vex_num;
    int flag[n];
    for(i=0;i<n;i++)flag[i]=0;

    for(i=0;i<n;i++){   //防止漏掉没有边的节点
        if(flag[i]==0){     //如果顶点没有被访问过
            printf("%c->",g->Vex[i]);
            flag[i]=1;
            push(i);        //第一个先入展
            while(!isEmpty()){
                x=stack[top-1];//先等于栈顶元素
                for(y=0;y<n;y++){
                    if(g->Edge[x][y]==1 && flag[y]==0){
                        printf("%c->",g->Vex[y]);
                        flag[y]=1;
                        push(y);        
                        break;          //找到一个节点了，断掉循环，下一次循环会等于改节点 
                    }
                }
                if(y==n)  //说明栈顶的元素没有边。应该栈了
                    pop();

            }

        }
    }

        
    // for(x=0;x<n;x++){
    //     for(y=0;y<n;y++)
    //     {
    //         if(g->Edge[x][y]==1)
    //         {
    //             fuck=1;
    //             break;
    //         }

    //     }
    //     if(fuck)
    //         break;

    // }
    // flag[x]=1;
    // printf("%c -> ",g->Vex[x]);
    // push(x);





    // while(!isEmpty()){
    //     x=stack[top-1];
    //     for(;x<n;x++){
    //         for(y=0;y<n;y++){
    //             if(g->Edge[x][y]==1 && flag[y] ==0){
    //                 printf("%c ->",g->Vex[y]);
    //                 push(y);
    //                 flag[y]=1;
    //                 break;
    //             }

    //         }
    //         if(y==n)pop();

            
            
    //     }


    // }



}

