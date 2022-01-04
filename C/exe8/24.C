#include<stdio.h>
#include<conio.h>
#include<math.h>


float height(float l,float deg)
{
	float t;
	t = l*sin(deg*3.14/180);
	return t;
}

void main()
{
	float l,deg,t;
	clrscr();
	printf("enter l:");
	scanf("%f",&l);

	printf("enter deg:");
	scanf("%f",&deg);

	t = height(l,deg);
	printf("height is : %f",t);
	getch();
}
