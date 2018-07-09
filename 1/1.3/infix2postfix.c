#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define data type
typedef struct stack{
    char *Data;
    struct stack *next;
}stack;

// head of the stack, which points to the top
stack *top;

// create stack
void CreateStack(){
    top = NULL;
}

// check if the stack is empty
int IsEmpty(){
    if (top == NULL)
        return 1;
    return 0;
}

void Push(char data){
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

char Pop(){
    if (IsEmpty() == 1){
        printf("The stack is empty.\n");
        return NULL;
    }
    else{
        stack *output = top;
        top = top->next; // the older data
        return output->Data; // return the top node
    }
    return NULL;
}

char GetTop(){
    if (IsEmpty() == 1){
        printf("The stack is empty.\n");
        return NULL;
    }
    else{
        return top->Data; // return the top node data
    }
    return NULL;
}


int IsOperator(char c){
    if (c =='(') return 1;
    else if (c == ')') return 1;
    else if (c == '+') return 1;
    else if (c == '-') return 1;
    else if (c == '*') return 1;
    else if (c == '/') return 1;
    else return 0;
}

int ComparePriority(char a, char b){
    // 1 >
    // 2 <=
    char priority[] = "(+-*/";
    int index_a, index_b;
    const char *ptr_a = strchr(priority, a);
    const char *ptr_b = strchr(priority, b);
    if(ptr_a) {
        index_a = ptr_a - priority;
    }
    if(ptr_b) {
        index_b = ptr_b - priority;
    }
    //
    if ((index_a - index_b == 1) && (index_b != 0)){
        return 2;
    }
    else if ((index_b - index_a == 1) && (index_a != 0)){
        return 2;
    }
    else{
        if (index_a - index_b > 0){
            return 1;
        }
        else{
            return 2;
        }
    }
    return 0;
}

int main(void)
{
    char equation[256];
    top = (stack *)malloc(sizeof(stack));
    CreateStack();
    printf("Input the infix equation:");
    fgets(equation, sizeof equation, stdin);
    strtok(equation, "\n");
    for (int i = 0; i<strlen(equation); i++){
        if (IsOperator(equation[i])){
            if (equation[i] == ')'){
                char y = Pop();
                while(y != '('){
                    printf("%c", y);
                    y = Pop();
                }
            }
            else{
                if (IsEmpty()){
                    Push(equation[i]);
                }
                else{
                    if (equation[i] == '('){
                        Push(equation[i]);
                    }
                    else{
                        switch(ComparePriority(equation[i], GetTop())){
                            case 1: //>
                                Push(equation[i]);
                                break;
                            case 2: //<=
                                while(ComparePriority(equation[i], GetTop()) != 1){
                                    char y = Pop();
                                    printf("%c", y);
                                    if (IsEmpty()) break; 
                                }
                                Push(equation[i]);
                                break;
                        }
                    }
                }
            }
        }
        else{
            printf("%c", equation[i]);
        }
    }
    
    while(IsEmpty() == 0){
        char y = Pop();
        printf("%c", y);
    }
    printf("\n");
    return 0;
}
