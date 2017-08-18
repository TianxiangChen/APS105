/* 
 * APS105 Lab6-- Mastermind
 * User enter the pattern length followed by maximum allowed round and 
 * the correct pattern.
 * Then every time user guess the pattern, the program will return how many black
 * peg(right char in right place) and white peg(wrong char in wrong place.
 * If the user cannot get the right pattern within the max. allowed round, game
 * ends.
 * Author: TianxiangChen
 *
 * Created on August 7, 2017, 4:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
 * 
 */
bool pattern_compare(char *real_pattern,char* input_pattern, char* result, int digit);
void printResult(char* result,int b,int w, int digit);
void printResultSeq(char **input_pattern,char **result,int round,int length);

int main(int argc, char** argv) {
    int length,guess;
    
    printf("Enter the pattern length: ");
    scanf("%d", &length);
    printf("Enter the number of guesses: ");
    scanf("%d", &guess);
    
    char** pattern;
    char** result;
    pattern=(char**)malloc((guess+1)*sizeof(char*));
    result=(char**)malloc((guess)*sizeof(char*));
    for(int i=0;i<guess+1;i++)
        pattern[i]=(char*)malloc(length*sizeof(char));
    for(int i=0;i<guess;i++)
        result[i]=(char*)malloc(length*sizeof(char));
        
    printf("Input the key pattern with no spaces: ");
    scanf("%s",pattern[0]);
    //printf("the intput is %s.\n",pattern[0]);
    
    bool IsWin=false;
    
    for(int round=1;((!IsWin)&&(round<=guess));round++){
        printf("Input a guess pattern with no spaces: ");
        scanf("%s",pattern[round]);
        IsWin=pattern_compare(pattern[0],pattern[round],result[round-1],length);
        printResultSeq(pattern,result,round,length);
    }

    if(IsWin)
        printf("You guessed the pattern!\n");
    else
        printf("You did not guess the pattern!\n");
    
    for(int i=0;i<guess+1;i++)
        free(pattern[i]);
    free(pattern);
    for(int i=0;i<guess;i++)
        free(result[i]);
    free(result);
    return (EXIT_SUCCESS);
}

bool pattern_compare(char *real_pattern,char* input_pattern, char* result, int digit){
    bool IsChecked_origin[digit];
    bool IsChecked_input[digit];
    
    for(int i=0;i<digit;i++){
        IsChecked_origin[i] = false;
        IsChecked_input[i] = false;
    }
    int b=0,w=0;/*b means correct char in correct position...
    w means correct char in wrong place*/
    for(int i=0;i<digit;i++){//this loop checks for b condition
        if(real_pattern[i]==input_pattern[i]){
            b++;
            IsChecked_origin[i]=true;
            IsChecked_input[i]=true;
        }       
    }
    
    for(int i=0;i<digit;i++){//this loop checks for w condition
        if(!IsChecked_origin[i]){
            for(int j=0;j<digit;j++){
                if((!IsChecked_input[j])&&(!IsChecked_origin[i])){
                    if(real_pattern[i]==input_pattern[j]){
                        w++;
                        IsChecked_origin[i]=true;
                        IsChecked_input[j]=true;
                    }
                }
            }
        }
    }
   
    printResult(result,b,w,digit);
    if(b==digit)
        return true;
    return false;
    
}

void printResult(char* result,int b,int w,int digit){
    for(int i=0;i<digit;i++){
        if(b>0){
            result[i]='b';
            b--;
        }
        else if(w>0){
            result[i]='w';
            w--;
        }
        else{
            result[i]='.';
        }
    }
}

void printResultSeq(char **input_pattern,char **result,int round,int length){
    for(int i=0;i<round;i++)
        printf("%d: %s %s\n",i+1,result[i],input_pattern[i+1]);
    
}