#include <stdio.h>
#include <stdlib.h>

// define data type
typedef struct stack{
    int Data;
    struct stack *next;
}stack;

// head of the stack, which points to the top
stack *top;

// create stack
void create_stack(){
    top = NULL;
}

// check if the stack is empty
int IsEmpty(){
    if (top == NULL)
        return 1;
    return 0;
}

void push(int data){
    // request space for new node
    stack *new_node = (stack *)malloc(sizeof(stack));
    
    // save the data to the new node
    new_node->Data = data;
    new_node->next = NULL;
    
    // push to the stack
    if (IsEmpty() == 1){
        top = new_node;
    }
    else{
        new_node->next = top; // the origin head is the older node
        top = new_node; // the lastest data is the top node
    }
}

int pop(){
    if (IsEmpty() == 1){
        printf("The stack is empty.\n");
        return 0;
    }
    else{
        stack *output = top;
        top = top->next; // the older data
        return output->Data; // return the top node
    }
    return -1;
}

int main(){
    top = (stack *)malloc(sizeof(stack));
    printf("Create a stack which size is 5.\n");
    create_stack();
    printf("Push: 1,\t2,\t3,\t4,\t5\n");
    push(1); push(2); push(3); push(4); push(5);
    // print the stack
    stack *current_node = top;
    while(current_node != NULL){
        printf("%d\t", current_node->Data);
        current_node = current_node->next;
    }
    printf("\n");
    printf("Pop, the top is: %d\n", pop());
    printf("Pop, the top is: %d\n", pop());
    // print the stack
    current_node = top;
    while(current_node != NULL){
        printf("%d\t", current_node->Data);
        current_node = current_node->next;
    }
    printf("\n");
    return 0;
}


