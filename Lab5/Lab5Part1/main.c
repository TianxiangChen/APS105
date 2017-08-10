/* 
 * APS105 Lab5
 * Part1--Data Encryption
 * Author: tianxiangchen
 *
 * Created on August 6, 2017, 9:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
/*
 * 
 */

void input(int *num);
int add4(int num);
int shift(int num);
void printOutput(int encryptNum, int originalNum);

int main(int argc, char** argv) {
    long int num,encryptNum,originalNum;
    input(&num);
    originalNum=num;
    encryptNum=add4(num);
    encryptNum=shift(encryptNum);
    printOutput(encryptNum,originalNum);
    return (EXIT_SUCCESS);
}

void input(int* num){
    bool valid=false;
    while(!valid){
        printf("Please enter an integer greater than 99999: ");
        scanf("%d",num);
        if(*num <= 99999)
            printf("Incorrect input.\n");
        else{
            printf("The number entered is %d.\n",*num);
            valid=true;
        }
    }
}


int add4(int num){
    int num_temp=num,new_num=0;
    
    for(int digit=1;num!=0;digit++){
        num_temp=num%10;
        num=(num-num_temp)/10;
        if(num_temp>=6)
            num_temp-=6;
        else
            num_temp+=4;
        new_num=new_num + pow(10,digit-1)*num_temp;
    }
    return new_num;
}

int shift(int num){
    int num_temp=num,new_num=0;
    
    for(int digit=1;num!=0;digit++){
        num_temp=num%10;
        num=(num-num_temp)/10;
        if(num>=1)
            new_num=new_num+num_temp*pow(10,digit);
        else
            new_num=new_num+num_temp;
    }

    return new_num;
}

void printOutput(int encryptNum, int originalNum){
    printf("Original number: %d\n",originalNum);
    printf("Encrypted number: %d\n",encryptNum);
}