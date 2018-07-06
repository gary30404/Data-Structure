#include <stdio.h>
#include <stdlib.h>

// define data type
typedef struct queue{
    int *Data;
    int front;
    int rear;
    int MAX_SIZE;
}queue;


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

int main(){
    queue *q = (queue *)malloc(sizeof(queue));
    printf("Create a queue which size is 5.\n");
    create_queue(q, 5);
    printf("Enqueue: 1,\t2,\t3\n");
    enqueue(q, 1); enqueue(q, 2); enqueue(q, 3); 
    // print the queue
    for (int i = q->front; i <= q->rear; i++){
        printf("%d\t", q->Data[i]);
    }
    printf("\n");
    printf("Enqueue: 4,\t5\n");
    enqueue(q, 4); enqueue(q, 5);
    for (int i = q->front; i <= q->rear; i++){
        printf("%d\t", q->Data[i]);
    }
    printf("\n");
    printf("Dequeue, the front is: %d\n", dequeue(q));
    printf("Dequeue, the front is: %d\n", dequeue(q));
    for (int i = q->front; i <= q->rear; i++){
        printf("%d\t", q->Data[i]);
    }
    printf("\n");
    return 0;
}


