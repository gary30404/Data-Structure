#include <stdio.h>
#include <stdlib.h>

// define data type
typedef struct stack{
    int Data;
    struct stack *next;
}stack;

stack *s1;
stack *s2;

// check if the stack is empty
int IsEmpty(stack **st){
    if (*st == NULL)
        return 1;
    return 0;
}

void push(stack **st, int data){
    // request space for new 
    stack *new_node = (stack *)malloc(sizeof(stack));
    
    // save the data to the new node
    new_node->Data = data;
    new_node->next = NULL;
    
    // push to the stack
    if (IsEmpty(st) == 1){
        *st = new_node;
    }
    else{
        new_node->next = *st; // the origin head is the older node
        *st = new_node; // the lastest data is the top node
    }
}

int pop(stack **st){
    stack *temp = *st;
    if (IsEmpty(st) == 1){
        printf("The stack is empty.\n");
        return -100;
    }
    else{
        *st = temp->next;
    }
    return temp->Data;
}

void enqueue(int data){
    push(&s1, data);
}

int dequeue(){
    int output;
    if (IsEmpty(&s1) == 1){
        printf("The stack is empty.\n");
        return 0;
    }
    else{
        while(IsEmpty(&s1)!=1) 
            push(&s2, pop(&s1));
        output = pop(&s2);
        while(IsEmpty(&s2)!=1) 
            push(&s1, pop(&s2));
        return output; 
    }
    return -1;
}

int main(){
    s1 = (stack *)malloc(sizeof(stack));
    s2 = (stack *)malloc(sizeof(stack));
    s1 = s2 = NULL;
    printf("Enqueue: 1,\t2,\t3\n");
    enqueue(1); enqueue(2); enqueue(3);
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Enqueue: 4\n");
    enqueue(4);
    printf("Dequeue: %d\n", dequeue());
    return 0;
}


