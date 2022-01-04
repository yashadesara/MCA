#include <stdio.h>

void main()
{
    int i,n,ans=0,count=0;
    
    printf("enter length n:");
    scanf("%d",&n);
    
    for(i=1; count<n; i+=2)
    {
        if(count%2!=0)
        {
            ans -= i;
           
        }
        else
        {
            ans += i;
        } 
        count++;
    }
    printf("%d",ans);
}