#include <stdio.h>
#include <stdlib.h>

// define data type
typedef struct queue{
    int Data;
    struct queue *next;
}queue;

// back of the queue, which points to the end
queue *rear;

// create queue
void create_queue(){
    rear = NULL;
}

void enqueue(int data){
    // request space for new node
    queue *new_node = (queue *)malloc(sizeof(queue));
    
    // save the data to the new node
    new_node->Data = data;
    
    // push to the back of the queue
    if (rear == NULL){
        new_node->next = new_node;
    }
    else{
        new_node->next = rear->next;
        rear->next = new_node;
    }
    rear = new_node;
}

int dequeue(){

    queue *t = (queue *)malloc(sizeof(queue));

    if (rear == NULL){
        printf("The queue is empty.\n");
        return 0;
    }
    else{
        if (rear->next == rear){
            t = rear;
            rear = NULL;
            return t->Data;
        }
        else{
            t = rear->next;
            rear->next = t->next;
            return t->Data;
        }
    }
    return -1;
}

int main(){
    printf("Create a queue which size is 5.\n");
    create_queue();
    printf("Enqueue: 1,\t2,\t3\n");
    enqueue(1); enqueue(2); enqueue(3); 
    // print the queue
    queue *current_node = rear->next;
    while(current_node != rear){
        printf("%d\t", current_node->Data);
        current_node = current_node->next;
    }
    printf("%d\n", rear->Data);
    printf("Enqueue: 4,\t5\n");
    enqueue(4); enqueue(5);
    current_node = rear->next;
    while(current_node != rear){
        printf("%d\t", current_node->Data);
        current_node = current_node->next;
    }
    printf("%d\n", rear->Data);
    printf("Dequeue, the front is: %d\n", dequeue());
    printf("Dequeue, the front is: %d\n", dequeue());
    // print the queue
    current_node = rear->next;
    while(current_node != rear){
        printf("%d\t", current_node->Data);
        current_node = current_node->next;
    }
    printf("%d\n", rear->Data);
    return 0;
}


