#include<stdio.h>
#include<stdlib.h>

//Linked List Structure
typedef struct Node{
    int data;
    struct Node *next;
}node;

//Function to delete first node
node *deleteHead(node *first){
    node *ptr = first;
    first = first->next;
    free(ptr);
    return first;
}

//Function to delete node of given index
void deleteIndex(node *first, int index){

    node *ptr = first;
    node *p;

    int i=0;

    while(i != index-1){
        ptr = ptr->next;
        i++;
    }
    p = ptr->next;
    ptr->next = p->next;
    free(p);

}

//Function to delete end node
void deleteEnd(node *first){

    node *ptr = first, *p = ptr->next;

    while(p->next != NULL){
        p = p->next;
        ptr = ptr->next; 
    }

    ptr->next = NULL;
    free(p);
}

//Funtion to delete node containing a given value
void deleteNode(node *first, int value){

    node *ptr = first, *p = first->next;

    while(p->data != value && p->next!=NULL){
        p = p->next;
        ptr = ptr->next;
    }

    if(p->data == value){
        ptr->next = p->next;
        free(p);
    }

}

//Print Array Function
void printArray(node *first){
    node *ptr = first;
    printf("\n");
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n***********************************\n\n");
}

int main(){

    node *first, *second, *third, *fourth, *fifth;

    int index,val;

    //Dynamically Allocating Memory In Heap For Linked List
    first = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    fifth = (node *)malloc(sizeof(node));

    //Linking First node to second
    first->data = 2;
    first->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = fifth;

    fifth->data = 10;
    fifth->next = NULL;

    printf("\n******** Before Deletion *********");
    printArray(first);

    first = deleteHead(first);
    printf("\n**** After Deletion of first node ****");
    printArray(first);

    printf("\nEnter the index you want to delete: ");
    scanf("%d", &index);
    deleteIndex(first,index);
    printf("\n** After deletion of node of given index **");
    printArray(first);

    deleteEnd(first);
    printf("\n** After deletion of last node **");
    printArray(first);

    printf("\nEnter the value you want to delete: ");
    scanf("%d",&val);
    deleteNode(first,val);
    printf("\n**** After Deletion of a given value ****");
    printArray(first);

    return 0;
}