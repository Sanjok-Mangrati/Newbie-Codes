//VERY SIMPLE STRING ENCRYPTION PROGRAM
//TO BE USED WITH MY decrypt_string.c PROGRAM

#include<stdio.h>
#include<string.h>

void encrypt(char *string){

    while(*string!='\0'){
        *string = *string + 1;   //Add 1 to the ASCII value of each character
        string++;
    }  
}

int main(){

    char s[100];

    printf("Enter string for encryption: ");
    gets(s);
    encrypt(s);
    
    printf("%s", s);
    return 0;
}