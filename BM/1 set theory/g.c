/*difference and symmatric difference of set.*/
#define MAX 30
#include <stdio.h>
#include <conio.h>

void Create(int set[]);
void Print(int set[]);
void Difference(int set1[], int set2[], int set3[]);
void Symmdiff(int set1[], int set2[], int set3[]);
int member(int set[], int x);
int main()
{
	int set1[MAX], set2[MAX], set3[MAX];
	int x, op;
	set1[0] = set2[0] = set3[0] = 0;
	do
	{
		printf("\n 1)Create \n 2)Print \n 3)Difference \n 4)Symmetrec Difference \n 5) Quit ");
			printf("\n Enter Your Choice = ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			printf("\n Creting First Set A = ");
			Create(set1);
			printf("\n Creating Second Set B = ");
			Create(set2);
			break;
		case 2:
			printf("\n Print the elements of First Set A = \n");
			Print(set1);
			printf("\n Print the elements of Second Set B = \n");
			Print(set2);
			break;
		case 3:
			Difference(set1, set2, set3);
			Print(set3);
			break;
		case 4:
			Symmdiff(set1, set2, set3);
			Print(set3);
			break;
		}
		printf("\n press any key to continue.....");
		getch();
	} while (op != 5);
}
/*creates set[] with initial elements*/
void Create(int set[])
{
	int n, i, x;
	set[0] = 0; /*make it a null set*/
	printf("\n No. of elements in the set is = ");
	scanf("%d", &n);
	printf("\n enter set elements are = ");
	for (i = 1; i <= n; i++)
		scanf("%d", &set[i]);
	set[0] = n; //Number of elements.
}
void Print(int set[])
{
	int i, n;
	n = set[0]; /* number of elements in the set */
	printf("\n Members of the set are = ");
	for (i = 1; i <= n; i++)
		printf("%d ", set[i]);
}
int member(int set[], int x)
{
	int i, n;
	n = set[0]; /* number of elements in the set*/
	for (i = 1; i <= n; i++)
		if (x == set[i])
			return (1);
	return (0);
}
/*difference of set1[] and set2[] is stored in set3[]*/
void Difference(int set1[], int set2[], int set3[])
{
	int i, n;
	n = set1[0]; /* number of elements in the set*/
	set3[0] = 0; /*make it a null set*/
	for (i = 1; i <= n; i++)
		if (!member(set2, set1[i]))
			set3[++set3[0]] = set1[i]; // insert and increment no. of elements
}
void Symmdiff(int set1[], int set2[], int set3[])
{
	int i, n;
	n = set1[0]; /* number of elements in the set*/
	set3[0] = 0; /*make it a null set*/
	//Calculate set1-set2
	for (i = 1; i <= n; i++)
		if (!member(set2, set1[i]))
			set3[++set3[0]] = set1[i]; // insert and increment no. of elements
	//Calculate set2-set1
	n = set2[0];
	for (i = 1; i <= n; i++)
		if (!member(set1, set2[i]))
			set3[++set3[0]] = set2[i]; // insert and increment no. of elements
}
