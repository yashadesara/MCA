#include <stdio.h>

void main()
{
    int i,n,ans=1;
    printf("enter length n:");
    scanf("%d",&n);
    
    for(i=1; i<=n; i++)
    {
        if(i%2!=0)
        {
            ans = 1;
            printf("%d\n",ans);
        }
        else
        {
            ans = -1;
            printf("%d\n",ans);
        } 
    }
}