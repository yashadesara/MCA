#include<stdio.h>
#include<conio.h>

int a[10][10],m,n;

void create()
{
	int i,j;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
			scanf("%d",&a[i][j]);
	}
}

void print()
{
	int i,j;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int a[10][10];
	clrscr();
	printf("enter rows x cols in matrix:\n");
	scanf("%d %d",&m,&n);
	create();
	printf("matrix is:\n");
	print();
	getch();
}