// #include<stdio.h>

// void main()
// {
// 	int i,n,a[10],search;
// 	printf("enter length: ");
// 	scanf("%d",&n);
	
// 	printf("enter element: ");
// 	for(i=0; i<n; i++)
// 		scanf("%d",&a[i]);
		
// 	printf("enter search: ");
// 	scanf("%d",&search);
		
// 	for(i=0; i<n; i++)
// 	{
// 		if(search==a[i])
// 		{
// 			printf("position at: %d ",i+1);
// 			break;
// 		}
// 	}
// 	if(i==n)
// 	{
// 		printf("not found %d",search);
// 		break;
// 	}
// }


//via structure method
#include<stdio.h>

struct linear_search
{
	int a[10],n;
};

void printfile(int a[10],int n)
{
	FILE *fp;
	int i;
	fp = fopen("demo.txt","w");
	for(i=0; i<n; i++)
		fprintf(fp,"%d ",a[i]);
	printf("\nprinted");
	fclose(fp);
}

void main()
{
	struct linear_search l;
	int i,search;
	printf("enter length: ");
	scanf("%d",&l.n);
	
	printf("enter element: ");
	for(i=0; i<l.n; i++)
		scanf("%d",&l.a[i]);
		
	printf("enter search: ");
	scanf("%d",&search);
		
	for(i=0; i<l.n; i++)
	{
		if(search==l.a[i])
		{
			printf("position at: %d ",i+1);
			break;
		}
		
	}
	if(i==l.n)
		printf("not found");

	printfile(l.a,l.n);
}
