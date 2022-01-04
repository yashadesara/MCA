#include<stdio.h>
#include<conio.h>

void main()
{
    float fer,cel;
    printf("enter value in Ferenhit : ");
    scanf("%f",&fer);

    cel = (fer-32)/1.8;
    printf("cel is : %.2f",cel);

}