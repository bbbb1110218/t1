#include <stdio.h>
#include <stdlib.h>

// 邻接表中的边
struct Edge {
    int dest;           // 目标节点的编号
    struct Edge *next;  // 指向下一个边的指针
};

// 邻接表中的节点
struct Node {
    int id;             // 节点的编号
    struct Edge *edge;  // 指向第一条边的指针
};

// 图
struct Graph {
    int num_nodes;      // 节点的数量
    struct Node *nodes; // 节点的数组
};

// 创建一个新的节点
struct Node *createNode(int id) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->id = id;
    node->edge = NULL;
    return node;
}

// 向节点的邻接表中添加一条边
void addEdge(struct Node *node, int dest) {
    struct Edge *edge = (struct Edge *) malloc(sizeof(struct Edge));
    edge->dest = dest;
    edge->next = node->edge;
    node->edge = edge;
}

// 创建一个新的图
struct Graph *createGraph(int num_nodes) {
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));
    graph->num_nodes = num_nodes;
    graph->nodes = (struct Node *) malloc(num_nodes * sizeof(struct Node));
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i].id = i;
        graph->nodes[i].edge = NULL;
    }
    return graph;
}

// 向图中添加一条边
void addGraphEdge(struct Graph *graph, int src, int dest) {
    addEdge(&graph->nodes[src], dest);
}

// 输出图的邻接表
void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d: ", i);
        struct Edge *edge = graph->nodes[i].edge;
        while (edge != NULL) {
            printf("%d ", edge->dest);
            edge = edge->next;
        }
        printf("\n");
    }
}

// 释放图的内存
void freeGraph(struct Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        struct Edge *edge = graph->nodes[i].edge;
        while (edge != NULL) {
            struct Edge *temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(graph->nodes);
    free(graph);
}

// 示例用法
int main() {
    struct Graph *graph = createGraph(4);
    addGraphEdge(graph, 0, 1);
    addGraphEdge(graph, 0, 2);
    addGraphEdge(graph, 1, 2);
    addGraphEdge(graph, 2, 0);
    addGraphEdge(graph, 2, 3);
    addGraphEdge(graph, 3, 3);
    printGraph(graph);
    freeGraph(graph);
    return 0;
}
