/* Write a Program to calculate Union, Intersection and Complement of a set*/
#include <stdio.h>

#define MAX 30
void Create(int set[]);
void Print(int set[]);
void Union(int set1[], int set2[], int set3[]);
void Intersection(int set1[], int set2[], int set4[]);
void Difference(int set1[], int set2[], int set5[]);
int member(int set[], int x);
int main()
{
	int set1[MAX], set2[MAX], set3[MAX];
	int x, op, *tmp;
	set1[0] = set2[0] = set3[0] = 0;
	printf("-----Set Operations-----\n");
	printf("\n 1) Create Two Sets");
	printf("\n 2) Print The Sets");
	printf("\n 3) A U B --- A Union B");
	printf("\n 4) A n B --- A Intersection B");
	printf("\n 5) U - A --- Complement of A");
	printf("\n 6) Exit from program \n");
	do
	{
		printf("\n Enter Your Choice = ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			printf("\n Create Set A = ");
			Create(set1);
			printf("\n Create Set B = ");
			Create(set2);
			break;
		case 2:
			printf("\n Print Set A = \n");
			Print(set1);
			printf("\n Print Set B = \n");
			Print(set2);
			break;
		case 3:
			Union(set1, set2, set3);
			Print(set3);
			break;

		case 4:
			Intersection(set1, set2, set3);
			Print(set3);
			break;
		case 5:
			Union(set1, set2, set3);
			tmp = set3;
			Difference(tmp, set1, set3);
			Print(set3);
			break;
		case 6:
			exit(0);
		default:
			printf("\n Please Enter your valid choice \n");
			break;
		}
	} while (op != 6);
	return 0;
}
void Create(int set[])
{
	int n, i, x;
	set[0] = 0;
	printf("\n No. of elements in the set = ");
	scanf("%d", &n);
	printf("Enter set elements = ");
	for (i = 1; i <= n; i++)
		scanf("%d", &set[i]);
	set[0] = n;
}
void Print(int set[])
{
	int i, n;
	n = set[0];
	printf("\n Members of the set = ");
	for (i = 1; i <= n; i++)
		printf("%d ", set[i]);
}
void Union(int set1[], int set2[], int set3[])
{
	int i, n;
	set3[0] = 0;
	n = set1[0];
	for (i = 0; i <= n; i++)
		set3[i] = set1[i];
	n = set2[0];
	for (i = 1; i <= n; i++)
		if (!member(set3, set2[i]))
			set3[++set3[0]] = set2[i];
}
int member(int set[], int x)
{
	int i, n;
	n = set[0];
	for (i = 1; i <= n; i++)
		if (x == set[i])
			return (1);
	return (0);
}
void Intersection(int set1[], int set2[], int set3[])
{
	int i, n;
	set3[0] = 0;
	n = set1[0];
	for (i = 1; i <= n; i++)
		if (member(set2, set1[i]))
			set3[++set3[0]] = set1[i];
}
void Difference(int set1[], int set2[], int set3[])
{
	int i, n;
	n = set1[0];
	set3[0] = 0;
	for (i = 1; i <= n; i++)
		if (!member(set2, set1[i]))
			set3[++set3[0]] = set1[i];
}