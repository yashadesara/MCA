#include<stdio.h>
#include<conio.h>

void main()
{
	int a[10][10],b[10][10],add[10][10],sub[10][10],i,j,r1,c1,r2,c2;
	clrscr();
	printf("enter row x col for matrix A:");
	scanf("%d %d",&r1,&c1);
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			scanf("%d",&a[i][j]);
	}

	printf("enter row x col for matrix B: ");
	scanf("%d %d",&r2,&c2);
	for(i=0; i<r2; i++)
	{
		for(j=0; j<c2; j++)
			scanf("%d",&b[i][j]);
	}

	if(r1!=r2 || c1!=c2)
		printf("not possible");
	else
	{
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				add[i][j] = a[i][j] + b[i][j];
		}
		printf("(A+B) is:\n");
		for(i=0; i<r2; i++)
		{
			for(j=0; j<c2; j++)
				printf("%d ",add[i][j]);
			printf("\n");
		}

		for(i=0; i<r1; i++)
		{
			for(j=0; j<c2; j++)
				sub[i][j] = a[i][j] - b[i][j];
		}
		printf("(A-B) is:\n");
		for(i=0; i<r2; i++)
		{
			for(j=0; j<c2; j++)
				printf("%d ",sub[i][j]);
			printf("\n");
		}
	}

	getch();
}