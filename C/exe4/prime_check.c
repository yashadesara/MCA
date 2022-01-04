#include <stdio.h>
#include <conio.h>

void main()
{
	int a, i, j, flag = 0;

	printf("enter the value of prime no");
	scanf("%d", &a);

	if (a == 0 || a == 1)
		printf("not prime %d :", a);
	else
	{
		for (i = 2; i < a; i++)
		{

			flag = 0;
			if (a % i == 0)
			{
				flag++;
				printf("not prime %d :", a);
				break;
			}
		}
		if (flag == 0)
			printf("Prime no : %d", a);
	}

}