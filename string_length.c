//Program to calculate length of a string

#include<stdio.h>
#include<string.h>

int strlength(char *arr);

int main(){

    char s[50];
    printf("Enter string: ");
    gets(s);

    int length = strlength(s);
    printf("length: %d", length-1);

    return 0;
}

int strlength(char *arr){

    char *ptr = arr;
    int count=1;

    while(*ptr != '\0'){
        count++;
        ptr++;
    }

    return count;
}