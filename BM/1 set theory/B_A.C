#include<stdio.h>
#include<conio.h>

void main()
{
	int i,a[10],n;
	clrscr();
	printf("enter length of set a:");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
			printf("\nNull is element of all sets\n");
		else{}
	}
	for(i=0; i<n; i++)
		printf("%d\n",a[i]);
	getch();

}