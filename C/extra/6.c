#include<stdio.h>
#include<conio.h>
int main()
{
	int a[50];
	int n,i,max,min;
	printf("enter length of n :");
	scanf("%d",&n);
	
	printf("enter elements of array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);	
	}
	
	max = a[0];
	min = a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>=max)
		{
			max = a[i];
		}
		if(a[i]<=min)
		{
			min = a[i];
		}		
	}
	printf("\n");
	printf("Maximum value is :");
	printf("%d\n",max);
	printf("Minimum value is :");
	printf("%d\n",min);
	getch();
	return 0;
}

