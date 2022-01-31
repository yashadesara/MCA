/*Take as input two matrices, A & B and print (A * B) and (B * A).
First check which ones out of (A * B) and (B * A) are possible to compute.*/

#include <stdio.h>
#include <conio.h>
int main()
{
	int m, n, p, q, i, j, k, A[10][10], B[10][10], mul[10][10], sum = 0, flag = 0;
	printf("Enter the no.of rows and no. of columns of A matrix = \n");
	scanf("%d%d", &m, &n);
	printf("Enter the no.of rows and no. of columns of B matrix = \n");
	scanf("%d%d", &p, &q);
	if (n != p)
		printf("Matrix multiplication A*B is not possible.\n");
	else
	{
		printf("Enter the elements of first matrix A = \n");
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &A[i][j]);
		printf("Enter the elements of second matrix B = \n");
		for (i = 0; i < p; i++)
			for (j = 0; j < q; j++)
				scanf("%d", &B[i][j]);
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < q; j++)
			{
				for (k = 0; k < p; k++)
				{
					sum = sum + A[i][k] * B[k][j];
				}
				mul[i][j] = sum;
				sum = 0;
			}
		}
		printf("Multiplication of two matrices A*B is = \n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < q; j++)
				printf("%d\t", mul[i][j]);
			printf("\n");
		}
		flag = 1;
	}
	/*Code for matrix multiplication B*A.*/
	if (q != m)
		printf("Matrix multiplication B*A is not possible.\n");
	else
	{
		if (flag != 1)
		{
			printf("Enter the elements of A matrix = \n");
			for (i = 0; i < m; i++)
				for (j = 0; j < n; j++)
					scanf("%d", &A[i][j]);
			printf("Enter the elements of B matrix = \n");
			for (i = 0; i < p; i++)
				for (j = 0; j < q; j++)
					scanf("%d", &B[i][j]);
		}
		for (i = 0; i < p; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < m; k++)
				{
					sum = sum + B[i][k] * A[k][j];
				}
				mul[i][j] = sum;
				sum = 0;
			}
		}
		printf("Multiplication of two matrices B*A is = \n");
		for (i = 0; i < p; i++)
		{
			for (j = 0; j < n; j++)
				printf("%d\t", mul[i][j]);
			printf("\n");
		}
	}
}