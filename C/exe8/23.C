#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	float v,theta,h,t;
	printf("Enter the velocity:");
	scanf("%f",&v);
	printf("\n Enter angle of projection:");
	scanf("%f",&theta);
	t = sin(theta) * sin(theta);
	h= (0.5 * v * v * t ) / 32.2;
	printf("\nThe maximum height reached is:%f \n",h);
	getch();
	return;
}
