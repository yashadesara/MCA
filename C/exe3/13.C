#include<stdio.h>
#include<conio.h>

void main()
{
    float cel,fer;
    printf("enter value in celcious : ");
    scanf("%f",&cel);

    fer = (1.8 * cel) + 32;
    printf("fer is : %.2f",fer);
    
}