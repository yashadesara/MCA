#include<stdio.h>
#include<conio.h>

void main()
{
	int a[10],i,n,flag=0;
	clrscr();
	printf("enter length of set a:\n");
	scanf("%d",&n);

	printf("enter elements of set a:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		flag++;
	}
	printf("length is: %d",flag);
	getch();
}
