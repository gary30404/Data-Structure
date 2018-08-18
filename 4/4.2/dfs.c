#include <stdio.h>
#include <stdlib.h>
#include <string.h>





void DFS(int graph[8][8], int *visit, int start){
    printf("%d ", start);
    visit[start] = 1;
    for (int i = 0; i<8; i++){
        if (graph[start][i] == 1 && visit[i] == 0)
            DFS(graph, visit, i);
    }

}


int main(){
    // adjacency matrix
    int graph[8][8] = { {0, 1, 1, 0, 0, 0, 0, 0},
                        {1, 0, 0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 0, 0, 1, 1, 0},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 0, 1, 0, 0, 0, 0, 1},
                        {0, 0, 1, 0, 0, 0, 0, 1},
                        {0, 0, 0, 1, 1, 1, 1, 0}
                        };
    int visit[8] = {0};
    DFS(graph, visit, 0);
    printf("\n");

    
    return 0;
}