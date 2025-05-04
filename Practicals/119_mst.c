#include <stdio.h>
#include <stdlib.h> 
typedef struct Node {
    int dest;
    int weight;
    struct Node* next;
} Node;
typedef struct Graph {
    Node* head[7];
} Graph;
Node* createNode(int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < 7; i++)
        graph->head[i] = NULL;
    return graph;
}
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
    newNode = createNode(src, weight);
    newNode->next = graph->head[dest];
    graph->head[dest] = newNode;
}
void printGraph(Graph* graph) {
    for (int i = 0; i < 7; i++) {
        Node* temp = graph->head[i];
        printf("Node %d -> ", i);
        while (temp) {
            printf("(%d, %d) -> ", temp->dest, temp->weight);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}