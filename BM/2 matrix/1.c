/* Write a function to Create a Matrix of size m x n and another function to Print a
Marix of size m x n*/
#include <stdio.h>
#include <conio.h>
#define SIZE 100

void Create();
void Print();

int matrix[SIZE][SIZE], row, col;
int main()
{

	printf("Input no. of rows = ");
	scanf("%d", &row);
	printf("Input no. of columns =");
	scanf("%d", &col);
	printf("Insert no. elements of matrix = \n");
	Create();
	printf("The given matrix is= \n");
	Print();
	getch();
}
void Create()
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("Row %d column %d = ", i + 1, j + 1);
			scanf("%d", &matrix[i][j]);
		}
	}
}
void Print()
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
}