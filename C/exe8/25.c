#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	float l,theta,x,y,r;
	printf("Enter the distance from a reference point");
	scanf("%f",&r);
	printf("\nEnter angle from a reference direction:");
	scanf("%f",&theta);
	x = r * cos(theta);
	y = r * sin(theta);
	printf("\nThe coordinates are:%f %f\n",x,y);
	getch();
	return;
}
