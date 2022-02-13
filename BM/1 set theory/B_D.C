#include<stdio.h>
#include<conio.h>

void main()
{
	int a[10],b[10],intersec[10],uni[10],i,j,n1,n2,k=0,k2=0;
	clrscr();

	printf("enter length:\n");
	scanf("%d",&n1);
	printf("enter element:\n");
	for(i=0; i<n1; i++)
		scanf("%d",&a[i]);

	printf("enter length:\n");
	scanf("%d",&n2);
	printf("enter element:\n");

	for(i=0; i<n2; i++)
		scanf("%d",&b[i]);

	// find intersection.
	for(i=0; i<n1; i++)
	{
		for(j=0; j<n2; j++)
		{
			if(a[i]==b[j])
			{
				intersec[k]=a[i];
				k++;
			}
		}
	}

	//find union.
	for(i=0; i<n1; i++)
	{
		for(j=0; j<k2; j++)
		{
			if(uni[j]==a[i])
				break;
		}
		if(j==k2)
		{
			uni[k2]=a[i];
				k2++;
		}
	}

	for(i=0; i<n2; i++)
	{
		for(j=0; j<k2; j++)
		{
			if(uni[j]==b[i])
				break;
		}
		if(j==k2)
		{
			uni[k2]=b[i];
				k2++;
		}
	}


	printf("intersection is:\n");
	for(i=0; i<k; i++)
		printf("%d\n",intersec[i]);

	printf("union is:\n");
	for(i=0; i<k2; i++)
		printf("%d\n",uni[i]);
	getch();
}