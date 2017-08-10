/*
 * APS105 Lab2
 * Part3--Loan Calculator
 */

/* 
 * File:   main.c
 * Author: tianxiangchen
 *
 * Created on August 5, 2017, 10:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 
 */

int main(int argc, char** argv) {

    int P, D, term;
    double r, monthly_pay;
    float x;
    
    printf("Enter the purchase price P: ");
    scanf("%d", &P);
    printf("Enter the amount of down payment D: ");
    scanf("%d", &D);
    printf("Enter the finance term (in months): ");
    scanf("%d", &term);
    printf("Enter the monthly interest rate (in percent): ");
    scanf("%lf", &r);
    r/=100;
    monthly_pay = ((P-D)*r*pow((1+r),term)) / (pow((1+r),term)-1);
    printf("The monthly payment is : %.2f", monthly_pay);
    return (EXIT_SUCCESS);
}

