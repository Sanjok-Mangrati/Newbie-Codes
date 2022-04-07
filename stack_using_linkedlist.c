#include<stdio.h>
#include<stdlib.h>

//Structure of stack
typedef struct stack{
    int data;
    struct stack *next;
}stack;

//Function to check if stack is Empty
int isEmpty(stack *top){
    if(top == NULL){
        return 1;
    }
    return 0;
}

//Function to check if stack is Full
int isFull(){
    stack *n = (stack *)malloc(sizeof(stack));

    if(n == NULL){
        free(n);
        return 1;
    }
    free(n);
    return 0;
}

//Function to push element in stack
stack *push(stack *top, int data){
    if(isFull()){
        printf("\nStack Overflow\n");
    }
    else{
        stack *a = (stack *)malloc(sizeof(stack));
        a->data = data;
        a->next = top;
        top = a;
        printf("\nSuccessfully pushed: %d\n", data);
        return top;
    }
}

//Function to pop element from stack
stack *pop(stack *top){
    if(isEmpty(top)){
        printf("\nStack Underflow\n");
    }
    else{
        int x = top->data;
        top = top->next;
        printf("\nSuccessfully popped: %d\n", x);
        return top;
    }
}

int main(){

    stack *top = NULL;
    printf("\nBefore Push\n");
    printf("\nE: %d F: %d\n",isEmpty(top),isFull());
    top = push(top,10);
    top = push(top,12);
    top = push(top,42);
    top = push(top,47);
    printf("\nAfter Push\n");
    printf("\nE: %d F: %d\n",isEmpty(top),isFull());

    printf("\nBefore Pop\n");
    printf("\nE: %d F: %d\n",isEmpty(top),isFull());
    top = pop(top);
    top = pop(top);
    top = pop(top);
    printf("\nE: %d F: %d\n",isEmpty(top),isFull());
    printf("\nBefore Pop\n");

    return 0;
}