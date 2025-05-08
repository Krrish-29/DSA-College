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
int minDistance(int distance[], bool visitedNodes[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < 7; v++)
        if (!visitedNodes[v] && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}
void dijkstra(Graph* graph, int src) {
    int distance[7];
    bool visitedNodes[7];
    for (int i = 0; i < 7; i++) {
        distance[i] = INT_MAX;
        visitedNodes[i] = false;
    }
    distance[src] = 0;
    for (int count = 0; count < 7 - 1; count++) {
        int u = minDistance(distance, visitedNodes);
        visitedNodes[u] = true;
        Node* temp = graph->head[u];
        while (temp != NULL) {
            int v = temp->dest;
            if (!visitedNodes[v] && distance[u] != INT_MAX && distance[u] + temp->weight < distance[v]) {
                distance[v] = distance[u] + temp->weight;
            }
            temp = temp->next;
        }
    }
    printf("Vertex     Distance from %d\n", src);
    for (int i = 0; i < 7; i++)
        printf(" %d             %d\n", i, distance[i]);
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
    printf("Graph:\n");printGraph(graph);
    printf("\nShortest Path According to Djikstra Algorithm:\n");dijkstra(graph,0);
}