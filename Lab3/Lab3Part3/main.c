/*
 * APS105 Lab3
 * Part3--Body Mass Index
 */

/* 
 * File:   main.c
 * Author: tianxiangchen
 *
 * Created on August 6, 2017, 12:31 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    double weight,height,bmi;
    char word1,word2;
    
    printf("Enter the body weight: ");
    scanf("%lf%c%c",&weight,&word1,&word2);
    
    //weight coversion
    if((word1=='l')&&(word2=='b'))
        weight *= 0.4536;
    
    printf("Enter the height: ");
    scanf("%lf%c%c",&height,&word1,&word2);
    
    //height coversion
    if((word1=='f')&&(word2=='t'))
        height /= 3.28;
    else if((word1=='i')&&(word2=='n'))
        height /= 39.37;
    
    bmi = weight / (height*height);
    
    //Rounding to one decimal
    bmi = (double) ((int)(bmi*10+0.5))/10;
    printf("The Body Mass Index (BMI) is: %.1lf\n", bmi);
    printf("Catagory: ");
    
    if(bmi<16.5)
        printf("Severely underweight");
    else if((bmi >=16.5)&&(bmi <=18.4))
        printf("Underweight");
    else if((bmi >=18.5)&&(bmi <=24.9))
        printf("Normal");
    else if((bmi >25)&&(bmi <=29.9))
        printf("Overweight");
    else
        printf("Obese");
    return (EXIT_SUCCESS);
}

