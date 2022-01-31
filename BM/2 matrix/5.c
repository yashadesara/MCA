/*Write a program to generate Null matrix and Unit matrix of order n.
Multiply matrix A with a Unit matrix.*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int m, n, i, j, k, sum = 0;
	int null[100][100], unit[100][100], first[10][10], mul[10][10];
	printf("Enter value to create null and unit matrix of order n =");
	scanf("%d", &n);
	printf("Null matrix is = \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			null[i][j] = 0;
			unit[i][j] = 0;
			if (i == j)
			{
				unit[i][j] = 1;
			}
			printf("%d", null[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n");
	printf("Unit matrix is = \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d", unit[i][j]);
		}
		printf("\n");
	}
	/*Process for entered the value of first matrix A.*/
	printf("Enter the no.of rows and no. of columns of first matrix = \n");
	scanf("%d%d", &m, &n);
	printf("Enter the elements of first matrix A = \n");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &first[i][j]);
	/*Process to do matrix multiplication i.e., A*I = A = I*A.*/
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				sum = sum + first[i][k] * unit[k][j];
			}
			mul[i][j] = sum;
			sum = 0;
		}
	}
	printf("Multiplication of two matrices A*I = \n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d\t", mul[i][j]);
		printf("\n");
	}
}