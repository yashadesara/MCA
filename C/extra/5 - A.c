#include <stdio.h>

double fact(int n)
{
    if(n>1)
        return (double)n*fact(n-1);
    return 1;
}

int main()
{
    int i,n;
    double sum=0.0,f=0.0;
    printf("enter a number: ");
    scanf("%d",&n);
    
    for(i=0; i<n; i++)
    {
        sum += (1/fact(i));
        printf("%lf\n",sum);
    }
    printf("final sum is:%lf",sum);
}