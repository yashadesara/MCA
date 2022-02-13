#include<stdio.h>
#include<conio.h>

void main()
{
	int a[10],b[10],i,j,n1,n2,flag,isequal=1;
	clrscr();

	printf("enter length:\n");
	scanf("%d",&n1);
	printf("enter element:\n");
	for(i=0; i<n1; i++)
		scanf("%d",&a[i]);

	printf("enter length:\n");
	scanf("%d",&n2);
	printf("enter element:\n");
	for(i=0; i<n2; i++)
		scanf("%d",&b[i]);

	for(i=0; i<n1; i++)
	{
		flag=0;
		for(j=0; j<n2; j++)
		{
			if(a[i]==b[j])
				flag=1;
		}
		if(flag==0)
		{
			isequal=0;
			break;
		}
	}
	if(isequal==1)
		printf("sets are equal");
	else
		printf("not equal");
	getch();
}