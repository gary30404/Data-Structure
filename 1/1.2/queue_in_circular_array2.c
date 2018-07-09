#include <stdio.h>
#include <stdlib.h>

// define data type
typedef struct queue{
    int *Data;
    int front;
    int rear;
    int tag;
    int MAX_SIZE;
}queue;


// queue param initialization
void create_queue(queue *qu, int size){
    qu->front = 0;
    qu->rear = 0;
    qu->tag = 0;
    qu->MAX_SIZE = size;
    qu->Data = (int *)malloc(sizeof(int) *size);
}


void enqueue(queue *qu, int data){

    if (qu->front == qu->rear && qu->tag == 1){
        printf("The queue is full.\n");
    }
    else{
        qu->rear = (qu->rear + 1) % qu->MAX_SIZE;
        qu->Data[qu->rear] = data;
        if (qu->front == qu->rear) qu->tag = 1;
    }
}

int dequeue(queue *qu){
    if (qu->front == qu->rear && qu->tag == 0){
        printf("The queue is empty.\n");
        return 0;
    }
    else{
        qu->front = (qu->front + 1) % qu->MAX_SIZE;
        if (qu->front == qu->rear) qu->tag = 0;
        return qu->Data[qu->front];
    }
    return -1;
}

int main(){
    queue *q = (queue *)malloc(sizeof(queue));
    printf("Create a queue which size is 5.\n");
    create_queue(q, 5);
    printf("Enqueue: 1,\t2,\t3\n");
    enqueue(q, 1); enqueue(q, 2); enqueue(q, 3); 
    // print the queue
    for (int i = q->front+1; i <= q->rear; i++){
        printf("%d\t", q->Data[i]);
    }
    printf("\n");
    printf("Enqueue: 4,\t5\n");
    enqueue(q, 4);
    for (int i = q->front+1; i <= q->rear; i++){
        printf("%d\t", q->Data[i]);
    }
    printf("\n");
    enqueue(q, 5);
    printf("Dequeue, the front is: %d\n", dequeue(q));
    printf("Dequeue, the front is: %d\n", dequeue(q));
    for (int i = q->front+1; i <= q->rear+q->MAX_SIZE; i++){
        printf("%d\t", q->Data[i%q->MAX_SIZE]);
    }
    printf("\n");
    return 0;
}


