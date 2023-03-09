#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


#define MAX 100

//临接矩阵
struct AMG_graph{
    int vex_num;
    int edge_num;         //顶点个数和 边的个数
    char Vex[MAX];                //顶点的数组
    int Edge[MAX][MAX];        //边的关系 用二维矩阵

};

double dist[MAX][MAX]; //最短距离
int p[MAX][MAX]; //最短距离

struct AMG_graph * Create_AMG_Graph(void);//
void ShowGraph(struct AMG_graph * graph);//显示
int seach_vex(struct AMG_graph * gp,char ch);//找索引

void floyd(struct AMG_graph* graph);//算法

int main(){
    struct AMG_graph *MyGraph;
    char start,end;
    int s,e;

    MyGraph=Create_AMG_Graph();
    ShowGraph(MyGraph);
    printf("After floyd......\n");
    floyd(MyGraph);
    ShowGraph(MyGraph);


    printf("输入两个最短距离的元素:\n");
    start=getchar();
    while(getchar() !='\n');
    end=getchar();
    //while(getchar() !='\n');

    //scanf("%c %c",&start,&end);
    //while(getchar() !='\n');
    s=seach_vex(MyGraph,start);
    e=seach_vex(MyGraph,end);
    printf("元素 %c 到 %c 之间最短的距离是 %.2lf:",start,end,dist[s][e]);





    // while(scanf("%c %c",&start,&end) && (s=seach_vex(MyGraph,start)) && (e=seach_vex(MyGraph,end)) && (s !=-1) && (e !=-1)){
    //     printf("元素 %c 到 %c 之间最短的距离是 %.2lf:",start,end,dist[s][e]);
    //     printf("输入两个最短距离的元素:\n");
    // }



    return 0;
}



struct AMG_graph *Create_AMG_Graph(){
    int i,j;
    double value;
    char u,v;
    struct AMG_graph *graph;
    int edge_count;//边的数量
    graph=(struct AMG_graph *)malloc(sizeof(struct AMG_graph));
    printf("please enter the number of vex:"); //顶点个数
    scanf("%d",&graph->vex_num);
    printf("please enter the number of edge:"); //顶点个数
    scanf("%d",&graph->edge_num);
    
    while(getchar() !='\n');
    printf("enter the vex value:\n");
    
    for(i=0;i<graph->vex_num;i++){  //填充顶点
        graph->Vex[i]=getchar();
        while(getchar() !='\n');
    }
    
    for(i=0;i<graph->vex_num;i++)
    {        //清空二维数组
        for(j=0;j<graph->vex_num;j++)
        {
            graph->Edge[i][j]=0;

            if(i==j)
                dist[i][j]=0; //初始化最短距离 自己到自己是0
            else
                dist[i][j]=INFINITY; //默认不连通 等于无穷大

            p[i][j]=-1; //前驱点的距离

        }
            
    }
    edge_count=graph->edge_num;
    
    while(edge_count--){
        printf("please enter the vex that connect each other:\n");
        u=getchar();
        while(getchar()!='\n');
        printf("please enter the anther:\n");
        v=getchar();
        while(getchar()!='\n');

        printf("请输入 %c 到 %c 的距离:\n",u,v);
        //v=getchar();
        scanf("%lf",&value);
        while(getchar()!='\n');
        i=seach_vex(graph,u);
        j=seach_vex(graph, v);
        assert(i>-1);
        assert(j>-1);

        if(i !=-1 && j !=-1){
              graph->Edge[i][j]=value;        //有向图 两个都设置为1  
              dist[i][j]=value; //更新最短距离
              p[i][j]=i;        //更新前驱点 前驱点为自己

        }else{
            printf("Input Error,please try again\n");
            edge_count++;  //加一次次机会

        }


      
        
    }

    
    return graph;

}

void ShowGraph(struct AMG_graph * graph){
    int i,j;

    printf("Show info:------------------------------\n");
    printf("Vec : %d ,Graph:%d \n",graph->vex_num,graph->edge_num);
    printf("The vec:------\n");
    for(i=0;i<graph->vex_num;i++){
        printf("%c\t",graph->Vex[i]);
    }
    printf("\n");
    //printf("The Edge:------\n");
    for(i=0;i<graph->vex_num;i++){
        for(j=0;j<graph->vex_num;j++){
                printf("[%3d]\t",graph->Edge[i][j]);
        }
        printf("\n");
        
    }

    
    printf("\n");

    printf("--------------------\n");
    printf("---Show  距离--------\n");
    for(i=0;i<graph->vex_num;i++){
        printf("%c\t",graph->Vex[i]);
    }
    printf("\n");
    for(i=0;i<graph->vex_num;i++){
    for(j=0;j<graph->vex_num;j++){
            printf("[%3.0lf]\t",dist[i][j]);
    }
    printf("\n");
        
    }


    printf("--------------------\n");

    printf("--------------------\n");
    printf("---Show  前驱点------\n");
    for(i=0;i<graph->vex_num;i++)
    {
        printf("%c\t",graph->Vex[i]);
    }

    printf("\n");

    for(i=0;i<graph->vex_num;i++){
        for(j=0;j<graph->vex_num;j++){
                printf("[%3d]\t",p[i][j]);
        }
        printf("\n");
        
    }
    printf("--------------------\n");
          
    
}

int seach_vex(struct AMG_graph * gp,char ch){
    int i;
    for(i=0;i<gp->vex_num;i++){
        if(ch==gp->Vex[i])
            return i;
    }
    return -1;
}

void floyd(struct AMG_graph* graph){
    int k;
    int i,j;
    for(k=0;k<graph->vex_num;k++){
        for(i=0;i<graph->vex_num;i++){
            for(j=0;j<graph->vex_num;j++){
                if(dist[i][j] > dist[i][k] +dist[k][j])
                {

                    dist[i][j]=dist[i][k] +dist[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }



    }

}


