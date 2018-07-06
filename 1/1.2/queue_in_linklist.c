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
        free(output);
        return output->Data; // return the top node
    }
    return -1;
}

int main(){
    front = (queue *)malloc(sizeof(queue));
    printf("Create a queue which size is 5.\n");
    create_queue();
    printf("Enqueue: 1,\t2,\t3\n");
    enqueue(1); enqueue(2); enqueue(3); 
    // print the queue
    queue *current_node = front;
    while(current_node != NULL){
        printf("%d\t", current_node->Data);
        current_node = current_node->next;
    }
    printf("\n");
    printf("Enqueue: 4,\t5\n");
    enqueue(4); enqueue(5);
    current_node = front;
    while(current_node != NULL){
        printf("%d\t", current_node->Data);
        current_node = current_node->next;
    }
    printf("\n");
    printf("Dequeue, the front is: %d\n", dequeue());
    printf("Dequeue, the front is: %d\n", dequeue());
    // print the queue
    current_node = front;
    while(current_node != NULL){
        printf("%d\t", current_node->Data);
        current_node = current_node->next;
    }
    printf("\n");
    return 0;
}


