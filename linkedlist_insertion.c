#include<stdio.h>
#include<stdlib.h>

//Linked List Structure
struct Node{
    int data;
    struct Node *next;
};

//Insert at Beginning Function
struct Node * insertAtBeg(struct Node *first, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = first;
    ptr->data = data;

    return ptr;
}

//Insert At Given Index Function
void insertInBetween(struct Node *first, int data, int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = first;

    int i = 0;

    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

}

//Insert At End Function
void insertAtEnd(struct Node *first, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = first;

    while(p->next!=NULL){
        p = p->next;
    }

    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
}

//Insert After A Given Node Function
void insertAfterNode(struct Node *prevNode, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

//Print List Function
void printArray(struct Node *first){
    struct Node *ptr = first;
    printf("\n");
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

void main(){

    struct Node *first, *second, *third, *fourth, *fifth;

    int data, index;

    //Dynamically Allocating Memory In Heap For Linked List
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    //Linking First node to second
    first->data = 4;
    first->next = second;

    second->data = 6;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = fifth;

    fifth->data = 12;
    fifth->next = NULL;

    printf("\nBefore Insertion\n");
    printArray(first);

    printf("\nEnter the element you want to insert at Beginning: ");
    scanf("%d", &data);

    first = insertAtBeg(first,data);
    printf("\nAfter Insertion in the Beginning\n");
    printArray(first);

    printf("\nEnter the element to insert with the Index: ");
    scanf("%d %d", &data, &index);

    insertInBetween(first,data,index);
    printf("\nAfter Insertion in Between\n");
    printArray(first);

    printf("\nEnter the element to insert in the End: ");
    scanf("%d", &data);

    insertAtEnd(first,data);
    printf("\nAfter Insertion at End\n");
    printArray(first);

    insertAfterNode(third,22);
    printf("\nInsertion, after a given Node\n");
    printArray(first);

}

