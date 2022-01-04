#include<stdio.h>
#include<conio.h>

double slop(int x1, int x2, int y1, int y2);

double slop(int x1, int x2, int y1, int y2)
{
    double z;
    z = (double)(y2-y1)/(x2-x1);
    return z;
}

void main()
{
    double x1=2, x2=12, y1=10, y2=6, z;
    z = slop(x1,x2,y1,y2);
    printf("slop is : %lf",z);
}