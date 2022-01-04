#include<stdio.h>
#include<conio.h>

double distance(int x1, int x2, int y1, int y2);

double distance(int x1, int x2, int y1, int y2)
{
    double z;
    z = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)); 
    return z;
}

void main()
{
    double x1=2, x2=12, y1=10, y2=6, z;
    z = distance(x1,x2,y1,y2);
    printf("value is : %lf",z);
}