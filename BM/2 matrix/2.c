/*Create 2 matrices A and B of size (m x n). Find (A + B) and (A – B) of two
matrices.*/
#include <stdio.h>
#include <conio.h>

void main()
{
	int m, n, p, q, i, j, first[10][10], second[10][10], sum[10][10], diff[10][10];
	printf("Enter no.of rows and no.of columns of first matrix:- \n");
	scanf("%d%d", &m, &n);
	printf("Enter the elements of first matrix A= \n");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &first[i][j]);
	printf("Enter no.of rows and no.of columns of second matrix:- \n");
	scanf("%d%d", &p, &q);
	if ((m != p) || (n != q))
	{
printf("Order of Matrix A and Matrix B must be same otherwise A+B and A-B are not possible. \n");
	}
	else
	{
		printf("Enter the elements of second matrix B:- \n");
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &second[i][j]);
		printf("Addition of two matrices A+B is:-\n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				sum[i][j] = first[i][j] + second[i][j];
				printf("%d\t", sum[i][j]);
			}
			printf("\n");
		}
		printf("Subtraction of two matrices A-B is:-\n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				diff[i][j] = first[i][j] - second[i][j];
				printf("%d\t", diff[i][j]);
			}
			printf("\n");
		}
	}
}
