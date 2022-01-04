#include<stdio.h>
#include<conio.h>
int main()
{	
	int a[50];
	int n,i,*p;
	int max,min;
	int mp=0,np=0;
	printf("enter length of n :");
	scanf("%d",&n);

	printf("enter elements of array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	p=&a[0];
	max = *p;
	min = *p;
	for(i=0;i<n;i++)
	{
		if(*p>=max)
		{
			max = *p;
			mp = i+1;
		}
		if(*p<=min)
		{
			min = *p;
			np=i+1;
		}
		p++;
	}
	printf("\n");
	printf("Maximum value is :");
	printf("%d pos is : %d\n",max,mp);
	printf("Minimum value is :");
	printf("%d pos is : %d\n",min,np);
	getch();
	return 0;
}

