#include<stdio.h>
#include<stdlib.h>

//Queue Structure
typedef struct queue{
    int size;
    int f,r;
    int *arr;
}queue;

//Function to check if queue is Full
int isFull(queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

//Function to check if queue is Empty
int isEmpty(queue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

//Function to add elements in queue
void enqueue(queue *q, int val){
    if(!isFull(q)){
        q->r++;
        q->arr[q->r] = val;
        printf("enqueued: %d\n",val);
        return;
    }
    printf("Queue Overflow!\n");
    
}

//Function to remove elements from queue
void dequeue(queue *q){
    if(!isEmpty(q)){
        q->f++;
        printf("dequeued: %d\n", q->arr[q->f]);
        return;
    }
    printf("Queue Underflow!\n");
}


int main(){

    queue *q = (queue*)malloc(sizeof(queue));
    q->size = 7;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q,2);
    enqueue(q,6);
    enqueue(q,8);
    enqueue(q,45);
    enqueue(q,76);
    enqueue(q,8765);
    enqueue(q,345);
    enqueue(q,890);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    
    enqueue(q,9);    //Cannot enqueue this element even after having free space from dequeuing elements. 
                    //This is the disadvantage of using a linear queue (wastage of space).

    return 0;
}