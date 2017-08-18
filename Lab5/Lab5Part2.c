/* 
 * APS105 Lab5
 * Part2--Craps
 * 
 * The game of craps is played with two dice. On the first roll, the player wins 
 * if the sum of the dice is 7 or 11. The player loses if the sum is 2, 3, or 12. 
 * Any other roll is called a “point” and the game continues. On each subsequent 
 * roll, the player wins if he or she rolls the point again. The player loses 
 * by rolling 7. Any other roll is ignored and the game continues. At the end 
 * of the game the user has a choice to start a new game by pressing y or Y. 
 * Pressing any other key will display the number of wins and losses and then
 *  exit the program.
 * 
 * Author: TianxiangChen
 *
 * Created on August 6, 2017, 11:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
/*
 * 
 */
int rollDice(void);
bool playGame(void);
void winLoss(void);

int main(int argc, char** argv) {
    winLoss();
    return (EXIT_SUCCESS);
}

int rollDice(void){
    int result;
    result=rand()%5+1;
    result+=rand()%5+1;
    printf("You rolled: %d\n",result);
    return result;
}

bool playGame(void){
    int result;
    result=rollDice();
    if((result==7)||(result==11))
        return true;
    else if((result==2)||(result==3)||(result==12))
        return false;
    else
        printf("Your point is %d\n",result);
    while(1){
        int result2;
        result2=rollDice();
        if(result2==7)
            return false;
        else if(result==result2)
            return true;  
    }
}

void winLoss(void){
    char y;
    int win,lose;
    do{
        bool GameResult;
        GameResult=playGame();
        if(GameResult){
            win++;
            printf("You win!\n");
        }
        else{
            lose++;
            printf("You lose!\n");
        }
        printf("Play again? ");
        scanf(" %c",&y);
    }while((y=='y')||(y=='Y'));
    
    printf("Wins: %d\n",win);
    printf("Losses: %d\n",lose);
}