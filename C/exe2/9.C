#include<stdio.h>

void main()
{
    int i;
    char str[20];

    printf("enter string : \n");
    scanf("%s",&str);

    for(i=0; str[i]!='\0'; i++);

    printf("length is %d",i);
}