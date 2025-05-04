#include <stdio.h>
#include <stdlib.h> 
#include<stdbool.h>
typedef struct Node {
    int dest;
    int weight;
    struct Node* next;
} Node;
typedef struct Graph {
    Node* head[10];
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
    for (int i = 0; i < 10; i++)
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
    for (int i = 0; i < 10; i++) {
        Node* temp = graph->head[i];
        printf("Node %d -> ", i);
        while (temp) {
            printf("(%d, %d) -> ", temp->dest, temp->weight);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void breadthFirstSearch(Graph* graph, int start) {
    bool visited[10] = {false};
    int queue[10], front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;
    printf("BFS Traversal: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node* temp = graph->head[current];
        while (temp) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = true;
                queue[rear++] = temp->dest;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
void dfs(Graph* graph, int node, bool visited[]) {
    visited[node] = true;
    printf("%d ", node);
    Node* temp = graph->head[node];
    while (temp) {
        if (!visited[temp->dest]) {
            dfs(graph, temp->dest, visited);
        }
        temp = temp->next;
    }
}
void depthFirstSearch(Graph* graph, int start) {
    bool visited[10] = {false};
    printf("DFS Traversal: ");
    dfs(graph, start, visited);
    printf("\n");
}
int main() {
    Graph* graph = createGraph();
    addEdge(graph, 1, 4, 8);
    addEdge(graph, 4, 7, 3);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 2, 5, 6);
    addEdge(graph, 5, 9, 4);
    addEdge(graph, 1, 3, 7);
    printGraph(graph);
    breadthFirstSearch(graph, 1);
    depthFirstSearch(graph, 1);
}