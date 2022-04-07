#include<stdio.h>
#include<stdlib.h>

//Stack Structure
typedef struct stack{
    
    int size;
    int top;
    int *arr;

}stack;

//Function to check if stack is Empty
int isEmpty(stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

//Function to check if stack is Full
int isFull(stack *s){
    if(s->top == (s->size-1)){
        return 1;
    }
    return 0;
}

void peek(stack *s, int i){

    if((s->top-i+1) < 0)
        printf("Invalid Index");
    else
        printf("\nElement at index %d is %d\n",i, s->arr[s->top-i+1]);

}

//Function to add element in stack
void push(stack *s,int val){

    if(isFull(s)){
       printf("\n\nError: Stack Overflow | Capacity: %d elements | Element %d not pushed\n\n", s->size,val);   
    }

    else{
        s->top++;
        s->arr[s->top] = val;
        printf("Element %d pushed sucessfully\n", val);
    }
}

int pop(stack *s){

    if(isEmpty(s)){
       printf("\n\nError: Stack Underflow");
       return -1; 
    }
    else{
        
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int main(){

    int i;

    stack *s1;
    s1->size = 5;
    s1->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));

    printf("\nBefore Push\nE: %d\tF: %d\n\n", isEmpty(s1), isFull(s1));

    push(s1,8);
    push(s1,7);
    push(s1,3);
    push(s1,81);
    push(s1,2);
    push(s1,77);

    printf("After Push\nE: %d\tF: %d\n\n", isEmpty(s1), isFull(s1));

    printf("Before Pop\nE: %d\tF: %d\n\n", isEmpty(s1), isFull(s1));

    printf("Popped: %d\n\n",pop(s1));

    printf("After Pop\nE: %d\tF: %d\n\n", isEmpty(s1), isFull(s1));    

    printf("Enter the index you want to search: ");
    scanf("%d",&i);

    peek(s1,i);

    return 0;
}