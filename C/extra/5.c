#include <stdio.h>

void main()
{
    int i,r,n,pow=1,factr=1,factn=1,factnr=1,temp,mul;
    printf("enter r:");
    scanf("%d",&r);
    printf("enter n:");
    scanf("%d",&n);
    
    for(i=1; i<=r; i++)
    {
        factr *= i; //to find factorial of n.
    }
    printf("fact of r %d\n",factr);
    
    for(i=1; i<=n; i++)
    {
        factn *= i; //to find factorial of r.
    }
    printf("fact of n %d\n",factn);
    
    temp = n-r;
    for(i=1; i<=temp; i++)
    {
        factnr *= i; //to find factorial of n-r.
    }
    printf("fact of (n-r)! %d\n",factnr);
    mul = factr*factnr;
    printf("fact of r!(n-r)! %d\n",mul);
    printf("fact of n!/[r!(n-r)!] %d\n",(factn/mul));
}