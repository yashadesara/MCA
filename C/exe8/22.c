#include<stdio.h>
#include<conio.h>

void main()
{
	int n,i,j,fact,sign=-1;
	float x,pow,res=0;
	printf("enter number X: \n");
	scanf("%f",&x);

	printf("enter number N: \n");
	scanf("%d",&n);

	x = x*3.14/180;

	for(i=1; i<=n; i+=2)
	{
		pow=1;
		fact=1;
		for(j=1; j<=i; j++)
		{
			pow = pow * x;
			fact = fact * j;
		}
		sign = sign*-1;
		res += sign*(pow/fact);
	}

	printf("sin %0.2f & %f",x,res);
}