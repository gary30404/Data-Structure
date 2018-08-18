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

typedef struct heap{
    int data;
    int vertex;
    struct heap *left;
    struct heap *right;
    struct heap *parent;
}heap;

typedef struct pair{
    int data;
    int vertex;
}pair;

node* createNode(int);
Graph* createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);
void build_heap(heap *rt, int *input);
heap *insert(heap *pt, int data, int index);
void adjust_bottom_up(heap *nd);
void adjust_top_down(heap *nd);
heap *get_next_parent(heap *rt);
heap *get_last_node(heap *rt);
int getHeight(heap *rt, int h);
int check(heap *rt);

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

void build_heap(heap *rt, int *input){
    heap *nd = malloc(sizeof(heap));
    heap *pt = malloc(sizeof(heap));
    pt = rt;
    for (int i = 1; i<8; i++){
        nd = insert(pt, input[i], i);
        adjust_bottom_up(nd);
        if (pt->left != NULL && pt->right !=NULL && pt->parent != NULL)
            pt = get_next_parent(pt->parent);
        else
            pt = get_next_parent(pt);
    }
}
heap *insert(heap *pt, int data, int index){
    heap *nd = malloc(sizeof(heap));
    nd->data = data;
    nd->vertex = index;
    nd->left = NULL;
    nd->right = NULL;
    if (pt->left == NULL) pt->left = nd;
    else pt->right = nd;
    nd->parent = pt;
    return nd;
}
heap *get_next_parent(heap *rt){
    heap *nd = malloc(sizeof(heap));
    nd = rt;
    if (rt->left == NULL || rt->right == NULL) return rt;
    int left_height = 0;
    int right_height = 0;
    left_height = getHeight(rt->left, left_height);
    right_height = getHeight(rt->right, right_height);
    if (left_height == right_height) return get_next_parent(rt->left);
    if (left_height > right_height)  return get_next_parent(rt->right);
    return NULL;
}

heap *get_last_node(heap *rt){
    heap *nd = malloc(sizeof(heap));
    nd = rt;
    if (rt->left == NULL) return rt;
    if (rt->right == NULL) return rt->left;
    int left_height = 0;
    int right_height = 0;
    left_height = getHeight(rt->left, left_height);
    right_height = getHeight(rt->right, right_height);
    if (left_height == right_height) return get_last_node(rt->right);
    if (left_height > right_height)  return get_last_node(rt->left);
    return NULL;
}

int getHeight(heap *rt, int h){
    if (rt->left != NULL) return getHeight(rt->left, h+1);
    if (rt->right != NULL) return getHeight(rt->right, h+1);
    return h;
}

void adjust_bottom_up(heap *nd){
    if (nd->parent == NULL) return;
    if (nd->parent->data > nd->data){
        int tmp_d = nd->parent->data;
        int tmp_i = nd->parent->vertex;
        nd->parent->data = nd->data;
        nd->parent->vertex = nd->vertex;
        nd->data = tmp_d;
        nd->vertex = tmp_i;
        adjust_bottom_up(nd->parent);
    }
}

void adjust_top_down(heap *nd){
    int tmp_d, tmp_i;
    if (nd == NULL) return;
    if (nd->left == NULL && nd->right == NULL) return;
    if (nd->left != NULL && nd->right == NULL){
        if (nd->data > nd->left->data){
            tmp_d = nd->left->data;
            tmp_i = nd->left->vertex;
            nd->left->data = nd->data;
            nd->left->vertex = nd->vertex;
            nd->data = tmp_d;
            nd->vertex = tmp_i;
        }
        return;
    }
    if (nd->right->data > nd->left->data){
        if (nd->data > nd->left->data){
            tmp_d = nd->left->data;
            tmp_i = nd->left->vertex;
            nd->left->data = nd->data;
            nd->left->vertex = nd->vertex;
            nd->data = tmp_d;
            nd->vertex = tmp_i;
            adjust_top_down(nd->left);
        }
    }
    else{
        if (nd->data > nd->right->data){
            tmp_d = nd->right->data;
            tmp_i = nd->right->vertex;
            nd->right->data = nd->data;
            nd->right->vertex = nd->vertex;
            nd->data = tmp_d;
            nd->vertex = tmp_i;
            adjust_top_down(nd->right);
        }
    }
}

pair *delete(heap *rt){
    if (rt->parent == rt) return NULL;
    heap *nd = malloc(sizeof(heap));
    heap *pt = malloc(sizeof(heap));
    pair *pr = malloc(sizeof(pair));
    pr->data = rt->data;
    pr->vertex = rt->vertex;
    nd = get_last_node(rt);
    rt->data = nd->data;
    rt->vertex = nd->vertex;
    // delete node
    pt = nd->parent;
    if (pt != NULL){ //prevent the last node segmaentation fault
        if (pt->left == nd) pt->left = NULL;
        else pt->right = NULL;
        nd->parent = NULL;
    }
    else{
        nd->parent = nd;
    }
    free(nd);
    adjust_top_down(rt);
    return pr;
}

int check(heap *rt){
    if (rt->parent == rt) return 0;
    else return 1;
}


void Dijkstras(Graph *graph, int cost[8][8], int start){
    int *s = cost[start];
    heap *rt = malloc(sizeof(heap));
    pair *pr = malloc(sizeof(pair));
    for (int i = 0; i< 8; i++)
        printf("%d ", s[i]);
    printf("\n");
    rt->data = s[0];
    rt->vertex = 0;
    rt->left = NULL;
    rt->right = NULL;
    rt->parent = NULL;
    build_heap(rt, s);
    while(check(rt)){
        pr = delete(rt);
        if (pr->data > s[pr->vertex]) pr->data = s[pr->vertex];
        node *temp = graph->adjLists[pr->vertex];
        while (temp){
            //relax
            if (s[temp->vertex]>pr->data+cost[pr->vertex][temp->vertex])
                s[temp->vertex] = pr->data+cost[pr->vertex][temp->vertex];
            temp = temp->next;
        }
    }
    for (int i = 0; i< 8; i++)
        printf("%d ", s[i]);
    printf("\n");
}


int main(){
    struct Graph* graph = createGraph(8);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 3);
    addEdge(graph, 5, 3);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 1);
    addEdge(graph, 1, 0);
    int INI = 30000;
    int cost[8][8] = {
                    {0,  INI,INI,INI,INI,INI,INI,INI},
                    {300,0,  INI,INI,INI,INI,INI,INI},
                    {1000,800,0,INI,INI,INI,INI,INI},
                    {INI,INI,1200,0,INI,INI,INI,INI},
                    {INI,INI,INI,1500,0,250,INI,INI},
                    {INI,INI,INI,1000,INI,0,900,1400},
                    {INI,INI,INI,INI,INI,INI,0,1000},
                    {1700,INI,INI,INI,INI,INI,INI,0}
                     };
    //printGraph(graph);
    Dijkstras(graph, cost, 4);
 
    return 0;
}