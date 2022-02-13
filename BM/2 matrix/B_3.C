#include<stdio.h>
#include<conio.h>

int main()
{
	int a[10][10],b[10][10],abaddt[10][10],absubt[10][10],abadd[10][10],absub[10][10],transA[10][10],transB[10][10],addT[10][10],subT[10][10],i,j,r1,c1,r2,c2,flag=0;
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
	// find transpose of A
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			transA[i][j] = a[j][i];
	}
	printf("transpose of A\n");
	for(i=0; i<r1; i++)
			{
		for(j=0; j<c1; j++)
			printf("%d ",transA[i][j]);
		printf("\n");
	}

	// find transpose of B
	for(i=0; i<r2; i++)
	{
		for(j=0; j<c2; j++)
			transB[i][j] = b[j][i];
	}
	printf("transpose of A\n");
	for(i=0; i<r2; i++)
	{
		for(j=0; j<c2; j++)
			printf("%d ",transB[i][j]);
		printf("\n");
	}

	if(r1!=r2 || c1!=c2)
		printf("not possible");
	else
	{
		// find (At+Bt)
		printf("(At+Bt) is: \n");
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				addT[i][j] = transA[i][j] + transB[i][j];
		}
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				printf("%d ",addT[i][j]);
			printf("\n");
		}
		//find (At-Bt)
		printf("(At-Bt) is: \n");
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				subT[i][j] = transA[i][j] - transB[i][j];
		}
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				printf("%d ",subT[i][j]);
			printf("\n");
		}

		//find(A+B)
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				abadd[i][j] = a[i][j] + b[i][j];
		}
		//find(A-B)
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				absub[i][j] = a[i][j] - b[i][j];
		}
		//find (A+B)t
		printf("(A+B)t is:\n");
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				abaddt[i][j] = abadd[j][i];
		}
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				printf("%d ",abaddt[i][j]);
			printf("\n");
		}

		//find (A-B)t
		printf("(A-B)t is:\n");
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				absubt[i][j] = absub[j][i];
		}
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
				printf("%d ",absubt[i][j]);
			printf("\n");
		}
		//checking equality
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
			{
				if(addT[i][j] == abaddt[j][i] && subT[i][j] == absubt[j][i])
					flag=1;
				else
					flag=0;
			}
		}
		if(flag==1)
			printf("yes, (At+bt)=(A+B)t and (At-bt)=(A-B)t");
		else
			printf("no, (At+bt)not=(A+B)t and (At-bt)not=(A-B)t");
	}
}
