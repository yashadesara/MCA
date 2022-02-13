#include<stdio.h>
#include<conio.h>

void main()
	{
	int i,j,r1,c1,a[100][100],scaler[100][100],k;
	clrscr();

	printf("enter mxn for A:");
	scanf("%d %d",&r1,&c1);
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			scanf("%d",&a[i][j]);
	}

	printf("enter scaler K for multiply :");
	scanf("%d",&k);
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			scaler[i][j] = a[j][i] * k;
	}

	printf("scaler is:\n");
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			printf("%d ",scaler[i][j]);
		printf("\n");
	}
	getch();
}
