/* Given an element value, check whether it is a member of the set or not.*/
#include <stdio.h>
#include <conio.h>
int main()
{
	int i, m, n, flag = 0;
	int a[10];
	printf("How many elements you want to enter= \n");
	scanf("%d", &n);
	printf("Enter element in the set A:- \n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Enter the element you want to search:- \n");
	scanf("%d", &m);
	for (i = 0; i < n; i++)
	{
		if (a[i] == m)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("value is not member of the set A");
	else
		printf("value is member of the set A");
}