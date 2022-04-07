//Simple program to Store and Display Bank details of a customer
//For structures basic practice

#include<stdio.h>
#include<string.h>

const int size = 5;

typedef struct accountinfo{
    char name[40];
    int accnum;
    int pin;
    float balance;

}accinfo;

void display(accinfo *ptr, int n){

    for(int i=0; i<n; i++){
        printf("\nAccount holder: %s", ptr->name);
        printf("\nAccount number: %d", ptr->accnum);
        printf("\nPin number: %d", ptr->pin);
        printf("\nAccount balance: %f\n", ptr->balance);

        ptr++;
    }
}

int main(){

    accinfo bankdetails[size];

    for(int i=0; i<size; i++){
        fflush(stdin);
        printf("Enter your name: ");
        gets(bankdetails[i].name);
        printf("Enter your account number: ");
        scanf("%d", &bankdetails[i].accnum);
        printf("Enter your pin number: ");
        scanf("%d", &bankdetails[i].pin);
        printf("Enter your balance: ");
        scanf("%f", &bankdetails[i].balance);
        printf("\n");
    }

    display(bankdetails,size);

    return 0;
}
