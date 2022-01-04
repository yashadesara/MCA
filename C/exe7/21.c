#include <stdio.h>

int power(int b, int e)
{
    int result=1;
	for(e; e>0; e--)
	{
		result = result * b;
	}
	return result;
}

int main()
{
	int b, e, res;
	printf("Enter a base number: ");
	scanf("%d", &b);

	printf("Enter an exponent: ");
	scanf("%d", &e);

	res = power(b, e);
	printf("Answer = %d", res);
	return 0;
	
}