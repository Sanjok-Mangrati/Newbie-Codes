//Just a shitty program that takes string as input only using %c format specifier
//Just for fun

#include<stdio.h>

int main(){

    char s[50];
    char c;
    int i=0;

    printf("Enter the string character by character: \n");

    while(c != '\n'){
        fflush(stdin);
        scanf("%c", &c);
        s[i] = c;
        i++;
    }

    s[i-1]='\0';

    printf("The string is: %s", s);

    return 0;
}