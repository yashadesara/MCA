/*Test whether two given sets are equal or not.*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int i, j, a, b, x[10], y[10], isequal = 1, flag;
	printf("\n Enter the size of set X=");
	scanf("%d", &a);
	printf("\n Please enter the elements of set X=");
	for (i = 0; i < a; i++)
	{
		scanf("%d", &x[i]);
	}
	printf("\n Enter the size set Y=");
	scanf("%d", &b);
	printf("\n Please enter the elements of set Y=");
	for (i = 0; i < b; i++)
	{
		scanf("%d", &y[i]);
	}
	for (i = 0; i < a; i++)
	{
		flag = 0;
		for (j = 0; j < b; j++)
		{
			if (x[i] == y[j])
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			isequal = 0;
			break;
		}
	}
	if (isequal == 1)
	{
		printf("\n Set X and Set Y both are Equal Sets");
	}
	else
	{
		printf("\n Set X and Set Y both are Not Equal Sets");
	}
}
