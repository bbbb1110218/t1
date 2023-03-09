#include <stdio.h>
#include <stdlib.h>

//临接表中的边
struct Edge{
	int dest;
	struct Edge *next;
};


//临接表中的节点
struct Node{
	int id;
	struct Edge*edge;
};

//图
struct Graph{
	int num_nodes;
	struct Node *nodes;
};

//检查重复项目，如果变种存在该值 返回1 应该使用 !该函数()
int checkRepetition(struct Edge* edge,int checkNum){
	struct Edge *move=edge;
	while(move != NULL){
		if(move->dest ==checkNum)
			return 1;
		move=move->next;
	}
	return 0;
}


//创建一个新的图
struct Graph *createGraph(int num_nodes){
	struct Graph* graph=(struct Graph *)malloc(sizeof(struct Graph));
	graph->num_nodes=num_nodes;
	graph->nodes=(struct Node*)malloc(num_nodes *sizeof(struct Node));
	for(int i=0;i<num_nodes;i++){
		graph->nodes[i].id=i;
		graph->nodes[i].edge=NULL;
	}
	return graph;
}


//创建一个新的节点
struct Node* createNode(int id){
	struct Node *node=(struct Node*)malloc(sizeof(struct Node ));
	node->id=id;
	node->edge=NULL;
	return node;
}





//添加一条新边
void addEdge(struct Node *node, int dest){
	if(!checkRepetition(node->edge,dest)){
		struct Edge* edge=(struct Edge *)malloc(sizeof(struct Edge));
		edge->dest=dest;
		edge->next=node->edge;
		node->edge=edge;
	}

}


//向图中添加一条新边

void addGraphEdge(struct Graph *graph, int src, int dest){
	addEdge(&graph->nodes[src],dest);
}


void printGraph(struct Graph *graph){
	for(int i=0;i<graph->num_nodes;i++){
		printf("%d :",i);
		struct Edge *edge=graph->nodes[i].edge;
		while(edge !=NULL){
			printf("%d ",edge->dest);
			edge=edge->next;
		}
		printf("\n");
	}
	printf("\n");
}


void freeGraph(struct Graph *graph){
	for(int i=0;i<graph->num_nodes;i++){
		struct Edge* edge=graph->nodes[i].edge;
		while(edge !=NULL){
			struct Edge*temp=edge;
			edge=edge->next;
			free(temp);
		}
	}
	free(graph->nodes);
	free(graph);
}



int main() {
    struct Graph *graph = createGraph(4);
    addGraphEdge(graph, 0, 1);
    addGraphEdge(graph, 0, 2);
    addGraphEdge(graph, 1, 2);
    addGraphEdge(graph, 0, 2);//重复添加的
    addGraphEdge(graph, 2, 0);
    addGraphEdge(graph, 2, 3);
    addGraphEdge(graph, 3, 3);
    printGraph(graph);
    freeGraph(graph);
    return 0;
}

