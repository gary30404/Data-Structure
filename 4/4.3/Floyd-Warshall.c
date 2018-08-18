#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FloydWarshall(int cost[3][3]){

    for (int k = 0; k<3; k++){
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if (cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}


int main(){

    int INI = 30000;
    int cost[3][3] = {
                    {0, 4, 11},
                    {6, 0, 2},
                    {3, INI,0}
                     };
    //printGraph(graph);
    FloydWarshall(cost);
 
    return 0;
}