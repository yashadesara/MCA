#include<stdio.h>
#include<conio.h>

void main()
{
	int i,j,a,flag=0,count=0;
	printf("enter starting the value :");
	scanf("%d",&a);

	for(i=2;count<a;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag++;
				break;
			}
		}
		if(flag==0)
		{
			count++;
			printf("\n %d",i);
		}
		flag=0;
	}
	
}

