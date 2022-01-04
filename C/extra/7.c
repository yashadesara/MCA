#include <stdio.h>

int main()
{
    int n,count=0,sum=0,mod;
    printf("enter n: ");
    scanf("%d",&n);
    
    for(count=0; n!=0; n/=10)       
    {
        mod=n%10;    
        sum=sum+mod;    
        count++;
    }
    printf("count is %d\n",count);
    printf("sum is %d",sum);
}
