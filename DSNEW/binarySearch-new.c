#include <stdio.h>  
int binarySearch(int a[], int beg, int end, int val)    
{    
    int mid;    
    if(end >= beg)     
    {        
		mid = (beg + end)/2;    
        if(a[mid] == val)                     
            return mid+1;    
                       
        else if(a[mid] < val)     
            return binarySearch(a, mid+1, end, val);    
        else       
            return binarySearch(a, beg, mid-1, val);               
    }    
    return -1;     
}   
int main() {  

	int a[10],search,n,i;
	printf("enter number of elements:");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
		
	printf("enter search elements:");
	scanf("%d",&search);

	int res = binarySearch(a, 0, n-1, search);  
	   
	if (res == -1)  
		printf("\nElement is not present in the array");  
	else  
		printf("\nElement is present at %d position of array", res);  
	  
	return 0;  
}  
