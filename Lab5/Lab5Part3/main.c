/* 
 * APS105 Lab5
 * Part3--Zeller's Algorithm
 * Author: tianxiangchen
 *
 * Created on August 7, 2017, 12:33 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
/*
 * 
 */
void inputDate(int *day, int *month, int *year);
void calculateDay(int day, int month, int year);

int main(int argc, char** argv) {
    int day,month,year;
    inputDate(&day,&month,&year);
    calculateDay(day,month,year);
    return (EXIT_SUCCESS);
}

void inputDate(int *day, int *month, int *year){
    printf("Please enter a date: ");
    scanf("%d/%d/%d",day,month,year);
}

void calculateDay(int day, int month, int year){
    int A,B,C,D;
    int W,X,Y,Z,R;
    if(month>=3)
        A=month-2;
    else
        A=month+10;
    B=day;
    if(month>=3)
        C=year%100;
    else
        C=year%100-1;
    D=(year-C)/100;
    //printf("A=%d, B=%d, C=%d, D=%d\n",A,B,C,D);
    W=(13*A-1)/5;
    X=C/4;
    Y=D/4;
    Z=W+X+Y+B+C-2*D;
    R=Z%7;
    while(R<0)
        R+=7;
    printf("The day %d/%d/%d is a ",day,month,year);
    switch(R){
        case 0:
            printf("Sunday.\n");
            break;
        case 1:
            printf("Monday.\n");
            break;
        case 2:
            printf("Tuesday.\n");
            break;
        case 3:
            printf("Wednesday.\n");
            break;
        case 4:
            printf("Thursday.\n");
            break;
        case 5:
            printf("Friday.\n");
            break;
        case 6:
            printf("Saturday.\n");
            break;
            
            
            
    }
}