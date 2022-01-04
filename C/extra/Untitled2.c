#include<stdio.h>

int swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a,b;
	printf("enter a:");
	scanf("\n%d",&a);
	printf("enter b:");
	scanf("%d",&b);
	swap(&a,&b);
	printf("a is: %d\nb is: %d",a,b);
}
