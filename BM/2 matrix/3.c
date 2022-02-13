/*Find Transpose of matrix A and of matrix B. Find (A' + B') and (A' − B').
Check whether (A' + B') = (A + B)' and (A' − B') = (A − B)'.*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int i, j, m, n, p, q, A[10][10], B[10][10], At[10][10], Bt[10][10];
	int sum1[10][10], sum2[10][10], At1[10][10];
	int diff1[10][10], diff2[10][10], At2[10][10];
	printf("Enter the no.of rows and no. of columns of for matrix A = \n");
	scanf("%d%d", &m, &n);
	printf("Enter the elements of matrix A = \n");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	printf("Enter the no.of rows and no. of columns of matrix B = \n");
	scanf("%d%d", &p, &q);
	if ((m != p) || (n != q))
	{
printf("Order of Matrix A and Matrix B must be same otherwise matrix Addition and matrix Subtraction are not possible. \n");
	}
	else
	{
		printf("Enter the elements of matrix B = \n");
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &B[i][j]);
		//Code for the Transpose of martrix A, i.e., A'
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				At[j][i] = A[i][j];
		printf("Transpose of given matrix A' is = \n");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%d\t", At[i][j]);
			printf("\n");
		}
		//Code for the Transpose of martrix B, i.e., B'
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				Bt[j][i] = B[i][j];
		printf("Transpose of given matrix B' is = \n");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%d\t", Bt[i][j]);
			printf("\n");
		}
		//Code for the Addition of Transpose of two matrices, i.e., A' + B'
		printf("Addition of Transpose of two matrices A' + B' is = \n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				sum1[i][j] = At[i][j] + Bt[i][j];
				printf("%d\t", sum1[i][j]);
			}
			printf("\n");
		}
		//Code for Addition of two matrices, i.e., A + B
		printf("Addition of two matrices A + B is = \n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				sum2[i][j] = A[i][j] + B[i][j];
				printf("%d\t", sum2[i][j]);
			}
			printf("\n");
		}
		//Code for the Transpose of martrix (A + B), i.e., (A + B)'
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				At1[j][i] = sum2[i][j];
		printf("Transpose of given matrix (A + B)' is = \n");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%d\t", At1[i][j]);
			printf("\n");
		}
		//Code for the comparision of (A' + B') = (A + B)'
		if (sum1[i][j] == At1[i][j])
			printf("(A' + B') = (A + B)' is possible & TRUE \n");
		else
			printf("(A' + B') = (A + B)' is NOT possible & FALSE \n");
		//Code for the Subtraction of Transpose of two matrices, i.e., A' − B'
		printf("Subtraction of Transpose of two matrices A' − B' is = \n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				diff1[i][j] = At[i][j] - Bt[i][j];
				printf("%d\t", diff1[i][j]);
			}
			printf("\n");
		}
		//Code for Subtraction of two matrices, i.e., A − B
		printf("Subtraction of two matrices A − B is = \n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				diff2[i][j] = A[i][j] - B[i][j];
				printf("%d\t", diff2[i][j]);
			}
			printf("\n");
		}
		//Code for the Transpose of martrix (A − B), i.e., (A − B)'
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				At2[j][i] = diff2[i][j];
		printf("Transpose of given matrix (A − B)' is = \n");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%d\t", At2[i][j]);
			printf("\n");
		}
		//Code for the comparision of (A' − B') = (A − B)'
		if (diff1[i][j] == At2[i][j])
			printf("(A' − B') = (A − B)' is possible & TRUE");
		else
			printf("(A' − B') = (A − B)' is NOT possible & FALSE");
	}
}
