#include<stdio.h>

void main()
{
	int i,j,n,a[10],min,swap;
	printf("enter length: ");
	scanf("%d",&n);
	
	printf("enter element: ");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	for(i=0; i<n-1; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(a[min]>a[j])
				min=j;
		}
		if(min!=i)
		{
			swap=a[i];
			a[i]=a[min];
			a[min]=swap;
		}
	}
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
}


// via structure method.
// #include<stdio.h>

// struct selection_sort
// {
// 	int a[10],n;
// };

// void printfile(int a[10],int n)
// {
// 	FILE *fp;
// 	int i;
// 	fp = fopen("demo.txt","w");
// 	for(i=0; i<n; i++)
// 		fprintf(fp,"%d ",a[i]);
// 	printf("\nprinted");
// 	fclose(fp);
// }

// void main()
// {
// 	struct selection_sort s;
// 	int i,j,min,swap;
// 	printf("enter length: ");
// 	scanf("%d",&s.n);
	
// 	printf("enter element: ");
// 	for(i=0; i<s.n; i++)
// 		scanf("%d",&s.a[i]);
	
// 	for(i=0; i<s.n-1; i++)
// 	{
// 		min=i;
// 		for(j=i+1; j<s.n; j++)
// 		{
// 			if(s.a[min]>s.a[j])
// 				min=j;
// 		}
// 		if(min!=i)
// 		{
// 			swap=s.a[i];
// 			s.a[i]=s.a[min];
// 			s.a[min]=swap;
// 		}
// 	}
// 	for(i=0; i<s.n; i++)
// 		printf("%d ",s.a[i]);

// 	printfile(s.a,s.n);
// }
