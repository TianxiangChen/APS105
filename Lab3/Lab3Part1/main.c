/*
 * APS105 Lab3
 * Part1--Cartesian Coordinates
 */

/* 
 * File:   main.c
 * Author: tianxiangchen
 *
 * Created on August 5, 2017, 11:56 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    double x,y;
    printf("Enter the x-coordinate in floating point: ");
    scanf("%lf",&x);
    printf("Enter the y-coordinate in floating point: ");
    scanf("%lf",&y);
    
    //for rounding to two decimals
    if (x>0)
        x=(double)((int)(x*100+0.5))/100;
    else
        x=(double)((int)(x*100-0.5))/100;
    
    if(y>0)
        y=(double)((int)(y*100+0.5))/100;
    else
        y=(double)((int)(y*100-0.5))/100;
    if(x==0 & y==0)
        printf("(0.00, 0.00) is at the origin.");
    else if(x > 0){
        if(y==0)
            printf("(%.2f, 0.00) is on the x axis.",x);
        else if(y > 0)
            printf("(%.2f, %.2f) is in quadrant I.",x,y);
        else
            printf("(%.2f, %.2f) is in quadrant IV.",x,y);    
    }
    else if(x < 0){
        if(y==0)
            printf("(%.2f, 0.00) is on the x axis.",x);
        else if(y > 0)
            printf("(%.2f, %.2f) is in quadrant II.",x,y);
        else
            printf("(%.2f, %.2f) is in quadrant III.",x,y);    
    }
    else
        printf("(0.00, %.2f) is on the y axis.",y);
         
    return (EXIT_SUCCESS);
}

