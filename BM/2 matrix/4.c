/*Add matrix A and Null matrix(O) means A + O.
Subtract Null matrix(O) from matrix A means A − O.*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int n, i, j, null[100][100], A[10][10], sum[10][10], diff[10][10];
	printf("Enter size to create Null matrix of order nxn =");
	scanf("%d", &n);
	printf("Null matrix is = \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			null[i][j] = 0;
			printf("%d", null[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	/*Code for entered the value of first matrix A.*/
	printf("Enter size of first matrix A of order nxn = \n");
	scanf("%d", &n);
	printf("Enter the elements of first matrix A = \n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	/*Addition of two matrices:- A(matrix) + O(Null matrix).*/
	printf("Addition of two matrices A + O is = \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			sum[i][j] = A[i][j] + null[i][j];
			printf("%d\t", sum[i][j]);
		}
		printf("\n");
	}
	/*Subtraction of two matrices:- A(matrix) - O(Null matrix).*/
	printf("Subtraction of two matrices A − O is = \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			diff[i][j] = A[i][j] - null[i][j];
			printf("%d\t", diff[i][j]);
		}
		printf("\n");
	}
	printf("A + O = A = A − O");
}
