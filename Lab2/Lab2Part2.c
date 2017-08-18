/*
 * APS105 Lab2
 * Part2--Decipher
 * abcd-->d(9-b(9-c)a)
 * User will input the encrypted number and the system
 * need to output the original number
 */

/* 
 * File:   main.c
 * Author: TianxiangChen
 *
 * Created on August 5, 2017, 10:11 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int encrypted_num, real_num;
    int a,b,c,d;
    printf("Enter an encrypted 4-digit combination: ");
    scanf("%d", &encrypted_num);
    
    int temp; //first use for getting encrypted abcd, then swapping a&d
    a = encrypted_num/1000;
    temp = encrypted_num - a*1000;
    b = temp/100;
    temp -= b*100;
    c = temp/10;
    temp -= c*10;
    d = temp;
    
    temp = a;
    a = d;
    d = temp;
    b = 9 - b;
    c = 9 - c;
    real_num = 1000*a + 100*b + 10*c + d;
    printf("The real combination is: %d", real_num);
    return (EXIT_SUCCESS);
}

