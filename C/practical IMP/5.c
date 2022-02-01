#include<stdio.h>

int main()
{
	int i,n,a[10],min,max;
	printf("length of erray: ");
	scanf("%d",&n);
	
	printf("\nelements of erray:\n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);	

	min = a[0];
	max = a[0];
	for(i=0; i<n; i++)
	{
		if(a[i]>=max)
			max=a[i];
		if(a[i]<=min)
			min=a[i];
	}
	printf("min is: %d\n",min);
	printf("max is: %d",max);	
}


int main()
{
	int i,n,a[10],min,max,*p;
	printf("length of erray: ");
	scanf("%d",&n);
	
	printf("\nelements of erray:\n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);	

	p=&a[0];
	max = *p;
	min = *p;
	
	for(i=0; i<n; i++)
	{
		if(*p>=max)
			max = *p;
		if(*p<=min)
			min = *p;
		p++;
	}
	printf("min is: %d\n",min);
	printf("max is: %d",max);	
}
