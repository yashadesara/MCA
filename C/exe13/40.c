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
			start=mid + 1;
			ans	= mid;
		}
			
		
		else
			end = mid - 1;
	} 
	return ans;
}
int main()
{
	int x = 11;
	printf("%d",mySqrt(x));
	return 0;
}
