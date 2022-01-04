#include<stdio.h>

void main()
{
    len();
}

int len()
{
    int i;
    char fname[20],mname[20],surname[20];
    
    printf("enter first name:\n");
    scanf("%s",&fname);
    
    printf("enter middle name:\n");
    scanf("%s",&mname);
    
    printf("enter surname:\n");
    scanf("%s",&surname);
    
    for(i=0; fname[i]!='\0'; i++);
        printf("length is: %d",i);
    for(i=0; mname[i]!='\0'; i++);
        printf("length is: %d",i);
    for(i=0; surname[i]!='\0'; i++);
        printf("length is: %d",i);
    
}
