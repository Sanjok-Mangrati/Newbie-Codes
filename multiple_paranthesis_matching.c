#include<stdio.h>
#include<stdlib.h>

//Stack Structure
typedef struct stack{
    
    int size;
    int top;
    char *arr;

}stack;

//Function to check if stack is Empty
int isEmpty(stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

//Function to add element in stack
void push(stack *s,char val){
    s->top++;
    s->arr[s->top] = val;   
}

//Function to remove element from stack
char pop(stack *s){
        
    char val = s->arr[s->top];
    s->top--;
    return val;
}

//Paranthesis Match Logic
int paranthesisMatch(char *exp){
    stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    char popped;

    for(int i=0; exp[i] != '\0'; i++){
        if(exp[i]=='(' || exp[i] == '{' || exp[i] == '['){
            push(sp,exp[i]);

        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped = pop(sp);
            if((popped == '(' && exp[i] == ')') || (popped == '{' && exp[i] == '}') || (popped == '[' && exp[i] == ']')){
                continue;
            }
            return 0;
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    return 0;
}

int main(){

    char *exp = "{(2+3)*(5-3[)}]";
    if(paranthesisMatch(exp)){
        printf("Balanced Expression");
    }
    else{
        printf("Unbalanced Expression");
    }
    
    return 0;
}