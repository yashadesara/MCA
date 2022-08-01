#include<stdio.h>

void main()
{
	int i,j,n,a[10],min,swap;
	printf("enter length: ");
	scanf("%d",&n);
	
	printf("enter element: ");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	for(i=0; i<n-1; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(a[min]>a[j])
				min=j;
		}
		if(min!=i)
		{
			swap=a[i];
			a[i]=a[min];
			a[min]=swap;
		}
	}
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
}
