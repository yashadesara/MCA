#include<stdio.h>
#include<conio.h>

int subset(int x[10],int a[10],int n1,int n2)
{
	int i,j;
	for(i=0; i<n1; i++)
	{
		for(j=0; j<n2; j++)
		{
			if(x[i]==a[j])
				break;
		}
		if(j==n1)
			return 0;
	}
	return 1;
}

int main()
{
	int x[10],a[10],i,j,n1,n2;

	printf("enter length:\n");
	scanf("%d",&n1);
	printf("enter element:\n");
	for(i=0; i<n1; i++)
		scanf("%d",&x[i]);

	printf("enter length:\n");
	scanf("%d",&n2);
	printf("enter element:\n");

	for(i=0; i<n2; i++)
		scanf("%d",&a[i]);

	if(subset(x,a,n1,n2))
		printf("subset");
	else
		printf("not subset");

}
