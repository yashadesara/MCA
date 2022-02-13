/*Create a symmetric matrix A. Find matrix A'. Check whether A = A' or not ?*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int i, j, m, n, A[10][10], Transpose[10][10], count = 0;
	printf("Enter the no.of rows and no. of columns of matrix A = \n");
	scanf("%d%d", &m, &n);
	printf("Enter the elements of matrix A = \n");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			Transpose[j][i] = A[i][j];
	printf("Transpose of given matrix A is i.e., A' = \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d\t", Transpose[i][j]);
		printf("\n");
	}
	/*To check A = A' or not ???*/
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (A[i][j] == Transpose[i][j])
			{
				count++;
				if (count == (m * n))
				{
					printf("Yes, A = A', so matrix A is Symmetric matrix.");
					getch();
					return 0;
				}
			}
		}
	}
printf("No, A ≠ AT, so matrix A is not Symmetric matrix.");
return 0;
}