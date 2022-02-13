/*Start with a NULL set and add elements one-by-one: Use different ways of
implementing sets and understand the pros and cons of each of these methods.*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int set[10], i, n;
	printf("Enter the elements = ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &set[i]);
		if ((set[i] == 0) || (set[i] == '\0'))
		{
			printf("ZERO is the member of the given set. \n");
		}
		else
		{
			//Skip the loop here.
		}
	}
	printf("\n Element of the given set is = {");
	for (i = 0; i < n; i++)
	{
		if (i == n-1)
		{
			printf("%d", set[i]);
		}
		else
		{
			printf("%d ,", set[i]);
		}
	}
	printf("}");
}
