#include<stdio.h>
#include<conio.h>

void main()
{
	int a[10],i,n,mem,flag=0;
	clrscr();
	printf("enter length of set a:\n");
	scanf("%d",&n);

	printf("enter elements of set a:\n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);

	printf("enter elements to search:\n");
	scanf("%d",&mem);

	for(i=0; i<n; i++)
	{
		if(a[i]==mem)
			flag++;
	}
	if(flag==1)
		printf("member");
	else
		printf("not memeber");
	getch();
}
