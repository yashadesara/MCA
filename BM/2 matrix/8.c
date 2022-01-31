/*Evaluate Scalar Product of a Matrix A: For example, k.A, where k is a constant
(number).*/
#include <stdio.h>
#include <conio.h>
int main()
{
	int i, j, m, n, A[10][10], num;
	printf("Enter the no.of rows and no. of columns of matrix:- \n");
	scanf("%d%d", &m, &n);
	printf("Enter the elements of matrix:- \n");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	/* Input multiplier K from user */
	printf("Enter any number to multiply with matrix A = ");
	scanf("%d", &num);
	/* Perform scalar multiplication of a given matrix */
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			/* (KAij) = K . Aij */
			A[i][j] = num * A[i][j];
		}
	}
	/* Print result of scalar multiplication of a given matrix */
	printf("\n Resultant matrix K.A is = \n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("\t %d", A[i][j]);
		}
		printf("\n");
	}
}