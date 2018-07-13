#include <stdio.h>
#include <stdlib.h>

// define data type
typedef struct queue{
    int Data;
    struct queue *next;
}queue;

// front of the queue, which points to the first
// back of the queue, which points to the end
queue *front;
queue *rear;

// create queue
void create_queue(){
    front = NULL;
    rear = NULL;
}

// check if the queue is empty
int isEmpty(){
    if (rear == NULL && front == NULL)
        return 1;
    return 0;
}

void enqueue(int data){
    // request space for new node
    queue *new_node = (queue *)malloc(sizeof(queue));
    
    // save the data to the new node
    new_node->Data = data;
    new_node->next = NULL;
    
    // push to the back of the queue
    if (isEmpty() == 1){
        front = new_node;
        rear = front;
    }
    else{
        rear->next = new_node; // next of the rear node points to new node
        rear = new_node;
    }
}

int dequeue(){
    if (isEmpty() == 1){
        printf("The queue is empty.\n");
        return 0;
    }
    else{
        queue *output = front;
        front = front->next; // the older data
        return output->Data; // return the top node
    }
    return -1;
}

void push(int data){
    enqueue(data);
}

int pop(queue *q){
    queue *temp = q;
    if (q == NULL)
        printf("The stack is empty.\n");
    else{
        int ln = 0;
        while(q != NULL){
            ln++;
            q = q->next;
        }
        for (int i = 0; i<ln-1; i++){
            int t = dequeue();
            enqueue(t);
        }
    }
    return dequeue();
}

int main(){
    front = (queue *)malloc(sizeof(queue));
    create_queue();
    printf("Push: 1, 2, 3\n");
    push(1);
    push(2);
    push(3);
    printf("Pop: %d\n", pop(front));
    printf("Pop: %d\n", pop(front));
    printf("Push: 4, 5\n");
    push(4);
    push(5);
    printf("Pop: %d\n", pop(front));

    return 0;
}


