#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum{
    white, 
    gray, 
    black
}color_of_node;

struct vertex{
    color_of_node color;
    int discover_time;
    int finish_time;
    int pi;
};

void DFS_VISIT(int graph[6][6], struct vertex node[6], int u, int time){
    printf("%d ", u);
    time++;
    node[u].discover_time = time;
    node[u].color = gray;
    for (int i = 0; i<6;i++){
        if (node[i].color == white){
            node[i].pi = u;
            DFS_VISIT(graph, node, i, time);
        }
    }
    node[u].color = black;
    time++;
    node[u].finish_time = time;
}

void DFS(int graph[6][6]){
    struct vertex node[6];
    int time = 0;
    for (int i = 0; i< 6;i++){
        node[i].color = white;
        node[i].discover_time = 0;
        node[i].finish_time = 0;
        node[i].pi = -1;
    }
    for (int i = 0; i< 6;i++){
        if (node[i].color == white)
            DFS_VISIT(graph, node, i, time);
    }

}


int main(){
    // adjacency matrix
    int graph[6][6] = { {0, 1, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0},
                        {1, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0}
                        };
    DFS(graph);
    printf("\n");

    
    return 0;
}