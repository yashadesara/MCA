#include<stdio.h>
#include<conio.h>
int main()
{
	int i,n,j,a[5];
	printf("enter the element of array");

	for(i=0;i<5;i++)
	{
		 scanf("%d",&a[i]);

	}
	printf("array Is :");
	for(i=0;i<5;i++)
	{
		printf("%d",a[i]);
	}
		   i--;
	printf("revrse array : ");
	for(j=0;j<i;j++)
	{
		n = a[j];
		a[j] = a[i];
		a[i] = n;
		i--;
	}
	for(i=0;i<5;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}