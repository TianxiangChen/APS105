/*
 * APS105 Lab3
 * Part2--Substance Test
 */

/* 
 * File:   main.c
 * Author: tianxiangchen
 *
 * Created on August 6, 2017, 12:20 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 
 */
int main(int argc, char** argv) {
    const int water=100,
            mercury=357,
            copper=1187,
            sliver=2193,
            gold=2660;
    int threhold, boil_point;
    
    printf("Enter the threshold in celsius: ");
    scanf("%d",&threhold);
    printf("Enter the observed boiling point in celsius: ");
    scanf("%d",&boil_point);
    
    
    if(fabs(boil_point - water) <= threhold)
        printf("The substance you tested is: water\n");
    else if(fabs(boil_point - mercury) <= threhold)
        printf("The substance you tested is: mercury\n");
    else if(fabs(boil_point - copper) <= threhold)
        printf("The substance you tested is: copper\n");
    else if(fabs(boil_point - sliver) <= threhold)
        printf("The substance you tested is: sliver\n");
    else if(fabs(boil_point - gold) <= threhold)
        printf("The substance you tested is: gold\n");
    else
        printf("Substance unknown.\n");
    return (EXIT_SUCCESS);
}

