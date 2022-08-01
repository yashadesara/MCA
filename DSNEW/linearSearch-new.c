#include<stdio.h>
#include<conio.h>

void main()
{
	int array[10],search,n,i,count=0;
	
	printf("enter number of elements:");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
		scanf("%d",&array[i]);
		
	printf("enter search elements:");
	scanf("%d",&search);
	
	for(i=0; i<n; i++)
	{
		if(array[i] == search)
		{
			printf("found at %d postition",i);
			count++;
			break;
		}
	}
	if(count==0)
		printf("not found");
				
}

