#include<stdio.h>
#include<conio.h>

int main()
{
	int num1,num2;
	int ans,ans2;

	printf("enter value for number 1 :");
	scanf("%d",&num1);

	printf("\n enter value for number 2 :");
	scanf("%d",&num2);

	ans=num1%num2;
	printf("\n reminder is : %d",ans);

	ans2=num1/num2;
	printf("\n Quotient is : %d",ans2);
	return 0;
}