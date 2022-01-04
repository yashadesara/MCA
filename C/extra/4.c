#include <stdio.h>

void main()
{
    int i,x,n,pow=1,fact=1;
    printf("enter x:");
    scanf("%d",&x);
    
    printf("enter n:");
    scanf("%d",&n);
    
    for(i=1; i<=n; i++)
    {
        pow*=x; //to find power.
        fact *= i; //to find factorial.
    }
    printf("power is %d\n",pow);
    printf("fact is %d\n",fact);
    printf("process of %d/%d is: %d",pow,fact,(pow/fact));
}