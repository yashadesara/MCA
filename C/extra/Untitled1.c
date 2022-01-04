#include<stdio.h>

int main()
{
	int n,i,a[10],min,max;
	printf("enter length n: ");
	scanf("%d",&n);
	printf("enter elements: ");
	
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);	
		
	min = a[0];
	max = a[0];
	
	for(i=0; i<n; i++)
	{
		if(a[i]<=min)
			min = a[i];
		if(a[i]>=max)
			max = a[i];
	}
	printf("min is: %d\n",min);	
	printf("max is: %d",max);		
}
