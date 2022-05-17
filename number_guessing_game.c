#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
    int number;
    srand(time(0));
    number = rand()%10 + 1; // Generates a random number between 1 to 100
    int guess, count=1;

    printf("***********NUMBER GUESSING GAME*************");

    do{ 
        printf("\nGuess the number b/w 1-100: ");
        scanf("%d", &guess);

        if(number < guess){
            printf("Guess is high, guess a smaller number \n");
        }

        else if(number > guess){
            printf("Guess is low, guess a higher number \n");
        }

        else if(number == guess){
            printf("Your guess is right! The number is %d and you took %d attempts. \n", number,count);
        }

        count++;

    }while(guess != number);

return 0;

}
