#include<stdio.h>
#include<conio.h>

void main()
	{
	int i,j,k,r1,c1,r2,c2,a[100][100],b[100][100],mul[100][100];
	clrscr();

	printf("enter mxn for A:");
	scanf("%d %d",&r1,&c1);

	printf("enter nxp for B:");
	scanf("%d %d",&r2,&c2);

	if()
	{
		printf("not possible");
	}
	{
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			scanf("%d",&a[i][j]);
	}

	for(i=0; i<r2; i++)
	{
		for(j=0; j<c2; j++)
			scanf("%d",&b[i][j]);
	}

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		{
			mul[i][j]=0;
			for(k=0; k<c1; k++)
				mul[i][j] += a[i][k] * b[k][j];
		}
	}

	printf("(A*B) is:\n");
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			printf("%d ",mul[i][j]);
		printf("\n");
	}
	}
	getch();
}
