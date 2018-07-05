#include <stdio.h>
#include <stdlib.h>

// define data type
typedef struct stack{
    int *Data;
    int top;
    int MAX_SIZE;
}stack;


// stack param initialization
void create_stack(stack *st, int size){
    st->top = -1;
    st->MAX_SIZE = size-1;
    st->Data = (int *)malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++){
        st->Data[i] = 0;
    }
}

// check if the stack is empty
int IsEmpty(stack *st){
    if (st->top == -1)
        return 1;
    return 0;
}

// check if the stack is full
int IsFull(stack *st){
    if (st->top == st->MAX_SIZE)
        return 1;
    return 0;
}

void push(stack *st, int data){

    // push to the stack
    if (IsFull(st) == 1){
        printf("The stack is full.\n");
    }
    else{
        st->Data[++st->top] = data;
    }
}

int pop(stack *st){
    if (IsEmpty(st) == 1){
        printf("The stack is empty.\n");
        return 0;
    }
    else{
        int output = st->Data[st->top];
        st->Data[st->top] = 0;
        st->top--;
        return output;
    }
    return -1;
}

int main(){
    stack *s = (stack *)malloc(sizeof(stack));
    printf("Create a stack which size is 5.\n");
    create_stack(s, 5);
    printf("Push: 1,\t2,\t3,\t4,\t5\n");
    push(s, 1); push(s, 2); push(s, 3); push(s, 4); push(s, 5);
    // print the stack
    for (int i = s->MAX_SIZE; i >= 0; i--){
        if (s->Data[i] > 0)
            printf("%d\t", s->Data[i]);
    }
    printf("\n");
    printf("Pop, the top is: %d\n", pop(s));
    printf("Pop, the top is: %d\n", pop(s));
    // print the stack
    for (int i = s->MAX_SIZE; i >= 0; i--){
        if (s->Data[i] > 0)
            printf("%d\t", s->Data[i]);
    }
    printf("\n");
    return 0;
}


