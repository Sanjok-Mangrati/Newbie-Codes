//PROGRAM FOR SLICING STRING

#include<stdio.h>

void slice(char *string, int start, int end){

    int i=0;

    while((i+start)<=end){
        string[i] = string[i+start];
        i++;
    }

    string[i] = '\0';
}

int main(){

    char s[]="Hello World!";

    slice(s,0,4);   //Syntax: slice(string, start index, end index)

    printf("%s", s);

    return 0;
}
