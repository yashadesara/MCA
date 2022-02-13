#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,r1,c1,a[100][100],unit[100][100],mul[100][100];
	printf("enter unit matrix size: ");
	scanf("%d",&r1);
	
	for(i=0; i<r1; i++)
	{
		for(j=0; j<r1; j++)
		{
			unit[i][j]=0;
			if(i==j)
				unit[i][j]=1;
		}
	}
	printf("enter matrix A size: ");
	scanf("%d %d",&r1,&c1);
	
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			scanf("%d",&a[i][j]);
	}

	//multiplication
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		{
			mul[i][j]=0;
			for(k=0; k<c1; k++)
			{
				mul[i][j] += a[i][k] * unit[k][j];
			}
		}
	}

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			printf("%d ",unit[i][j]);
		printf("\n");
	}

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			printf("%d ",mul[i][j]);
		printf("\n");
	}
}
