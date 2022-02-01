#include<stdio.h>

int swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	printf("%d ",*a);
	printf("%d ",*b);
}

int main()
{
	int a=10,b=20;
	swap(&a,&b);	
}


