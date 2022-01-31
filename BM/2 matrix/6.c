/*Create matrix A of size (m x n) and matrix B of size (n x p). Multiply matrix A and
matrix B to get matrix C of size (m x p). */
#include <stdio.h>
#include <conio.h>

int main()
{
	int m, n, p, q, i, j, k, sum = 0, first[10][10], second[10][10], mul[10][10];
	printf("Enter the no.of rows and no. of columns of first matrix:- \n");
	scanf("%d%d", &m, &n);
	printf("Enter the elements of first matrix A :- \n");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &first[i][j]);
	printf("Enter the no.of rows and no. of columns of second matrix:- \n");
	scanf("%d%d", &p, &q);
	if (n != p)
		printf("Matrix multiplication A*B is not possible.\n");
	else
	{
		printf("Enter the elements of second matrix B:- \n");
		for (i = 0; i < p; i++)
			for (j = 0; j < q; j++)
				scanf("%d", &second[i][j]);
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < q; j++)
			{
				for (k = 0; k < p; k++)
				{
					sum = sum + first[i][k] * second[k][j];
				}
				mul[i][j] = sum;
				sum = 0;
			}
		}
		printf("Multiplication of two matrices A*B:- \n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < q; j++)
				printf("%d\t", mul[i][j]);
			printf("\n");
		}
	}
}