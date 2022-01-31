//Given a positive integer, find whether it is a prime number or a composite number. Write an efficient algorithm.

#include<stdio.h>

int main()
{
	int i=2,no;
	printf("Enter a number: ");
	scanf("%d",&no);
	
	for(i=2; i<=no-1; i++)
	{
		if(no%i==0)
		{
			printf("not prime");
			break;
		}	
	}
	
	if(i==no)
	{
		printf("prime");
	}
}
