#include<stdio.h>

void main()
{
    char fname[20],mname[20],surname[20];
    
    printf("enter first name:\n");
    scanf("%s",&fname);
    
    printf("enter middle name:\n");
    scanf("%s",&mname);
    
    printf("enter surname:\n");
    scanf("%s",&surname);
    
    printf("name is : %s %s %s",fname,mname,surname);
    
}