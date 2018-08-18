#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    int vertex;
    struct node* next;
}node;

typedef struct Graph{
    int numVertices;
    struct node** adjLists;
}Graph;

node* createNode(int);
Graph* createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);

node *createNode(int v){
    node *newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
 
Graph *createGraph(int vertices){
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
 
    return graph;
}
 
void addEdge(Graph *graph, int src, int dest){
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
 
    // Add edge from dest to src
    /*
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
    */
}
 
void printGraph(Graph *graph){
    for (int v = 0; v < graph->numVertices; v++){
        node *temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp){
            printf("%d", temp->vertex);
            temp = temp->next;
            if (temp) printf(" -> ");
        }
        printf("\n");
    }
}



void BellmanFord(Graph *graph, int cost[5][5], int start){
    // find input vertices 
    Graph *input_vertices = createGraph(graph->numVertices);
    for (int i = 0; i<graph->numVertices; i++){
        node *v = graph->adjLists[i];
        while (v){
            addEdge(input_vertices, v->vertex, i);
            v = v->next;
        }
    }
    
    int *Dist = cost[start];
    int Dist_prev[5];
    for (int i = 0; i<5; i++)
        Dist_prev[i] = Dist[i];
    
    printf("k=%d ", 1);
    for (int i = 0; i<graph->numVertices; i++)
        printf("%d ", Dist[i]);
    printf("\n");
    
    for (int k = 2; k<graph->numVertices; k++){
        for (int i = 0; i<graph->numVertices; i++){
            // find u (source is i)
            node *u = input_vertices->adjLists[i];
            int min = Dist_prev[i];
            while (u){
                if (Dist_prev[i] > Dist_prev[u->vertex] + cost[u->vertex][i]){
                    if (Dist_prev[u->vertex] + cost[u->vertex][i] < min)
                        min = Dist_prev[u->vertex] + cost[u->vertex][i];
                }
                u = u->next;
            }
            Dist[i] = min;
        }
        
        printf("k=%d, ", k);
        for (int i = 0; i<graph->numVertices; i++)
            printf("%d ", Dist[i]);
        printf("\n");
        
        for (int i = 0; i<5; i++)
            Dist_prev[i] = Dist[i];
    }
}


int main(){
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 1);
    int INI = 30000;
    int cost[5][5] = {
                    {0,  6, 7,INI,INI},
                    {INI,0, 8, -4, 5 },
                    {INI,INI,0, 9, -3},
                    {INI,INI,INI,0, 7},
                    {INI,-2,INI,INI,0}
                     };
    //printGraph(graph);
    BellmanFord(graph, cost, 0);
 
    return 0;
}