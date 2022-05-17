//Infix to Postfix conversion using stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    int size;
    int top;
    char *arr;
}stack;

int isEmpty(stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

void push(stack *s,char val){
        s->top++;
        s->arr[s->top] = val;
}

char pop(stack *s){
    char val = s->arr[s->top];
    s->top--;

    return val;
}

int precedence(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}

int isOperator(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/'){
        return 1;
    }
    return 0;
}

char *intoPo(char *infix){
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));

    int i=0,j=0;

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i]) > precedence(s->arr[s->top])){
                push(s,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postfix[j] = pop(s);
        j++;
    }
    postfix[i] = '\0';
    return postfix;

}

int main(){

    char *infix = "x-y/z-k*d";

    printf("Infix: %s\n",infix);
    printf("Postfix: %s",intoPo(infix));

    return 0;
}