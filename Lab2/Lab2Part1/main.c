/*
 * APS105 Lab2
 * Part1--Car Rental
 * 1 day within each 4-day block is free
 * Count for HST, which is 13%
 */

/* 
 * File:   main.c
 * Author: TianxiangChen
 *
 * Created on August 5, 2017, 9:53 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    const double HST = 0.13; 
    double daily_rate, total_charge;
    int rental_period, free_days;
    
    printf("Enter the daily rate: ");
    scanf("%f", &daily_rate);
    printf("Enter the rental period (in days): ");
    scanf("%d", &rental_period);
    
    free_days = rental_period / 4;
    total_charge = (rental_period - free_days) * daily_rate * (1+HST);
    printf("Your total free day(s) in this rental is %d\n", free_days);
    printf("Your total charge including taxes is: %.2f",total_charge);
    return (EXIT_SUCCESS);
}

