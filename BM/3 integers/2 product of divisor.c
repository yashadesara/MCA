#include<stdio.h>

int main()
{
	int n,i,j,isPrime;
	
	printf("enter a number: ");
	scanf("%d",&n);
	
	for(i=2; i<=n; i++)
	{
		if(n%i==0)
		{
			isPrime=1;
			for(j=2; j<=i/2; j++)
			{
				if(i%j==0)
				{
					isPrime=0;
					break;
				}
			}
			
			if(isPrime==1)
				printf(" %d",i);
		}
	}
}
