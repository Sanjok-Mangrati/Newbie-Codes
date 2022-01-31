#include<stdio.h>

const int rows, columns;

void printTable(int arr[rows][columns], int n[rows]);

int main(){

    printf("Enter the size of the array in [rows][columns]: ");
    scanf("%d %d", &rows, &columns);

    int mulTable[rows][columns], num[rows];
    int *ptr = num;

    for(int i=0; i<rows; i++){
        printf("Enter the number you want the multiplication table for: ");
        scanf("%d", ptr);
        ptr++;
    }

    printTable(mulTable, num);

    return 0;
}

void printTable(int arr[rows][columns],int n[rows]){

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            arr[i][j]= n[i] * (j+1);
        }
    }

    for(int i=0; i<rows; i++){
        printf("\n*******************************************");
        printf("\nThe Multiplication Table of %d is: \n", n[i]);

        for(int j=0; j<columns; j++){
            printf("%d X %d = %d \n", n[i], j+1, arr[i][j]);
        }

        printf("*******************END*********************\n\n");
    }
}
