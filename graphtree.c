#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Structure for a node in the adjacency list
struct Node {
int vertex;
struct Node* next;
};
// Structure for an adjacency list
struct Graph {
int numVertices;
struct Node** adjLists;
bool* visited;
};
// Function to create a new node
struct Node* createNode(int vertex) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
perror("Memory allocation failed");
exit(1);
}
newNode->vertex = vertex;
newNode->next = NULL;
return newNode;
}
// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
if (graph == NULL) {
perror("Memory allocation failed");
exit(1);
}
graph->numVertices = numVertices;
graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));
graph->visited = (bool*)malloc(numVertices * sizeof(bool));
if (graph->adjLists == NULL || graph->visited == NULL) {
perror("Memory allocation failed");
exit(1);
}
for (int i = 0; i < numVertices; i++) {
graph->adjLists[i] = NULL;
graph->visited[i] = false;
}
return graph;
}
// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
struct Node* newNode = createNode(dest);
newNode->next = graph->adjLists[src];
graph->adjLists[src] = newNode;
newNode = createNode(src);
newNode->next = graph->adjLists[dest];
graph->adjLists[dest] = newNode;
}
// Function to perform Depth-First Search (DFS) traversal
void DFS(struct Graph* graph, int vertex) {
graph->visited[vertex] = true;
printf("%d ", vertex);struct Node* adjList = graph->adjLists[vertex];
while (adjList != NULL) {
int neighbor = adjList->vertex;
if (!graph->visited[neighbor]) {
DFS(graph, neighbor);
}
adjList = adjList->next;
}
}
// Function to perform Breadth-First Search (BFS) traversal
void BFS(struct Graph* graph, int startVertex) {
int queue[graph->numVertices];
int front = 0, rear = 0;
graph->visited[startVertex] = true;
queue[rear++] = startVertex;
while (front < rear) {
int currentVertex = queue[front++];
printf("%d ", currentVertex);
struct Node* adjList = graph->adjLists[currentVertex];
while (adjList != NULL) {
int neighbor = adjList->vertex;
if (!graph->visited[neighbor]) {
graph->visited[neighbor] = true;
queue[rear++] = neighbor;
}
adjList = adjList->next;
}
}
}
int main() {
int numVertices = 6; // Change this to the number of vertices in your graph
struct Graph* graph = createGraph(numVertices);
// Add edges to the graph
addEdge(graph, 0, 1);
addEdge(graph, 0, 2);
addEdge(graph, 1, 3);
addEdge(graph, 1, 4);
addEdge(graph, 2, 4);
addEdge(graph, 3, 5);
addEdge(graph, 4, 5);
printf("DFS Traversal: ");
DFS(graph, 0);
// Reset visited flags
for (int i = 0; i < numVertices; i++) {
graph->visited[i] = false;
}
printf("\nBFS Traversal: ");
BFS(graph, 0);
printf("\n");
return 0;
}