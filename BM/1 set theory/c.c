/*Find out the number of elements of a given set.*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int x[10], n, i;
	printf("\n Enter how many elements you required in set A:- ");
	scanf("%d", &n);
	printf("\n Please enter the elements:-");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	printf("Size of the given set A is %d \n", n);
}
