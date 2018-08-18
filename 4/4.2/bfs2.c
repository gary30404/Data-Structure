#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// define data type
typedef struct queue{
    int *Data;
    int front;
    int rear;
    int MAX_SIZE;
}queue;

typedef enum {white, gray, black}color_of_node;
struct vertex{
    color_of_node color;
    int u_distance;
    int pi;
};

// queue param initialization
void create_queue(queue *qu, int size){
    qu->front = 0;
    qu->rear = -1;
    qu->MAX_SIZE = size - 1;
    qu->Data = (int *)malloc(sizeof(int) *size);
    for (int i = 0; i < size; i++){
        qu->Data[i] = 0;
    }
}

// check if the queue is empty
int IsEmpty(queue *qu){
    if (qu->rear == -1)
        return 1;
    return 0;
}

// check if the queue is full
int IsFull(queue *qu){
    if (qu->rear == qu->MAX_SIZE)
        return 1;
    return 0;
}

void enqueue(queue *qu, int data){

    if (IsFull(qu) == 1){
        printf("The queue is full.\n");
    }
    else{
        qu->Data[++qu->rear] = data;
    }
}

int dequeue(queue *qu){
    if (IsEmpty(qu) == 1){
        printf("The queue is empty.\n");
        return 0;
    }
    else{
        int output = qu->Data[qu->front];
        for (int i = 0;i < qu->rear; i++)
            qu->Data[i] = qu->Data[i+1];
        qu->Data[qu->rear] = 0;
        qu->rear--;
        return output;
    }
    return -1;
}


void BFS(int graph[8][8], int start){
    //initialize
    queue *q = (queue *)malloc(sizeof(queue));
    create_queue(q, 8);
    struct vertex node[8];
    for (int i = 0; i< 8;i++){
        node[i].color = white;
        node[i].u_distance = 0;
        node[i].pi = -1;
    }
    //start
    node[start].color = gray;
    node[start].u_distance = 0;
    node[start].pi = -1;
    enqueue(q, start);
    while(!IsEmpty(q)){
        int next = dequeue(q);
        printf("%d ", next);
        for (int i = 0; i<8; i++){
            if (graph[next][i] == 1 && node[i].color == white){
                node[i].color = gray;
                node[i].u_distance = node[next].u_distance+1;
                node[i].pi = next;
                enqueue(q, i);
            }
        }
        node[next].color = black;
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
    BFS(graph, 0);
    printf("\n");

    
    return 0;
}