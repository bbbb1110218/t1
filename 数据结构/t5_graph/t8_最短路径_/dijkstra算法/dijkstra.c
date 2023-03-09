#include<stdio.h>
#include<limits.h>
#include <stdbool.h>
// #define bool int 
// #define true 1
// #define false 0

#define V 6

int minMinstance(int dist[],bool sptSet[]){
    int min=INT_MAX;
    int min_index;
    for(int v=0;v<V;v++){
        if(sptSet[v] == 0 && dist[v] <min){
            min=dist[v];
            min_index=v;
        }
    }

    return min_index;

}

void PrintSolution(int dist[]){
    printf("here is the solution:\n");
    for(int i=0;i<V;i++){
        printf("%d\t%d\n",i,dist[i]);
    }
    printf("\n");
}

void dijkstra(int graph[V][V],int src){
    int dist[V];
    bool sptSet[V];

    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }

    dist[src]=0;
    for(int count=0;count<V-1;count++){
        int u=minMinstance(dist,sptSet);
        sptSet[u]=true;
        for(int v=0;v<V;v++){
            if(!sptSet[v] && graph[u][v] && dist[u]+graph[u][v] < dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }

    }

    PrintSolution(dist);


    
}



int main() {
   int graph[V][V]={{0,2,0,6,0,0},
                    {2,0,3,8,5,0},
                    {0,3,0,0,7,0},
                    {6,8,0,0,9,10},
                    {0,5,7,9,0,1},
                    {0,0,0,10,1,0}};
   dijkstra(graph, 0);
   return 0;
}