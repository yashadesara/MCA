#include<stdio.h>

int main()
{
	int i,n,fact=1,fibo,a=0,b=1;
	printf("enter n: ");
	scanf("%d",&n);
	
	printf("fibo series is: \n");
	printf("%d\n",a);
	printf("%d\n",b);
	for(i=1; i<=n-2; i++)
	{
		fibo=a+b;
		printf("%d\n",fibo);	
		a=b;
		b=fibo;
	}
	
	for(i=1; i<=n; i++)
		fact *= i;
	printf("factorial is %d",fact);
}

