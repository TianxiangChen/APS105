/* 
 * APS105 Lab4
 * Part2--Statistics
 * Using the formula provided in the handout to output mean,std, min and max.
 * Author: TianxiangChen
 *
 * Created on August 6, 2017, 5:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
/*
 * 
 */
int main(int argc, char** argv) {
    int n=0;
    double mean=0,std=0,max=0,min=0,num;
    double sq_sum=0,sum=0;
    bool valid= true;

    printf("Please enter a list of numbers ending with a negative number.\n");
    while(valid){
        scanf("%lf",&num);
        if(num<0)
            valid = false;
        else{
            n++;
            if(n==1){
                max=num;
                min=num;
            }
               
            if(num>max)
                max=num;
            if(num<min)
                min=num;
            mean=(mean*(n-1)+num)/n;
            sum=sum+num;
            sq_sum=sq_sum+num*num;
            std=sqrt((sq_sum-sum*sum/n)/(n-1));
        }
    }
    if(n==0)
        printf("N = 0, no statistics can be calculated!");
    else if(n==1)
        printf("N = %d, min = %.2lf, max = %.2lf, mean = %.2lf, std = Undefined",
               n,min,max,mean);
    else
        printf("N = %d, min = %.2lf, max = %.2lf, mean = %.2lf, std = %.2lf", n,
                min,max,mean,std);
   
    return (EXIT_SUCCESS);
}

