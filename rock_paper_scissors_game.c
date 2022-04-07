#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void game(char player, char comp){

    if(player == comp){
        printf("\nDraw!, You both chose %c", comp);
    }

    else if((player == 'r' && comp == 'p') || (player == 'p' && comp == 's') || (player == 's' && comp == 'r')){
        printf("\nYou lose! , you chose %c and computer chose %c", player, comp);
    }
    else if((player == 'r' && comp == 's') || (player == 'p' && comp == 'r') || (player == 's' && comp == 'p')){
        printf("\nYou win! , you chose %c and computer chose %c", player, comp);
    }
    else{
        printf("\nInvalid option. \n Syntax:Enter 'r' for rock, 'p' for paper and 's' for scissor");
    }


}

void computer(char *comp){

    int number;

    srand(time(0));
    number = rand()%100 + 1;

    if(number <= 33){
        *comp = 'r';
    }
    else if(number > 33 && number <= 66){
        *comp = 'p';
    }
    else{
        *comp = 's';
    } 
}

int main(){

    char player, comp;

    int gameover = 1;
    char play;
    

    do{
        
        fflush(stdin);
        printf("\nEnter 'r' for rock, 'p' for paper and 's' for scissor: ");
        scanf("%c", &player);
        computer(&comp);
        game(player,comp);
        fflush(stdin);
        printf("\n\nDo you want to play again? (Y/n): ");
        scanf("%c", &play);

        if(play == 'N' || play == 'n'){
            gameover = -1;
        }
        else{
            gameover =1;
        }

    }while(gameover != -1);
}