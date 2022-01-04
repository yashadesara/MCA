#include<stdio.h>
double mySqrt(double x)
{
	double start=1,end=x,ans;
	if(x==0 || x==1)
		return x;
	while (start<=end)
	{
		double mid = (start+end)/2;
		
		if(mid*mid == x)
			return mid;
		
		if(mid*mid<x)
		{
			start=mid + .0000001;
			ans	= mid;
		}
			
		
		else
			end = mid - .0000001;
	} 
	return ans;
}
int main()
{
	double x = 3102;
	printf("%lf",mySqrt(x));
	return 0;
}
