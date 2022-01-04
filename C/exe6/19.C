#include<stdio.h>
#include<conio.h>

double midpoint(int x1, int x2, int y1, int y2);

double midpoint(int x1, int x2, int y1, int y2)
{
    double ans1, ans2;
    ans1 = (double)(x1+x2)/2;
    ans2 = (double)(y1+y2)/2;
    printf("midpoint is : (%lf %lf)",ans1,ans2);
}

void main()
{
    double x1=3, x2=8, y1=7, y2=12;
    midpoint(x1,x2,y1,y2);
}