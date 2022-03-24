// #include<stdio.h>

// void main()
// {
// 	int a[10],n,i,j,temp;
// 	printf("enter length of A:");
// 	scanf("%d",&n);
	
// 	printf("enter element of A:");
// 	for(i=0; i<n; i++)
// 		scanf("%d",&a[i]);
		
// 	for(i=0; i<n; i++)
// 	{
// 		for(j=0; j<n-i-1; j++)
// 		{
// 			if(a[j]>a[j+1])
// 			{
// 			 	temp=a[j];
// 				a[j]=a[j+1];
// 				a[j+1]=temp;
// 			}//if end
// 		}//j++
// 	}//i++
	
// 	for(i=0; i<n; i++)
// 		printf("%d ",a[i]);
// }


// via structure method.

#include<stdio.h>
struct bubble_sort
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
	struct bubble_sort b;
	int i,j,temp;
	printf("enter length of A:");
	scanf("%d",&b.n);
	
	printf("enter element of A:");
	for(i=0; i<b.n; i++)
		scanf("%d",&b.a[i]);
		
	for(i=0; i<b.n; i++)
	{
		for(j=0; j<b.n-i-1; j++)
		{
			if(b.a[j]>b.a[j+1])
			{
			 	temp=b.a[j];
				b.a[j]=b.a[j+1];
				b.a[j+1]=temp;
			}//if end
		}//j++
	}//i++
	
	for(i=0; i<b.n; i++)
		printf("%d ",b.a[i]);
		
	printfile(b.a,b.n);
}

