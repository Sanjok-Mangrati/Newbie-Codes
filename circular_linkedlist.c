#include<stdio.h>
#include<stdlib.h>

//Linked List Structure
struct Node{

    int data;
    struct Node *next;

};

//Function to print Linked List
void printArray(struct Node *first){

    struct Node *ptr = first;

    printf("\n************************************\n");
    do{
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }while(ptr != first);
    printf("\n************************************\n");

}

int main(){

    struct Node *first, *second, *third, *fourth, *fifth;

    //Dynamically Allocating Memory In Heap For Linked List 
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    //Linking first node to second
    first->data = 2;
    first->next = second;

    second->data = 4;
    second->next = third;
    
    third->data = 6;
    third->next = fourth;
    
    fourth->data = 8;
    fourth->next = fifth;
    
    fifth->data = 10;
    fifth->next = first;

    printArray(first);
    
    return 0;
}