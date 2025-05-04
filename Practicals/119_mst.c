#include <stdio.h>
#include <stdlib.h> 
#include<stdbool.h>
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
Graph* prims(Graph* graph) {
    bool inMST[7] = {false};
    int key[7];int parent[7];
    for (int i = 0; i < 7; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[0] = 0;
    for (int count = 0; count < 7 - 1; count++) {
        int minKey = INT_MAX, u = -1;
        for (int v = 0; v < 7; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        inMST[u] = true;
        Node* temp = graph->head[u];
        while (temp) {
            int v = temp->dest;
            if (!inMST[v] && temp->weight < key[v]) {
                key[v] = temp->weight;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }
    Graph* mstGraph = createGraph();
    for (int i = 1; i < 7; i++) {
        addEdge(mstGraph, parent[i], i, key[i]);
    }
    return mstGraph;
}
int main() {
    Graph* graph = createGraph();
    addEdge(graph, 0, 4, 6);
    addEdge(graph, 1, 4, 8);
    addEdge(graph, 4, 7, 3);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 2, 5, 6);
    addEdge(graph, 5, 6, 4);
    addEdge(graph, 1, 3, 7);
    printGraph(graph);
    Graph* MST = prims(graph);
    printf("Minimum Spanning Tree using Prim's Algorithm :\n");
    printGraph(MST);
}