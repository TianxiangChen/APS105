/*
 * APS105 Lab7--The Mastermind Assistant (Recursion)
 * This lab asks user to input the pattern length, guessed pattern and number
 * of white and black pegs, using recursion to output all the possible solution 
 */

/* 
 * File:   main.c
 * Author: Tianxiang Chen
 *
 * Created on August 9, 2017, 11:09 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
 * 
 */
void MastermindAssist(char* guess, int black, int white, int length);
void MastermindAssistHelper(char* guess, char test[], bool IsUsed[], int black,
        int white, int yellow, int digit, int size, int length);

int main(int argc, char** argv) {
    
    int length,white,black;
    printf("Enter the pattern length: ");
    scanf("%d", &length);
    char guess[length+1];
    printf("Input the guess pattern: ");
    scanf("%s", guess);
    printf("Enter the number of the black pegs in the feedback: ");
    scanf("%d", &black);
    printf("Enter the number of the white pegs in the feedback: ");
    scanf("%d", &white);
    
    MastermindAssist(guess, black, white, length);
    return (EXIT_SUCCESS);
}

void MastermindAssist(char* guess, int black, int white, int length){
    char test[length+1];
    bool IsUsed[length];
    int yellow = length - black - white;//the number of wrong place.
    for(int i=0; i<length;i++){
        test[i]=guess[i];
        IsUsed[i]=false;
    }
    test[length]='\0';
    printf("\n");
    MastermindAssistHelper(guess,test,IsUsed,black,white,yellow,0,length,length);
    
}

void MastermindAssistHelper(char* guess, char test[], bool IsUsed[], int black, int white,
        int yellow, int digit, int size, int length){
    if(size==1){//base case, size==1
        if(black==1){//case 1 last one is correct
            if(!IsUsed[digit]){
                char temp=test[digit];
                test[digit]=guess[digit];
                printf("%s\n", test);
                test[digit]=temp;
            }
        }
        else if(yellow==1){//case 2, last one is wrong 
            char temp=test[digit];
            for(char i='a';(i<='f');i++){
                if(i!=guess[digit]){
                    test[digit]=i;
                    printf("%s\n", test);
                }
            }
            test[digit]=temp;
        }
        else{//case 3, white==1
            char temp=test[digit];
            for(int i=0;i<length;i++){
                if((i!=digit)&&(guess[i]!=test[digit])&&(!IsUsed[i])){
                    test[digit]=guess[i];
                    printf("%s\n", test);
                }
            }
            test[digit]=temp;
        }
        

        return;
         
    }
    
    
    //recursive case
        if(black > 0){
            if(!IsUsed[digit]){
            char temp=test[digit];
            test[digit]=guess[digit];
            IsUsed[digit]=true;
            MastermindAssistHelper(guess, test, IsUsed, black-1, white, yellow,
                    digit+1,size-1,length);
            IsUsed[digit]=false;
            test[digit]=temp;
            }
        }
        if(white > 0){
            for(int i=0;i<length;i++){
                char temp=test[digit];
                if((i!=digit)&&(!IsUsed[i])&&(test[digit]!=guess[i])){                        
                    test[digit]=guess[i];
                    IsUsed[i]=true;
                    MastermindAssistHelper(guess, test, IsUsed, black,
                            white-1, yellow, digit+1,size-1,length);
                    IsUsed[i]=false;
                }
                test[digit]=temp;
            }
        }
        if(yellow > 0){
            char temp=test[digit];
            for(char i='a';(i<='f');i++){
                if(i!=guess[digit]){
                    test[digit]=i;
                    IsUsed[digit]=true;
                    MastermindAssistHelper(guess, test, IsUsed, black, white,
                        yellow-1, digit+1, size-1,length);
                    IsUsed[digit]=false;
                }
            }
            test[digit]=temp;
        }
    
    
        
}