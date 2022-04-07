#include<stdio.h>
#include<stdlib.h>

//Stack Structure
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

void push(stack *s, char val){
    
    s->top++;
    s->arr[s->top] = val;
    return;
}

int pop(stack *s){
    if(isEmpty(s)){
        return 1;
    }
    s->top--;
    return 0;
}

void paranthesisMatch(stack *s){

    if(s->top != -1){
        printf("Unbalanced Expression by Stack not Empty");
    }

    else{
        printf("Balanced Expression");
    }

}

int main(){

    stack *s1 = (stack *)malloc(sizeof(stack));
    s1->size = 100;
    s1->top = -1;
    s1->arr = (char*)malloc(s1->size * sizeof(char));
    char s[100];
    printf("Enter the expression: ");
    gets(s);


    char *ptr = s;
    while(*ptr != '\0'){

        if(*ptr == '('){
            push(s1,'(');
            ptr++;
        }
        else if(*ptr == ')'){
            if(isEmpty(s1)){
                printf("Unbalanced Expression by Stack Underflow");
                return 0;
            }
            pop(s1);
            ptr++;
        }
        else{
            ptr++;
            continue;
        }
    }

    paranthesisMatch(s1);

    return 0;
}