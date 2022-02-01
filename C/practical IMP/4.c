#include<stdio.h>

int mySqrt(int x)
{
	int start=1,end=x,ans;
	if(x==0 || x==1)
		return x;
		
	while (start<=end)
	{
		int mid = (start+end)/2;
		if(mid*mid == x)
			return mid;
		
		if(mid*mid<x)
		{
			start=mid;
			ans	= mid;
		}
		else
			end = mid;
	} 
	return ans;
}
int main()
{
	int x = 144;
	printf("sqare root is: %d",mySqrt(x));
}
