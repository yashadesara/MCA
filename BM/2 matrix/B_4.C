#include<stdio.h>
#include<conio.h>

void main()
{
	int i,j,a[10][10],nullM[10][10],r1,c1,r2,c2,sub[10][10];
	clrscr();

	printf("enter matrix A size: ");
	scanf("%d %d",&r1,&c1);
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		    scanf("%d",&a[i][j]);
	}
	printf("enter null matrix size: ");
	scanf("%d %d",&r2,&c2);

	if(r1!=r2 || c1!=c2)
		printf("Not Possible");
	else
	{

	for(i=0; i<r2; i++)
	{
		for(j=0; j<c2; j++)
		    nullM[i][j]=0;
	}

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		    sub[i][j] = a[i][j] - nullM[i][j];
	}
	printf("matrix A is\n");
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		    printf("%d ",a[i][j]);
		printf("\n");
	}

	printf("Null matrix is\n");
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		    printf("%d ",nullM[i][j]);
		printf("\n");
	}
	printf("(A-NULL) is\n");
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		    printf("%d ",sub[i][j]);
		printf("\n");
	}
	}
	getch();
}