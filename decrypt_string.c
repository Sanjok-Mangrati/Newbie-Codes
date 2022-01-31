//VERY SIMPLE STRING DECRYPTION PROGRAM
//TO BE USED WITH MY encrypt_string.c PROGRAM

#include<stdio.h>
#include<string.h>

void decrypt(char *string){

    while(*string!='\0'){
        *string = *string - 1;   //Subtract 1 from the ASCII value of each character
        string++;
    }  
}

int main(){

    char s[100];

    printf("Enter string for decryption: ");
    gets(s);
    decrypt(s);

    printf("%s", s);
    return 0;
}