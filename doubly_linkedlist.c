#include<stdio.h>
#include<stdlib.h>

//Linked List Structure
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}node;

//Function to print doubly linked list forwards as well as backwards
void printArray(node *first){
    node *ptr = first;
    printf("\n***********************************\n");
    while(ptr->next!=NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\t", ptr->data);
    printf("\n***********************************\n\n");

    printf("\n***********************************\n");
    while(ptr->prev!=NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->prev;
    }
    printf("%d\t", ptr->data);
    printf("\n***********************************\n\n");

}

int main(){

    node *first, *second, *third, *fourth, *fifth;

    //Dynamically Allocating Memory In Heap For Linked List 
    first = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));
    fourth = (node*)malloc(sizeof(node));
    fifth = (node*)malloc(sizeof(node));

    //Linking first node to second and first node to previous node
    first->data = 2;
    first->prev = NULL;
    first->next = second;

    second->data = 4;
    second->prev = first;
    second->next = third;
    
    third->data = 6;
    third->prev = second;
    third->next = fourth;
    
    fourth->data = 8;
    fourth->prev = third;
    fourth->next = fifth;
    
    fifth->data = 10;
    fifth->prev = fourth;
    fifth->next = NULL;

    printArray(first);
    

    return 0;
}