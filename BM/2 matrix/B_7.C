#include<stdio.h>
#include<conio.h>

int main()
	{
	int i,j,r1,c1,a[100][100],trans[100][100],flag=0,e=0;

	printf("enter mxn for A:");
	scanf("%d %d",&r1,&c1);
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			scanf("%d",&a[i][j]);
	}

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			trans[i][j] = a[j][i];
	}

	printf("transpose is:\n");
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			printf("%d ",trans[i][j]);
		printf("\n");
	}

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		{
			if(a[i][j]==trans[i][j])
			{
				flag++;
				if(flag==(r1*c1))
					e=1;
				else
					e=0;
			}
		}
	}

	printf("%d",flag);
	if(e==1)
		printf("A=At");
	else
		printf("Anot=At");
}
