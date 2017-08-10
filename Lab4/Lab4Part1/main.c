/* 
 * APS105 Lab4
 * Part1--Making Change
 * Author: tianxiangchen
 *
 * Created on August 6, 2017, 4:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
 * 
 */

void printing_seg(int money_type,int num);

int main(int argc, char** argv) {
    bool valid=true;
    int money;

    while(valid){
        printf("Please give an amount in cents less than 100: ");
        scanf("%d", &money);
        
        if((money>100)||(money<=0))
            valid=false;
        else{
            int quarter, dime, nickel, cent;
            int money_temp;//for calculating
            quarter = money/25;
            money_temp = money - quarter * 25;
            dime = money_temp / 10;
            money_temp = money_temp - dime * 10;
            nickel = money_temp / 5;
            cent = money_temp - nickel * 5;
            
            //print results
            
            printf("%d cent",money);
            if(money==1)//two case: one cent and others
                printf(": ");
            else
                printf("s: ");

            if(quarter!=0){
                bool isEnd=(dime==0)&&(nickel==0)&&(cent==0);
                printing_seg(1,quarter);
                if(!isEnd)
                    printf(", ");
                else{
                    printf(".\n");
                }
            }
            if(dime!=0){
                bool isFirst=(quarter==0);
                bool isEnd=(nickel==0)&&(cent==0);
                if(isEnd){
                    if(!isFirst)
                        printf("and ");
                    printing_seg(2,dime);
                    printf(".\n");
                }
                else{
                    printing_seg(2,dime);
                    printf(", ");
                }
            }
            if(nickel!=0){
                bool isFirst=(quarter==0)&&(dime==0);
                bool isEnd=(cent==0);
                if(isEnd){
                    if(!isFirst)
                        printf("and ");
                    printing_seg(3,nickel);
                    printf(".\n");
                }
                else{
                    printing_seg(3,nickel);
                    printf(", ");
                }
            }
            if(cent!=0){
                bool isFirst=(quarter==0)&&(dime==0)&(nickel==0);
                if(!isFirst)
                    printf("and ");
                printing_seg(4,cent);
                printf(".\n");
                }
            }   
        }
    if(!valid)
        printf("Goodbye.");

    return (EXIT_SUCCESS);
}

void printing_seg(int money_type,int num)
{
    
    printf("%d ",num);
    switch (money_type){
        case 1:
            printf("quarter");
            break;
        case 2:
            printf("dime");
            break;
        case 3:
            printf("nickel");
            break;
        case 4:
            printf("cent");
            break;        
    }
    if(num>1)
        printf("s");

}